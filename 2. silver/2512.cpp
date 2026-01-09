#include <iostream>
using namespace std;

#define true 1
#define false 0
#define MAX_ACCOUT 100000
#define MAX_PROVINCES 100000

int provinces[MAX_PROVINCES + 5];
int N, M;

int findMax(void) {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        if (ret < provinces[i])
            ret = provinces[i];
    }

    return ret;
}

int test(int threshold) {
    int account = M;
    for (int i = 0; i < N; i++) {
        if (provinces[i] < threshold)
            account -= provinces[i];
        else
            account -= threshold;
    }

    if (account >= 0)
        return true;
    else
        return false;
}

int bSearch(int st, int ed, int* out) {
    if (st > ed)
        return 0;
    
    int mid = (st + ed) / 2;
    if (test(mid) == true) {
        *out = mid;
        bSearch(mid+1, ed, out);
    } else {
        bSearch(st, mid-1, out);
    }
    return 0;
}

void input(void) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &provinces[i]);
    scanf("%d", &M);
}

void solution(void) {
    int out = 0;
    int max_request = findMax();

    bSearch(1, max_request, &out);
    printf("%d", out);
}

int main() {
	input();
    solution();
	return 0;
}

/*
아이디어:
상한액을 어떻게 계산할 것인가가 핵심
1e5를 모두 탐색하면 1e5 * 1e4 = 1e9이니까 안됨
딱봐도 이진탐색 사용하면 됨

입력:
N(지방의 수) ~ [3, 1e4]
(요청 예산) ~ [1, 1e5]
M(총 예산) ~ [N, 1e9]

출력:
배정된 예산들 중 최대값인 정수

제약조건:
1. 예산 배정
    1-1. 모든 요청이 배정될 수 있는 경우 요청한 금액 그대로 배정
    1-2. 모든 요청이 배정될 수 없는 경우 특수한 정수 상한액 계산하여 
        1-2-1. 그 이상인 요청은 모두 상한액 배정
        1-2-2. 상한액 이하인 요청에 대해서는 요청한 금액 배정
*/