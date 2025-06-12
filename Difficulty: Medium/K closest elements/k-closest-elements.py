import heapq

class Solution:
    def printKClosest(self, arr, k, x):
        
        kMinHeap = []
        
        for num in reversed(arr):
            if num == x:
                continue
            newHeapItem = (-abs(x - num), num)
            if len(kMinHeap) < k:
                heapq.heappush(kMinHeap, newHeapItem)
            elif newHeapItem > kMinHeap[0]:
                heapq.heapreplace(kMinHeap, newHeapItem)
            #print(kMinHeap)
        
        res = []
        while kMinHeap:
            _ , num = heapq.heappop(kMinHeap)
            res.append(num)
        return reversed(res)

