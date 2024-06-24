class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dis(n,1e9);
        q.push({0,{src,0}});
        dis[src]=0;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;

            for(auto iter:adj[node]){
                int edgW=iter.second;
                int adjNode=iter.first;
                if(cost + edgW <dis[adjNode] && stops<=k){
                    dis[adjNode]=cost+edgW;
                    q.push({1+stops,{adjNode,cost+edgW}});
                }
            }
        }
        return dis[dst]==1e9?-1:dis[dst];
    }
};