#include<stdio.h>
#define MAX 100
int stack[MAX] , adj[MAX][MAX],status[MAX];
int n,top=-1;
void push(int node);
void pop();
void depth_search(int start_node);
int main()
{
    int i, j,start_node;
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix : ");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&adj[i][j]);
    while(1){
        top=-1;
        for(i=0;i<n;i++)
            status[i]=0;
        printf("\nEnter the starting node(-1 to quit) : ");
        scanf("%d",&start_node);
        if(start_node==-1)
            break;
        depth_search(start_node-1);
    }
    return 0;
}
void depth_search(int start_node){
    int temp,j;
    push(start_node);
    while(top>-1)
    {
        temp=stack[top];
        pop();
        if(status[temp]==0)
        printf("%d-->",(temp+1));
        status[temp]=1;
        for(j=(n-1);j>=0;j--)
        {
            if((adj[temp][j]==1))
            {
                push(j);
            }
        }
    }
}
void push(int node)
{
    stack[++top]=node;
}
void pop()
{
    if(top==-1)
        printf("\nStack underflown");
    else
        top--;
}
