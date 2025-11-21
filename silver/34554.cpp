#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
vector<bool> isPrime;

void sieve() {
    isPrime[0] = false;
    isPrime[1] = false;
    isPrime[2] = true;
    for (int i = 2; i * i <= 20000; i++) {
        if (!isPrime[i])
            continue;
        for (int j = i * i; j <= 20000; j += i)
            isPrime[j] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif    
    
    isPrime.assign(20001, true);
    sieve();

    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        if (isPrime[N + 1])
            cout << 1 << "\n" << 1 << " " << N + 1 << "\n";
        else
            cout << 0 << "\n";
    }

    return 0;
}