// DFS.
// Time: O(v + e); Space: O(v)

class Solution:
    UNDISCOVERED = 0
    DISCOVERED = 1
    VISITED = 2
    
    def build_graph(self, course_num, prerequisites):
        self.adj = [[] for _ in range(course_num)]
        
        for p in prerequisites:
            self.adj[p[1]].append(p[0])
        
        self.state = [self.UNDISCOVERED] * course_num
    
    def DFS(self, u):
        self.state[u] = self.DISCOVERED
        
        for v in self.adj[u]:
            if self.state[v] == self.UNDISCOVERED:
                if not self.DFS(v):
                    return False
            elif self.state[v] == self.DISCOVERED:
                return False
            
        self.state[u] = self.VISITED
        
        return True
        
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        self.build_graph(numCourses, prerequisites)
        
        for u in range(numCourses):
            if self.state[u] == self.UNDISCOVERED and not self.DFS(u):
                return False
        
        return True

