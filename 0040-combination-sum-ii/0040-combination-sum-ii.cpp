class Solution {
public:
    void solve(int index, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& answer) {
        // Base condition
        if(target == 0) {
            answer.push_back(current);
            return;
        }

        // Backtracking condition
        if(index == candidates.size()) {
            return;
        }

        // Taking curr element
        if(candidates[index] <= target) {
            current.push_back(candidates[index]);

            // Recursion
            solve(index + 1, candidates, target - candidates[index], current, answer);

            //Poping the element to go to previous case
            current.pop_back();
        }

        int nextIndex = index + 1;

        while (nextIndex < candidates.size() &&
               candidates[nextIndex] == candidates[index]) {
            nextIndex++;
        }

        // Skip the current number
        solve(nextIndex, candidates, target, current, answer);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> answer;
        vector<int> current;

        solve(0, candidates, target, current, answer);
        return answer;
    }
};