#if 1
#include <iostream>
#include <vector>

using namespace std;

typedef struct st {
    int r, c;
    st(int r, int c) {
        this->r = r;
        this->c = c;
    }
} Pos;

vector<vector<bool>> map(16, vector<bool>(16, false));
vector<bool> visited_cols(16, false);
long answer = 0;

int dr[2] = {-1, -1};
int dc[2] = {1, -1};

bool isOutOfBound(int N, Pos pos) {
    return pos.r < 1 || pos.r > N || pos.c < 1 || pos.c > N;
}

void printMap(int N) {
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) 
            cout << map[r][c] << " ";
        cout << endl;
    }
}

bool isReachable(int N, Pos pos, int dir) {
    int nr = pos.r + dr[dir];
    int nc = pos.c + dc[dir];
    
    if (isOutOfBound(N, Pos(nr, nc)))
        return false;
    
    if (map[nr][nc] == true)
        return true;
    
    return isReachable(N, Pos(nr, nc), dir);
}

void dfs(int N, Pos pos) {
    if (pos.r == N) {
        answer++;
        return;
    }

    for (int c = 1; c <= N; c++) {
        if (visited_cols[c])
            continue;

        Pos npos(pos.r+1, c);

        if (isReachable(N, npos, 0) || isReachable(N, npos, 1))
            continue;

        map[npos.r][c] = true;
        visited_cols[c] = true;

        dfs(N, npos);

        map[npos.r][c] = false;
        visited_cols[c] = false;
    }    
}

int main() {
    int N;
    cin >> N;

    for (int c = 1; c <= N; c++) {
        Pos pos(1, c);

        map[1][c] = true;
        visited_cols[c] = true;

        dfs(N, pos);

        map[1][c] = false;
        visited_cols[c] = false;
    }    

    cout << answer << endl;
}
#endif