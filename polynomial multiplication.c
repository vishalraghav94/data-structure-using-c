#include <stdio.h>
#include <stdlib.h>
void insert ( int , int , int);
void print(int);
void delete ( int , int);
void multiplication();
struct node{
    int coefficient;
    int exponent;
    struct node* link;
};
struct node* start[3];
int n;
int main()
{
    start[0] = NULL;
    start[1] = NULL;
    start[2] = NULL;
    int choice , coeff , expo , i , listnum = 0;
    while (1) {
        printf("\n1.Form Polynomial\n2.Print List\n3.Multiplication ( LIST 3 = LIST 1 * LIST 2 )");
        printf("\n\nEnter Your Choice : ");
        scanf("%d" , &choice);
        switch (choice) {
            case 1:
                printf("\nEnter List Number(1/2/3) : ");
                scanf("%d" , &listnum);
                printf("How Many Elements? : ");
                scanf("%d" , &n);
                for (i=0; i<n; i++) {
                    printf("\nEnter coefficient : ");
                    scanf("%d" , &coeff);
                    printf("\nEnter exponent : ");
                    scanf("%d" , &expo);
                    insert(coeff , expo , listnum);
                }
                break;
            case 2:
                printf("\nEnter List Number(1/2/3) : ");
                scanf("%d" , &listnum);
                print(listnum);
                break;
            case 3:
                multiplication();
                break;
            default:
                break;
        }
        
    }
    return 0;
}
void insert( int coeff , int expo , int listnum)
{
    struct node* temp , *q;
    temp = malloc(sizeof(struct node));
    temp->coefficient = coeff;
    temp->exponent = expo;
    q = start[listnum-1];
    if (start[listnum-1] == NULL || expo > (q->exponent)) {
        temp->link = start[listnum-1];
        start[listnum-1] = temp;
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
void print(listnum)
{
    struct node* temp;
    temp = start[listnum-1];
    printf("\nList is : ");
    while (temp != NULL) {
        if (temp->exponent==0) {
            printf("%d" ,temp->coefficient);
            return;
        }
        if (temp->link == NULL) {
            printf("%dx^%d " , temp->coefficient , temp->exponent);
            return;
        }
        printf("%dx^%d + " , temp->coefficient , temp->exponent);
        temp = temp->link;
        }
    printf("\n");
}
void multiplication()
{
    struct node* temp ,*q;
    int count =1;
    temp = start[0];
    while (temp!=NULL) {
        q = start[1];
        while (q!=NULL) {
            insert((temp->coefficient*q->coefficient), (temp->exponent+q->exponent), 3);
            q = q->link;
        }
        temp = temp->link;
    }
    temp = NULL;
    q = start[2];
    while (q->link!=NULL) {
        temp = q->link;
        if (q->exponent == temp->exponent) {
            while (q->exponent == temp->exponent) {
                q->coefficient = q->coefficient + temp->coefficient;
                delete((count+1) , 3);
                temp = q->link;
            }
        }
        q = q->link;
        count++;
    }
    printf("\n____Multiplication Completed____");
}
void delete ( int count , int listnum )
{
    struct node* temp,*q;
    temp = start[listnum-1];
    q = start[listnum-1];
    int count2 = 1;
    while ((temp->link!=NULL)&&(count2!= count)) {
        temp = temp->link;
        count2++;
        if (count2 != count) {
            q = q->link;
        }
        
    }
    if (temp->link == NULL) {
        q->link = NULL;
        free(temp);
        return;
    }
    q->link = temp->link;
    free(temp);
}
