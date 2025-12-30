#include <iostream>
#include <cstdlib>
using namespace std;
typedef long long ll;

#define SIZE (51)
#define MAX (2e9)

ll answer;
ll N, T, P;
ll scores[SIZE];

int cmp(const void *a, const void *b) {
    const ll *va = (ll *)a;
	const ll *vb = (ll *)b;

	return *va < *vb;
}

void input() {
	scanf("%llu %llu %llu", &N, &T, &P);
	for (ll i = 0; i < N; i++) 
		scanf("%llu", &scores[i]);
}

ll solution() {
	if (N == 0) return 1;

	qsort(scores, N, sizeof(ll), cmp);

	ll i, tie_cnt, rank;
	i = 0; tie_cnt = 1; rank = 1;

	while ((i+1) < N) {
		while ((i+1) < N && scores[i] == scores[i+1]) {
			tie_cnt++;
			i++;
		}

		if ((i+1) == N) {
			if (T > scores[i])
				return rank;
			if ((i+1) < P)
				return (T == scores[i]) ? rank : rank + tie_cnt;
			else
				return -1;
		}
		
		if (T >= scores[i])
			return rank;

		rank += tie_cnt;
		tie_cnt = 1;
		i++;
	}

	if (T > scores[i])
		return rank;
	if ((i+1) < P)
		return (T == scores[i]) ? rank : rank + tie_cnt;
	else
		return -1;
		
}


int main() {
	input();
	answer = solution();
	printf("%lld", answer);
	return 0;
}

/*
입력:
N(점수 개수) ~ [0, P]
P(등재 가능한 점수 개수) ~ [10, 50]
(각 점수) ~ [0, 2e9]

출력:
태수의 점수가 랭킹 리스트에서 몇 등인지 구해라.
점수가 랭킹 리스트에 올라갈 수 없다면 -1

제약조건:
1. 등수 결정
 1-1. 등수는 위에서부터 몇 번째 있는 점수인지로 결정한다.
 1-2. 같은 점수가 있을 때는 그러한 점수의 등수 중 가장 작은 등수가 된다.
2. 예외
 2-1. 랭킹 리스트가 꽉 차있으면, 새 점수가 이전 점수보다 좋을 때만 바뀐다.
 2-2. 랭킹 리스트에 올라갈 수 없을 정도라면 -1 출력한다.
*/