#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map{};
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.count(complement) && map[complement] != i) {
                return {i, map[complement]};
            }
        }

        return {};
    }
};

// Time complexity: O(n)
// Space complexity: O(n)

// --------------------------------------------------------------------------------
// careful of the case where complement == nums[i], need to ensure we are not using the same element twice
// hence the check map[complement] != i
// --------------------------------------------------------------------------------