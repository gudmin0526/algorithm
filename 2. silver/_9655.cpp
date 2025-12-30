#include <iostream>
#include <vector>
#define L false
#define W true

using namespace std;
vector<bool> dp;
int N;

int main() {
	cin >> N;
	dp.assign(N+1, L);

	// 0. base - 돌이 0개면 짐
	dp[0] = L;
	for (int i = 1; i <= N; i++) {
		// 1. 일단 지는 상태라고 가정
		dp[i] = L;

		// 2. 상대를 지게 만들 수 있는 경우가 하나라도 있으면 W
		if ((i - 1 >= 0 && dp[i - 1] == L) ||
			(i - 3 >= 0 && dp[i - 3] == L)) {
			dp[i] = W;
		}
	}
	if (dp[N] == W)
		cout << "SK";
	else
		cout << "CY";

	return 0;
}

/*
아이디어:
두 사람이 완벽하게 게임한다는 가정
상대를 반드시 지게 만들 수 있는지에 대한 것
못 움직이는 상태부터 조건을 쌓는다

dp[i]에서 dp[i-m]들을 본다는 것에서
i-m의 상대가 W이면 그 위치에서 상대는 무조건 이길 수 있다는 거임
그래서 모든 m에 대해서 dp[i-m]이 W라면 나는 i에선 무조건 진다는 거지

state - 
남은 돌 개수 n
action - 
n -> n-1
n -> n-3
base - 
n = 0 -> L

제약조건:
1. 게임 규칙
 1-1. 상근과 청명은 턴을 번갈아가며 돌을 가져간다.
 1-2. 돌은 1개 또는 3개 가져갈 수 있다.
 1-3. 마지막 돌을 가져가는 사람이 게임을 이긴다.
 1-4. 게임은 상근이가 먼저 시작한다.

유형:
DP, 게임이론
 */