/* Complexity
 *   Time: O(1)
 *   Space: O(1)
 */

class Solution {
public:
    enum Operator {kAdd, kMul, kSub, kDiv};
    vector<Operator> operators = {kAdd, kMul, kSub, kDiv};

    bool Calculate(vector<double>& nums) {
        if (nums.size() == 1) return abs(24 - nums[0]) < 1e-6;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i != j) {
                    vector<double> new_nums;

                    for (int k = 0; k < nums.size(); ++k) {
                        if (k != i && k != j) new_nums.push_back(nums[k]);
                    }

                    for (auto op: operators) {
                        if ((op == kAdd || op == kMul) && i > j) continue;
                        switch (op) {
                            case kAdd:
                                new_nums.push_back(nums[i] + nums[j]);
                                break;
                            case kMul:
                                new_nums.push_back(nums[i] * nums[j]);
                                break;
                            case kSub:
                                new_nums.push_back(nums[i] - nums[j]);
                                break;
                            case kDiv:
                                if (nums[j] == 0) continue;
                                else new_nums.push_back(nums[i] / double(nums[j]));
                        }
                        if (Calculate(new_nums)) return true;
                        new_nums.pop_back();
                    }
                }
            }
        }

        return false;
    }

    bool judgePoint24(vector<int>& nums) {
        vector<double> new_nums;

        for (auto n: nums) new_nums.push_back(n);

        return Calculate(new_nums);
    }
};
