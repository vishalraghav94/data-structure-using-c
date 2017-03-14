//
//  main.c
//  solving postfix
//
//  Created by Vishal Raghav on 19/08/16.
//  Copyright (c) 2016 Vishal Raghav. All rights reserved.
//

#include <stdio.h>
#define MAX 100
int stac[MAX];
int* top = NULL;
void push ( int data ) {
    if (top == NULL) {
        top = stac;
        *top = data;
    }
    else{
        top++;
        *top = data;
    }
}
void pop(){
    if (top == NULL) {
        printf("stack is empty");
    }
    else if (top == stac){
        top = NULL;
    }
    else{
        top--;
    }
}
int isnumeric ( char ptr){
    if ((ptr>='0')&&(ptr<='9')) {
        return 1;
    }
    else
        return 0;
}
int isoperator(char ptr){
    if ((ptr=='+')||(ptr=='-')||(ptr=='*')||(ptr=='/')||(ptr=='%')) {
        return 1;
    }
    else
        return 0;
}
int calculate(char op , int op1 , int op2)
{
    switch (op) {
        case '+':
                return (op1+op2);
            break;
            case '-':
                return (op1-op2);
            break;
            case '*':
                return (op1*op2);
            break;
            case '/':
                return (op1/op2);
            break;
            case '%':
                return (op1%op2);
            break;
        default:
            return 0;
            break;
    }
}
int postfixevaluate ( char []);
int main()
{
    char str[MAX];
    int result;
    printf("Enter String: ");
    fgets(str, 100, stdin);
    result = postfixevaluate(str);
    printf("\nResult is : %d" , result);
    return 0;
}
int postfixevaluate( char str[]){
    char* ptr = str;
    while (((*ptr) != '\n')&&((*ptr) != '\0')) {
        if ((*ptr)==' ') {
            continue;
        }
        else if (isnumeric(*ptr)) {
            int operand = 0;
            while (((*ptr)!='\0') && (!(isoperator(*ptr))) && ((*ptr)!=' ')) {
                operand = (operand*10) + ( (*ptr) - '0');
                ptr++;
            }
            push(operand);
            if (isoperator(*ptr)) {
                ptr--;
            }
        }
        else {
            int op2 = *top;
            pop();
            int op1 = *top;
            pop();
            int res = calculate(*ptr, op1, op2);
            push(res);
        }
        ptr++;
    }
    return stac[0];
}
