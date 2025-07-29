// set_mismatch.cpp
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());  // Step 1: Sort the array

        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == ans)
                ans++;  // Missing number tracker
        }

        //  Duplicate detection without map
        int repeat = -1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                repeat = nums[i];
                break;
            }
        }

        return {repeat, ans};
    }
};
