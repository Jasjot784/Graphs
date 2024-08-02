// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> ans;
        ans.push_back(0);
        
        queue<int> q;
        q.push(0);
        vector<int> visited(V,0);
        visited[0]=1;
        
        while(!q.empty()){
            int i = q.front();
            q.pop();
            for(int j = 0;j<adj[i].size();j++){
                if(visited[adj[i][j]]==0){
                    ans.push_back(adj[i][j]);
                q.push(adj[i][j]);
                }
                
                visited[adj[i][j]] = 1;
            }
        }
        return ans;
    }
};
