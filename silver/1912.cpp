#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, answer;
vector<int> numbers;

void input() {
    answer = -1e9;
    cin >> N;
    numbers.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> numbers[i];
}

void solution() {
    int acc, lo, hi;
    acc = lo = hi = 0;
    
    while (lo <= hi) {
        if (acc < 0)
            acc -= numbers[lo++];
        else if (hi >= N)
            break;
        else
            acc += numbers[hi++];
        if (answer < acc && lo < hi)
            answer = acc;
    }

    cout << answer << endl;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    input();
    solution(); 

    return 0;
}

/*
아이디어:
1e5니까 nlogn
연속, 부분합, 완전탐색 -> 투포인터, 인덱스트리
그러나 순서가 중요하지 않으므로 투포인터
그런데 음수가 있으므로 항상 증가하지 않음, 이것을 고려

입력:
n ~ [1, 1e5]
(수) ~ [-1e3, 1e3]

출력:
연속, 합, 가장 큰 합

제약조건:
1. 연속된 몇 개의 수 선택
2. 구할 수 있는 합 중 가장 큰 합
3. 수는 한 개 이상 선택
*/