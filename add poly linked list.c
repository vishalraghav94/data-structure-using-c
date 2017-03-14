#include <stdio.h>
#include <stdlib.h>
void insert ( int , int , int);
void print(int);
void addition();
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
        printf("\n1.Form Polynomial\n2.Print List\n3.Addition ( LIST 3 = LIST 1 + LIST 2 )");
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
                printf("\nEnter List Number(1/2) : ");
                scanf("%d" , &listnum);
                print(listnum);
                break;
            case 3:
                addition();
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
        printf("%dx^%d + " , temp->coefficient , temp->exponent);
        temp = temp->link;
    }
    printf("\n");
    
}
void addition ()
{
    struct node* temp1 , *temp2;
    temp1 = start[0];
    temp2 = start[1];
    while ((temp1!=NULL)&&(temp2!=NULL)) {
        if (temp1->exponent == temp2->exponent){
        insert(((temp1->coefficient)+(temp2->coefficient)), temp1->exponent, 3);
        temp1= temp1->link;
        temp2=temp2->link;
        }
        else if (temp1->exponent < temp2->exponent)
        {
         insert(temp2->coefficient, temp2->exponent, 3);
            temp2 = temp2->link;
        }
        else
        {
            insert(temp1->coefficient, temp1->exponent, 3);
            temp1 = temp1->link;

        }
    }
    if ((temp1!=NULL)==(temp2!=NULL)) {
        return;
    }
    if (temp1==NULL) {
        while (temp2!=NULL) {
            insert(temp2->coefficient, temp2->exponent, 3);
            temp2 = temp2->link;
        }
        return;
    }
    if (temp2==NULL) {
        while (temp1!=NULL) {
            insert(temp1->coefficient, temp1->exponent, 3);
            temp1 = temp1->link;
        }
        return;
    }
}