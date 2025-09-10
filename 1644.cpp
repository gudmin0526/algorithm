#if 1
#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 4'000'000;

bool is_prime[MAX+1];
vector<int> prime_list;

int N, answer;

void input() {
    // 초기화
    for (int i = 2; i <= MAX; i++)
        is_prime[i] = true;
    
    prime_list.clear();

    N = answer = 0;

    // 입력 받기
    scanf("%d", &N);
}

void setPrimeList() {
    // 에라토스테네스의 체 이용하여 소수 구하기
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }

    // 구한 소수들을 벡터에 넣기
    for (int i = 2; i <= N; i++) {
        if (is_prime[i])
            prime_list.push_back(i);
    }
}

void doTwoPointer() {
    int lo, hi, acc;
    lo = hi = acc = 0;

    int sz = prime_list.size();
    while (1) {
        if (acc > N)
            acc -= prime_list[lo++];
        else if (hi >= sz)
            break;
        else
            acc += prime_list[hi++];
        
        if (acc == N)
            answer++;
    }
}

int main() {
    
    input();

    setPrimeList();

    doTwoPointer();

    printf("%d\n", answer);

    return 0;
}
#endif