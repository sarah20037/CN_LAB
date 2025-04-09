#include <stdio.h>

#define INFINITY 9999
#define N 4  // Number of routers

int cost[N][N], dist[N][N], hop[N][N];

int main() {
    // Input cost matrix
    printf("Enter the cost matrix (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &cost[i][j]);
            dist[i][j] = cost[i][j];
            hop[i][j] = j;
        }
    }

    // Distance Vector Algorithm
    int changed = 1;
    while (changed) {
        changed = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        hop[i][j] = hop[i][k];
                        changed = 1;
                    }
                }
            }
        }
    }

    // Display final distance matrix
    printf("\nDistance Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", dist[i][j]);
        }
        printf("\n");
    }

    // Display next hop matrix
    printf("\nNext Hop Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", hop[i][j] + 1);  // +1 to show router number starting from 1
        }
        printf("\n");
    }

    return 0;
}
