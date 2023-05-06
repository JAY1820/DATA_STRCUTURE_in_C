
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

#define MAX_NODES 100

int main() {
    
    FILE *fp;
    fp = fopen("tgraph.txt", "r");
    fscanf(fp, "%d %d", &isDirected, &isWeighted);
    fscanf(fp, "%d %d", &n, &m);
    if (isDirected && !isWeighted) {
        generateAdjMatrix(fp);
    }else {
        generateAdjList(fp);
    }
    fclose(fp);

    fp = fopen("fgraph.txt", "r");
    fscanf(fp, "%d %d", &isDirected, &isWeighted);
    fscanf(fp, "%d %d", &n, &m);

    if (isDirected && !isWeighted) {
        generateAdjMatrix(fp);
    } else {
        generateAdjList(fp);
    }
    
    fclose(fp);

    printf("\nDFS: ");
    int visited[MAX_NODES] = {0};
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, visited);
        }
    }

    printf("\nBFS: ");
    bfs(0);
    printf("\n");
    
    return 0;
}
