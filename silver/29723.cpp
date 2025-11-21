#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> scores;
vector<string> reqs;
vector<int> answer;
int N, M, K, p;
string s;

bool compare(pair<string, int>& p1, pair<string, int>& p2) {
    return p1.second < p2.second;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> s >> p;
        scores[s] = p;
    }

    answer.assign(2, 0);
    reqs.assign(K, "");
    for (int i = 0; i < K; i++) {
        cin >> reqs[i];
        answer[0] += scores[reqs[i]];
        answer[1] += scores[reqs[i]];
        scores.erase(reqs[i]);
    }

    vector<pair<string, int>> scores_vec;
    for (pair<string, int> p : scores)
        scores_vec.push_back(p);

    sort(scores_vec.begin(), scores_vec.end(), compare);

    for (int i = 0; i < M - K; i++) {
        answer[0] += scores_vec[i].second;
        answer[1] += scores_vec[scores_vec.size()-i-1].second;
    }

    cout << answer[0] << " " << answer[1] << "\n";

    return 0;
}