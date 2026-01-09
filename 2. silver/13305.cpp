#include <iostream>
#include <cstdint>
typedef int64_t ll;

#define MAX_NODES 100'000
#define MAX_COST 1'000'000'000

ll N;
ll edge_lens[MAX_NODES + 5];
ll oil_costs[MAX_NODES + 5];

void input() {
    scanf("%lld", &N);
    for (int i = 1; i <= N-1; i++)
        scanf("%lld", &edge_lens[i]);
    for (int i = 1; i <= N; i++)
        scanf("%lld", &oil_costs[i]);    
}

void solve() {
    ll acc_cost = 0;
    ll partial_len = 0;
    ll min_cost = oil_costs[1];
    for (int i = 1; i <= N - 1; i++) {
        // 현재 도시에서 충전하는 게 더 싸면 청산 후 갱신
        if (min_cost > oil_costs[i]) {
            acc_cost += min_cost * partial_len;
            min_cost = oil_costs[i];
            partial_len = 0;
        } 
        partial_len += edge_lens[i];
    }
    acc_cost += min_cost * partial_len;

    printf("%lld", acc_cost);
}

int main() {
    setbuf(stdout, NULL);
    input();
    solve();
	return 0;
}

/*
아이디어:
도시가 1e5이므로 각 도시마다 비용을 계속 갱신하면 시간초과
복잡하게 생각할 것 없이 현재까지 온 도시 중 가장 기름이 싼 도시에서 충전하는게 최선이다.
min 비용을 기억하고 거기서부터 min 갱신될 때까지 거리 누적해서 곱하고
이 작업을 도착 노드까지 반복하면 그게 최소 비용일 것이다.

입력:
N(도시 개수) ~ [2, 1e5]
(거리) ~ [1, 1e9]
(비용) ~ [1, 1e9]

출력:
제일 왼쪽 도시에서 제일 오른쪽 도시로 가는 최소 비용

제약조건:
1. 비용

2. 예외
    2-1. 도로들은 서로 길이가 다를 수 있음
    2-2. 기름통의 크기는 무제한
    2-3. 각 도시에는 단 하나의 주유소
    2-4. 도시마다 주유소의 리터당 가격은 다를 수 있음 
*/