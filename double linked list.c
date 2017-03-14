//
//  main.c
//  double linked list
//
//  Created by Apple on 01/04/16.
//  Copyright (c) 2016 Gronical App Studios. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
void insert (int);
void insertbetw( int , int);
void print();
void printbackw();
void delete ( int );
struct node {
    struct node* previous;
    int info;
    struct node* next;
};
struct node* start;
int main()
{
    start = NULL;
    int choice , num , n , i , position , element;
    while (1) {
    printf("\n1.Insert in Beginning\n2.Insert in between\n3.Print\n4.Print Backwards\n5.Delete");
    printf("\n\nEnter Choice : ");
    scanf("%d" , &choice);
    switch (choice) {
        case 1:
            printf("\nHow many elements : ");
            scanf("%d" , &n);
            for (i=0; i<n; i++) {
                printf("\nEnter element : ");
                scanf("%d" , &num);
                insert(num);
            }
            break;
        case 2:
            printf("\nEnter position : ");
            scanf("%d" , &position);
            printf("\nHow many elements : ");
            scanf("%d" , &n);
            for (i=0; i<n; i++) {
                printf("\nEnter element : ");
                scanf("%d" , &num);
                insertbetw(num , position);
            }
            break;
        case 3:
            print();
            break;
        case 4:
            printbackw();
            break;
        case 5:
            printf("\nEnter the element : ");
            scanf("%d" , &element);
            delete(element);
            break;
        default:
            break;
    }
    }
    return 0;
}
void print()
{
    struct node* temp;
    temp = start;
    printf("\nList is : ");
    while (temp != NULL) {
        printf(" %d" , temp->info);
        temp = temp->next;
    }
    printf("\n");
    
}
void insert ( int num )
{
    struct node* temp;
    temp = malloc(sizeof(struct node));
    temp->info = num;
    if (start == NULL) {
        start = temp;
        temp->next = NULL;
        return;
    }
    temp->next = start;
    start->previous = temp;
    start = temp;
}
void insertbetw ( int num , int position)
{
    struct node* temp , *temp1;
    int i;
    if (position == 1) {
        insert(num);
        return;
    }
    temp = malloc(sizeof(struct node));
    temp->info = num;
    temp1 = start;
    for (i=0; i<position-2; i++) {
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
    temp->previous = temp1;
}
void printbackw ()
{
    struct node* temp1 , *last;
    last = NULL;
    temp1 = start;
    while ((temp1->next)!=NULL) {
        temp1 = temp1->next;
    }
    last = temp1;
    printf("\nList is : ");
    while (last!= start) {
        printf(" %d" , last->info);
        last = last->previous;
    }
    printf(" %d\n" ,last->info);
}
void delete ( int num)
{
    struct node* temp , *q;
    q = NULL;
    temp = start;
    if (start == NULL) {
        printf("\nNo element to delete...");
        return;
    }
    if (temp->next == NULL) {
        free(temp);
        start = NULL;
        return;
    }
    if (temp->info==num) {
        start = temp->next;
        (temp->next)->previous = NULL;
        free(temp);
        return;
    }
    while ((temp != NULL)&&(temp->info!=num)) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nElement not found...");
    }
    else{
        q = temp->previous;
        q->next = temp->next;
        if (temp->next != NULL) {
        (temp->next)->previous = q;
        }
        free(temp);
        
    }
}