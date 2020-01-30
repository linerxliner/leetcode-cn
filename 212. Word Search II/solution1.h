const int kLetterNum = 26;
const int kDRow[] = {-1, 0, 1, 0}, kDColumn[] = {0, 1, 0, -1};

class Solution {
public:
    struct TrieNode {
        bool is_end = false, is_visited = false;
        TrieNode *succ[kLetterNum];
        
        TrieNode() {
            memset(succ, NULL, sizeof(succ));
        }
    } root;
    
    vector<string> results;
    string solution;
    
    void Insert(string& word) {
        TrieNode * curr = & root;
        
        for (auto c: word) {
            if (curr->succ[c - 'a'] == NULL) curr->succ[c - 'a'] = new TrieNode;
            curr = curr->succ[c - 'a'];
        }
        
        curr->is_end = true;
    }
    
    void DFS(vector<vector<char>>& board, int row, int column, vector<vector<bool>>& visited, TrieNode *curr) {
        if (curr == NULL) return;
        else {
            visited[row][column] = true;
            solution += board[row][column];
        }
        if (curr->is_end && !curr->is_visited) {
            curr->is_visited = true;
            results.push_back(solution);
        }
        
        for (int i = 0; i < 4; ++i) {
            int new_row = row + kDRow[i], new_column = column + kDColumn[i];
            
            if (new_row >= 0 && new_row < board.size() && new_column >= 0 && new_column < board[0].size() && !visited[new_row][new_column])
                DFS(board, new_row, new_column, visited, curr->succ[board[new_row][new_column] - 'a']);
        }
        
        solution.erase(solution.size() - 1, 1);
        visited[row][column] = false;
    }
    
    void Search(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        
        for (int row = 0; row < board.size(); ++row) {
            for (int column = 0; column < board[0].size(); ++column) {
                DFS(board, row, column, visited, root.succ[board[row][column] - 'a']);
            }
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto& w: words) Insert(w);
        Search(board);
        
        return results;
    }
};
