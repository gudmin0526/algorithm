#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX_DAY 250000

int daily_visitors_count[MAX_DAY + 5];
int X, N;

void input() {
    scanf("%d %d", &N, &X);
    for (int i = 0; i < N; i++)
        scanf("%d", &daily_visitors_count[i]);
}

void solution() {
    int acc = 0;
    int max_visitors = 0;
    int max_visitors_count = 0;

    int i = 0;
    int j = X;

    for (int k = i; k < j; k++)
        acc += daily_visitors_count[k];
    max_visitors = acc;
    max_visitors_count = 1;

    while (1) {
        if ((j - i) > X)
            acc -= daily_visitors_count[i++];
        else if (j >= N)
            break;
        else 
            acc += daily_visitors_count[j++];
        
        if ((j - i) == X) {
            if (max_visitors == acc) {
                max_visitors_count++;
            } else if (max_visitors < acc) {
                max_visitors = acc;
                max_visitors_count = 1;
           }
        }
    }
    if (max_visitors == 0) printf("SAD");
    else                   printf("%d\n%d", max_visitors, max_visitors_count);
}

int main() {
	// 코드 작성
    input();
    solution();
	return 0;
}

/*
아이디어:
간단히 생각하면 부분합 문제의 쉬운 버전
 */