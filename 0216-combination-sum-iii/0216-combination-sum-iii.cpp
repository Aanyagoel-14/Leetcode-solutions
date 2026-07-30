class Solution {
public:
    void solve(int start, int k, int target,
               vector<int>& current,
               vector<vector<int>>& answer) {

        if(current.size() == k) {
            if(target == 0) {
                answer.push_back(current);
            }
            return;
        }

        for(int num = start; num <= 9; num++) {

            if(num > target) {
                break;
            }

            current.push_back(num);

            solve(num + 1, k, target - num, current, answer);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> answer;
        vector<int> current;

        solve(1, k, n, current, answer);

        return answer; 
    }
};