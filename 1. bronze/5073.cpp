#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

string input;
stringstream ss;
vector<int> sides(3, 0);

int main() {
	while (1) {
		getline(cin, input, '\n');
		ss.str(input);
		ss >> sides[0] >> sides[1] >> sides[2];
		if (sides[0] == 0) break;

		sort(sides.begin(), sides.end());
		
		if (sides[2] >= sides[1] + sides[0])
			cout << "Invalid" << "\n";
		else if (sides[0] == sides[1] && sides[0] == sides[2])
			cout << "Equilateral" << "\n";
		else if (sides[0] == sides[1] || sides[1] == sides[2] || sides[0] == sides[2])
			cout << "Isosceles" << "\n";
		else
			cout << "Scalene" << "\n";
		
		ss.clear();
	}
}

/*
제약조건
1. 삼각형 정의
 1-1. 세 변의 길이가 모두 같음
 1-2. 두 변의 길이만 같음
 1-3. 세 변의 길이가 모두 다름
 1-4. 가장 긴 변 보다 나머지 두 변의 합이 길지 않음
*/