#if 1
#include <cstdio>

using namespace std;

int N, M;

int map[101][101];
int dist[101];

int main() {
    scanf("%d %d", &N, &M);
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            map[i][j] = 1e9;
        map[i][i] = 0;
    }

    int u, v;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        map[u][v] = 1;
        map[v][u] = 1;
    }

    for (int m = 1; m <= N; m++) {
        for (int s = 1; s <= N; s++) {
            for (int e = 1; e <= N; e++) {
                if (map[s][e] > map[s][m] + map[m][e])
                    map[s][e] = map[s][m] + map[m][e];
            }
        }
    }

    int min_dist = 1e9;
    int min_user = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j<= N; j++) 
            dist[i] += map[i][j];
        if (min_dist > dist[i]) {
            min_dist = dist[i]; 
            min_user = i;
        }
    }

    printf("%d\n", min_user);

    return 0;
}
#endif