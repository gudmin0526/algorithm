#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> word_lens;
vector<vector<int>> alphabet_count;
int N, answer;

void input() {
    N = answer = 0;
    
    cin >> N;
    alphabet_count.assign(N, vector<int>(26, 0));   
    word_lens.assign(N, 0);
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        word_lens[i] = word.length();
        for (char& c : word) 
            alphabet_count[i][c - 'A']++;
    }
}



void solution() {
    for (int i = 1; i < N; i++) {        
        int count_diff = 0;
        int len_diff = abs(word_lens[0] - word_lens[i]);
        for (int j = 0; j < 26; j++) 
            count_diff += abs(alphabet_count[0][j] - alphabet_count[i][j]);

        // diff == 2, 크기가 같을 때 -> 가능
        //            크기가 1만큼 다를 때 -> ABC ABDD -> 불가능
        // diff == 3, 크기가 같을 때 -> 불가능
        //            크기가 1만큼 다를 때 -> ABC ADDD -> 불가능
        
        if ((count_diff < 2) || 
            (count_diff == 2 && len_diff == 0)) {
                answer++;
            }
    }

    cout << answer << endl;
}

int main() {
	input();
    solution();
}

/*
아이디어:

입력:
(단어의 개수) ~ [1, 1e2]
(각 단어의 길이) ~ [1, 10]

출력:
입력으로 주어진 첫 번째 단어와 비슷한 단어가 몇 개인지 

제약조건:
0. 제약
    0-1. 알파벳 대문자로만 이루어져 있다.

1. 같은 구성 판별
    1-1. 두 개의 단어가 같은 종류의 문자
    1-2. 같은 문자는 같은 개수만큼 존재

2. 비슷한 단어 판별
    2-1. 두 단어가 같은 구성을 갖는 경우
    2-2. 한 단어에서 한 문자를 더하거나, 뺴거나, 바꾸어도 
         같은 구성을 갖게 되는 경우
*/