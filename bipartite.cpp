// https://leetcode.com/problems/is-graph-bipartite/
class Solution {
public:
    void doColor(vector<vector<int>>& graph,int v,vector<int> &color,vector<bool> &visited){
        queue<int> q;
        q.push(v);
        visited[v] = true;
        color[v] = 1;

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            int cuccol = color[cur];
;           
            for(int i = 0;i<graph[cur].size();i++){
                if(!visited[graph[cur][i]]){
                    visited[graph[cur][i]] = true;
                    if(cuccol==1)color[graph[cur][i]]=2;
                    else color[graph[cur][i]]=1;  
                    q.push(graph[cur][i]);
                }
            }
        }return;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<bool> visited(v,false);
        vector<int> color(v);
       

        for(int i = 0;i<v;i++){
            if(!visited[i])
            doColor(graph,i,color,visited);
        }

        for(int i = 0;i<graph.size();i++){
            for(int j = 0;j<graph[i].size();j++){
                if(color[i]==color[graph[i][j]])return false;
            }
        }
        return true;

    }
};
