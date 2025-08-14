class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> result;
         if(root==nullptr) return result;
         queue<TreeNode*>q;
         bool leftToright=0;
         q.push(root);

         while(!q.empty()){
             int n=q.size();
            vector<int>level;
            for(int i=0; i<n; i++){
                TreeNode* node=q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(!leftToright){
                result.push_back(level);
                leftToright=!leftToright;
            }
            else{
                reverse(level.begin(),level.end());
                 result.push_back(level);
                leftToright=!leftToright;
            }
         }
         return result;

    }
};