//
//  main.c
//  Binary tree
//
//  Created by Vishal Raghav on 03/08/16.
//  Copyright (c) 2016 Vishal Raghav. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root = NULL;
struct node* getnew ( int data ){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}
struct node* insert( struct node* root , int data ){
    if (root==NULL) {
        root = getnew(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}
int search ( struct node* root , int data){
    if (root==NULL) {
        return 0;
    }
    if (data == root->data) {
        return 1;
    }
    else if (data<=root->data )
    {
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}
struct node* find( struct node* root , int data){
    if (root==NULL) {
        return 0;
    }
    if (data == root->data) {
        return root;
    }
    else if (data<=root->data )
    {
        return find(root->left, data);
    }
    else{
        return find(root->right, data);
    }
}
struct node* findmin ( struct node* root )
{
    if (root==NULL) {
        printf("\nError: Binary Tree is Empty!");
    }
    else if(root->left == NULL)
        return root;
    
        return findmin(root->left);
}
struct node* findmax ( struct node* root )
{
    if (root==NULL) {
        printf("\nError: Binary Tree is Empty!");
    }
    else if(root->right == NULL)
        return root;
    
    return findmax(root->right);
}
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
void printbreadth(struct node* root){
    if (root==NULL) {
        return;
    }
    push(root);
    while ((start!=(-1))&&(start<=end)) {
        struct node* current = pop();
        printf("%d " , current->data);
        if (current->left!=NULL) {
            push(current->left);
        }
        if (current->right!=NULL) {
            push(current->right);
        }
    }
}
void printpreorder(struct node* root){
    if (root==NULL) {
        return;
    }
    printf("%d " , root->data);
    printpreorder(root->left);
    printpreorder(root->right);
}
void printinorder(struct node* root){
    if (root==NULL) {
        return;
    }
    printinorder(root->left);
    printf("%d " , root->data);
    printinorder(root->right);
}
void printpostorder(struct node* root){
    if (root==NULL) {
        return;
    }
    printpostorder(root->left);
    printpostorder(root->right);
    printf("%d " , root->data);
    
}
int bstval(struct node* root , int a , int b)
{
    if (root==NULL) {
        return 1;
    }
    if (((root->data)<b)&&((root->data)>a)&&(bstval(root->left, a , root->data))&&(bstval(root->right, root->data , b))) {
        return 1;
    }
    else
        return 0;
}

int bstvalidation(struct node* root){
    return bstval(root , INT32_MIN , INT32_MAX);
}
struct node* deletenode (struct node* root , int data ){
    if (root==NULL) {
        return root;
    }
    else if (root->data < data)
        root->right = deletenode(root->right, data);
    else if (root->data > data)
        root->left = deletenode(root->left, data);
    else{
        if (((root->left)==NULL)&&((root->right)==NULL)) {
            free(root);
            root = NULL;
        }
        else if ((root->left)==NULL) {
            struct node* temp = root;
            root = root->right;
            free(temp);
            temp=NULL;
        }
        else if ((root->right)==NULL) {
            struct node* temp = root;
            root = root->left;
            free(temp);
            temp=NULL;
        }
        else{
            struct node* temp= findmin(root->right);
            root->data = temp->data;
            root->right = deletenode(root->right, temp->data);
        }
    }
    return root;
}
struct node* inordersuccessor ( struct node* root , int data)
{
    struct node* current = find(root, data);
    if (root==NULL) {
        return NULL;
    }
    if (current->right!=NULL) {
        return findmin(current->right);
    }
    else{
        struct node* successor = NULL;
        struct node* ancestor = root;
        while (ancestor!=current) {
            if (current->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else{
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}
int main(){
    root = insert(root, 15);
    root = insert(root, 18);
    root = insert(root, 13);
    root = insert(root, 35);
    root = insert(root, 12);
    root = insert(root, 98);
    root = insert(root, 8);
    root = insert(root, 25);
    root = insert(root, 58);
    root = insert(root, 343);
    root = insert(root, 365);
    root = insert(root, 129);
    root = insert(root, 93);
    root = insert(root, 80);
    
    printf("\nBinary Tree is (breadth Traversal) : ");
    printbreadth(root);
    printf("\nBinary Tree is (Preorder Traversal) : ");
    printpreorder(root);
    printf("\nBinary Tree is (Inorder Traversal) : ");
    printinorder(root);
    printf("\nBinary Tree is (Postorder Traversal) : ");
    printpostorder(root);
    printf("\nMaximum Number is : %d" , findmax(root)->data);
    printf("\nMinimum Number is : %d" , findmin(root)->data);
    printf("\nHeight of tree : %d" , findheight(root));
    int b = bstvalidation(root);
    if (b==1) {
        printf("\nIS BST");
    }
               else
                   printf("\nNOT BST");
    int i;
    printf("\nEnter no to be searched : ");
    scanf("%d" , &i);
    int j = search(root, i);
    if (j == 1) {
        printf("\nFound");
    }
    else
        printf("\nNot Found");
    printf("\nEnter no to be deleted : ");
    scanf("%d" , &i);
    deletenode(root, i);
    printinorder(root);
    printf("\nEnter no to find its inorder successor : ");
    scanf("%d" , &i);
    printf("\nInorder Successor: %d" , inordersuccessor(root, i)->data);
    return 0;
}

