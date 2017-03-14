//
//  main.c
//  circular linked list
//
//  Created by Apple on 31/03/16.
//  Copyright (c) 2016 Gronical App Studios. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
void insert ( int num);
void delete ( int );
void print();
void addbegin ( int num );
void addbetw ( int num , int position);
struct node{
    int data;
    struct node* link;
};
struct node* last;
int main()
{
    last = NULL;
    int choice , num , position,element , n , i;
    while (1) {
        printf("1.Add last\n2.Delete Element\n3.Print List\n4.Add at beginning\n5.Add in between");
        printf("\n\nEnter Your Choice : ");
        scanf("%d" , &choice);
        switch (choice) {
            case 1:
                printf("How Many Elements? : ");
                scanf("%d" , &n);
                for (i=0; i<n; i++) {
                    printf("\nEnter element : ");
                    scanf("%d" , &num);
                    insert(num);
                }
                break;
            case 2:
                printf("\nEnter Element : ");
                scanf("%d" , &element);
                delete(element);
                break;
            case 3:
                print();
                break;
            case 4:
                printf("How Many Elements? : ");
                scanf("%d" , &n);
                for (i=0; i<n; i++) {
                    printf("\nEnter element : ");
                    scanf("%d" , &num);
                    addbegin(num);
                }
                break;
            case 5:
                printf("How Many Elements? : ");
                scanf("%d" , &n);
                for (i=0; i<n; i++) {
                    printf("\nEnter element : ");
                    scanf("%d" , &num);
                    printf("\nEnter Position : ");
                    scanf("%d" , &position);
                    addbetw(num , position);
                }
                break;
            default:
                break;
        }
    }
    return 0;
}
void insert ( int num )
{
    struct node* temp;
    temp = malloc(sizeof(struct node));
    temp->data = num;
    if (last == NULL) {
        last = temp;
        temp->link = last;
        
    }
    else
    {
        temp->link = last->link;
        last->link = temp;
        last = temp;
    }
}
void delete ( int element)
{
    if (last == NULL){ printf("\nNo element present..\n");
        return;
    }
    struct node* temp , *q;
    temp = last->link;
    q = last->link;
    temp = temp->link;
    if (element==q->data) {
        last->link = q->link;
        free(q);
    }
    else if (element==last->data)
    {
        while (temp!=last) {
            temp = temp->link;
            q = q->link;
        }
        q->link = last->link;
        last = NULL;
        free(temp);
        last = q;
        return;
    }
    else if (temp->data == element)
    {
        q->link = temp->link;
        free(temp);
        return;
    }
    while (temp != last) {
        temp = temp->link;
        q = q->link;
        if (temp->data == element) {
            q->link = temp->link;
            free (temp);
            break;
        }
    }
    
}
void print()
{
    struct node* temp;
    temp = last->link;
    printf("\nList is : ");
    while (temp != last) {
        printf(" %d" , temp->data);
        temp = temp->link;
    }
    printf(" %d\n" , temp->data);
    
}
void addbegin(int num)
{
    struct node* temp;
    temp = malloc(sizeof(struct node));
    temp->data = num;
    if (last == NULL) {
        last = temp;
        temp->link = last;
        
    }
    else
    {
        temp->link = last->link;
        last->link = temp;
    }
    
}
void addbetw(int num , int position)
{
    struct node* temp , *q;
    int i;
    temp = malloc(sizeof(struct node));
    temp->data = num;
    q = last->link;
    if (position == 1) {
        addbegin(num);
        return;
    }
    for (i=0; i<(position-2); i++) {
        q = q->link;
    }
    if (last == NULL) {
        last = temp;
        temp->link = last;
        
    }
    else
    {
        temp->link = q->link;
        q->link = temp;
    }
    
}