#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <math.h>       /* for sin(), exp(), pow(), etc. */

#define MAXOP       100     /* max size of operand or operator */
#define NUMBER      '0'     /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
double top(void);
void duplicate(void);
void swap(void);
void clear(void);

/* reverse Polish calculator */
main()
{
    int type;
    double op1, op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            push((int)pop() % (int)op2);
            break;
        case '^':
            op2 = pop();
            op1 = pop();
            if (op1 == 0.0 && op2 <= 0.0) {
                printf("error: domain error\n");
                push(0.0);
            }
            else if (op1 < 0.0)
                push(pow(op1, (int)op2));
            else
                push(pow(op1, op2));
            break;
        case 't':
        case 'T':
            printf("\t%.8g\n", top());
            break;
        case 'd':
        case 'D':
            duplicate();
            break;
        case 's':
        case 'S':
            swap();
            break;
        case 'c':
        case 'C':
            clear();
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL  100     /* maximum depth of val stack */

int sp = 0;             /* next free stack position */
double val[MAXVAL];     /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* top: return top value from stack without popping */
double top(void)
{
    return val[sp];
}

/* duplicate: duplicate the top stack value */
void duplicate(void) 
{
    if (sp < MAXVAL) {
        val[sp+1] = val[sp];
        sp++;
    } 
    else 
        printf("error: stack full, can't duplicate\n");
}

/* swap: swap the top two values on the stack */
void swap(void) {
    if (sp >= 1) {
        int temp;
        temp = val[sp];
        val[sp] = val[sp-1];
        val[sp-1] = temp;
    }
    else
        printf("error: stack contains less than two values, can't swap\n");
}

/* clear: clear all values from the stack */
void clear(void) {
    val[sp] = 0.0;
    while (sp > 0)
        val[--sp] = 0.0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i = 0, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (c == '-') {     /* test for negative number */
        if (isdigit(c = getch())) {
            s[0] = '-';
            s[1] = c;
            i++;
        } else {
            ungetch(c);
            return s[0];
        }
    }
    else if (c == 't' || c == 'T' || c == 'd' || c == 'D'
        || c == 's' || c == 'S' || c == 'c' || c == 'C') {
        getch();
        return s[0];     /* return character command */
    }
    if (!isdigit(c) && c != '.')
        return c;       /* not a number */
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
