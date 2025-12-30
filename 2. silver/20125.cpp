#include <iostream>
using namespace std;

#define true 1
#define false 0

typedef enum body_t {
	BODY_LEFT_ARM = 0,
	BODY_RIGHT_ARM,
	BODY_WAIST,
	BODY_LEFT_LEG,
	BODY_RIGHT_LEG,
	BODY_CNT,
} body_t;

typedef struct {
	int x, y;
} pos_t;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

char pic[1001][1001];
int body_lens[5];
pos_t heart;
int N;

int isOutOfBound(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= N;
}

int main() {
	setbuf(stdout, NULL);
	// 0. 입력 받기
	scanf("%d", &N);
	for (int y = 0; y < N; y++) {
		scanf("%s", pic[y]);
	}

	for (int i = 0; i < BODY_CNT; i++)
		body_lens[i] = 0;
	
	// 1. 심장 찾기
	for (int y = 0; y < N; y++) {
		int adj_cnt;
		for (int x = 0; x < N; x++) {
			adj_cnt = 0;
			if (pic[y][x] != '*') 
				continue;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (isOutOfBound(nx, ny)) 
					break;
				if (pic[ny][nx] == '*')
					adj_cnt++;
			}
			if (adj_cnt == 4) {
				heart.x = x;
				heart.y = y;
			}
		}
		if (adj_cnt == 4)
			break;
	}

	// 2. 왼쪽 팔
	int x = heart.x - 1;
	int y = heart.y;
	while (!isOutOfBound(x, y) && pic[y][x] == '*') {
		body_lens[BODY_LEFT_ARM]++;
		x--;
	}

	// 3. 오른쪽 팔
	x = heart.x + 1;
	y = heart.y;
	while (!isOutOfBound(x, y) && pic[y][x] == '*') {
		body_lens[BODY_RIGHT_ARM]++;
		x++;
	}

	// 4. 허리
	x = heart.x;
	y = heart.y + 1;
	while (!isOutOfBound(x, y) && pic[y][x] == '*') {
		body_lens[BODY_WAIST]++;
		y++;
	}

	// 5. 양쪽 다리
	while (!isOutOfBound(x, y)) {
		if (!isOutOfBound(x-1, y) && pic[y][x-1] == '*')
			body_lens[BODY_LEFT_LEG]++;
		if (!isOutOfBound(x+1, y) && pic[y][x+1] == '*')
			body_lens[BODY_RIGHT_LEG]++;
		y++;		
	}
	
	printf("%d %d\n", heart.y + 1, heart.x + 1);
	for (int i = 0; i < BODY_CNT; i++) {
		printf("%d ", body_lens[i]);
	}

	return 0;
}

/*
제약조건:

*/