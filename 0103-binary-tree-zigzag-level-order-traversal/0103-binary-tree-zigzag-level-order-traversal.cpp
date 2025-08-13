
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> result;
         if(root==nullptr) return result;
         queue<TreeNode*>q;
         bool tarack=0;
         q.push(root);
           
         while(!q.empty()){
             int n=q.size();
            vector<int>arr;
            for(int i=0; i<n; i++){
                TreeNode* node=q.front();
                q.pop();
                arr.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(!tarack){
                result.push_back(arr);
                tarack=!tarack;
            }
            else{
                reverse(arr.begin(),arr.end());
                 result.push_back(arr);
                tarack=!tarack;
            }
         }

         return result;

    }
};