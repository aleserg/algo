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
    int maxPath{INT_MIN};
    int maxPathSum(TreeNode* root) 
    {
        findMaxPathSum(root);
        return maxPath;
    }
    int findMaxPathSum(TreeNode* root) 
    {
        if ( !root )
          return 0;
        //Если по какой-то из веток сумма меньше 0, то её отбрасываем
        int left = std::max( findMaxPathSum(root->left), 0 );
        int right = std::max( findMaxPathSum(root->right), 0 );
        int max = root->val + left + right; //Максимальным путем может быть сама нода
        maxPath = std::max( max, maxPath );
        //Вычитаем минимальную из ветвей, чтобы у нас не получилась сумма всего дерева, вместо одного пути
        return max - std::min(left,right);    
    }
};
