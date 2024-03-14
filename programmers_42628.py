import heapq

def solution(operations):
    min_heap = []
    max_heap = []
    operations = [op.split() for op in operations]
    for op in operations:
        if op[0] == "I":
            heapq.heappush(min_heap, int(op[1]))
            heapq.heappush(max_heap, -int(op[1])) 
        elif min_heap:
            if op[1] == "1":
                heapq.heappop(max_heap)
                min_heap = [-i for i in max_heap]
                heapq.heapify(min_heap)
            else:
                heapq.heappop(min_heap)
                max_heap = [-i for i in min_heap]
                heapq.heapify(max_heap)
    
    if not min_heap:
        return [0, 0]
    return [-heapq.heappop(max_heap), heapq.heappop(min_heap)]

if __name__ == "__main__":
    print(solution(["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]))