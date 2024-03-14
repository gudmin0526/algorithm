def solution(n, edge):
    graph = [[] for _ in range(n+1)]
    for e in edge:
        graph[e[0]].append(e[1])
        graph[e[1]].append(e[0])

    queue = [(1, 1)]
    answer = [0] * (n+1)
    answer[1] = 1
    while queue:
        x, dist = queue.pop(0)
        for v in graph[x]:
            if answer[v] == 0:
                queue.append((v, dist+1))
                answer[v] = dist+1
    return answer.count(max(answer))


if __name__ == "__main__":
    print(solution(6, [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]))