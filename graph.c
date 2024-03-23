#include <stdio.h>
int visit[20];
int v,i,j,f=-1,r=-1,que[20],G[20][20];
void DFS(int s);
void BFS(int s);
void addque(int s);
int deleteque();
void main() {
    int E, e1, e2,source;
    printf("Enter number of vertices");
    scanf("%d", &v);
    for (i = 1; i <= v; i++) {
        for (j = 1; j <= v; j++) {
            G[i][j] = 0;
        }
    }
    printf("Enter number of edges");
    scanf("%d", &E);
    for (i = 1; i <= E; i++) {
        printf("Enter Edge");
        scanf("%d%d", &e1, &e2);

        G[e1][e2] = 1;
        G[e2][e1] = 1;
    }
    printf("Graph in Adjacency Matrix Form\n");
    for (i = 1; i <= v; i++) {
        for (j = 1; j <= v; j++) {
            printf("%d  ", G[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=v;i++)
    {
        visit[i]=0;
    }
    printf("Enter a Source");
    scanf("%d",&source);
    printf("DFS TRAVERSAL");
    DFS(source);
    for(i=1;i<=v;i++)
    {
        visit[i]=0;
    }
    printf("BFS TRAVERSAL");
    BFS(source);
}
void DFS(int s)
{   visit[s]=1;
    printf("%d->",s);
    for(i=1;i<=v;i++)
    {
        if(G[s][i]==1 && visit[i]==0)
        {
            DFS(i);
        }
    }
}
void BFS(int s) {
    visit[s] = 1;
    printf("%d->", s);
    addque(s);
    while (f != -1) {
        s = deleteque();
        for (i = 1; i <= v; i++) {
            if (G[s][i] == 1 && visit[i] == 0) {
                printf("%d->", i);
                visit[i] = 1;
                addque(i);
            }
        }
    }
    printf("\n");
}
void addque(int s)
{
    if(f==-1 && r==-1)
    {
        f=0;
        r=0;
        que[r]=s;
    }
    else
    {
        r+=1;
        que[r]=s;
    }}
int deleteque() {
    int data;
    if (f == -1) {
        printf("Que Empty");
        return -1;
    } else if (f == r) {
        data = que[f];
        f = r = -1;
        return data;
    } else {
        data = que[f];
        f = f + 1;
        return data;
    }
}