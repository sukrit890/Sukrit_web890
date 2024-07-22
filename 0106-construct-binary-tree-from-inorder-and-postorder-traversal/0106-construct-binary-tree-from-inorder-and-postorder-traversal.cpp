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

/*
Optimized Approach
Time complexity -> O(n) and Space -> O(n)
where:
- n: number of nodes in a binary tree
- is: inorderStart
- ie: inorderEnd
- ps: postorderStart
- pe: postorderEnd
*/
class Solution {
    TreeNode* constructBinaryTree(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, map<int,int> &mpp){
        if(ps>pe || is>ie){
            return nullptr;
        }
        TreeNode* root=new TreeNode(postorder[pe]);
        int inRoot=mpp[postorder[pe]];
        int numsLeft=inRoot-is;

        root->left=constructBinaryTree(inorder,is,inRoot-1,postorder,ps,ps+numsLeft-1,mpp);
        root->right=constructBinaryTree(inorder,inRoot+1,ie,postorder,ps+numsLeft,pe-1,mpp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()){
            return nullptr;
        }
        map<int,int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        
        return constructBinaryTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
    }
};