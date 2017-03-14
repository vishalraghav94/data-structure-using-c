//
//  main.c
//  string reversal using stack
//
//  Created by Apple on 08/04/16.
//  Copyright (c) 2016 Gronical App Studios. All rights reserved.
//

#include <stdio.h>
#include <string.h>
void push ( char );
char pop();
#define MAX 20
char str[MAX];
char stack[MAX];
int top = -1;
int main()
{
    printf("Enter the String : ");
    gets(str);
    printf("\nInputted String : %s" , str);
    int i =0;
    while (str[i]!='\0') {
        push(str[i]);
        i++;
    }
    for (i=0; i<strlen(str); i++) {
        str[i] = pop();
    }
    printf("\nReversed String : %s\n\n" , str);
    return 0;
    
}
void push ( char c)
{
    
    if (top == (MAX -1)) {
        printf("\nStack Overflow");
        return;
    }
    top = top+1;
    stack[top] = c;
    
}
char pop ()
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