/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";
        string result = "";
         
        queue<pair<TreeNode*, string>> q;
        q.push({root, "0"});
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                auto cur = q.front();q.pop();
                result += to_string(cur.first->val) + "|" + cur.second + "!";
                if(cur.first->left != nullptr) q.push({cur.first->left, cur.second+"0"});
                if(cur.first->right != nullptr) q.push({cur.first->right, cur.second+"1"});
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;
        int n = data.length();
        int index = 0;
        unordered_map<string, TreeNode*> hmap;

        TreeNode* result;
        while(index < n) {
            int end = index;
            while(data[end++] != '|' ) {}
            int nodeVal = stoi(data.substr(index, end-index));
            index = end;
            while(data[end++] != '!' ) {}
            string nodeLabel = data.substr(index, end-index-1);
            index = end;
            TreeNode* node = new TreeNode(nodeVal);
            if(nodeLabel != "0") {
                int len = nodeLabel.length();
                if(nodeLabel[len-1] == '0') {
                    hmap[nodeLabel.substr(0, len-1)]->left = node;
                } else {
                    hmap[nodeLabel.substr(0, len-1)]->right = node;
                }
            } else {
                result = node;
            }
            hmap[nodeLabel] = node;
        }

        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));