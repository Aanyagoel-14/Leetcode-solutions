class Solution {
public:
    void solve(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& answer) {
        if(index == nums.size()) {
            answer.push_back(current);
            return;
        }

        // Take the current element
        current.push_back(nums[index]);
        solve(index + 1, nums, current, answer);

        // Backtrack
        current.pop_back();

        // Skip all duplicates
        int nextIndex = index + 1;

        while(nextIndex < nums.size() && nums[nextIndex] == nums[index]) {
            nextIndex++;
        }

        // Skip the element
        solve(nextIndex, nums, current, answer);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> current;
        vector<vector<int>> answer;

        solve(0, nums, current, answer);
        return answer;


    }
};