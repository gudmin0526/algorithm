"""
최단거리 탐색이므로 bfs를 사용하는 것이 적절하다.
"""

def solution(board):
    board = [list(i) for i in board]
    sx, sy = 0, 0

    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == 'R':
                sx, sy = j, i

    queue = [(sx, sy, 0)]
    visited = [(sx, sy)]
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    while queue:
        x, y, dist = queue.pop(0)
        for i in range(4):
            nx, ny = x, y
            while (0 <= nx + dx[i] < len(board[0]) and 0 <= ny + dy[i] < len(board) and 
                    board[ny + dy[i]][nx + dx[i]] != 'D'):
                nx += dx[i]
                ny += dy[i]                
            if nx == x and ny == y:
                continue
            if board[ny][nx] == 'G':
                return dist + 1
            if (nx, ny) not in visited:
                visited.append((nx, ny))           
                queue.append((nx, ny, dist+1))
    return -1

if __name__ == "__main__":
    print(solution([".D.R", "....", ".G..", "...D"]))