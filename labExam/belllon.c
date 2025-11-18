#include <stdio.h>
#include <time.h>
#define INF 999999

int main() {
    int n, e;
    scanf("%d", &n);
    scanf("%d", &e);

    int u[100], v[100], w[100];

    for(int i = 0; i < e; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }

    int src;
    scanf("%d", &src);

    int dist[100];

    for(int i = 0; i < n; i++)
        dist[i] = INF;
    dist[src] = 0;

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    for(int i = 1; i <= n - 1; i++) {
        for(int j = 0; j < e; j++) {
            if(dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]]) {
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }

    for(int j = 0; j < e; j++) {
        if(dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]]) {
            printf("Negative cycle detected\n");
            end = clock();
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
           
            printf("%f\n", cpu_time_used);
            return 0;
        }
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    for(int i = 0; i < n; i++) {
        if(dist[i] == INF)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }
 printf("Execution time to run it :- ");
    printf("\n%f\n", cpu_time_used);

    return 0;
}
