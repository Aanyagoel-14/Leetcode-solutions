class Solution {
public:
    void solve(int start, int k, int target, vector<int>& current, vector<vector<int>>& answer) {

        if(current.size() == k) {
            if(target == 0) {
                answer.push_back(current);
            }
            return;
        }

        for(int i = start; i <= 9; i++) {
            if(i > target)
                break;

            current.push_back(i);

            // Recursion for next num
            solve(i + 1, k, target - i, current, answer);

            current.pop_back();
        }
        
    }

    vector<vector<int>> combinationSum3(int k, int n) {
         vector<int> current;
         vector<vector<int>> answer;

         solve(1, k, n, current, answer);
         return answer;
    }
};