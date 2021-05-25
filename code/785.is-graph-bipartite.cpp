class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int len = graph.size();
        vector<int> colors(len, 0);
        
        for (int i = 0; i < len; i++) {
            if (colors[i] == 1 or colors[i] == -1) continue;
            queue<int> q;
            q.push(i);
            colors[i] = 1;
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                
                for (int next : graph[curr]) {
                    if (!colors[next]) {
                        colors[next] = -1*colors[curr];
                        q.push(next);
                    }
                    
                    if (colors[next] == colors[curr]) return false;
                }
            }
        }
        
        return true;
    }
};