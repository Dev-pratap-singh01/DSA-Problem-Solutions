/*Left Rotate Array by One


0

100
Easy

Given an integer array nums, rotate the array to the left by one.



Note: There is no need to return anything, just modify the given array.


Examples:
Input: nums = [1, 2, 3, 4, 5]

Output: [2, 3, 4, 5, 1]

Explanation: Initially, nums = [1, 2, 3, 4, 5]

Rotating once to left -> nums = [2, 3, 4, 5, 1]

Input: nums = [-1, 0, 3, 6]

Output: [0, 3, 6, -1]

Explanation: Initially, nums = [-1, 0, 3, 6]

Rotating once to left -> nums = [0, 3, 6, -1]

Input: nums = [7, 6, 5, 4]

[5, 6, 4, 7]
[5, 4, 7, 6]
[6, 5, 4, 7]
[4, 7, 6, 5]
*/





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to rotate array to the left by one position
    void rotateArrayByOne(vector<int>& nums) {
        int temp = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            nums[i - 1] = nums[i];
        }
        nums[n - 1] = temp;
    }
};
