#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll N, M, answer;
vector<ll> abils;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    answer = 0;
    cin >> N >> M;
    abils.assign(N, 0);
    for (ll i = 0; i < N; i++)
        cin >> abils[i];
    sort(abils.begin(), abils.end());

    ll left = 0, right = N-1;
    while (left < right) {
        if (abils[left] + abils[right] >= M) {
            left++; right--;
            answer++;
        } else {
            left++;
        }
    }

    cout << answer << "\n";

    return 0;
}

/*
아이디어:
1e5면 정렬을 사용할 수 있음.
1. 오름차순 정렬
2. 양쪽 포인터를 보고, M보다 작으면 Left를 증가
3. M보다 크면 Left 증가, Right 감소

입력:
N ~ [1, 1e5]
M ~ [1, 1e9]
a_i(능력치) ~ [1, 1e9]

출력:
견학 보낼 수 있는 최대 팀 수

제약조건:
1. 팀원이 두 명
2. 팀의 능력치(모든 팀원의 능력치를 합한 값)가 M 이상
3. N명으로 최대한 많은 팀을 만들어 견학
*/