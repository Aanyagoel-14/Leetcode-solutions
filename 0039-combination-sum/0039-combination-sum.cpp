class Solution {
public:
    void solve(int index, vector<int>& candidates, int target,
               vector<int>& current,
               vector<vector<int>>& answer) {

        if (target == 0) {
            answer.push_back(current);
            return;
        }

        if (index == candidates.size() || target < 0) {
            return;
        }

        // Take the current number
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);

            solve(index, candidates,
                  target - candidates[index],
                  current, answer);

            current.pop_back();
        }

        // Skip the current number
        solve(index + 1, candidates, target, current, answer);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> current;

        solve(0, candidates, target, current, answer);

        return answer;

    }
};