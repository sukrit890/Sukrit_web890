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

    void recurr(TreeNode* root, int vertical, int level, 
        map<int,map<int,multiset<int>>> &nodes){
            if(root){
                nodes[vertical][level].insert({root->val});
                recurr(root->left, vertical-1, level+1, nodes);
                recurr(root->right, vertical+1, level+1, nodes);
            }
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        vector<vector<int>> ans;
        recurr(root,0,0,nodes);
        for(auto i: nodes){
            vector<int> col;
            for(auto j : i.second){
                for(auto k : j.second){
                    col.push_back(k);
                }
            }
            ans.push_back(col);
        } 
        return ans;
    }
};