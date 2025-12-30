#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> transfer_stations;
int N, s;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s == 1)
            transfer_stations.push_back(i);
    }

    if (N == 2 || transfer_stations.empty()) {
        cout << "mnx" << "\n";
        return 0;
    }

    bool turn = false; // true: 세훈, false: 민아
    for (int i = transfer_stations.size()-2; i >= 0; i--) {
        if (transfer_stations[i+1] - transfer_stations[i] == 1)
            turn = !turn;
        else
            turn = false; // 민아가 이전 1을 말해줘야 세훈이가 그 자리 1을 말할 수 있음
    }

    if (transfer_stations[0] == 1) {
        cout << (turn ? "mnx" : "alsdkffhgk") << "\n";
    } else {
        cout << "mnx" << "\n";
    }

    return 0;
}

/*
아이디어:
완전탐색으로 해결하는 것은 불가능
뒤에서부터 시작해서, 
1 0 1 -> 민아, 민아 -> 민아 승
1 0 0 1 -> 민아, 민아 -> 민아 승
1 0 1 1 -> 민아, 세훈, 민아 -> (시작은 세훈이므로) 민아 승
0 1 0 0 1 -> 민아, 민아 -> 세훈 승
0 1 0 1 1 -> 민아, 세훈, 민아 -> 세훈 승
0 1 1 -> 민아, 세훈 ->  세훈 승
1 0 1 1 -> 민아, 세훈, 민아 -> 민아 승
항상 선공자 입장에서 생각한다.

입력:
N ~ [2, 5e5]

출력:
세훈이가 이기면 mnx, 민아가 이기면 alsdkffhgk

제약조건:
1. 1번과 N번을 제외한 각 역은 환승역이거나 일반역
2. 게임 규칙
 2-1. 지하철 모양을 1번
 2-2. 세훈 시작, 번갈아 진행
 2-3. 턴마다 지하철 모형을 다음 역으로 옮기는 행동을 한 번 이상 원하는 만큼
      단, 환승역 도착시 움직일 수 없음
 2-4. 자신의 턴에 모형을 N번에 놓는 사람이 승리
3. 두 사람은 항상 최선의 선택을 함
*/