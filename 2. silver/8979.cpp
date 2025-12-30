#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct medal_t {
	int idx;
	int gold, silver, bronze;
	
	medal_t(int idx, int gold, int silver, int bronze) 
		: idx(idx), gold(gold), silver(silver), bronze(bronze) {}
	
	bool operator<(const medal_t& other) const {
		if (gold == other.gold && silver == other.silver)
			return bronze > other.bronze;
		if (gold == other.gold)
			return silver > other.silver;
		return gold > other.gold;
	}
	
	bool operator==(const medal_t& other) const {
		return gold == other.gold && silver == other.silver && bronze == other.bronze;
	}
} medal_t;

vector<medal_t> medals;
vector<int> places;
int N, K;

int main() {
	cin >> N >> K;
	medals.assign(N, {0, 0, 0, 0});
	places.assign(N+1, 0);

	for (int i = 0; i < N; i++) {
		cin >> medals[i].idx >> medals[i].gold;
		cin >> medals[i].silver >> medals[i].bronze;
	}
	sort(medals.begin(), medals.end());

	int p = 1;
	int acc = 1;
	places[medals[0].idx] = 1;
	for (int i = 1; i < N; i++) {
		acc++;
		if (medals[i] == medals[i-1]) {

		} else {
			p = acc;
		}
		places[medals[i].idx] = p;
	}

	cout << places[K];

	return 0;
}

/*
아이디어:
금, 은, 동의 크기 순서대로 정렬
1. 이전의 값을 기억하면서 등수를 매김
1-1. 금, 은, 동 같으면 등수 유지, 누적 +1
1-2. 금, 은, 동 다르면 등수 갱신, 누적 +1

출력:
입력받은 국가 K의 등수

제약조건:
1. 순위 결정
 1-1. 금메달 수가 더 많은 나라
 1-2. 은메달 수가 더 많은 나라
 1-3. 동메달 수가 더 많은 나라
2. 순위 표현
 2-1. 각 국가는 1부터 N 사이의 정수
 2-2. 등수는 (자신보다 더 잘한 나라 수) + 1
 2-3. 금, 은, 동의 수가 같으면 등수가 같다.
 2-4. 공동 등수가 나오면 그 다음 스킵
*/