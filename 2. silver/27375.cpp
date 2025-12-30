#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Lecture {
    int w, s, e;
    Lecture(int w, int s, int e) : w(w), s(s), e(e) {}

    bool operator<(const Lecture& o) const noexcept {
        if (w == o.w)
            return s < o.s;
        return w < o.w;
    }
};

vector<vector<bool>> visited;
vector<Lecture> lectures;
int n, k, answer;

void dfs(int acc, int idx) {
    if (acc >= k || idx >= lectures.size()) {
        if (acc == k) answer++;
        return;
    }

    Lecture l = lectures[idx];

    dfs(acc, idx + 1);

    for (int i = l.s; i <= l.e; i++) {
        if (visited[l.w][i] == true)
            return;
    }

    for (int i = l.s; i <= l.e; i++)
        visited[l.w][i] = true;

    dfs(acc + l.e - l.s + 1, idx + 1);

    for (int i = l.s; i <= l.e; i++)
        visited[l.w][i] = false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    answer = 0;
    cin >> n >> k;

    visited.assign(5, vector<bool>(11, false));
    lectures.clear();

    int w, s, e;
    for (int i = 0; i < n; i++) {
        cin >> w >> s >> e;
        if (w == 5) continue;
        lectures.push_back({w, s, e});
    }
    sort(lectures.begin(), lectures.end());

    dfs(0, 0);

    cout << answer << "\n";

    return 0;
}

/* 
아이디어:
완전탐색 dfs + 백트래킹으로 접근
요일 별로 visited 배열, 금요일 빼고 4(월화수목) * 10(교시) = 40
겹치는 것이 있으면 넘어감

입력:

출력:
정확히 k학점을 들으면서 금공강인 시간표의 가짓수

제약조건:
1. 금공강이 있는 시간표의 가짓수
2. 두 수업 동시 수강 불가능
3. 학점 e-s+1
*/