#if 1
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int N, offset;
vector<pii> idx_abil;
vector<int> rel_abil;
unordered_map<int, int> idx2abil;

vector<int> tree;

bool compare(const pii & p1, const pii & p2) {
	return p1.second > p2.second;
}

bool compare2(const pii & p1, const pii & p2) {	
	return p1.first < p2.first;
}

void input() {
	cin >> N;
	idx_abil.resize(N);
	tree.resize(N * 4);
	rel_abil.resize(N);
	for (int i = 0; i < N; i++) {
		int abil;
		cin >> abil;
		idx_abil[i] = { i, abil };
        idx2abil[i] = abil;
	}
}

void initTree() {
	offset = 1;
	while (offset < N)
		offset *= 2;

	for (int i = 0; i < N * 4; i++)
		tree[i] = 0;
}

void updateTree(int idx) {
	idx += offset;

	tree[idx] = 1;
	while (idx > 0) {
		idx /= 2;
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}
}

int queryTree(int from, int to) {
	from += offset;
	to += offset;

	int ret = 0;
	while (from <= to) {
		if (from % 2 == 1)
			ret += tree[from++];
		if (to % 2 == 0)
			ret += tree[to--];
		from /= 2;
		to /= 2;
	}
	return ret;
}

void solution() {
	// 2. 실력 순으로 오름차순 정렬
	sort(idx_abil.begin(), idx_abil.end(), compare);

	// 3. 상대 크기([1, N])을 가진 벡터로 변환	
	for (int i = 0; i < N; i++) {
		int idx = idx_abil[i].first;
		rel_abil[idx] = i;
	}
	
	for (int i = 0; i < N; i++) {
		cout << queryTree(0, rel_abil[i] - 1) + 1 << " " << idx2abil[i] << "\n";
		updateTree(rel_abil[i]);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);

	int T = 1;

	for (int tc = 1; tc <= T; tc++) {
		input();
		initTree();
		solution();
	}


	return 0;
}
#endif