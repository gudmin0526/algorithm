#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;

unordered_map<string, vector<string>> groups;
unordered_map<string, ll> holdings;
unordered_map<string, ll> prices;

ll N, M, Q;

void input() {
    cin >> N >> M >> Q;

    ll P;
    string G, H;
    for (int i = 0; i < N; i++) {
        cin >> G >> H >> P;
        groups[G].push_back(H);
        prices[H] = P;
    }
}

void handle(ll op, string name, ll val) {
    if (op == 1) {
        if (prices[name] * val > M)
            return;
        M -= prices[name] * val;
        holdings[name] += val;
    } else if (op == 2) {
        if (holdings[name] <= 0)
            return;
        val = holdings[name] < val ? holdings[name] : val;
        M += prices[name] * val;
        holdings[name] -= val; 
    } else if (op == 3) {
        prices[name] += val;
    } else if (op == 4) {
        for (string& c : groups[name])
            prices[c] += val;              
    } else if (op == 5) {
        for (string& c : groups[name]) {
            // floating point 연산 주의
            prices[c] = (prices[c] * (100 + val)) / 100;
            prices[c] -= prices[c] % 10;
        }
    } else if (op == 6) {
        cout << M << "\n";
    } else if (op == 7) {
        ll eval = 0;
        for (pair<string, ll> h : holdings)
            eval += prices[h.first] * h.second;
        cout << M + eval << "\n";
    }
}

void solution() {
    ll op, val;
    string H;
    for (int i = 0; i < Q; i++) {
        cin >> op;
        if (op != 6 && op != 7)
            cin >> H >> val;
        handle(op, H, val);
    }
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    input();
    solution();

    return 0;
}

/*
입력:

출력:

제약조건:
1. 처음 보유하고 있는 주식은 없음
2. 대소문자 구별
3. 거래의 단위는 10원. 5번은 주가를 반영한 뒤, 일의 자리에서 버림
4. long long 사용
5. 없는 회사, 없는 그룹이 주어지지 않음
6. 같은 회사 이름 두 번 등장하지 않음
*/