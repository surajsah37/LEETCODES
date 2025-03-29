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
  void flattenFind(TreeNode* root,vector<TreeNode*>&result){
    if(!root)
    return;
    result.push_back(root);
    flattenFind(root->left,result);
    flattenFind(root->right,result);
  }
    void flatten(TreeNode* root) {
        if(!root)
        return;
        vector<TreeNode*>result;
        flattenFind(root,result);
        for(int i=0;i<result.size()-1;i++){
            result[i]->left=NULL;
            result[i]->right=result[i+1];
        }
    }
};