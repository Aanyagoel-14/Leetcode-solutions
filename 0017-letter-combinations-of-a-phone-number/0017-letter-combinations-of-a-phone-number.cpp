class Solution {
public:
    void solve(int i, string& digits, string& current, vector<string>& answer, string mapping[]) {
        // Base condition
        if(i == digits.size()){
            answer.push_back(current);
            return;
        }

        // Map the digits
        // Convert char to integer
        int digit = digits[i] - '0';
        string letters = mapping[digit];

        for(char ch : letters) {
            current.push_back(ch);

            // Recusrion for next element
            solve(i + 1, digits, current, answer, mapping);

            // Backtacking
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string current;
        vector<string> answer;

        if(digits.empty()){ 
            return answer; 
        }

        string mapping[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" }; 

        solve(0, digits, current, answer, mapping);
        return answer;
    }
};