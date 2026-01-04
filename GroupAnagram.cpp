#include <string>
#include <unordered_map>
#include <vector>
#include <array>

struct ArrHash {
    std::size_t operator()(array<int, 26> const& a) const noexcept {
        std::size_t h = 0;
        for (int x : a) {
            h ^= std::hash<int>{}(x) + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
        }

        return h;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       
        std::unordered_map<std::array<int, 26>, std::vector<std::string>, ArrHash> m{};

        for (auto& w : strs) {
            std::array<int, 26> wc{0};
            for (auto l : w) {
                int idx = l - 'a';
                wc[idx]++;
            }

            m[wc].push_back(w);
        }

        std::vector<std::vector<std::string>> res{};
        res.reserve(m.size());
        for (auto& [key, group] : m) {
            res.push_back(std::move(group));
        }

        return res;
    }
};

// A special situation.
//
// The type of key std::array<int, 26> that we need for this hashmap requires a custom hash function
// And we can use a HASH COMBINATION LOOP to combine the entire collection of data (26) down to a single identifying 
// number because most hash function including std::hash<int> are designed to handle only one piece of data at a time
//
// First, you need to understand that in order for unordered_map to work with std::array, there are 2 must-haves:
//  1. The hash function with the operator() overloaded (function object or you might be more familiar with FUNCTOR)
//  2. Equality checks, in this case std::array already have that built in so you dont have to worry about it for now
//
// Notes on bit shifting:
// For example: 5 shifts left by n bits: 5 << n is equals to 5 x 2^n
//              5 shifts right by n bits: 5 >> n is equals to 5/2^n (discard decimal values)