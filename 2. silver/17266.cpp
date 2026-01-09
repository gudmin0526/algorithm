#include <iostream>
#include <cstdlib>
#define true 1
#define false 0
#define MAX_LIGHTS 100'000u

int N, M;
int light_positions[MAX_LIGHTS + 5];

int test(int height) {
    int rightmost = 0;
    for (int i = 0; i < M; i++) {
        if (height < light_positions[i] - rightmost)
            return false;
        rightmost = light_positions[i] + height;
    }
    if (height < N - light_positions[M-1])
        return false;
    
    return true;
}

void bSearch(int st, int ed, int* out) {
    if (st > ed)
        return;
    
    int mid = (st + ed) / 2;
    if (test(mid) == true) {
        *out = mid;   
        bSearch(st, mid-1, out);
    }  else {
        bSearch(mid+1, ed, out);
    }
}

void input() {
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) 
        scanf("%d", &light_positions[i]);
}

void solve() {
    int answer = 0;
    bSearch(1, N, &answer);
    printf("%d", answer);
}

int main() {
	// 코드 작성
    input();
    solve();
	return 0;
}

/*
아이디어:
완탐으로 하면 1e5 * 1e5 = 1e10이므로 불가능
이진탐색하면서 이전 가로등이 오른쪽 비추는 범위를 계속 보면서 
둘 차이가 자연수면 안되는 거니까 넓이를 늘리고 하는 걸 하면 된다.
O(Mlog1e5)

입력:
N(굴다리 길이) ~ [1, 1e5]
M(가로등 개수) ~ [1, N]
x(가로등 위치) ~ [0, N]

출력:
굴다리 N을 모두 비추기 위한 가로등의 최소 높이

제약조건:
1. 가로등 설치
  1-1. 가로등의 높이는 모두 같아야 한다.
  1-2. 가로등 높이가 H라면 양쪽으로 H만큼 비춘다.

2. 예외
  2-1. 가로등 위치는 오름차순
  2-2. 가로등 위치는 중복 X
*/