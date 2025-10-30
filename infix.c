#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define SIZE 100
char stack[SIZE];
int top = -1;

void push(char item)
{
    if (top >= SIZE - 1) {
        printf("\nStack Overflow.");
    }
    else {
        top = top + 1;
        stack[top] = item;
    }
}

char pop()
{
    char item;
    if (top < 0) {
        printf("stack under flow");
        exit(1);
    }
    else {
        item = stack[top];
        top = top - 1;
        return (item);
    }
}

int is_operator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-') {
        return 1;
    }
    else {
        return 0;
    }
}

int precedence(char symbol)
{
    if (symbol == '^') {
        return (3);
    }
    else if (symbol == '*' || symbol == '/') {
        return (2);
    }
    else if (symbol == '+' || symbol == '-') {
        return (1);
    }
    else {
        return (0);
    }
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
    int i, j;
    char item;
    char x;
    push('(');
    strcat(infix_exp, ")");
    i = 0;
    j = 0;
    item = infix_exp[i];

    while (item != '\0')
    {
        if (item == '(') {
            push(item);
        }
        else if (isdigit(item)) {
            postfix_exp[j] = item;
            j++;
        }
        else if (is_operator(item) == 1) {
            x = pop();
            while (is_operator(x) == 1 && precedence(x) >= precedence(item)) {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if (item == ')') {
            x = pop();
            while (x != '(') {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
        }
        i++;
        item = infix_exp[i];
    }
    postfix_exp[j] = '\0';
}

void evaluation(char postfix[])
{
    int i, a, b, result, post_eval;
    char ch;
    for(i=0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];
        if(isdigit(ch))
        {
            push(ch - '0');
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            b = pop();
            a = pop();
            switch(ch)
            {
                case '+':
                    result = a+b;
                    break;
                case '-':
                    result = a-b;
                    break;
                case '*':
                    result = a*b;
                    break;
                case '/':
                    result = a/b;
                    break;
                case '^':
                    result = pow(a,b);
                    break;
            }
            push(result);
        }
    }
    post_eval = pop();
    printf("\nThe postfix evaluation is: %d\n",post_eval);
}

void main()
{
    char infix[SIZE], postfix[SIZE];
    printf("\nEnter Infix expression : ");
    scanf("%s",infix);
    InfixToPostfix(infix, postfix);
    printf("Postfix Expression: ");
    printf("%s",postfix);
    evaluation(postfix);
}
