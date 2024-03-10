def solution(k, ranges):
    seq = [k]
    while k != 1:
        if k % 2 == 0:
            k = k // 2
        else:
            k = k * 3 + 1
        seq.append(k)
    
    answer = []
    n = len(seq) - 1
    for r in ranges:
        if n + r[1] < r[0]:
            answer.append(-1)
            continue
        s = 0
        for i in range(r[0], n + r[1]):
            s += min(seq[i], seq[i+1])
            s += abs(seq[i] - seq[i+1]) / 2

        answer.append(s)
    return answer

if __name__ == "__main__":
    print(solution(5, [[0,0],[0,-1],[2,-3],[3,-3]]))