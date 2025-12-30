#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

unordered_set<string> user_set;

int N;
char game;
string s;

int main() {
	cin >> N >> game;
	for (int i = 0; i < N; i++) {
		cin >> s;
		user_set.insert(s);
	}

	switch (game) {
	case 'Y':
		cout << user_set.size();
		break;
	case 'F':
		cout << user_set.size() / 2;
		break;
	case 'O':
		cout << user_set.size() / 3;
		break;
	}

	return 0;
}

/*
아이디어:

출력:
임스가 최대 몇 번 게임 플레이할 수 있는지

제약조건:
1. 규칙
 1-1. Y, F, Q는 각각 2, 3, 4명이서 플레이하는 게임이다.
 1-2. 인원수가 부족하면 게임을 시작할 수 없다.

2. 예외
 2-1. 임스는 한 번 같이 플레이한 사람과 다시 플레이하지 않는다.
 2-2. 임스와 함께 하고자 하는 사람 중 동명이인은 없다.
*/