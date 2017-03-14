#include <stdio.h>
#include <stdlib.h>
void insert ( int , int );
void print();
struct node{
    int coefficient;
    int exponent;
    struct node* link;
};
struct node* start;
int n;
int main()
{
    start = NULL;
    int choice , coeff , expo , i;
    while (1) {
        printf("\n1.Form Polynomial\n2.Print List\n");
        printf("\n\nEnter Your Choice : ");
        scanf("%d" , &choice);
        switch (choice) {
            case 1:
                printf("How Many Elements? : ");
                scanf("%d" , &n);
                for (i=0; i<n; i++) {
                    printf("\nEnter coefficient : ");
                    scanf("%d" , &coeff);
                    printf("\nEnter exponent : ");
                    scanf("%d" , &expo);
                    insert(coeff , expo);
                }
                break;
            case 2:
                print();
                break;
                default:
                break;
        }
        
    }
    return 0;
}
void insert( int coeff , int expo)
{
    struct node* temp , *q;
    temp = malloc(sizeof(struct node));
    temp->coefficient = coeff;
    temp->exponent = expo;
    q = start;
    if (start == NULL || expo > (q->exponent)) {
        temp->link = start;
        start = temp;
    }
    else
    {
        while (q->link != NULL && expo < (q->link->exponent)) {
            q = q->link;
        }
        temp->link = q->link;
        q->link = temp;
    }
    
}
void print()
{
    struct node* temp;
    temp = start;
    printf("\nList is : ");
    while (temp != NULL) {
        if (temp->exponent==0) {
            printf("%d" ,temp->coefficient);
            return;
        }
        printf("%dx^%d + " , temp->coefficient , temp->exponent);
        temp = temp->link;
    }
    printf("\n");
    
}
