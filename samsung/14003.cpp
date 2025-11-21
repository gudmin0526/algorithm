#if 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pii;

int N;
unordered_map<int, int> idx2val;
vector<pii> val_idx; // (value, idx)
vector<pii> tree;
vector<int> parent;
vector<int> answer;
int offset;

bool compare(pii & p1, pii & p2) {
	if (p1.first == p2.first)
		return p1.second < p2.second;
	return p1.first < p2.first;
}

void input() {
	cin >> N;

	val_idx.resize(N);
	parent.resize(N);
	tree.resize(N * 4);
	answer.clear();

	for (int i = 0; i < N; i++) {
		cin >> val_idx[i].first;
		val_idx[i].second = i;
		idx2val[i] = val_idx[i].first;
		parent[i] = 0;
	}
}

void initTree() {
	offset = 1;
	while (offset < N)
		offset *= 2;

	for (int i = 0; i < N; i++)
		tree[offset + i] = { 0, 0 };
	for (int i = offset - 1; i > 0; i--)
		tree[i] = { 0, 0 };
	for (int i = offset + N; i < N * 4; i++)
		tree[i] = { 0, 0 };
}

pii query(int from, int to) {
	from += offset;
	to += offset;

	pii ret = { 0, 0 }; // (lsi, idx)
	while (from <= to) {
		if (from % 2 == 1) {
			if (ret.first < tree[from].first)
				ret = tree[from];
			from++;
		}
		if (to % 2 == 0) {
			if (ret.first < tree[to].first)
				ret = tree[to];
			to--;
		}
		from /= 2;
		to /= 2;
	}

	return ret;
}

void update(int id, int val) {
	id += offset;
	tree[id] = { val, id - offset };
	while (id > 0) {
		id /= 2;
		if (tree[id * 2].first > tree[id * 2 + 1].first)
			tree[id] = tree[id * 2];
		else
			tree[id] = tree[id * 2 + 1];
	}
}

void solution() {
	// (값, 인덱스)에서 값으로 오름차순, 인덱스로 오름차순 정렬
	sort(val_idx.begin(), val_idx.end(), compare);

	// 값이 같은 동안 쿼리, 같은 값의 마지막만 넣어주면 된다
	int i = 0;
	while (1) {
		if (i == N)
			break;

        vector<int> update_list; // val_idx[i].second, 업데이트할 노드들
        vector<pii> ret_list; // (lsi, parent idx)
        while (i + 1 < N && val_idx[i].first == val_idx[i + 1].first) {
            update_list.push_back(val_idx[i].second);
            ret_list.push_back(query(0, val_idx[i].second));
            i++;
        }
        
        update_list.push_back(val_idx[i].second);
        ret_list.push_back(query(0, val_idx[i].second));

        int sz = update_list.size();
        for (int j = 0; j < sz; j++) {
            update(update_list[j], ret_list[j].first + 1);
            parent[update_list[j]] = ret_list[j].second;
        }
        
        i++;
	}
}


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	input();
	initTree();
	solution();

	int sz = tree[1].first;
	int last = tree[1].second;

	cout << sz << endl;
	
	for (int i = 0; i < sz; i++) {
		answer.push_back(idx2val[last]);
		last = parent[last];
	}

	for (int i = sz - 1; i >= 0; i--)
		cout << answer[i] << " ";

	return 0;
}
#endif