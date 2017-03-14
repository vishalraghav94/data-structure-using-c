//
//  main.c
//  Implementing Queue
//
//  Created by Vishal Raghav on 23/08/16.
//  Copyright (c) 2016 Vishal Raghav. All rights reserved.
//

#include <stdio.h>
struct node* queue[100];
int start = -1;
int end = -1;
void push ( struct node* address )
{
    if (start == (-1)||(start>end)) {
        start = 0;
        end = 0;
    }
    else if (end==100)
    {
        printf("\nQueue Overflow!");
    }
    else
        end++;
    queue[end] = address;
}
struct node* pop() {
    struct node* d;
    if (start == (-1)||(start>end)) {
        printf("\nQueue Underflow!");
    }
    else
    {
        d = queue[start];
        start++;
    }
    return d;
}
void print(){
    int i;
    if (start == (-1)||(start>end)) {
        printf("\nQueue Underflow!");
        return;
    }
    for (i=start; i<=end; i++) {
        printf("%d " , queue[i]);
    }
}
int main() {
    push(90);
    push(76);
    push(63);
    push(23);
    push(45);
    push(3);
    print();
    printf("\nPopped: %d\n" ,pop());
    print();
    printf("\nPopped: %d\n" ,pop());
    print();
    push(100);
    print();
    return 0;
}
