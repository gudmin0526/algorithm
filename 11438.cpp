#if 1
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

typedef pair<int, int> pii;

const int SIZE = 1e5 + 5;

int N, M;
vector<vector<int>> map(SIZE);
int par[18][SIZE];
pii query[SIZE];
int depth[SIZE];

void swap(int & x, int & y);

void init() {
    N = M = 0;
    for (int i = 0; i < SIZE; i++) {
        map[i].clear();
        query[i] = {0, 0};
        depth[i] = 0;
    }
    for (int k = 0; k <= 17; k++) {
        for (int v = 0; v < SIZE; v++)
            par[k][v] = 0;
    }
}

void input() {
	int u, v;

    scanf("%d", &N);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d %d", &u, &v);
		map[u].push_back(v);
		map[v].push_back(u);
	}

    scanf("%d", &M);
    for (int i = 1; i <= M; i++) {
        scanf("%d %d", &u, &v);
        query[i] = { u, v };
    }
}

void initTable() {
    vector<bool> visited(N + 1, false);
    deque<int> dq;

    visited[1] = true;
    dq.push_back(1);

    while (!dq.empty()) {
        int x = dq.front();
        dq.pop_front();

        for (int i = 0; i < map[x].size(); i++) {
            int child = map[x][i];

            if (visited[child]) // 양방향이기 때문에 중복 방문 방지
                continue;

            depth[child] = depth[x] + 1;
            visited[child] = true;
            par[0][child] = x; // child의 바로 위에 있는 것은 parent

            for (int k = 1; k <= 17; k++) {
                par[k][child] = par[k-1][par[k-1][child]];

                if (par[k][child] == 0)
                    break;
            }
            dq.push_back(child);
        }
    }
}

int getLCA(int x, int y) {
	if (depth[x] < depth[y]) // 무조건 x가 더 높은 depth를 갖게끔
		swap(x, y);
	for (int i = 17; i >= 0; i--) {
		if ((depth[x] - depth[y]) & (1 << i)) // 큰 step부터 이동하면서 좁혀나감
			x = par[i][x]; // 최종적으로 둘의 depth가 갖아지게끔
	}

	if (x == y) // 둘의 depth를 갖게 했더니 LCA인 경우
		return x;

	for (int i = 17; i >= 0; i--) { // 마찬가지로 큰 step부터 살펴보면서 범위를 좁혀나감
		if (par[i][x] != par[i][y]) {
			x = par[i][x];
			y = par[i][y];
		}
	}
	return par[0][x]; // 결국 LCA의 바로 아래까지 도달
}

void solution() {
    for (int i = 1; i <= M; i++)
        printf("%d\n", getLCA(query[i].first, query[i].second));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

    init();
    input();
    initTable();
    solution();

	return 0;
}
#endif

void swap(int & x, int & y) {
	int temp = x;
	x = y;
	y = temp;
}