// Leetcode Problem: Two Sum II - Input Array Is Sorted
// Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Tags: Two Pointers, Binary Search
// Time Complexity: O(n), Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int srt = 0;
        int end = numbers.size() - 1;
        vector<int> ans;

        while (srt < end) {
            int currsum = numbers[srt] + numbers[end];

            if (currsum == target) {
                ans.push_back(srt + 1);  // 1-based indexing
                ans.push_back(end + 1);
                return ans;
            } else if (currsum > target) {
                end--;
            } else {
                srt++;
            }
        }

        return ans;  
    }
};
