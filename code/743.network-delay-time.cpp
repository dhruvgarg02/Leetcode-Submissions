typedef pair<int, int> pii;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pii>> g (n+1);
        for (const auto &time : times)
            g[time[0]].emplace_back(time[1], time[2]);
        
        vector<bool> visited (n+1, 0);
        vector<int> distance (n+1, INT_MAX);
        
        distance[0] = 0; distance[k] = 0;
        
        priority_queue <pii, vector<pii>, greater<pii>> pq;
        
        pq.emplace(0, k); // 0 cost to reach K
        
        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            
            if (visited[u]) continue;
            
            for (auto i : g[u]) {
                auto [v, weight] = i;
                if (cost + weight < distance[v]) {
                    distance[v] = cost + weight;
                    pq.emplace (distance[v], v);
                }
            }
            
            visited[u] = 1;
        }
        
        int res = *max_element(distance.begin(), distance.end());
        
        return res == INT_MAX ? -1 : res;
    }
};