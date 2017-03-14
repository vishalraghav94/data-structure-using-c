#include<stdio.h>
#define MAX 100
int matrix[MAX][MAX];
int elements;
void create_graph();
void insert_node();
void insert_edge(int origin , int destination);
void delete_node(int data);
void delete_edge(int origin , int destination);
void display();
int main(){
    int choice;
    int origin , destination , data;
    create_graph();
    while(1){
    printf("\n1.Insert Node\n2.Insert Edge\n3.Delete Node\n4.Delete Edge\n5.Display\n6.Exit\nEnter Your Choice : ");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        insert_node();
        break;
    case 2:
        printf("\nEnter Edge : ");
        scanf("%d %d",&origin,&destination);
        insert_edge(origin,destination);
        break;
    case 3:
        printf("\nEnter node to be deleted : ");
        scanf("%d",&data);
        delete_node(data);
        break;
    case 4:
        printf("\nEnter edge to be deleted : ");
        scanf("%d %d",&origin,&destination);
        delete_edge(origin,destination);
        break;
    case 5:
        display();
        break;
    default:
        return 0;
    }
    }
}
void create_graph()
{
    int i , max_edges,origin ,destination;
    printf("\nEnter no. of nodes : ");
    scanf("%d",&elements);
    max_edges = elements*(elements-1);
    for(i=0;i<max_edges;i++)
    {
        printf("\nEnter edge %d :(-1 -1 to quit): ",(i+1));
        scanf("%d %d",&origin,&destination);
        if((origin==(-1))||(destination==(-1)))
            return;
        if((origin>=elements)||(destination>=elements)||(origin<0)||(destination<0))
        {
            printf("\nInvalid Edge");
            i--;
        }
        else
        matrix[origin][destination] = 1;
    }
}
void insert_node()
{
   elements++;
   int i , j;
   for(i=0;i<elements;i++)
   {
       matrix[i][elements-1] = 0;
       matrix[elements-1][i] = 0;
   }
}
void insert_edge(int origin , int destination)
{
    if(origin>=elements)
        printf("\nSource node not found...");
    else if(destination>=elements)
        printf("\nDestination node not found...");
        else
        matrix[origin][destination] = 1;
return;
}
void delete_node(int data)
{
    if(data==(elements-1))
    {
        elements--;
        return;
    }
    int i,j;
    for(i=data;i<(elements-1);i++)
    {
        for(j=0;j<=elements;j++){
        matrix[j][i]= matrix[j][i+1];
        matrix[i][j]= matrix[i+1][j];
        }
    }
    elements--;

}
void delete_edge(int origin , int destination)
{
    if((origin>elements)||(destination>elements)||(matrix[origin][destination]==0))
    {
        printf("\n____|Edge Doesn't Exist|_____");
        return;
    }
    matrix[origin][destination] = 0;
}
void display()
{
    int i,j;
    for(i=0;i<elements;i++)
    {
        for(j=0;j<elements;j++)
            printf("%d  ",matrix[i][j]);
        printf("\n\n");
    }
    return;
}
