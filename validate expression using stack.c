//
//  main.c
//  validate expression stack
//
//  Created by Apple on 08/04/16.
//  Copyright (c) 2016 Gronical App Studios. All rights reserved.
//

#include <stdio.h>
#define MAX 20
#include <string.h>
char stack[MAX];
int top = -1;
int flag = 1;
void push ( char );
char pop();
int main()
{
    char exp[MAX] , temp;
    int i;
    printf("Enter Expression : ");
    gets(exp);
    for (i=0; i<strlen(exp); i++) {
        if ((exp[i] == '(')||(exp[i]=='{')||(exp[i] == '[')) {
            push(exp[i]);
        }
    }
    if (top == -1) {
        flag = 0;
    }
    for (i=0; i<strlen(exp); i++) {
        if ((exp[i] == ')')||(exp[i]=='}')||(exp[i] == ']')) {
        temp = pop();
        if ((exp[i] == ')')&&((temp == '{') || (temp == '['))) {
            flag = 0;
            break;
        }
        if ((exp[i] == '}')&&((temp == '[') || (temp == '('))) {
            flag = 0;
            break;
        }
        if ((exp[i] == ']')&&((temp == '{') || (temp == '('))) {
            flag = 0;
            break;
        }
        if (top == -1) {
            break;
        }
        }
        
    }
    if (top>=0) {
        flag = 0;
    }
    if (flag == 0) {
        printf("\nInvalid Expression\n\n");
    }
    else
        printf("\nValid Expression\n\n");
    return 0;
}
void push ( char c)
{
    if (top == (MAX - 1)) {
        printf("\nStack Overflow");
    }
    else
    {
        top = top+1;
        stack[top] = c;
    }
}
char pop()
{
    if (top == -1) {
        printf("\nStack Underflow");
        return '\0';
    }
    else
        return stack[top--];
}