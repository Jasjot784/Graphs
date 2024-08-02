// https://leetcode.com/problems/clone-graph/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
        return nullptr;
    }

    unordered_map<Node*, Node*> cloned;  // Map to store original node to cloned node mapping
    queue<Node*> q;
    q.push(node);

    Node* root = new Node(node->val);
    cloned[node] = root;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        for (Node* neighbor : curr->neighbors) {
            // If the neighbor node is not cloned yet, create a new cloned node and add it to the queue
            if (cloned.find(neighbor) == cloned.end()) {
                Node* clonedNeighbor = new Node(neighbor->val);
                cloned[curr]->neighbors.push_back(clonedNeighbor);
                cloned[neighbor] = clonedNeighbor;
                q.push(neighbor);
            }
            // If the neighbor node is already cloned, simply add it to the cloned node's neighbors
            else {
                cloned[curr]->neighbors.push_back(cloned[neighbor]);
            }
        }
    }

    return root;

       
    }
};
