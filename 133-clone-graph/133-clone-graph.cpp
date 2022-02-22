/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        Node* rootNode = new Node(node->val);
        //Queue<old, new>
        queue<pair<Node*, Node*>> q;
        //Map<old, new>
        unordered_map<Node*, Node*> created;
        //Visited OldNode for creating its neighbours
        unordered_set<Node*> visited;
        q.push({node, rootNode});
        created[node] = rootNode;
        visited.insert(node);
        while(!q.empty()) {
            Node* oldNode = q.front().first;
            Node* newNode = q.front().second;
            // cout<<"Removed Node "<<newNode->val<<": ";
            q.pop();
            for(auto oldNodeNeigh: oldNode->neighbors) {
                if(created.find(oldNodeNeigh) == created.end()) {
                    Node* newNodeNeigh = new Node(oldNodeNeigh->val);
                    created[oldNodeNeigh] = newNodeNeigh;
                }
                // cout<<oldNodeNeigh->val<<" -> ";
                newNode->neighbors.push_back(created[oldNodeNeigh]);
                if(visited.find(oldNodeNeigh) == visited.end()) {
                    visited.insert(oldNodeNeigh);
                    q.push({oldNodeNeigh, created[oldNodeNeigh]});
                }
            }
            // cout<<"\n";
        }
        return rootNode;
    }
};