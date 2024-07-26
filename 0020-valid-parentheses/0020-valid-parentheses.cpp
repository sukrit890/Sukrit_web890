class Solution {
public:
    bool isValid(string s) {
        stack<char>gg;
        for(auto ch: s){
            if(ch== '(' ||ch== '[' ||ch== '{' ){
                gg.push(ch);
            }
            else{
                if (gg.empty() ||(ch == ')' && gg.top() != '(') ||  (ch == '}' && gg.top() != '{') ||(ch == ']' && gg.top() != '[')) {
                    return false; }
                gg.pop();  }
        }
        return gg.empty();}
};