/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> graph;
        // using DFS to build adjacency list
        buildGraph(root, graph);
        
        queue<int> q;
        unordered_set<int> visited;
        q.push(target->val);
        visited.insert(target->val);
        // using BFS to find target nodes
        while (!q.empty() && k != 0) {
            int size = q.size();
            while (size != 0) {
                int node = q.front(); q.pop();
                for (int i=0; i<graph[node].size(); i++) {
                    if (visited.find(graph[node][i]) == visited.end()) {
                        q.push(graph[node][i]);
                        visited.insert(graph[node][i]);
                    }
                }
                size--;
            }
            k--;
        }
        
        vector<int> ret;
        while (!q.empty()) {
            ret.push_back(q.front());
            q.pop();
        }
        
        return ret;
    }
    
    void buildGraph(TreeNode* root,  unordered_map<int, vector<int>>& graph) {
        if (root->left != nullptr) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            buildGraph(root->left, graph);
        }
        
        if (root->right != nullptr) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            buildGraph(root->right, graph);
        }
        
        return;
    }
};