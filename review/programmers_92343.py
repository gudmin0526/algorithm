"""
벽느낌
"""

def dfs(sheep, wolf, visited, info, edges, answer):
    if sheep <= wolf:
        return

    answer[0] = max(answer[0], sheep)
    for e in edges:
        parent = e[0]
        child = e[1]
        if visited[parent] and not visited[child]:
            visited[child] = True
            if info[child] == 0:
                dfs(sheep+1, wolf, visited, info, edges, answer)
            else:
                dfs(sheep, wolf+1, visited, info, edges, answer)
            visited[child] = False


def solution(info, edges):
    visited = [False] * len(info)
    visited[0] = True
    answer = [0]
    dfs(1, 0, visited, info, edges, answer)
    return answer[0]
         

if __name__ == "__main__":
    print(solution([0,0,1,1,1,0,1,0,1,0,1,1], 
                   	[[0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9]]))