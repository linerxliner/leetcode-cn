const int kPM[] = {-1, 1};

class Solution {
public:
    struct Hash {
        int len;
        vector<int> keys, values;
        
        Hash (int N) {
            len = N * N * 4 + 3;
            keys = vector<int>(len);
            values = vector<int>(len, 0);
        }
        
        int Probe(int n) {
            int idx = (n % len + len) % len;
            
            for (int b = 0; b < len; ++b) {
                for (int i = 0; i < 2; ++i) {
                    int t = (b % len);
                    
                    idx = (idx + kPM[i] * t * t) % len;
                    if (idx < 0) idx = (idx + len) % len;
                    if (keys[idx] == n || values[idx] == 0) return idx;
                }
            }
            
            return -1;
        }
        
        void Incr(int n) {
            int idx = Probe(n);

            if (values[idx] == 0) keys[idx] = n;
            ++values[idx];
        }

        int Get(int n) {
            int idx = Probe(n);

            if (keys[idx] == n && values[idx] > 0) return values[idx];
            else return 0;
        }
    };
    
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int cnt = 0, tmp;
        Hash hash(A.size());
        
        for (auto& i: A) {
            for (auto& j: B) {
                hash.Incr(i + j);
            }
        }
        
        for (auto& i: C) {
            for (auto& j: D) {
                if ((tmp = hash.Get(-(i + j))) > 0) cnt += tmp;
            }
        }
        
        return cnt;
    }
};
