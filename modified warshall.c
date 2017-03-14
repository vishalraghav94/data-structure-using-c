#include<stdio.h>
#define MAX 100
#define infinity 9999
void path_matrix(int w_adj[MAX][MAX] , int path[MAX][MAX]);
void display(int adj[MAX][MAX]);
int minimum(int , int);
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
    path_matrix(w_adj,path);
    printf("\n Shortest Path Matrix : \n");
    display(path);
    return 0;
}
void display(int adj[MAX][MAX]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        printf("%d ",adj[i][j]);
        printf("\n");
    }
}
int minimum(int a, int b)
{
    if(a<=b)
        return a;
    else
        return b;
}
void path_matrix(int w_adj[MAX][MAX],int path[MAX][MAX])
{
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
                if(w_adj[i][j]==0)
                path[i][j]=infinity;
        else
        path[i][j]=w_adj[i][j];
        }
    for(k=0;k<n;k++)
    {
        printf("\nFor Q%d = \n",k);
        display(path);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            path[i][j]= minimum(path[i][j],(path[i][k]+path[k][j]));
    }
}
