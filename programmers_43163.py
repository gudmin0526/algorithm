"""
가장 짧은 변환 과정을 찾으므로 bfs를 사용하는 것이 적절하다.
"""

def solution(begin, target, words):
    if target not in words:
        return 0
    
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    queue = [(begin, 0)]
    visited = []
    while queue:
        w, cnt = queue.pop(0)
        for i in range(len(target)):
            for j in range(len(alphabet)):
                nw = w[:i] + alphabet[j] + w[i+1:]
                if nw == target:
                    return cnt + 1
                if nw in words and nw not in visited:
                    visited.append(nw)
                    queue.append((nw, cnt+1))
        print(queue)
    return 0

if __name__ == "__main__":
    print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log"]))