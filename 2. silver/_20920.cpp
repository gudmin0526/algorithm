#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include "../.algorithm/inc/my_qsort.h"

#define NUM_LIMIT  100000U
#define LEN_LIMIT  10U

/* ===========
 * Solution
 * =========== */

typedef struct {
    char word[LEN_LIMIT+5];
    int len;
    int count;
} word_t;

int N, M;

char inputs[NUM_LIMIT+5][LEN_LIMIT+5];
int inputs_size = 0;

word_t words[NUM_LIMIT+5];
int words_size = 0;

void input() {
    scanf("%d %d", &N, &M);

    inputs_size = 0;
    words_size = 0;
    pool_idx = 0;

    char input[LEN_LIMIT+5];
    for (int i = 0; i < N; i++) {
        scanf("%s", input);

        // 길이 작으면 넘어감
        if (strlen(input) < M)
            continue;

        strcpy(inputs[inputs_size++], input);
    }
}

int cmp_word(const void* a, const void* b) {
    const word_t* wa = (const word_t*)a;
    const word_t* wb = (const word_t*)b;

    // 1. 개수가 많은 단어
    if      (wa->count < wb->count) return 1;
    else if (wa->count > wb->count) return -1;

    // 2. 길이가 긴 단어
    if      (wa->len < wb->len) return 1;
    else if (wa->len > wb->len) return -1;

    // 3. 사전 순으로 앞에 있는 단어
    return strcmp(wa->word, wb->word);

}

int cmp_input(const void* a, const void* b) {
    const char* sa = (const char*)a;
    const char* sb = (const char*)b;

    return strcmp(sa, sb);
}

void solution() {
    // 입력 문자열 정렬 후 전처리한다.
    qsort(inputs, inputs_size, sizeof(inputs[0]), cmp_input);

    // word_t 배열 전처리한다.
    for (int i = 0; i < inputs_size; i++) {
        if (i == 0 || strcmp(inputs[i-1], inputs[i]) != 0) {
            strcpy(words[words_size].word, inputs[i]);
            words[words_size].len = strlen(inputs[i]);
            words[words_size].count = 0;
            words_size++;
        }
        words[words_size - 1].count++;
    }

    // 규칙에 따라 단어장 정렬한다.
    qsort(words, words_size, sizeof(word_t), cmp_word);

    // 단어장의 앞에 위치한 단어부터 한 단어씩 출력한다.
    for (int i = 0; i < words_size; i++) {
        printf("%s\n", words[i].word);
    }
}

int main() {
    input();
    solution();
    return 0;
}

/*
문자열 해시 연습하기

입력:
N(단어의 개수) ~ [1, 1e5]
M(단어 길이 기준) ~ [1, 10]

출력:
단어장의 앞에 위치한 단어부터 한 줄에 한 단어씩 순서대로 출력

제약조건:
1. 단어장 만들기
    1-1. 자주 나오는 단어일수록 앞 배치
    1-2. 단어 길이가 길수록 앞 배치
    1-3. 사전 순으로 앞 단어일수록 앞 배치
    
2. 예외
    2-1. 길이가 M 이상인 단어들만 외운다.
    2-2. 알파벳 소문자들로만 주어진다.
    2-3. 단어의 길이는 10을 넘지 않는다.
    2-4. 단어장에 반드시 단어가 1개 이상 존재하는 입력만 주어진다.
*/