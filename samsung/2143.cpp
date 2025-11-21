#if 1
#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

int A[1001], B[1001];
unordered_map<long, long> psum_A;
unordered_map<long, long> psum_B;
long answer = 0;

int main() {
    long T, N, M;
    cin >> T;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    
    cin >> M;
    for (int i = 1; i <= M; i++)
        cin >> B[i];

    for (int i = 1; i <= N; i++) {
        long acc = 0;
        for (int j = i; j <= N; j++) {
            acc += A[j];
            psum_A[acc]++;
        }
    }

    for (int i = 1; i <= M; i++) {
        long acc = 0;
        for (int j = i; j <= M; j++) {
            acc += B[j];
            psum_B[acc]++;
        }
    }

    for (const pair<long, long> p : psum_A)
        answer += p.second * psum_B[T-p.first];

    cout << answer << endl;

    return 0;
}
#endif