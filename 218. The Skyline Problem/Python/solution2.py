// Scans buildings with keeping current max height.
// Time: O(n), Space: O(n)

class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        building_skylines = []
        active_skylines = []
        curr_skyline = 0
        result = []
        
        for l, r, h in buildings:
            building_skylines.append([l, -h, r])
            building_skylines.append([r, 0, 0])
        
        building_skylines.sort()
        
        for l, h, r in building_skylines:
            while len(active_skylines) > 0 and l >= active_skylines[0][1]:
                heapq.heappop(active_skylines)
            if h != 0:
                heapq.heappush(active_skylines, [h, r])
            max_skyline = 0 if len(active_skylines) == 0 else -active_skylines[0][0]
            if curr_skyline != max_skyline:
                result.append([l, max_skyline])
                curr_skyline = max_skyline
        
        return result
                    
