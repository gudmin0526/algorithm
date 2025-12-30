#if 1
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef struct st {
    ll cost;
    int cur, k;

    bool operator<(const st & other) const {
        return cost > other.cost;
    }
} Path;

const ll INF = 1e18;

int N, M, K;
vector<vector<pii>> adj;
vector<vector<ll>> dist;

void input() {
    cin >> N >> M >> K;

    adj.assign(N+1, vector<pii>());

    for (int i = 0; i < M; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({ cost, v });
        adj[v].push_back({ cost, u });
    }
}

void dijkstra() {
    dist.assign(K+1, vector<ll>(N+1, INF));
    
    priority_queue<Path> pq;
    pq.push({ 0, 1, 0 }); // (cost, cur, k)
    dist[0][1] = 0;

    while (!pq.empty()) {
        Path p = pq.top();
        pq.pop();

        // stale-skip
        if (p.cost > dist[p.k][p.cur])
            continue;
        
        for (int i = 0; i < adj[p.cur].size(); i++) {
            int cost = adj[p.cur][i].first;
            int next = adj[p.cur][i].second;

            // 이전 노드로 바로 돌아가는 경우
            if (next == p.cur)
                continue;

            // 해당 도로를 포장하지 않는 경우
            if (dist[p.k][next] > p.cost + cost) {
                dist[p.k][next] = p.cost + cost;
                pq.push({ dist[p.k][next], next, p.k });
            }

            // 해당 도로를 포장하는 경우
            if (p.k < K && dist[p.k+1][next] > p.cost) {
                dist[p.k+1][next] = p.cost;
                pq.push({ dist[p.k+1][next], next, p.k+1 });
            }
        }
    }
}

void solution() {
    dijkstra();

    ll min_val = INF;
    for (int i = 0; i <= K; i++)
        min_val = min(min_val, dist[i][N]);
    cout << min_val << "\n";
    
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    input();
    solution();

    return 0;
}
#endif