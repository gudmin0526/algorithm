#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, A, B;

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif

    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> A >> B;
        cout << "yes" << "\n";
    }

    return 0;
}

/*
하나만 성립하면 가능한 것이다.
6 7
1 * 6 = 6
6 8
1 * 1 * 1 * 2 * 3 = 6
1을 무한히 곱할 수 있기 때문에 B가 어떤 값 이상이면 무조건 변할 수 있다.
소인수들을 곱한 것이 최소값이다. 곱해서 나오는 값 >= 더해서 나오는 값.
아니다. ai는 정수이므로 뺄 수도 있다. 
따라서 1을 무한히 더할 수도 있고 무한히 뺄 수도 있다. 그러므로 항상 yes이다.
A = 7, B = 0
A = 7 * (-1)^8 * (1) = 7. 7 - 8 + 1 = 0
*/