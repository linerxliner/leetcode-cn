class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int min_idx;
        int current_integral = 0, min_integral = INT_MAX;
        
        for (int i = 0; i < gas.size(); ++i) {
            current_integral += gas[i] - cost[i];
            if (current_integral < min_integral) {
                min_integral = current_integral;
                min_idx = i;
            }
        }
        
        return current_integral >= 0 ? (min_idx + 1) % gas.size() : -1;
    }
};
