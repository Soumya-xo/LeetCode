class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        
        priority_queue<array<long long, 2>, vector<array<long long, 2>>, greater<array<long long, 2>>> free_servers;
        for (int i = 0; i < n; ++i) {
            free_servers.push({servers[i], i});
        }
        
        priority_queue<array<long long, 3>, vector<array<long long, 3>>, greater<array<long long, 3>>> busy_servers;
        
        vector<int> ans(m);
        long long current_time = 0;
        
        for (int j = 0; j < m; ++j) {
            current_time = max(current_time, (long long)j);
            
            while (!busy_servers.empty() && busy_servers.top()[0] <= current_time) {
                auto curr = busy_servers.top();
                busy_servers.pop();
                long long weight = curr[1];
                long long idx = curr[2];
                free_servers.push({weight, idx});
            }
            
            if (free_servers.empty()) {
                current_time = busy_servers.top()[0];
                while (!busy_servers.empty() && busy_servers.top()[0] <= current_time) {
                    auto curr = busy_servers.top();
                    busy_servers.pop();
                    long long weight = curr[1];
                    long long idx = curr[2];
                    free_servers.push({weight, idx});
                }
            }
            
            auto server = free_servers.top();
            free_servers.pop();
            long long weight = server[0];
            long long idx = server[1];
            
            ans[j] = idx;
            busy_servers.push({current_time + tasks[j], weight, idx});
        }
        
        return ans;
    }
};