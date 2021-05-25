class Solution {
    
private:
    string findP(string s, map<string, string>& p) {
        return p[s] == s ? s : findP(p[s], p);
    }
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map <string, string> owner;
        map <string, string> parents;
        map <string, set<string>> unions;
        
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                parents[accounts[i][j]] = accounts[i][j];
                owner[accounts[i][j]] = accounts[i][0];
            }
        }
        
        for (int i = 0; i < accounts.size(); i++) {
            string p = findP(accounts[i][1], parents);
            for (int j = 2; j < accounts[i].size(); j++)
                parents[findP(accounts[i][j], parents)] = p;
        }
        
        for (auto ele : parents) {
            cout<<ele.first<<"\t"<<ele.second<<"\n";
        }
        
        for (int i = 0; i < accounts.size(); i++) 
            for (int j = 1; j < accounts[i].size(); j++)
                unions[findP(accounts[i][j], parents)].insert(accounts[i][j]);
        
        vector<vector<string>> res;
        for (auto i : unions) {
            vector<string> temp (i.second.begin(), i.second.end());
            temp.insert(temp.begin(), owner[i.first]);
            res.emplace_back(temp);
        }
            
        return res;
    }
};