#if 1
#include <iostream>
#include <deque>

using namespace std;

int programs[1'000'001];
int answer[1'000'001];
deque<int> dq;
deque<int> result;

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> programs[i];
        dq.push_front(i);
    }

    int top_el;
    for (int i = 1; i <= N; i++) {
        switch (programs[i]) {
        case 1:
            result.push_back(dq.back());
            dq.pop_back();
            break;
        case 2:
            top_el = dq.back();
            dq.pop_back();
            result.push_back(dq.back());
            dq.pop_back();
            dq.push_back(top_el);
            break;
        case 3:
            result.push_back(dq.front());
            dq.pop_front();
            break;
        }
    }

    int i = 1;
    while (!result.empty()) {
        answer[result.back()] = i++;
        result.pop_back();
    }

    for (int i = 1; i <= N; i++)
        cout << answer[i] << " ";

    return 0;
}
#endif