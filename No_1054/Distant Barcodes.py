class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        counter = Counter(barcodes)
        
        min_heap = [(-freq, code) for code, freq in counter.items()]
        heapq.heapify(min_heap)
        
        ret = []
        while min_heap:
            freq1, code1 = heapq.heappop(min_heap)
            ret.append(code1)
            freq1 += 1
            if min_heap:
                freq2, code2 = heapq.heappop(min_heap)
                ret.append(code2)
                freq2 += 1
                if freq2:
                    heapq.heappush(min_heap, (freq2, code2))
            
            if freq1:
                heapq.heappush(min_heap, (freq1, code1))
        
        return ret