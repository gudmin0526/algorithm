#include <iostream>
#include <cmath>
using namespace std;

int H, W, N, M;

int main() {
	cin >> H >> W >> N >> M;
	// ceil은 float이므로 int로 캐스팅한 후 곱해줘야 정확한 값이 나온다
	cout << (int)ceil((double)H / (N+1)) * (int)ceil((double)W / (M+1));
	return 0;
}

/*
아이디어:
(1, 1)에 무조건 앉히고 시작
어차피 앉을 수 있는 곳은 정해져 있음
첫 번째 줄을 쭉 앉힌 다음 그걸 곱하기
N이 1이면 한 명이 2칸 차지한다고 생각. 근데 이제 올림을 하는
ceil(4 / (1+1)) = 2
ceil(5 / (1+1)) = 3

입력:
H, W, N, M ~ [1, 5e4]

출력:
강의실이 수용할 수 있는 최대 인원 수

제약조건:
1. 앉기 규칙
 1-1. 모든 참가자는 세로로 N칸 또는 M칸 이상 비우고 앉음
 1-2. 세로줄 번호의 차가 N보다 크거나 가로줄 번호의 차가 M보다 큰 곳
*/