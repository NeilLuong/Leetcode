class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        std::unordered_set<int> seen{};
        for (auto n : nums) {
            seen.insert(n);
        }

        int max = 1;

        for (auto s : seen) {
            if (!seen.contains(s - 1)) {
                int curr = s;
                int length = 1;
                while (seen.contains(curr + 1)) {
                    length++;
                    curr = curr + 1;
                    if (length > max) max = length;
                }
            }
        }

        return max;
    }
};