// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
   void letsdo(const vector<vector<int>>& list, vector<bool>& visited, vector<int>& ans, int current) {
    ans.push_back(current);
    visited[current] = true;
    for (int i = 0; i < list[current].size(); i++) {
        int neighbor = list[current][i];
        if (!visited[neighbor]) {
            letsdo(list, visited, ans, neighbor);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<vector<int>> list(V);
    for (int i = 0; i < V; i++) {
        list[i] = adj[i];
    }

    vector<bool> visited(V, false);
    vector<int> ans;
    letsdo(list, visited, ans, 0);
    return ans;
}
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
