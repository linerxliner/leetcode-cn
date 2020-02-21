// Spot-slope method.
// Time: O(n ^ 2), Space: O(n ^ 2)

class Solution:
    def gcd(self, n, m):
        while m != 0:
            r = n % m
            n = m
            m = r
            
        return n
    
    def maxPoints(self, points: List[List[int]]) -> int:
        point_num = len(points)
        max_points = 0
        
        for i in range(point_num):
            duplicates = 0
            k_counter = collections.Counter()
            
            from_point = points[i]
            for j in range(i + 1, point_num):
                to_point = points[j]
                dx, dy = to_point[0] - from_point[0], to_point[1] - from_point[1]
                
                if dx == dy == 0:
                    duplicates += 1
                else:
                    gcd = self.gcd(dy, dx)
                    k_counter[str(dy // gcd) + '/' + str(dx // gcd)] += 1
            
            max_points = max(max_points, (max(k_counter.values()) if len(k_counter) > 0 else 0) + duplicates + 1)
            
        return max_points
                
