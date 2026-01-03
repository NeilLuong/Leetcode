#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen{};
        for (auto& num : nums) {
            if (!seen.insert(num).second) {
                return true;
            }
        }
        return false;
    }
};

// Time complexity: O(n)
// Space complexity: O(n)

// --------------------------------------------------------------------------------
// unordered_set should be used here instead of set because unordered_set provides average O(1) time complexity for insertions and lookups,
// while set provides O(log n) time complexity due to its underlying balanced tree structure.
//
// insert() of unordered_set actually returns a pair<iterator, bool>, where the bool indicates whether the insertion took place. 
// So no need to do the traditional find() + insert() approach.
//
// MINOR thought: primitve like int, copying is as fast or faster than moving