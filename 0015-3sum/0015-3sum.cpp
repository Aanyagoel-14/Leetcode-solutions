class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        // Step 1 : Sort the array
        sort(nums.begin(), nums.end());

        // Fix one element
        for(int i = 0; i < nums.size(); i++) {

            // Skip duplicate fixed elements
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0) {

                    ans.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // Skip duplicate left values
                    while(left < right && nums[left] == nums[left - 1])
                        left++;

                    // Skip duplicate right values
                    while(left < right && nums[right] == nums[right + 1])
                        right--;
                }

                else if(sum < 0) {
                    // Need a bigger sum
                    left++;
                }

                else {
                    // Need a smaller sum
                    right--;
                }
            }
        }

        return ans;
    }
};