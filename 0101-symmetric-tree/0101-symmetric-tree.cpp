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

 bool isSymmetric(TreeNode* root) {
    // when tree is empty mean it is symmetric
    if(root==NULL) return true;
    // creating the queue
    queue<TreeNode*>q;
    // push the left and right children into the queue
    q.push(root->left);
    q.push(root->right);
    while(!q.empty()){
        // Get the first node from the queue
        TreeNode*t1=q.front();
        q.pop(); // Remove it from the queue

        // get the second node from the queue
        TreeNode*t2=q.front();
        q.pop();  //remove this from the queue
        if(!t1 && !t2) continue;  // when both the tree ar null continue checking
        // if one is null and another is not than
        if (!t1 || !t2 || t1->val != t2->val) return false;
        // Push corresponding child nodes in mirrored order for checking symmetry
        q.push(t1->left);  
        q.push(t2->right);  
        q.push(t1->right); 
        q.push(t2->left);  
    }
    return true; // If a
    }
 };








/*
  // brute force
  bool isMirror(TreeNode*t1,TreeNode*t2){
    if(t1==NULL &&t2==NULL)
    return true;;
    if(t1==NULL || t2==NULL)
    return false;
    // checking if current node has same values
    return(t1->left==t2->right)&&
     isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
  }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        return true;
        return isMirror(root->left,root->right);
    }
    */