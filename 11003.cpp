#if 1
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<long> seq(5'000'001, 0);
vector<long> answer(5'000'001, 0);
deque<pair<long, long>> deq; // (val, idx)


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	cin >> N >> L;

	for (int i = 1; i <= N; i++)
		cin >> seq[i];

    for (int i = 1; i <= L; i++) {
        if (deq.empty() || seq[i] < deq.front().first)
            deq.push_front({ seq[i], i });
        else if (seq[i] == deq.front().first)
            deq.front().second = i;
        else if (seq[i] > deq.back().first)
            deq.push_back({ seq[i], i });
        else { // deq.front().first < seq[i] <= deq.back().first
            while (deq.back().first >= seq[i])
                deq.pop_back();
            deq.push_back( {seq[i], i} );
        }

        answer[i] = deq.front().first;
    }

    for (int i = L+1; i <= N; i++) {
        while (!deq.empty() && deq.front().second < (i - L + 1))
            deq.pop_front();

        if (deq.empty() || seq[i] < deq.front().first)
            deq.push_front({ seq[i], i });
        else if (seq[i] == deq.front().first)
            deq.front().second = i;
        else if (seq[i] > deq.back().first)
            deq.push_back({ seq[i], i });
        else { // deq.front().first < seq[i] <= deq.back().first
            while (deq.back().first >= seq[i])
                deq.pop_back();
            deq.push_back( {seq[i], i} );
        }

        answer[i] = deq.front().first;
    }

    for (int i = 1; i <= N; i++) 
        cout << answer[i] << " ";

	return 0;
}

#endif