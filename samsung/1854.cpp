#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

const int V_SIZE = 1e3 + 1;

int n, m, k;
vector<pii> map[V_SIZE];
priority_queue<int> dist[V_SIZE];
priority_queue<pii> pq;

int main() {
    
    scanf("%d %d %d", &n, &m, &k);

    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        map[a].push_back({c, b});  // (cost, dest)
    }

    pq.push({0, 1});
    dist[1].push(0);

    while (!pq.empty()) {
        int comecost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < map[cur].size(); i++) {
            int nextcost = comecost + map[cur][i].first;
            int next = map[cur][i].second;

            if (dist[next].size() < k || dist[next].top() > nextcost) {
                if (dist[next].size() == k) dist[next].pop();
                dist[next].push(nextcost);
                pq.push({-nextcost, next});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i].size() < k)
            printf("-1\n");
        else {
            printf("%d\n", dist[i].top());
        }
    }

    return 0;
}