class Solution {
public:
    static bool Comp(string& a, string& b) {
        return a > b;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        string result;
        
        for (auto n: nums) strs.push_back(to_string(n));
        sort(strs.begin(), strs.end(), Comp);
        if (strs[0] == "0") return "0";
        for (auto& s: strs) result += s;
        
        return result;
    }
};
