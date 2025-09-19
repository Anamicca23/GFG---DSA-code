class Solution {
public:
    int minParentheses(string& s) {
        int balance = 0;   // tracks unmatched '('
        int insertions = 0; // tracks unmatched ')'
        
        for(char ch : s) {
            if(ch == '(') {
                balance++;
            } else { // ch == ')'
                if(balance > 0) {
                    balance--;  // match with an existing '('
                } else {
                    insertions++; // need an extra '('
                }
            }
        }
        
        // insertions for extra ')' + balance for extra '('
        return insertions + balance;
    }
};