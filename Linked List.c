#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* link;
};
struct node* head;
int n;
void insert ( int x);
void print();
void delete(int x);
void addele ( int , int);
int main()
{
    head = NULL;
    int i , x , del , add , position , choice;
    while (1) {
    printf("1.Form List\n2.Add Element\n3.Delete Element\n4.Print List");
    printf("\n\nEnter Your Choice : ");
    scanf("%d" , &choice);
    switch (choice) {
        case 1:
    printf("\nEnter How Many Numbers? : ");
    scanf("%d" , &n);
    for (i=0; i<n; i++) {
        printf("\nEnter Element : ");
        scanf("%d" , &x);
        insert(x);
    }
        break;
    case 2:
    printf("\nEnter the element to add : ");
    scanf("%d" , &add);
    printf("\nEnter the position : ");
    scanf("%d",&position);
    addele(add, position);
        break;
    case 3:
    printf("\nEnter the number you want to delete : ");
    scanf("%d" , &del);
    delete(del);
        break;
    case 4:
    print();
        break;
    }
    }
    return 0;

}
void insert ( int x )
{
    struct node* temp;
    temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->link = head;
    head = temp;
}
void print()
{
    struct node* temp;
    temp = head;
    printf("\nList is : ");
    while (temp != NULL) {
        printf(" %d" , temp->data);
        temp = temp->link;
    }
    printf("\n");
    
}
void delete ( int x)
{
    struct node* temp , *q;
    temp = head;
    q = head;
        if (x == head->data) {
        head = temp->link;
        free(temp);
        return;
    }
        while (temp->link != NULL) {
        temp = temp->link;
        if (temp->data!=x) {
            q = q->link;
        }
        else if (temp->data == x)
        {
            break;
        }
        else
            continue;
    }
    if (temp == NULL) {
        free(temp);
    }
    else
    {
        q->link = temp->link;
                free(temp);
    }
}
void addele ( int add , int position)
{
    struct node* temp , *temp1;
    int i;
    temp = malloc(sizeof(struct node));
    temp1 = head;
    for (i=0; i<(position-2); i++) {
        temp1 = temp1->link;
    }
    temp->link = temp1->link;
    temp1->link = temp;
    temp->data = add;
}