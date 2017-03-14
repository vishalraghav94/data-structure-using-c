#include<stdio.h>
#define MAX 100
void breadth_order(int start_node);
void enqueue(int node);
void dequeue();
int queue[MAX];
int status[MAX];
int start = -1,end = -1;
int adj[MAX][MAX];
int n;
int main()
{
    int i , j , k,start_node;
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        status[i]=0;
    printf("Enter the Adjacency matrix : ");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&adj[i][j]);
        while(1){
                start=-1;
                end =-1;
        for(i=0;i<n;i++)
        status[i]=0;
    printf("\nEnter the starting node (-1 to quit) : ");
    scanf("%d",&start_node);
    if(start_node==-1)
        break;
    breadth_order(start_node-1);
        }
    return 0;
}
void breadth_order(int start_node)
{
    int temp,j;
    enqueue(start_node);
    while(start<=end)
    {
        temp=queue[start];
        printf("%d-->",(temp+1));
        for(j=0;j<n;j++)
        {
            if((adj[temp][j]==1)&&(status[j]==0)){
                enqueue(j);
                status[j]=1;
            }
        }
        dequeue();
    }
}
void enqueue(int node)
{
    if(start==-1)
        start=0;
    queue[++end]=node;
}
void dequeue()
{
    if(end==-1)
    {
        printf("\nQueue underflown");
        return;
    }
    start++;
}
