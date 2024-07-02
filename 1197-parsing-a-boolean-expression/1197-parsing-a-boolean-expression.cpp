class Solution {
public:
    // Overall, the solution is O(N)

    pair<bool, int> f(string& s, int i, char curr) { // returns value of expression and index of its ending
        int b;
        if(s[0]=='t') b = true;
        else if(s[0]=='f') b = false;
        else b = -1; // decide value of b later
        
        while(true) {
            char ch = s[i];
            if(ch==',') {
                i++;
                continue;
            }

            if(ch == 't') {
                if(b==-1) b = true;
                else if(curr == '|') b = b || true;
                else if(curr == '&') b = b && true;
                i++;
            }
            else if(ch == 'f'){
                if(b==-1) b = false;
                else if(curr == '|') b = b || false;
                else if(curr == '&') b = b && false;
                i++;
            }
            else if(ch == ')'){ // current expression ends here (dont worry about ')' present in some f() in between, we have evaluated them all in recursive calls)
                if(curr == '!') return {!b,i};
                return {b,i};
            }
            else { // this is a symbol, so a new expression begins
                pair<bool, int> bb;
                bb = f(s, i+2, s[i]); // i+2 is the first index of new expression after '('

                if(b==-1) b = bb.first;
                else if(curr=='&') b = b && bb.first;
                else if(curr=='|') b = b || bb.first;
                
                i = bb.second+1; // update i to one index after the above expression ended
            }

        }

        cout<<"This should not execute"<<endl;
        return {0,0}; // dummy return statement
    }

    bool parseBoolExpr(string expression) {
        if(expression[0]=='f') return false;
        else if(expression[0]=='t') return true;

        char curr = expression[0];
        return f(expression, 2, curr).first; // string, starting index after '(', current symbol
    }
};