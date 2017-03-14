#include<stdio.h>
#define MAX 100
#define infinity 9999
#define temp 0
#define perm 1
struct node{
    int dist;
    int pred ;
    int status;
};
struct node state[MAX];
int n;
int w_adj[MAX][MAX];
void dijkstra(int origin , int dest);
int distance( int origin , int destination);
int findmin();
int main()
{
    int i , j , origin , dest;
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        state[i].dist = infinity;
        state[i].pred = 0;
        state[i].status = temp;
    }
    printf("\nEnter weighted adjacency matrix : ");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&w_adj[i][j]);
    printf("\nEnter origin and destination node : ");
    scanf("%d %d",&origin , &dest);
    dijkstra(origin , dest);
    return 0;
}
void dijkstra(int origin , int dest)
{
    int start = origin,path=0;
    state[start].dist = 0;
    int i,j=0;
    while((state[dest].status)!=perm)
    {
        state[start].status = perm;
         printf("\nstatus %d : %d",start,state[start].status);
        for(i=0;i<n;i++)
        {
            if(start!=i){
            printf("\ndistance : %d",state[i].dist);
            if((w_adj[start][i]!=0)&&(state[i].status==temp))
            {
                if((state[i].dist)>=((state[start].dist)+distance(start,i)))
                {

                    state[i].dist = (state[start].dist)+distance(start,i);
                    printf("\ndistance inside(%d + %d,%d): %d",start,start,i,state[i].dist);
                    state[i].pred = start;
                }
            }
        }
        }
        start = findmin();
        printf("\nStart : %d",start);
    }
    j = dest;
    printf("\n");
    while(state[j].pred!=origin)
    {
        path = path+distance((state[j].pred),j);
        printf("%d<--",j);
        j=state[j].pred;
    }
    printf("%d<--%d",j,origin);
    path = path + distance(origin,j);
    printf("\nShortest Distance between %d to %d : %d",origin , dest , path);
    printf("\n");
    for(j=0;j<n;j++)
        printf("\nDist %d : %d pred %d : %d Status %d : %d",j,state[j].dist,j,state[j].pred,j,state[j].status);
}
int distance(int origin , int destination)
{
    return w_adj[origin][destination];
}
int findmin()
{
    int min,i;
    min = 99;
    state[min].dist = infinity;
    for(i=0;i<n;i++){
    if((state[i].status)==temp)
        if((state[i].dist)<(state[min].dist))
            min = i;
    }
    return min;
}
