#if 1
#include <cstdio>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


enum class Status { Maybe, False, True };

typedef pair<int, int> pii;

const int INFO_SIZE = 3e5 + 5;
const int STORY_SIZE = 3e4 + 5;

int N, M, offset;

set<int> years;
unordered_map<int, int> year2idx;
unordered_map<int, int> year2rain;

int rel_info[INFO_SIZE];
pii tree[INFO_SIZE * 4];

pii story[STORY_SIZE];
pii rel_story[STORY_SIZE];

void input() {
    scanf("%d", &N);

    int year1, year2, rain, i;
    for (i = 0; i < N; i++) {
        scanf("%d %d", &year1, &rain);
        year2rain[year1] = rain;
        years.insert(year1);
    }

    scanf("%d", &M);
    for (i = 0; i < M; i++) {
        scanf("%d %d", &year1, &year2);
        story[i].first = year1;
        story[i].second = year2;

        years.insert(year1);
        years.insert(year2);
    }

    int prev = 1e9+5;
    vector<int> insert_list;
    for (int y : years) {
        if (y - 1 > prev)  // gap
            insert_list.push_back(y - 1);
        prev = y;
    }
    for (int y : insert_list) years.insert(y);
}

void rangeCompression() {
    int i = 0;
    for (int y : years) year2idx[y] = i++;

    for (int y : years) rel_info[year2idx[y]] = year2rain[y];

    for (i = 0; i < M; i++) {
        rel_story[i].first = year2idx[story[i].first];
        rel_story[i].second = year2idx[story[i].second];
    }

    N = years.size();
}

void initTree() {
    offset = 1;
    while (offset < N) offset *= 2;

    bool is_assumption;
    for (int i = 0; i < N; i++) {
        is_assumption = (rel_info[i] == 0);
        tree[offset + i] = {rel_info[i], is_assumption ? 0 : 1};
    }
    for (int i = offset - 1; i > 0; i--) {
        pii left = tree[i * 2];
        pii right = tree[i * 2 + 1];
        int max_val = max({left.first, right.first});
        is_assumption = (left.second == 0 || right.second == 0);
        tree[i] = {max_val, is_assumption ? 0 : 1};
    }
    for (int i = offset + N; i < INFO_SIZE * 4; i++) tree[i] = {0, 0};
}

Status queryTree(int from, int to, int rainX) {
    from += offset;
    to += offset;

    Status res = Status::True;

    while (from <= to) {
        if ((from % 2) == 1) {
            if (tree[from].first >= rainX) return Status::False;
            if (tree[from].second == 0) res = Status::Maybe;
            from++;
        }
        if ((to % 2) == 0) {
            if (tree[to].first >= rainX) return Status::False;
            if (tree[to].second == 0) res = Status::Maybe;
            to--;
        }
        from /= 2;
        to /= 2;
    }
    return res;
}

void solution() {
    for (int i = 0; i < M; i++) {
        int Y = rel_story[i].first;
        int X = rel_story[i].second;
        
        int rainY = rel_info[Y];
        int rainX = rel_info[X];

        Status res;

        if ((rainY == 1 || rainX == 1) && Y - X > 1) {
            answer.push_back(Status::False);
            continue;
        }

        else if (rainY == 0 && rainX == 0) {
            answer.push_back(Status::Maybe);
        }

        else if (rainX == 0) {
            Status res = queryTree(Y + 1, X - 1, rainY);
            if (res == Status::False)
                answer.push_back(Status::False);
            else
                answer.push_back(Status::Maybe);
        }

        else if (rainY == 0) {
            Status res = queryTree(Y + 1, X - 1, rainX);
            if (res == Status::False)
                answer.push_back(Status::False);
            else
                answer.push_back(Status::Maybe);
        }

        else if (rainY < rainX) {
            answer.push_back(Status::False);
            continue;
        }
        
        res = queryTree(Y+1, X-1, rainX);
        answer.push_back(res);
    }
}

int main() {

    input();
    rangeCompression();

    initTree();
    solution();

    return 0;
}
#endif