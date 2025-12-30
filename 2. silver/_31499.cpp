#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> factorial;
long long N, M;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    
    cin >> N >> M;
    factorial.assign(N+1, 0);
    factorial[1] = 1 % M;
    for (int i = 2; i <= N; i++)
        factorial[i] = (i * factorial[i-1]) % M;

    cout << factorial[N] << "\n";

    return 0;
}

/*
{1, 2}, {2, 1}

N = 2
B: {1, 2}
C: {1, 2}

N = 3
B: {1, 2, 3}
C: {1, 2 ,3}
*/