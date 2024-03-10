"""
완전 탐색은 불가능.
그리디도 불가능.      

"""

def solution(triangle):
    answer = 0
    dp = [[0] * i for i in range(1, len(triangle)+1)]
    dp[0][0] = triangle[0][0]
    for i in range(1, len(dp)):
        for j in range(len(dp[i])):
            if j == 0:
                dp[i][j] = dp[i-1][j] + triangle[i][j]
            elif j == len(dp[i]) - 1:
                dp[i][j] = dp[i-1][j-1] + triangle[i][j]
            else:
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]

    return max(dp[len(dp)-1])

if __name__ == "__main__":
    print(solution([[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]))