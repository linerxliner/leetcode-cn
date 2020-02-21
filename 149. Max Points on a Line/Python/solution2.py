// Three point collinear method.
// Time: O(n ^ 3): Space: O(1)

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        if len(points) < 3:
            return len(points)
        
        point_num = len(points)
        max_points = 0
        
        for i in range(point_num):
            point1 = points[i]
            
            duplicates = 0
            for j in range(i + 1, point_num):
                point2 = points[j]

                dx, dy = point2[0] - point1[0], point2[1] - point1[1]
                
                if dx == 0 and dy == 0:
                    duplicates += 1
                    max_points = max(max_points, duplicates + 1)
                else:
                    same_line = 0
                    check_value = point1[0] * dy - point1[1] * dx
                    for k in range(j + 1, point_num):
                        point3 = points[k]
                        if point3[0] * dy - point3[1] * dx == check_value:
                            same_line += 1
                    max_points = max(max_points, same_line + duplicates + 2)
        
        return max_points
                
