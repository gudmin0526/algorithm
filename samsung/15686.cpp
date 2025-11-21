#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int map[51][51];
vector<pair<int, int>> chickens;
vector<pair<int, int>> homes;
vector<int> chicken_distances;

int answer = INT_MAX;

int getChickenDistance(pair<int, int> home, pair<int, int> chicken) {
	return abs(home.first - chicken.first) + abs(home.second - chicken.second);
}

void dfs(int M, int idx, int order) {
    // M개 선택 완료한 경우
    if (order >= M) {
		int sum_distance = 0;
		for (int i = 0; i < chicken_distances.size(); i++)
			sum_distance += chicken_distances[i];
		if (answer > sum_distance)
			answer = sum_distance;
		return;
	}

    // M개를 고르지 못하고 범위를 넘어감
	if (idx >= chickens.size())
		return;

	// 해당 치킨집을 포함하지 않는 경우
	dfs(M, idx + 1, order);

    // 백트래킹을 위해 변경 내역 저장
    vector<pair<int, int>> changes; // { idx, prev_distance }

    // 치킨집을 포함하는 경우를 위해 계산
	int sz = homes.size();
	for (int i = 0; i < sz; i++) {
		int dist = getChickenDistance(homes[i], chickens[idx]);
		if (dist < chicken_distances[i]) {
            changes.push_back({ i, chicken_distances[i] });
			chicken_distances[i] = dist;
        }
	}

	// 해당 치킨집을 포함하는 경우
	dfs(M, idx + 1, order + 1);
    
    // 백트래킹
    for (pair<int, int> change : changes) {
        int idx = change.first;
        int prev_dist = change.second;
        chicken_distances[idx] = prev_dist;
    }
}

int main() {
	int N, M;
	cin >> N >> M;

	// 맵을 입력받는다.
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++)
			cin >> map[r][c];
	}

	// 치킨집과 집의 좌표들을 저장한다.
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (map[r][c] == 2)
				chickens.push_back({ r, c });
			if (map[r][c] == 1) {
				homes.push_back({ r, c });
				chicken_distances.push_back(INT_MAX);
			}
		}
	}

	// dfs와 백트래킹으로 모든 경우의 수를 따져본다.
	dfs(M, 0, 0);

	cout << answer << endl;
}