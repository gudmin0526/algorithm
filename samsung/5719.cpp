#if 1
#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

const int SIZE = 5e2 + 1;
const int INF = 1e9;

int N, M, S, D;

vector<vector<pii>> adj;

vector<int> dist;
vector<vector<int>> pred;
vector<vector<bool>> removed;

bool input() {
    cin >> N >> M;
    if (N == 0 && M == 0)
        return true;
        
    cin >> S >> D;
    adj.assign(N, {});
    removed.assign(N, vector<bool>(N, false));
    pred.assign(N, {});

    for (int i = 0; i < M; i++) {
        int U, V, P;
        cin >> U >> V >> P;
        adj[U].push_back({P, V});
    }
    return false;
}

void dijkstra() {

    dist.assign(N, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        int comecost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < adj[cur].size(); i++) {
            int cost = adj[cur][i].first;
            int next = adj[cur][i].second;

            if (removed[cur][next])
                continue;
            
            int nextcost = cost + comecost;
            if (dist[next] > nextcost) {
                dist[next] = nextcost;
                pq.push({ nextcost, next });

                // 1회차 탐색
                if (!pred.empty()) {
                    pred[next].clear();
                    pred[next].push_back(cur);
                }
            }    
            else if (!pred.empty() && dist[next] == nextcost) {
                pred[next].push_back(cur);
            }
        }
    }
}

void eraseShortestEdges() {
    vector<bool> visited(N, false);
    deque<int> dq;

    dq.push_back(D);
    visited[D] = true;

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        for (int pre : pred[cur]) {
            removed[pre][cur] = true;

            if (visited[pre])
                continue;
            
            visited[pre] = true;
            dq.push_back(pre);
        }
    }
}

void solution() {

    // 최단거리 찾기
    dijkstra();

    // 최단경로 간선 지우기
    eraseShortestEdges();
    pred.clear();

    // 거의 최단거리 찾기
    dijkstra();

    if (dist[D] == INF)
        cout << -1 << "\n";
    else
        cout << dist[D] << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    while (1) {
        if (input())
            break;
        solution();
    }

    return 0;
}
#endif