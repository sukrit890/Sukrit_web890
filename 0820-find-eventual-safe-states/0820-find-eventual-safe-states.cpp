class Solution {
public:


    
 vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int v = graph.size();
        vector<int> indegree(v, 0);
        queue<int> q;
        vector<int> safe_nodes;

        vector<int> revadj[v];

        for(int i = 0;i<v;i++){
            for(auto it : graph[i]){
                revadj[it].push_back(i);
            }
        }

        for (int i = 0; i < v; i++) {
            for (auto it : revadj[i]) {
                indegree[it]++;
            }
        }

        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe_nodes.push_back(node);

            for (auto it : revadj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }     
        }

        sort(safe_nodes.begin() , safe_nodes.end());

        return safe_nodes; 
        

    }
};         