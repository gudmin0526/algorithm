#include <iostream>
#include <string>
using namespace std;

int N, p, kbs1, kbs2;
string ch;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ch;
		if (ch == "KBS1")
			kbs1 = i;
		if (ch == "KBS2")
			kbs2 = i;
	}
	p = 0;
	
	// 1. KBS1
	while (kbs1 != 0) {
		while (p < kbs1) {
			p++;
			cout << '1';
		}
		cout << '4';
		p--;
		kbs1--;

		if (kbs1 == kbs2)
			kbs2++;
	}
	
	// 2. KBS2
	while (kbs2 != 1) {
		while (p > kbs2) {
			p--;
			cout << '2';
		}
		while (p < kbs2) {
			p++;
			cout << '1';
		}
		cout << '4';
		p--;
		kbs2--;
	}
	
	return 0;
}

/*
아이디어:
단순하게 생각하면 KBS1으로 가서 제일 처음으로
KBS2로 가서 그 다음으로
"제일 적게"라는 조건이 있으면 골치 아프겠지만 그게 아니라서 쉬움

출력:
상근이가 눌러야 하는 버튼 순서

제약조건:
1. 기본 채널
 1-1. 리스트 왼편 작은 화살표 -> 현재 선택한 채널
 1-2. 가장 처음 화살표는 제일 첫 번째 채널을 가리키고 있음
2. 리스트 순서 바꾸기
 2-1. 화살표 한 칸 아래 (i -> i+1)
 2-2. 화살표 한 칸 위 (i -> i-1)
 2-3. 현재 선택한 채널 한 칸 아래(i <-> i+1, 화살표는 i+1)
 2-4. 현재 선택한 채널 위로 한 칸(i <-> i-1, 화살표는 i-1)
 2-5. 화살표가 범위를 넘어가면 무시 
3. 예외
 3-1. 이미 정답대로 정해진 입력은 주어지지 않음
*/