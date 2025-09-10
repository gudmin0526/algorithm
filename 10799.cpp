#if 1
#include <cstdio>
#include <deque>

using namespace std;
// () ((( () () )( () ) () ))( () )
// 3 + 3 + 1 + 3 + 1 + 2 + 2 + 1 + 1

char str[100001];

int main() {
    deque<char> dq;

    int cnt = 0;
    int answer = 0;
    scanf("%s", &str);
    for (char c : str) {
        if (c == '(') {
            dq.push_back(c);
            cnt++;
        } else if (c == ')') {
            if (dq.back() == '(') {
                --cnt;
                answer += cnt;
            } else {
                cnt--;
                answer += 1;
            }
            dq.push_back(c);
        } else {
            break;
        }
    }

    printf("%d", answer);

    return 0;
}
#endif