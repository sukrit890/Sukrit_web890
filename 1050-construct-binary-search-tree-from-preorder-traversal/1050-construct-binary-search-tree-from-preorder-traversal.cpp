/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
           int i=0;
          return Builder(preorder,i,INT_MAX);
    }
    TreeNode* Builder(vector<int>& preorder,int & i,int bound){
            if(i==preorder.size() || preorder[i]>bound) return NULL; //Base condition
            TreeNode* node = new TreeNode(preorder[i++]); // Creating nodes
            node->left = Builder(preorder,i,node->val); // Values to the left are lesser than the node val
            node->right = Builder(preorder,i,bound); //Values to the right are lesser than the previous node val
        return node;
    }
};