#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
struct Order {
    int p, x, f;
    Order(int p, int x, int f) : p(p), x(x), f(f) {};
};

unordered_map<int, int> sell_volume;
unordered_map<int, int> buy_volume;
int N, price;
int p, x, f;

void handle(int p, int x, int f) {
    if (f == 1) { // buy
        if (sell_volume[p] > 0) {
            int traded = min(sell_volume[p], x);
            sell_volume[p] -= traded;
            buy_volume[p] += x - traded;
            price = p;
        } else {
            buy_volume[p] += x;
        }
    } else {      // sell
        if (buy_volume[p] > 0) {
            int traded = min(buy_volume[p], x);
            buy_volume[p] -= traded;
            sell_volume[p] += x - traded;
            price = p;
        } else {
            sell_volume[p] += x;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    price = 1e4;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p >> x >> f;
        handle(p, x, f);
    }

    cout << price << "\n";

    return 0;
}

/*
입력:
N(주문의 개수) ~ [1, 1e5]

출력:
N개의 주문이 처리된 후 HRX 회사 주식의 현재 가격

제약조건:
1. 주식의 단위는 1주이며, 가격은 10원 단위
2. 가격은 1e4 시작, 처음 10원 단위의 모든 구매/판매 물량은 0
3. 거래
 3-1. 가격 p의 판매 물량 s가 1 이상이고, 주문으로 x주를 구매하고자 한다면 min(s, x)가 구매
      x > s일 때 x - min(s, x)주가 구매 물량으로 전환
 3-2. 가격 p의 구매 물량 s가 1 이상이고, 주문으로 x주를 판매하고자 한다면 min(s, x)주가 판매
      x > s일 때 x - min(s, x)주가 판매 물량으로 전환
4. 가격
 4-1. 가격 p에 대해 구매/판매할 수 있는 주식이 1주 이상이면 가격이 p로 변경
 4-2. 구매할 수 있는 주식이 0주라면 가격 변동 x, 구매 물량만 추가
 4-3. 판매할 수 있는 주식이 0주라면 가격 변동 x, 판매 물량만 추가
*/