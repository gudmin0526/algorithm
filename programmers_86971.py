"""
n이 100 이하이므로 완전탐색을 시도해볼 수 있다.
"""

def dfs(graph, visited, v, cnt):
    for i in graph[v]:
        if not visited[i]:
            visited[i] = True
            cnt = dfs(graph, visited, i, cnt + 1)
    return cnt
    

def solution(n, wires):
    graph = [[] for _ in range(n+1)]
    for i in wires:
        graph[i[0]].append(i[1])
        graph[i[1]].append(i[0])
    
    answer = []
    for i in wires:
        visited = [False] * (n+1)
        visited[0] = True

        graph[i[0]].remove(i[1])
        graph[i[1]].remove(i[0])
        temp = []
        for j in range(1, n+1):
            if not visited[j]:
                visited[j] = True
                temp.append(dfs(graph, visited, j, 1))
        
        answer.append(abs(temp[0]-temp[1]))

        graph[i[0]].append(i[1])
        graph[i[1]].append(i[0])
    
    return min(answer)
    
if __name__ == "__main__":
    print(solution(9, [[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]]))