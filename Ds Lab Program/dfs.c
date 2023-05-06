void DFS(int A[][8], int start, int n)
{
    static int visited[] = {0};
    int v;
    int i = start;

    if (visited[i] == 0)
    {
        printf("%d ", start);
        visited[i] = 1;

        for (v = 1; v < n; v++)
        {
            if (A[i][v] == 1 && visited[v] == 0)
                DFS(A, v, n);
        }
    }
}