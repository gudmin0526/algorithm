#include <iostream>
using namespace std;

#define MAX_SHORTCUT 12

typedef struct {
    int st_pos;
    int fn_pos;
    int len;
} Shortcut;

int N, D;
Shortcut shortcuts[MAX_SHORTCUT+5];
char shortcuts_size = 0;


void input() {
    scanf("%d %d", &N, &D);
    shortcuts_size = 0;

    int st_pos, fn_pos, len;
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", st_pos, fn_pos, len);
        if (len > (fn_pos - st_pos)) continue;
        shortcuts[shortcuts_size++] = { st_pos, fn_pos, len };
    }
}

int main() {
	// 코드 작성
	return 0;
}

/*
아이디어:
그리디??는 아닌 것 같다.
완전탐색으로 해결하는 것이 맞는듯
지름길이 최대 12개니까 
시작 위치 기준 오름차순, 도착 위치 기준 오름차순 정렬
그리고 남은 것 중 갈 수 있는 선택지가 있는지

역주행이 불가능하니까 지나치면 갱신 안하고 종료
만약 지름길의 길이가 (도착 - 시작)보다 크다면 버린다. (이건 전처리)

정리
1. 지름길 3개 값 기준 오름차순 정렬 (도착 > 출발 > 길이)
2. for + dfs로 지름길 탐색
3. 만약 지나치는 선택지만 존재한다면 break하고 남은 고속도로 길이 더하기

입력:
N(지름길의 개수) ~ [1, 12]
D(고속도로의 길이) ~ [1, 1e4]

출력:
세준이가 운전해야하는 거리의 최솟값

제약:
1. 주행 규칙
    1-1. 모든 지름길은 일방통행이다.
    1-2. 고속도로를 역주행할 수는 없다.
    1-3. 지름길의 시작 위치는 도착 위치보다 작다.
*/