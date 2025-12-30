#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, bool> pib;

vector<pib> belt;
int N, K, sz, rnd;
int up, down;

int count(const vector<pib>& belt) {
    int cnt = 0;
    for (int i = 0; i < sz; i++) {
        if (belt[i].first == 0)
            cnt++;
    }

    return cnt;
}

void printBelt(int up) {

        cout << belt[up].first << "(" << up << ")" << " ";
    for (int i = (up + 1 == sz) ? 0 : up + 1; i != up; i = (i + 1 == sz) ? 0 : i + 1) {
        cout << belt[i].first << "(" << i << ")" << " ";
    }
    cout << endl;
}

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
// #endif

    cin >> N >> K;
    sz = 2 * N;
    rnd = 0;
    belt.assign(sz, {0, false});
    for (int i = 0; i < sz; i++)
        cin >> belt[i].first;

    up = 0;
    down = N-1;

    while (count(belt) < K) {        
        // 1. 벨트 회전
        up = (up == 0) ? sz - 1 : up - 1;
        down = (down == 0) ? sz - 1 : down - 1;

        // 2. 로봇 이동
        // 2-1. down에서 로봇 내림
        belt[down].second = false;
        
        // 2-2. 벨트 위 로봇 전진
        for (int i = (down == 0) ? sz - 1 : down - 1; i != up; 
            i = (i == 0) ? sz - 1 : i - 1) { 
            
            if (!belt[i].second) 
                continue;
            
            int dst = (i == sz - 1) ? 0 : i + 1;
            if (belt[dst].first > 0 && !belt[dst].second) {
                belt[dst].first--;
                belt[dst].second = true;
                belt[i].second = false;
            }
        }
        belt[down].second = false;

        // 2-3. 로봇 올리기
        if (belt[up].first > 0 && !belt[up].second) {
            belt[up].first--;
            belt[up].second = true;
        }        
        rnd++;
    }

    cout << rnd << endl;
    
    return 0;
}

/*
1 2 1
2 1 2
up, down을 유지하면 어차피 down부터 up까지 보면 됨
즉 첫번째 로봇의 위치는 기억할 필요 없음
*/