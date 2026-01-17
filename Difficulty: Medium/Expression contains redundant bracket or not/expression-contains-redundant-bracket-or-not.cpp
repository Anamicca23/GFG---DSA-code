class Solution {
  public:
    bool isOperator(char c){
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }
    
    bool checkRedundancy(string &s) {
        stack<char>st;
        
        for(char c : s){
            
            if(c == '(' || isOperator(c)){
                st.push(c);
            }else if(c == ')'){
                if(st.top() == '('){
                    return true;
                }else{
                    while(!st.empty() && st.top() != '('){
                        st.pop();
                    }
                    st.pop();
                }
            }
            
        }
        
        return false;
    }
};