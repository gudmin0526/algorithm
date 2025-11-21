#if 1
#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

typedef struct st {
    ll cost;
    int cur;
    bool operator<(const st & other) const {
        return cost > other.cost;
    }
} Node;

const ll INF = 1e18;

int N, M;
vector<vector<pii>> adj;
vector<ll> dist;
vector<vector<int>> pred;
vector<pii> removed;
vector<vector<bool>> removedAdj;

void input() {
    cin >> N >> M;
    adj.assign(N+1, {});
    dist.assign(N+1, INF);
    pred.assign(N+1, {});
    removedAdj.assign(N+1, vector<bool>(N+1, false));

    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({ z, y });
        adj[y].push_back({ z, x });
    }
}

void dijkstra() {
    priority_queue<Node> pq;
    pq.push({0, 1}); // cost, node
    dist[1] = 0;

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        // stale-skip
        if (node.cost > dist[node.cur])
            continue;

        for (int i = 0; i < adj[node.cur].size(); i++) {
            int next = adj[node.cur][i].second;
            ll cost = adj[node.cur][i].first;

            if (removedAdj[node.cur][next])
                continue;

            if (!pred[next].empty() && pred[next][0] == node.cur)
                continue;

            if (dist[next] > node.cost + cost) {
                dist[next] = node.cost + cost;
                pred[next].clear();
                pred[next].push_back(node.cur);
                pq.push({ node.cost + cost, next });
            }
        }
    }
}

void eraseEdgesFromShortestPath() {
    vector<bool> visited(N+1, false);
    deque<int> dq;
    dq.push_back(N);
    visited[N] = true;

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        for (int i = 0; i < pred[cur].size(); i++) {
            int next = pred[cur][i];
            
            if (visited[next])
                continue;

            removed.push_back({cur, next});

            dq.push_back(next);
        }
    }
}

void solution() {
    dijkstra();

    eraseEdgesFromShortestPath();

    ll answer = 0;

    for (pii edge : removed) {
        removedAdj[edge.first][edge.second] = true;
        removedAdj[edge.second][edge.first] = true;
        dist.assign(N+1, INF);
        pred.assign(N+1, {});
        dijkstra();
        removedAdj[edge.first][edge.second] = false;
        removedAdj[edge.second][edge.first] = false;

        if (answer < dist[N])
            answer = dist[N];
    }

    dijkstra();
    cout << answer << endl;
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