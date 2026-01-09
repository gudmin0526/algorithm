#include <iostream>
#include <cstring>
using namespace std;

#define true 1
#define false 0
#define MAX_TABLE_LENGTH 20000

char table[MAX_TABLE_LENGTH + 5];
char visited[MAX_TABLE_LENGTH + 5];
int N, K;

void input() {
    memset(visited, false, sizeof(visited));
    scanf("%d %d", &N, &K);
    scanf("%s", table);
}

void solution() {
    int eater_count = 0;
    for (int i = 0; i < N; i++) {
        if (table[i] == 'H') continue;

        int prev_eater_count = eater_count;

        // 왼쪽부터 자기자신까지
        for (int j = i - K; j <= i; j++) {
            if (j < 0) continue;
            if (visited[j] == true) continue;

            if (table[j] == 'H') {
                visited[j] = true;
                eater_count++;
                break;
            }
        }
        if (prev_eater_count != eater_count) 
            continue;
        
        // 오른쪽 탐색
        for (int j = i + 1; j <= i + K; j++) {
            if (j >= N) break;
            if (visited[j] == true) continue;

            if (table[j] == 'H') {
                visited[j] = true;
                eater_count++;
                break;
            }
        }
    }

    printf("%d", eater_count);
}

int main() {
	// 코드 작성
    input();
    solution();
	return 0;
}

/*
아이디어:
각 좌석에 앉은 사람마다 DFS with visited
근데 "최대"를 구해야 하기 때문에 단순하게 생각하면 안됨

쉽게 생각하면 1차원 라인이니까
최대한 왼쪽에 있는 햄버거를 먹는게 좋겠지
dfs해도 되는데 그냥 visited 사용한 선형 완전탐색이 가장 무난한듯

입력:
N(식탁 길이) ~ [1, 2e4]
K(햄버거 선택 가능 거리) ~ [1, 10] 

출력:
햄버거를 먹을 수 있는 최대 사람 수

제약조건:
1. 햄버거 먹기 규칙
    1-1. 자신의 위치에서 거리가 K 이하인 햄버거만 먹을 수 있다.
*/