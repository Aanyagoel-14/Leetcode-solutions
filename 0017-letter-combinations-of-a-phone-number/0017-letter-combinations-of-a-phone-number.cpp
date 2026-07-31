class Solution {
public:
     void solve(int i, string& digits, string& current,
               vector<string>& answer, string mapping[]) {
        
        // One letter has been selected for every digit
        if(i == digits.size()) {
            answer.push_back(current);
            return;
        }

        int digit = digits[i] - '0';
        string letters = mapping[digit];

        // Try every letter belonging to the current digit
        for(char ch : letters) {
            current.push_back(ch);

            solve(i + 1, digits, current, answer, mapping);

            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> answer;

        if(digits.empty()) {
            return answer;
        }

        string mapping[10] = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string current;

        solve(0, digits, current, answer, mapping);

        return answer;
    }
};