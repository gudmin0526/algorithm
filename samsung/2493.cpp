#if 1
#include <cstdio>
#include <deque>

using namespace std;

typedef pair<int, int> pii;

const int MAX = 5e5;

int heights[MAX];
deque<pii> stk; // (값, 인덱스)

int N;

void input() {
    // 초기화
    for (int i = 0; i < MAX; i++)
        heights[i] = 0;
    stk.clear();
    N = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &heights[i]);
}

void solution() {
    for (int i = 0; i < N; i++) {
        // 1. push 이전, top의 값이 현재보다 작은 동안 pop
        while (!stk.empty() && stk.back().first < heights[i])
            stk.pop_back();

        // 2. top의 인덱스 출력
        if (stk.empty())
            printf("%d ", 0);
        else
            printf("%d ", stk.back().second+1);

        // 3. top의 값이 현재 값과 같으면 pop
        if (!stk.empty() && stk.back().first == heights[i])
            stk.pop_back();
        
        // 4. (현재 값, 현재 인덱스) push
        stk.push_back({heights[i], i});
    }
}

int main() {
    input();
    solution();
}

#endif 