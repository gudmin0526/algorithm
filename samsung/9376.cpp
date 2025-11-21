#if 1
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <unordered_map>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef struct st {
    int cost, x, y;
    bool operator<(const st & other) const {
        return cost > other.cost;
    }
} Node;

const int INF = 1e8;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int H, W;
vector<vector<char>> jail;
vector<vector<vector<int>>> dist;
vector<Node> prisoner;

bool isOutOfBound(int x, int y) {
    return x < 0 || y < 0 || x > W+1 || y > H+1;
}

void input() {
    cin >> H >> W;

    jail.assign(H+2, vector<char>(W+2));
    prisoner.clear();

    prisoner.push_back({ 0, 0, 0 });

    for (int y = 0; y <= H + 1; y++) {
        for (int x = 0; x <= W + 1; x++) {
            if (y == 0 || x == 0 || y == H + 1 || x == W + 1) {
                jail[y][x] = '.';
                continue;
            }

            cin >> jail[y][x];
            
            if (jail[y][x] == '*')
                continue;

            if (jail[y][x] == '$')
                prisoner.push_back({ 0, x, y });
        }
    }
}

void dijkstra(Node node, int idx) {    

    vector<vector<int>> prev(H+2, vector<int>(W+2, -1));
    priority_queue<Node> pq;
    pq.push(node);
    dist[idx][node.y][node.x] = 0;

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.cost > dist[idx][cur.y][cur.x])
            continue;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (isOutOfBound(nx, ny) || jail[ny][nx] == '*')
                continue;

            if (prev[cur.y][cur.x] == ny * (W+2) + nx)
                continue;

            prev[ny][nx] = cur.y * (W+2) + cur.x;

            int cost = (jail[ny][nx] == '#') ? 1 : 0;

            if (dist[idx][ny][nx] > cur.cost + cost) {
                dist[idx][ny][nx] = cur.cost + cost;
                pq.push({ cur.cost + cost, nx, ny });
            }
        }
    }
}

void solution() {

    dist.assign(3, vector<vector<int>>(H+2, vector<int>(W+2, INF)));
    
    // 3명이 한 지점에서 만난다.
    for (int i = 0; i < 3; i++)
        dijkstra(prisoner[i], i);

    int ret = INF;
    for (int y = 1; y <= H; y++) {
        for (int x = 1; x <= W; x++) {
            int acc = 0;
            for (int k = 0; k < 3; k++)
                acc += dist[k][y][x];
            
            if (jail[y][x] == '*')
                continue;
            
            if (jail[y][x] == '#')
                acc -= 2;
            
            ret = min(ret, acc);
        }
    }
    cout << ret << "\n";
}

int main() {
    ios_base::sync_with_stdio(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        input();
        solution();
    }

    return 0;
}
#endif