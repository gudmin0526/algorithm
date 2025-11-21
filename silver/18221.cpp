#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<vector<int>> grid;
vector<int> stu, pf;
int N, dist, acc;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    acc = 0;
    cin >> N;
    grid.assign(N, vector<int>(N, 0));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> grid[y][x];
            if (grid[y][x] == 2)
                stu = {x, y};
            else if (grid[y][x] == 5)
                pf = {x, y};
        }
    }

    dist = (int)sqrt((pow(stu[0]-pf[0], 2) + pow(stu[1]-pf[1], 2)));

    if (dist < 5) {
        cout << 0 << "\n";
    } else {
        if (stu[0] == pf[0]) {
            for (int i = min(stu[1], pf[1]); i <= max(stu[1], pf[1]); i++) {
                if (grid[i][stu[0]] == 1)
                    acc++;
            }
        } else if (stu[1] == pf[1]) {
            for (int i = min(stu[0], pf[0]); i <= max(stu[0], pf[0]); i++) {
                if (grid[stu[1]][i] == 1)
                    acc++;
            }
        } else {
            for (int i = min(stu[1], pf[1]); i <= max(stu[1], pf[1]); i++) {
                for (int j = min(stu[0], pf[0]); j <= max(stu[0], pf[0]); j++) {     
                    if (grid[i][j] == 1)
                        acc++;
                }
            }
        }
        cout << (acc >= 3 ? 1 : 0) << "\n";
    }

    return 0;
}

/*
입력:

출력:
도망갈 수 있으면 1, 그렇지 못하면 0

제약조건:
1. 각 책상 자리는 비어있음, 성규, 다른 학생, 교수 4가지 상태 중 하나
2. 도망가는데 성공하려면 거리가 5 이상이면서, 직사각형 안에 학생 3명 이상
3. 같은 행, 열의 책상에 앉아있다면 선분 상에 학생 3명 이상
*/