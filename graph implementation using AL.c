#include<stdio.h>
#include<stdlib.h>
struct edge{
    char dest;
    struct edge* link;
};
struct node{
    char data;
    struct node* next;
    struct edge* adj;
};
struct node* start = NULL;
void insert_node(char node);
void insert_edge(char origin , char destin);
void display();
void delete_node(char node);
void delnode_edge(char node);
void delete_edge(char origin , char destination);
struct node* find( char node);
int main()
{
    char node , origin , destin;
    int choice;
    while(1)
    {
        printf("\n\n1.Add Node\n2.Add Edge\n3.Display\n4.Delete Node\n5.Delete Edge\n6.Exit");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("\nEnter node : ");
            fflush(stdin);
            scanf("%c",&node);
            insert_node(node);
            break;
        case 2:
            printf("\nEnter origin and destination(separated by space) : ");
            fflush(stdin);
            scanf("%c %c",&origin , &destin);
            insert_edge(origin,destin);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nEnter node to be deleted : ");
            fflush(stdin);
            scanf("%c", &node);
            delete_node(node);
            //delnode_edge(node);
            break;
        case 5:
            printf("\nEnter origin and destination(separated by space) : ");
            fflush(stdin);
            scanf("%c %c",&origin , &destin);
            delete_edge(origin,destin);
            break;
        default:
            exit(0);
        }
    }

return 0;
}
void insert_node(char node)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = node;
    temp->next = NULL;
    temp->adj = NULL;
    if(start==NULL)
    {
        start = temp;
        return;
    }
    struct node* temp1 = start;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next = temp;
}
void insert_edge( char origin , char destin)
{
    struct edge* temp = (struct edge*)malloc(sizeof(struct edge));
    temp->dest = destin;
    temp->link = NULL;
    struct node* orig , *destination;
 orig = find(origin);
 destination = find(destin);
 if((orig==NULL)||(destination==NULL))
 {
 printf("\nNOde not found");
 return;
 }
 if(orig->adj == NULL)
 {
     orig->adj = temp;
     return;
 }

    struct edge* temp2 = orig->adj;
    while(temp2->link!=NULL)
        temp2 = temp2->link;
    temp2->link = temp;

}
void display()
{
    struct node* temp = start;
    struct edge* q;
    while(temp!=NULL)
    {
        printf("\n%c",temp->data);
        q = temp->adj;
        while(q!=NULL)
        {
            printf("--%c",q->dest);
            q = q->link;
        }
        temp = temp->next;
    }

}
struct node* find( char node )
{
    struct node* temp = start , *loc;
    while( temp!=NULL)
    {
        if(temp->data==node)
            {
            loc = temp;
            return loc;
            }
            else
            temp = temp->next;
    }
    loc = NULL;
    return loc;
}
void delete_node(char node)
{
    struct node* temp,*q;
    if(start->data == node)
    {
        temp = start;
        start = start->next;
        temp->adj = NULL;
        free(temp);
        return;
    }
    temp = start;
    while(temp->next->next!=NULL)
    {
        if(temp->next->data == node)
        {
            q = temp->next;
            temp->next = q->next;
            q->adj = NULL;
            free(q);
            return;
        }
        temp = temp->next;
    }
    if(temp->next->data == node)
    {
        q = temp->next;
        temp->next = NULL;
        q->adj=NULL;
        free(q);
        return;
    }
}
void delnode_edge( char node )
{
    struct node* temp = start;
    struct edge* q,*r;
    int i =0;
    while(temp!=NULL){
    if(temp->adj->dest==node)
    {
        r = temp->adj;
        temp->adj = r->link;
        free(r);
        continue;
    }
    q = temp->adj;
        while(q->link->link!=NULL)
        {
            if(q->link->dest==node)
            {
                r = q->link;
                q->link = r->link;
                free(r);
                continue;
            }
                q = q->link;
        }
        if(q->link->dest==node)
        {
            r = q->link;
            free(r);
            q->link=NULL;
        }
    temp = temp->next;
    printf("--%d",i++);
}
return;
}

void delete_edge( char origin , char destination)
{
    struct node* temp = start;
    struct edge* q,*r;
    while((temp->data!=origin)&&(temp!=NULL))
    {
        temp = temp->next;
    }
    if(temp==NULL){
        printf("\n____Deletion Failed: No origin node exists...");
        return;
    }
    if(temp->adj->dest==destination)
    {
        q = temp->adj;
        temp->adj = temp->adj->link;
        free(q);
        return;
    }
    q = temp->adj;
    while(q->link->link!=NULL)
    {
        if(q->link->dest==destination)
        {
            r = q->link;
            q->link = r->link;
            free(r);
            return;
        }
        q = q->link;
    }
    if(q->link->dest==destination)
    {
        r = q->link;
        q->link=NULL;
        free(r);
        return;
    }
        printf("\n______Error : No destination node found......");
}
