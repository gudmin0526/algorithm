"""
100 / 000 000 000 000 000 000 000 000 / 000 000 000 000 000 000 001
200 / 200 000 000 000 000 000 010 010 / 000 000 000 000 000 002 002
300 / 300 300 301 001 100 120 020 020 / 021 001 100 103 003 003 003
400 / 410 412 402 432 432 430 430 034 / 034 234 234 204 214 014 004

100 / 000 000 000 / 000 000 000 001
200 / 200 000 010 / 010 000 002 002
300 / 301 321 320 / 023 123 103 003

3을 완성하는데 7번 = 3+4.
4를 완성하는데 7+8 = 15번.

n이 짝수일 경우 한 칸 이동. 
n이 홀수일 경우 두 칸 이동.

원판의 순서가 바뀐다는 점을 생각해서 풀어보자.
13
12 13 23 
13 12 32 13 21 23 13
12 13 23 12 31 32 12 13 23 21 31 23 12 13 23
n-1을 기준으로 2와 3이 바뀌고 13이 나온다. 그리고 1과 2가 바뀐다.
"""

def solution(n):
    dp = [0] * (n+1)
    dp[1] = 1
    for i in range(2, n+1):
        dp[i] = dp[i-1] * 2 + 1
    
    arr = [[1, 3]]
    for i in range(2, n+1):
        prev = [list(i) for i in arr]
        for j in range(len(prev)):
            if prev[j][0] == 3:
                arr[j][0] = 2
            if prev[j][0] == 2:
                arr[j][0] = 3
            if prev[j][1] == 3:
                arr[j][1] = 2
            if prev[j][1] == 2:
                arr[j][1] = 3   
        arr.append([1, 3])
        arr.extend([list(i) for i in prev])
        for j in range(len(prev)):
            if prev[j][0] == 1:
                arr[len(prev)+j+1][0] = 2
            if prev[j][0] == 2:
                arr[len(prev)+j+1][0] = 1
            if prev[j][1] == 1:
                arr[len(prev)+j+1][1] = 2
            if prev[j][1] == 2:
                arr[len(prev)+j+1][1] = 1 
    return arr

if __name__ == '__main__':
    print(solution(int(input())))

