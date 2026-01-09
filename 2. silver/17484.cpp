#include <iostream>
#include <cstdint>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX_ROW 6
#define MAX_COL 6

typedef struct {
    int x, y;
} Pos;

int dx[3] = {-1, 0, 1};

int graph[MAX_ROW+5][MAX_COL+5];
int N, M;

void input() {
    scanf("%d %d", &N, &M);

    memset(graph, 0, sizeof(graph));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++)
            scanf("%d", &graph[y][x]);
    }
}

void dfs(Pos pos, int acc, int prev_dir, int* out) {
    acc += graph[pos.y][pos.x];
    if (pos.y >= N - 1) {
        *out = min(*out, acc);
        return;
    }

    for (int k = 0; k < 3; k++) {
        int nx = pos.x + dx[k];
        int ny = pos.y + 1;
        if (nx < 0 || nx >= M) continue;
        if (k == prev_dir) continue;
        dfs({nx, ny}, acc, k, out);
    }

}

void solution() {
    int min_fuel = 1e9+1;
    for (int x = 0; x < M; x++)
        dfs({x, 0}, 0, -1, &min_fuel);
    printf("%d", min_fuel);
}

int main() {
    input();
    solution();
    return 0;
}

/*
아이디어:
딱 봐도 DP로 푸는 문제 
-> DFS였음. 이전 방향을 기억해야 하므로 DP로 풀면 복잡해짐

출력:
달 여행에 필요한 최소 연료의 값

제약조건:
1. 우주선 특징
    1-1. 지구 -> 달로 가는 경우 (-1, 1), (0, 1), (1, 1)으로 (x, y) 이동 가능
    1-2. 우주선은 같은 방향으로 두 번 연속으로 움직일 수 없음
*/