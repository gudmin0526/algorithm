#if 1
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cmath>
#define LIMIT 1e9

using namespace std;

vector<string> programs;
vector<long> nums;
deque<long> deq;

void printDeque() {
    vector<long> vec(deq.begin(), deq.end());
    for (long i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void executeProgram() {
    for (string cmd : programs) {
        long first_el, second_el;

        // 숫자가 부족해 연산을 수행할 수 없을 때 (empty)
        if (cmd == "POP" || cmd == "INV" || cmd == "DUP") {
            if (deq.empty()) {
                cout << "ERROR" << endl;
                return;
            }
        }

        // 숫자가 부족해 연산을 수행할 수 없을 때 
        if (cmd == "SWP" || cmd == "ADD" || cmd == "SUB" || 
            cmd == "DIV" || cmd == "MUL" || cmd == "MOD") {
            if (deq.size() < 2) {
                cout << "ERROR" << endl;
                return;
            }
            first_el = deq.back();
            deq.pop_back();
            second_el = deq.back();
            deq.pop_back();
        }

        // 0으로 나눴을 때 (DIV/MOD)
        if (cmd == "DIV" || cmd == "MOD") {
            if (first_el == 0) {
                cout << "ERROR" << endl;
                return;
            }
        }

        if (cmd.substr(0, 3) == "NUM") {
            long x = stoi(cmd.substr(4));
            deq.push_back(x);
        } else if (cmd == "POP") {
            deq.pop_back();
        } else if (cmd == "INV") {
            first_el = deq.back();
            deq.pop_back();
            deq.push_back(-first_el);
        } else if (cmd == "DUP") {
            first_el = deq.back();
            deq.push_back(first_el);
        } else if (cmd == "SWP") {
            deq.push_back(first_el);
            deq.push_back(second_el);
        } else if (cmd == "ADD") {
            long add = first_el + second_el;
            // 연산의 절댓값이 1e9을 넘을 때
            if (abs(add) > LIMIT) {
                cout << "ERROR" << endl;
                return;
            }
            deq.push_back(add);
        } else if (cmd == "SUB") {
            long sub = second_el - first_el;
            // 연산의 절댓값이 1e9을 넘을 때
            if (abs(sub) > LIMIT) {
                cout << "ERROR" << endl;
                return;
            }
            deq.push_back(sub);
        } else if (cmd == "MUL") {
            long mul = first_el * second_el;
            // 연산의 절댓값이 1e9을 넘을 때
            if (abs(mul) > LIMIT) {
                cout << "ERROR" << endl;
                return;
            }
            deq.push_back(mul);
        } else if (cmd == "DIV") {
            long abs_div = abs(second_el) / abs(first_el);
            // 피연산자 중 음수가 한 개일때는 몫의 부호 음수, 그 외는 양수
            if (first_el * second_el < 0)
                deq.push_back(-abs_div);
            else
                deq.push_back(abs_div);
        } else if (cmd == "MOD") {
            long abs_mod = abs(second_el) % abs(first_el);
            // 나머지의 부호는 피제수의 부호와 같음
            if (second_el >= 0)
                deq.push_back(abs_mod);
            else
                deq.push_back(-abs_mod);
        }
        #if 0
        cout << cmd << " : ";
        printDeque();
        #endif
    }

    // 스택에 저장되어 있는 숫자가 1개일 때
    if (deq.size() == 1) {
        cout << deq.back() << endl;
        return;
    }

    // 1개가 아닐 때
    cout << "ERROR" << endl;

}

int main() {
    string cmd;
    long N, val;

    while (1) {
        getline(cin, cmd);

        // 프로그램 입력받기
        while (cmd != "END") {
            if (cmd == "QUIT")
                return 0;
            programs.push_back(cmd);
            getline(cin, cmd);
        }

        // 숫자 입력받기
        cin >> N;
        for (long i = 0; i < N; i++) {
            cin >> val;
            nums.push_back(val);
        }
        
        // 각 숫자들에 대해 프로그램 실행
        for (long num : nums) {
            deq.push_back(num);
            executeProgram();
            deq.clear();
        }

        // 빈 줄 출력
        cout << endl;

        // 다음 프로그램을 위해 비우기
        programs.clear();
        nums.clear();
    }
}

#endif