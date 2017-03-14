#include<stdio.h>
#define MAX 100
void path_matrix(int adj[MAX][MAX] , int path[MAX][MAX]);
void to_boolean(int w_adj[MAX][MAX],int adj[MAX][MAX]);
void display(int adj[MAX][MAX]);
int n;
int main()
{
    int w_adj[MAX][MAX],adj[MAX][MAX] , i , j , path[MAX][MAX];
    printf("Enter number of vertices : ");
    scanf("%d",&n);
     printf("\nEnter Weighted adjacency matrix : ");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            scanf("%d",&w_adj[i][j]);
    }
    printf("\nWeighted Adjacency matrix is : \n");
    display(w_adj);
    to_boolean(w_adj,adj);
    printf("\nAdjacency matrix is : \n");
    display(adj);
    path_matrix(adj,path);
    printf("\nPath Matrix : \n");
    display(path);
    return 0;
}
void to_boolean(int w_adj[MAX][MAX],int adj[MAX][MAX])
{
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        {
            if(w_adj[i][j]!=0)
                adj[i][j]=1;
            else
                adj[i][j]=0;
        }
    }
}
void display(int adj[MAX][MAX]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        printf("%d ",adj[i][j]);
        printf("\n");
    }
}
void path_matrix(int adj[MAX][MAX],int path[MAX][MAX])
{
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        path[i][j]=adj[i][j];
    for(k=0;k<n;k++)
    {
        printf("\nFor P%d = \n",k);
        display(path);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            path[i][j]=((path[i][j])||((path[i][k])&&(path[k][j])));
    }
}
