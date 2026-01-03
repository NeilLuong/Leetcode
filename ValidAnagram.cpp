#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> count{};
        for (auto c : s) {
            count[c]++;
        }

        for (auto c : t) {
            count[c]--;
        }

        for (auto& [key, freq] : count) {
            if (freq != 0) {
                return false;
            }
        }

        return true;
    }
};

// Time complexity: O(n)
// Space complexity O(1)

// --------------------------------------------------------------------------------
// unordered_map is used here to count character frequencies because it provides average O(1) time
// complexity for insertions and lookups, making it efficient for this purpose.
//
// auto& when iterating over learge objects to improve performance by avoiding unnecessary copies.
// -------------------------------------------------------------------------------