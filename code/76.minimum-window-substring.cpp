class Solution {
public:
    string minWindow(string s, string t) {
        // unordered_map<char, int> cmap;
        unordered_map<char, int> m;
        int l = 0, r = 0, counter = t.length(), minlen = INT_MAX, minstart = 0;
        
        for(char c : t) {
            m[c]++;
        }
        
        while(r < s.length()) {
            if(m[s[r]] > 0) counter--; 
            m[s[r]]--;
            r++;
            while(counter == 0) {
                if(r-l < minlen) {
                    minlen = r-l;
                    minstart = l;
                }
                m[s[l]]++;
                if(m[s[l]] > 0) counter++;
                l++;
            }
        }
        
        if(minlen == INT_MAX) return "";
        return s.substr(minstart, minlen);
    }
};