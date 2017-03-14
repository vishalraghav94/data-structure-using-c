//
//  main.c
//  AVL TREES
//
//  Created by Vishal Raghav on 16/09/16.
//  Copyright (c) 2016 Vishal Raghav. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef enum { FALSE , TRUE } bool;
struct node {
    int data;
    int balance;
    struct node* right;
    struct node* left;
};
bool ht_inc;
struct node* insert ( int , struct node*);
void display ( int*,int , int );
struct node* queue[100];
int start = -1;
int end = -1;
int arr[100];
int _noe = 0;
int max( int a , int b)
{
    if (a>=b) {
        return a;
    }
    else
        return b;
}
int findheight ( struct node* root)
{
    if (root==NULL) {
        return -1;
    }
    return (max(findheight(root->left) , findheight(root->right)) + 1);
}
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
void printbreadth(struct node* root){
    if (root==NULL) {
        return;
    }
    push(root);
    while ((start!=(-1))&&(start<=end)) {
        struct node* current = pop();
        arr[_noe] = current->data;
        _noe++;
        if (current->left!=NULL) {
            push(current->left);
        }
        if (current->right!=NULL) {
            push(current->right);
        }
    }
}
int main() {
    int choice , noe , i , element,j;
    struct node* root = NULL;
    while (1) {
        printf("\n1.Insert\n2.Display\n3.Exit");
        printf("\nEnter Choice : ");
        scanf("%d" , &choice);
        switch (choice) {
            case 1:
                printf("\nNumber of elements : ");
                scanf("%d" , &noe);
                for (i=0; i<noe; i++) {
                    printf("\nEnter Element- %d : ", (i+1));
                    scanf("%d",&element);
                    root = insert(element, root);
                }
                break;
                case 2:
                printf("\nTree is : \n");
                printbreadth(root);
                printf("\n");
                display(arr,findheight(root),_noe);
                break;
                case 3:
                return 0;
                break;
            default:
                printf("\n________Invalid Choice________");
                break;
        }
    }
    return 0;
}
struct node* insert ( int data , struct node* pptr){
    struct node* aptr;
    struct node* bptr;

    if (pptr==NULL) {
        pptr = (struct node*)malloc(sizeof(struct node));
        pptr->data = data;
        pptr->left=NULL;
        pptr->right=NULL;
        pptr->balance=0;
        ht_inc = TRUE;
        return pptr;
    }
    if (data < (pptr->data)) {
        pptr->left = insert(data, pptr->left);
        if (ht_inc == TRUE) {
            switch (pptr->balance) {
                case -1:/*Right Heavy*/
                    pptr->balance = 0;
                    ht_inc = FALSE;
                    break;
                case 0:/*Balanced*/
                    pptr->balance = 1;
                    break;
                case 1:/*Left Heavy*/
                    aptr = pptr->left;
                    if (aptr->balance == 1) {
                        printf("\nLeft to Left Rotation");
                        pptr->left = aptr->right;
                        aptr->right = pptr;
                        pptr->balance = 0;
                        aptr->balance=0;
                        pptr = aptr;
                    }
                    else{
                        printf("\nLeft to Right rotation");
                        bptr = aptr->right;
                        aptr->right = bptr->left;
                        bptr->left = aptr;
                        pptr->left = bptr->right;
                        bptr->right=pptr;
                        if (bptr->balance == 1) {
                            pptr->balance = -1;
                        }
                        else
                            pptr->balance = 0;
                        if (bptr->balance == -1) {
                            aptr->balance = 1;
                        }
                        else
                            aptr->balance = 0;
                        bptr->balance = 0;
                        pptr = bptr;
                    }
                    ht_inc = FALSE;
                    break;
                default:
                    break;
            }
        }
    }
    if (data > (pptr->data)) {
        pptr->right = insert(data, pptr->right);
        if (ht_inc == TRUE) {
            switch (pptr->balance) {
                case 1:/*Left Heavy*/
                    pptr->balance = 0;
                    ht_inc = FALSE;
                    break;
                case 0:/*Balanced*/
                    pptr->balance = -1;
                    break;
                case -1: /*Left Heavy*/
                    aptr = pptr->right;
                    if (aptr->balance == -1) {
                        printf("\nRight to Right Rotation");
                        pptr->right = aptr->left;
                        aptr->left = pptr;
                        pptr->balance = 0;
                        aptr->balance=0;
                        pptr = aptr;
                    }
                    else{
                        printf("\nRight to Left rotation");
                        bptr = aptr->left;
                        aptr->left = bptr->right;
                        bptr->right = aptr;
                        pptr->right = bptr->left;
                        bptr->left = pptr;
                        if (bptr->balance == -1) {
                            pptr->balance = 1;
                        }
                        else
                            pptr->balance = 0;
                        if (bptr->balance == 1) {
                            aptr->balance = -1;
                        }
                        else
                            aptr->balance = 0;
                        bptr->balance = 0;
                        pptr = bptr;
                    }
                    ht_inc = FALSE;
                    break;
                default:
                    break;
            }
        }

    }
    return pptr;
}
void display ( int arr[] , int height , int _noe){
    int width = 5*height;
    int width1 = width+15;
    int width2 = 2*width;
    int var_height =0;
    int max_nodes;
    int i,j, k;
    for(i=0;i<_noe;i++)
    {
        for(k=0;k<(width1-width2);k++)
            printf(" ");
        max_nodes = pow(2,var_height);
        var_height++;
        for(j=0;j<max_nodes;j++)
        {
            printf("%*d",width2,arr[i]);
            i++;
        }
        printf("\n");
        width1 = width1-5;
        width2 = width2/2;
    }
}
