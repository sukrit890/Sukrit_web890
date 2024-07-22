/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Optimized Approach
// Time Complexity: O(n) and Space Complexity: O(n)

 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // Check if the tree is empty
        if(root==nullptr){
            return "";
        }
        // Initialize an empty string to store the serialized data
        string s="";
        // Use a queue for level-order traversal
        queue<TreeNode*> q;
        // Start with the root node
        q.push(root);

        // Perform level-order traversal
        while(!q.empty()){
            // Get the front node in the queue
            TreeNode*  currNode=q.front();
            q.pop();
            // Check if the current node is null and append "#" to the string
            if(currNode==nullptr){
                s.append("#,");
            }else{
                // Append the value of the current node to the string
                s.append(to_string(currNode->val) + ",");
            }
            if(currNode!=nullptr){
                // Push the left and right children to the queue for further traversal
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // Check if the serialized data is empty
        if(data.size()==0){
            return nullptr;
        }

        // Use a stringstream to tokenize the serialized data
        stringstream s(data);
        string str;

        // Read the root value from the serialized data
        getline(s, str, ',');
        TreeNode *root=new TreeNode(stoi(str));
        // Use a queue for level-order traversal
        queue<TreeNode*> q;
        // Start with the root node
        q.push(root);

        // Perform level-order traversal to reconstruct the tree
        while(!q.empty()){
            // Get the front node in the queue
            TreeNode *currNode=q.front();
            q.pop();

            // Read the value of the left child from the serialized data
            getline(s, str, ',');
            if(str == "#"){
                currNode->left=nullptr;
            }
            else{
                TreeNode *leftNode=new TreeNode(stoi(str));
                currNode->left=leftNode;
                q.push(leftNode);
            }

            // Read the value of the right child from the serialized data
            getline(s, str, ',');
            if(str=="#"){
                currNode->right=nullptr;
            }
            else{
                TreeNode *rightNode=new TreeNode(stoi(str));
                currNode->right=rightNode;
                q.push(rightNode);
            }
        }
        // Return the reconstructed root of the tree
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));