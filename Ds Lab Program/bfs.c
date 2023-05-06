void BFS(int A[][8], int start, int n)
{
    int i = start, v;
    int visited[8] = {0};
    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);

    while (!isEmpty())
    {
        i = dequeue();

        for (v = 1; v <= n; v++)
        {
            if (A[i][v] == 1 && visited[v] == 0)
            {
                printf("%d ",v);
                visited[v] = 1;
                enqueue(v);
            }
        }
    }
}