#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int T;

vector<int> dates = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    cin >> T;
    vector<int> inputs(10, 0); 
    for (int tc = 0; tc < T; tc++) {
        int i = 0, acc = 366;
        for (i = 0; i < 10; i++)
            cin >> inputs[i];
        
        for (int m = 1; m <= 12; m++) {

            string month = to_string(m);
            for (i = 0; i < 10; i++) {
                if (inputs[i] == 1 && month.find(to_string(i)) != string::npos) {
                    acc -= dates[m];
                    break;
                }
            }    
            if (i < 10)
                continue;  

            for (int d = 1; d <= dates[m]; d++) {

                string date = to_string(d);
                for (i = 0; i < 10; i++) {
                    if (inputs[i] == 1 && date.find(to_string(i)) != string::npos) {
                        acc--;
                        break;
                    }
                } 
            }
        }

        cout << acc << "\n";
    }

    return 0;
}