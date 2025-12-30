#if 1
#include <cstdio>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pii;
typedef unordered_map<int, int> umapii; // (소수, 지수)

const int SIZE = 1e2;
const int MAX = 1e6;

int N;
int cards[SIZE];

bool is_prime[MAX + 1]; 
vector<int> prime_list;

vector<umapii> factor_cnts(SIZE);
int total_factor_cnts[MAX + 1];

pii answer;

void init() {
    N = 0;
    for (int i = 0; i < SIZE; i++) {
        cards[i] = 0;
        factor_cnts[i].clear();
    }
    for (int i = 2; i <= MAX; i++)
        is_prime[i] = true;
    for (int i = 0; i <= MAX; i++)
        total_factor_cnts[i] = 0;
    prime_list.clear();

    answer.first = 1;
    answer.second = 0;
}

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &cards[i]);
}

void setPrimeList() {
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }

    for (int i = 2; i <= MAX; i++) {
        if (is_prime[i])
            prime_list.push_back(i);
    }
}

void primeFactorization() {
    int temp, sz, p;
    for (int i = 0; i < N; i++) {
        temp = cards[i];
        sz = prime_list.size();
        for (int j = 0; j < sz; j++) {
            p = prime_list[j];
            while ((temp % p) == 0) {
                factor_cnts[i][p]++;
                total_factor_cnts[p]++;
                temp /= p;
            }
        }
    }
}

void solution() { 
    int q, sz, p;
    sz = prime_list.size();
    for (int i = 0; i < sz; i++) {
        p = prime_list[i];
        q = total_factor_cnts[p] / N;
        if (q <= 0)
            continue;
        answer.first *= pow(p, q);
        for (int j = 0; j < N; j++)
            answer.second += max(0, q - factor_cnts[j][p]);
    }
}

void output() {
    printf("%d %d\n", answer.first, answer.second);
}

int main() {
    init();
    input();
    setPrimeList();
    primeFactorization();
    solution();
    output();

    return 0;
}
#endif