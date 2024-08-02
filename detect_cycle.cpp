// https://leetcode.com/problems/course-schedule/description/
class Solution {
public:
    bool detectcycle(vector<vector<int>>& adj, int now, vector<int>& trev) {
    trev[now] = 1;  // Mark the current node as visited (1: visiting, 2: visited)
    for (int i = 0; i < adj[now].size(); i++) {
        int next = adj[now][i];
        if (trev[next] == 1) {
            return true;  // Cycle detected
        } else if (trev[next] == 0) {
            if (detectcycle(adj, next, trev)) {
                return true;  // Cycle detected in the next node
            }
        }
    }
    trev[now] = 2;  // Mark the current node as visited (2: visited)
    return false;   // No cycle detected
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    if (prerequisites.empty()) {
        return true;  // No prerequisites, all courses can be finished
    }

    vector<vector<int>> adj(numCourses);
    for (int i = 0; i < prerequisites.size(); i++) {
        int course = prerequisites[i][0];
        int prerequisite = prerequisites[i][1];
        adj[course].push_back(prerequisite);
    }

    vector<int> trev(numCourses, 0);  // Tracking the visited nodes (0: unvisited, 1: visiting, 2: visited)
    for (int i = 0; i < numCourses; i++) {
        if (trev[i] == 0 && detectcycle(adj, i, trev)) {
            return false;  // Cycle detected, cannot finish all courses
        }
    }
    return true;  // No cycle detected, can finish all courses
}
};
