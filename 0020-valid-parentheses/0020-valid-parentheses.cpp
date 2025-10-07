class Solution {
public:
    bool isValid(string s) {
        stack<char> myStk;
        for(char ch : s){
            if(ch == '(' or ch == '{' or ch == '['){
                myStk.push(ch);
            }
            else{
                if(myStk.empty()) return false;
                char top = myStk.top();
                if((ch == ')' and top == '(') or
                    (ch == '}' and top == '{') or
                    (ch == ']' and top == '[')){
                        myStk.pop();
                }
                else{
                    return false;
                }
            }
        }
        return myStk.empty();
    }
};