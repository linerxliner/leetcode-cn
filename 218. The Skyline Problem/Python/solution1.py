// Divide and conquer.
// Time: O(nlogn), Space: O(n)

class Solution:
    def output(self, result, x, curr_skyline):
        if len(result) == 0 or result[-1][0] != x:
            result.append([x, curr_skyline])
        else:
            result[-1][1] = curr_skyline
    
    def append_residue(self, result, skylines, prev_skyline):
        for x, curr_skyline in skylines:
            if prev_skyline != curr_skyline:
                self.output(result, x, curr_skyline)
                prev_skyline = curr_skyline
        
    def merge(self, left_skylines, right_skylines):
        result = []
        prev_skyline = left_skyline = right_skyline = 0
        left_len, right_len = len(left_skylines), len(right_skylines)
        left_idx = right_idx = 0
        
        while left_idx < left_len and right_idx < right_len:
            if left_skylines[left_idx][0] < right_skylines[right_idx][0]:
                x, left_skyline = left_skylines[left_idx]
                left_idx += 1
            else:
                x, right_skyline = right_skylines[right_idx]
                right_idx += 1
            
            curr_skyline = max(left_skyline, right_skyline)
            
            if prev_skyline != curr_skyline:
                self.output(result, x, curr_skyline)
                prev_skyline = curr_skyline
        
        self.append_residue(result, left_skylines[left_idx:], prev_skyline)
        self.append_residue(result, right_skylines[right_idx:], prev_skyline)
        
        return result
        
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        building_num = len(buildings)
        
        if building_num == 0:
            return []
        elif building_num == 1:
            return [[buildings[0][0], buildings[0][2]], [buildings[0][1], 0]]
        
        left_skylines = self.getSkyline(buildings[:building_num // 2])
        right_skylines = self.getSkyline(buildings[building_num // 2:])
        
        return self.merge(left_skylines, right_skylines)
                    
