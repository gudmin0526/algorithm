#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include "../.algorithm/inc/my_hashmap.h"

#define MAX_TEAMS 200
#define MAX_PARTICIPANTS 1000

/* ===========
 * Hash Map
 * =========== */

size_t hash_func(void* key) {
    return (*(unsigned int*)key ^ 2654435761U);
}

int key_compare_func(void* k1, void* k2) {
    int* ik1 = (int*)k1;
    int* ik2 = (int*)k2;

    if (*ik1 == *ik2) return 0;
    return 1;
}

/* =========== 
 *  Solution 
 * =========== */

typedef struct  {
    int team;
    int score;
    int order;
} record_t;

int T, N;
int fifth_scores[MAX_TEAMS+5];
record_t race_data[MAX_PARTICIPANTS+5];

MyHashMap hashmap;

void input() {
    myhashmap_reset(&hashmap);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &race_data[i].team);
        race_data[i].score = 0;
        race_data[i].order = 0;
    }
}

void solve() {
    // 1. 자격 없는 팀(여섯 명 참가 안함)을 걸러내기 위한 map counting
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        if (myhashmap_get(
                &hashmap, 
                &race_data[i].team, 
                sizeof(race_data[i].team), 
                &cnt, 
                sizeof(cnt)
            ) != 0)
        {
            cnt = 0;
        }
        
        cnt++;
        myhashmap_put(
            &hashmap, 
            &race_data[i].team, 
            sizeof(race_data[i].team), 
            &cnt,
            sizeof(cnt)
        );
        race_data[i].order = cnt;
    }
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        myhashmap_get(
            &hashmap, 
            &race_data[i].team, 
            sizeof(race_data[i].team), 
            &cnt, 
            sizeof(cnt)
        );
        if (cnt < 6) 
            race_data[i].team = 0;
    }

    // 2. 남은 인원들에게 점수 부여
    int rank = 1;
    for (int i = 0; i < N; i++) {
        if (race_data[i].team == 0)
            continue;
        race_data[i].score = rank++;
        if (race_data[i].order == 5)
            fifth_scores[race_data[i].team] = rank;
    }

    // 3. 부여한 점수 바탕으로 총점 계산해서 우승팀 산출
    for (int i = 0; i < N; i++) {
        if (race_data[i].team == 0) 
            continue;

        int zero = 0;
        myhashmap_put(
            &hashmap, 
            &race_data[i].team, 
            sizeof(race_data[i].team), 
            &zero,
            sizeof(zero)
        );
    }
    for (int i = 0; i < N; i++) {
        if (race_data[i].team == 0) 
            continue;
        if (race_data[i].order > 4)
            continue;

        int score = 0;
        myhashmap_get(
            &hashmap, 
            &race_data[i].team, 
            sizeof(race_data[i].team), 
            &score, 
            sizeof(score)
        );

        score += race_data[i].score;
        myhashmap_put(
            &hashmap, 
            &race_data[i].team, 
            sizeof(race_data[i].team), 
            &score,
            sizeof(score)
        );
    }

    int min_score = 1e9;
    int winner = 0;
    for (int i = 0; i < N; i++) {
        if (race_data[i].team == 0) 
            continue;

        int score = 0;
        myhashmap_get(
            &hashmap, 
            &race_data[i].team, 
            sizeof(race_data[i].team), 
            &score, 
            sizeof(score)
        );

        if (min_score > score) {
            min_score = score;
            winner = race_data[i].team;
        }

        if (min_score == score) {
            if (fifth_scores[winner] > fifth_scores[race_data[i].team])
                winner = race_data[i].team;
        }
    }

    printf("%d\n", winner);
}

int main() {
    scanf("%d", &T);

    hashmap.hash_func = &hash_func;
    hashmap.key_compare_func = &key_compare_func;
    for (int tc = 1; tc <= T; tc++) {
        input();
        solve();
    }
    return 0;
}

/*
아이디어:
일단 자격 없는 팀(여섯 명 안된 팀)을 먼저 걸러내는 것이 우선
자격 없는 팀 번호는 모두 0으로 처리

입력:
T(테스트 케이스)
N(선수 숫자) ~ [6, 1e3]
M(팀번호) ~ [1, 2e2]

출력:
하나의 테스트 케이스에 대한 우승팀의 번호 한 줄 출력

제약조건:
1. 경기 규칙
  1-1. 한 팀은 여섯 명의 선수로 구성
  1-2. 팀 점수는 상위 네 명 주자의 점수 합산
  1-3. 점수는 자격을 갖춘 팀의 주자들에게만, 결승점을 통과한 순서대로
  1-4. 점수를 더해 가장 낮은 점수를 얻는 팀이 우승 

2. 예외
  2-1. 여섯 명의 주자가 참가 못한 팀은 제외
  2-2. 동점의 경우 다섯 번째 주자가 가장 빨리 들어온 팀 우승
  2-3. 여섯 명 보다 많은 선수가 참가하는 팀은 없음
  2-4. 적어도 한 팀은 참가 선수가 여섯
  2-5. 모든 선수는 끝까지 완주
*/