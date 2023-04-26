#include <stdio.h>

#define MAX_NODES 50

int cost[MAX_NODES][MAX_NODES];
int near[MAX_NODES];
int n,u,v;

void Prim() {
    int total = 0;

    printf("The Minimal Spanning Tree Is:\n");

    near[0] = 1;

    for (int k = 1; k < n; k++)
    {
        int min_cost = MAX_NODES;
        u = -1, v = -1;
        
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (cost[i][j] && ((near[i] && !near[j]) || (!near[i] && near[j])))
                {
                    if (cost[i][j] < min_cost)
                    {
                        min_cost = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        near[u] = near[v] = 1;
        printf("Edge (%d,%d) with weight %d\n", u, v, min_cost);
        total += min_cost;
    }

    printf("Total path length is %d\n", total);
}


int main()
{
    printf("Enter the number of nodes in the graph (max %d): ", MAX_NODES);
    scanf("%d", &n);
    

    printf("Enter the cost adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &cost[i][j]);
        }
    }

    Prim();

    return 0;
}

/* 

 0  10   0  30 100
 10   0  50  20   0
 0  50   0  40  10
 30  20  40   0  60
 100   0  10  60   0

*/
