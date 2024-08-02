// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
class Solution
{
	public:
	vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<bool> visited(V, false);
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});

        while (!pq.empty()) {
            int curver = pq.top().second;
            pq.pop();

            if (visited[curver])
                continue;

            visited[curver] = true;

            for (int i = 0; i < adj[curver].size(); i++) {
                int vertex = adj[curver][i][0];
                int distance = adj[curver][i][1];

                if (!visited[vertex] && dist[curver] + distance < dist[vertex]) {
                    dist[vertex] = dist[curver] + distance;
                    pq.push({dist[vertex], vertex});
                }
            }
        }

        return dist;
    }
};
