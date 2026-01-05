class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalExpt0{1};
        int count{0};
        int idx{0};
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
                idx = i;
            }
        }
        if(count >= 2) {return std::vector<int>(nums.size(), 0);}
        if(count == 1) {
            for (int i = 0; i < nums.size(); i++) {
                if (i != idx) {
                    totalExpt0 *= nums[i];
                }
            }

            std::vector<int> v = std::vector<int>(nums.size(), 0);
            v[idx] = totalExpt0;

            return v;
        }

      int total{1};

        for (int i = 0; i < nums.size(); i++) {
                total *= nums[i];
        }
        std::vector<int> finalV = std::vector<int>(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            finalV[i] = total / nums[i];
        }

        return finalV;
        
    } 
};
