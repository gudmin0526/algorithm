#if 1
#include <iostream>
#include <vector>
#include <deque>

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

const int ceilLog2N = 16;
const int INF = 1e9;

int N, M;
vector<vector<pii>> adj;
vector<vector<int>> par;
vector<vector<int>> dist;
vector<int> depth;
vector<pii> query;

void input() {
    cin >> N;
    adj.assign(N+1, {});
    par.assign(ceilLog2N+1, vector<int>(N+1, 0));
    dist.assign(ceilLog2N+1, vector<int>(N+1, 0));
    depth.assign(N+1, 0);
    for (int i = 1; i <= N-1; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({ cost, v });
        adj[v].push_back({ cost, u });
    }

    cin >> M;
    query.resize(M);   
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        query[i] = { u, v }; 
    }
}

void initTable() {
    deque<int> dq;
    dq.push_back(1);
    depth[1] = 1;
    
    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i].second;
            int cost = adj[cur][i].first;
            
            if (par[0][cur] == next)
                continue;

            par[0][next] = cur;
            dist[0][next] = cost;
            depth[next] = depth[cur] + 1;

            for (int i = 1; i <= ceilLog2N; i++) {
                par[i][next] = par[i-1][par[i-1][next]];
                
                if (par[i][next] == 0)
                    break;

                // 부모에서 부모의 부모로 가는 비용 + 부모로 가는 비용
                dist[i][next] = dist[i-1][par[i-1][next]] + dist[i-1][next];
            }
            dq.push_back(next);
        }
    }
}

int getDist(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);

    int acc_dist = 0;
    for (int i = ceilLog2N; i >= 0; i--) {
        if ((depth[u] - depth[v]) & (1 << i)) {
            acc_dist += dist[i][u];
            u = par[i][u];
        }
    }

    if (u == v) 
        return acc_dist;

    for (int i = ceilLog2N; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            acc_dist += dist[i][u];
            acc_dist += dist[i][v];
            u = par[i][u];
            v = par[i][v];
        }
    }

    return acc_dist + dist[0][u] + dist[0][v];
}

void solution() {
    initTable();
    for (int i = 0; i < M; i++) {
        cout << getDist(query[i].first, query[i].second) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif    
    
    input();
    solution();

    return 0;
}
#endif