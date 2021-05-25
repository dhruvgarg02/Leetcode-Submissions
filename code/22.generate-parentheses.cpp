class Solution {
private:
    void recursion(int open, int close, string& s, vector<string>& res) {
        if (!open and !close){
            res.emplace_back(s);
            return;
        } 
        
        if (open) {
            string s1 = s;
            s1.push_back('(');
            recursion(open-1, close, s1, res);
        }
        
        if (close > open) {
            string s2 = s;
            s2.push_back(')');
            recursion(open, close-1, s2, res);
        }
        
        return;
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int open = n, close = n;
        string s;
        recursion(open, close, s, res);
        return res;
    }
};