#if 1
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;

const int SIZE = 1e6;

int N, offset;
pii tree[SIZE * 4];

int sumNode(const pii & p) {
    if (p.second == -1)
        return p.first;
    return p.first + p.second;
}

void input() {
    cin >> N;
}

void initTree() {
    offset = 1;
    while (offset < SIZE)
        offset = offset << 1;

    for (int i = 0; i < SIZE; i++)
        tree[i + offset] = { 0, -1 };
        
    for (int i = SIZE + offset; i < SIZE * 4; i++)
        tree[i] = { 0, 0 }; 

    for (int i = offset - 1; i > 0; i--)
        tree[i] = { 0, 0 } ;
}

void updateTree(int idx) {
    idx += offset;

    while (idx > 0) {
        idx = idx >> 1;
        tree[idx].first = sumNode(tree[(idx << 1)]);
        tree[idx].second = sumNode(tree[(idx << 1) + 1]);
    }
}

int queryTree(int place) {
    int idx = 1;
    while (1) {
        // 리프 노드에 도달
        if (tree[idx].second == -1)
            return (idx + 1) - offset;
            
        if (place <= tree[idx].first) {
            idx = (idx << 1);
        }
        else {
            place -= tree[idx].first;
            idx = (idx << 1) + 1; 
        }
    }
}

void solution() {
    int A, B, C;
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        if (A == 2) {
            cin >> C;
            int candy = B;

            tree[(candy - 1) + offset].first += C;
            updateTree(candy - 1);
        } else {
            int place = B;
            int candy = queryTree(place);
            
            tree[(candy - 1) + offset].first -= 1;
            updateTree(candy - 1);

            cout << candy << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    input();
    initTree();
    solution();

    return 0;
}
#endif