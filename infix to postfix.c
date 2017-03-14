//
//  main.c
//  infix to postfix
//
//  Created by Apple on 13/04/16.
//  Copyright (c) 2016 Gronical App Studios. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 20
#define Blank ' '
#define Tab '\t'
long int stack[MAX];
char infix[MAX] , postfix[MAX];
int i , top = -1 , j;
void push ( long int );
long int pop();
int prec ( char );
void infix_to_postfix();
int blank(char);
long int eval();
int main()
{
    printf("Enter Infix Expression : ");
    fflush(stdin);
    gets(infix);
    infix[strlen(infix)] = '#';
    push('#');
    infix_to_postfix();
    printf("\nPostfix Expression : ");
    puts(postfix);
    printf("\nResult = %ld \n" , eval());
    return 0;
    
}
void push ( long int c)
{
    
    if (top == (MAX -1)) {
        printf("\nStack Overflow");
        return;
    }
    top = top+1;
    stack[top] = c;
    
}
long int pop ()
{
    if (top == -1) {
        printf("\nStack Underflow");
        return 0;
    }
    else
    {
        return stack[top--];
    }
    
}
int prec ( char c)
{
    switch (c) {
        case '(':
            return 0;
            break;
           case '+':
            case '-':
            return 1;
            break;
            case '*':
            case '/':
            case '%':
            return 2;
            break;
            case '^':
            return 3;
            break;
            default:
            return 100;
            break;
    }
}
int blank ( char c )
{
    if ((c == Blank) || (c == Tab)) {
        return 1;
    }
    else return 0;
}
void infix_to_postfix ()
{
    char next;
    int temp;
    j = 0;
    for (i = 0; infix[i]!='#'; i++) {
        if(!blank(infix[i])) {
            switch (infix[i]) {
                case '(':
                    push('(');
                    break;
                    case ')':
                    while ((next = pop())!='(') {
                        postfix[j++] = next;
                    }
                    break;
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                    case '%':
                    case '^':
                    temp = prec(infix[i]);
                    while ((temp <= prec(stack[top]))&&(stack[top]!='#')) {
                        next = pop();
                        postfix[j++] = next;
                    }
                    push(infix[i]);
                    break;
                default:
                    postfix[j++] = infix[i];
                    break;
            }
        }
    }
    while (stack[top]!='#') {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
long int eval()
{
    long int result;
   long int a , b;
    postfix[strlen(postfix)] = '#';
    for (i = 0; postfix[i]!='#'; i++) {
        if ((postfix[i]<='9')&&(postfix[i]>='0')) {
            push(postfix[i] - 48);
        }
        else{
        a = pop();
        b= pop();
        switch (postfix[i]) {
            case '+':
                push(b+a);
                break;
            case '-':
                push(b-a);
                break;
            case '*':
                push(b*a);
                break;
            case '/':
                push(b/a);
                break;
            case '%':
                push(b%a);
                break;
            case '^':
                push(pow(b,a));
                break;
                    }
        }
    }
    result = pop();
    return result;
    
}
