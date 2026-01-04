#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<std::vector<int>> bucket{nums.size() + 1};
        std::vector<int> res{};
        
        if (nums.empty()) return res;

        std::unordered_map<int, int> freq{};
        for (auto n : nums) {
            freq[n]++;
        }
        
        for (auto& [n, f] : freq) {
            bucket[f].push_back(n);
        }

        for (std::size_t i = bucket.size(); i-- > 0;) {
            for (auto n : bucket[i]) {
                res.push_back(n);
                if (res.size() >= k) {
                    return res;
                }
            }
            
        }

        return res;
    }
};