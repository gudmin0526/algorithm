#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> heights;
int P, T, answer;

void input() {
	answer = 0;
	for (int i = 0; i < 20; i++) {
		cin >> heights[i];
	}
}

int findLowerBound(int x) {
	for (int i = 0; i < 20; i++) {
		if (heights[i] > x)
			return i;
	}
}

void shiftRight(int st, int ed) {
	for (int i = ed; i >= st; i--) {
		heights[i+1] = heights[i];
		answer++;
	}
}

void solution() {
	// 1. 줄세우기
	for (int i = 1; i < 20; i++) {
		// 1-1. 키가 큰 학생이 없을 때
	
		// 1-2. 키가 큰 학생이 있을 때
		if (heights[i-1] > heights[i]) {
			int lbi = findLowerBound(heights[i]);
			int x = heights[i];
			shiftRight(lbi, i-1);
			heights[lbi] = x;

		}
	}
}

int main() {
	cin >> P;
	heights.assign(20, 0);
	for (int tc = 1; tc <= P; tc++) {
		cin >> T;
		input();
		solution();
		cout << T << ' ' << answer << '\n';
	}
	return 0;
}

/*
아이디어:
앞부터 볼 때 지나온 곳은 이미 정렬되어 있으므로 다 하나씩 밀어야함
즉 큰 것 중에 가장 작은 것을 찾아야함
찾고, 밀고 하는 건 O(N^2) 20개니깐 가능

출력:
학생들이 뒤로 물러난 걸음 수의 총합

제약조건:
1. 줄세우기 규칙
 1-1. 자기 앞에 자기보다 키가 큰 학생이 없다면 그 자리에 서고 차례 끝
 1-2. 키가 큰 학생이 한 명 이상 있다면 그중 가장 앞에 있는 학생의 바로 앞(밀어내기)
2. 예외
 2-1. 같은 키를 가진 학생은 없다.
*/