class Solution {
public:
    void solve(int index, string& num, long long target,
               string expression, long long value,
               long long previous, vector<string>& answer) {

        // All digits have been used
        if (index == num.size()) {
            if (value == target) {
                answer.push_back(expression);
            }
            return;
        }

        long long currentNumber = 0;
        string currentString = "";

        // Try numbers of different lengths
        for (int i = index; i < num.size(); i++) {

            // Numbers such as 05 and 00 are not allowed
            if (i > index && num[index] == '0') {
                break;
            }

            currentNumber = currentNumber * 10 + (num[i] - '0');
            currentString += num[i];

            // First number does not need an operator
            if (index == 0) {
                solve(i + 1, num, target,
                      currentString, currentNumber,
                      currentNumber, answer);
            }
            else {
                // Add current number
                solve(i + 1, num, target,
                      expression + "+" + currentString,
                      value + currentNumber,
                      currentNumber, answer);

                // Subtract current number
                solve(i + 1, num, target,
                      expression + "-" + currentString,
                      value - currentNumber,
                      -currentNumber, answer);

                // Multiply with the previous operand
                solve(i + 1, num, target,
                      expression + "*" + currentString,
                      value - previous + previous * currentNumber,
                      previous * currentNumber, answer);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> answer;

        solve(0, num, target, "", 0, 0, answer);

        return answer;
    }
};