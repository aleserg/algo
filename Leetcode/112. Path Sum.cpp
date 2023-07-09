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
    bool isLeaf( TreeNode * node )
    {
      return !node->left && !node->right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        return hasSum(root, targetSum,0);
    }
    bool hasSum( TreeNode* root, int targetSum, int prevSum )
    {
        if ( !root )
          return false;
        prevSum += root->val;
        if ( isLeaf(root) )   //Пока не встретим лист суммируем значения во всех нодах
          return prevSum == targetSum;
        return hasSum(root->right, targetSum, prevSum) || hasSum(root->left, targetSum, prevSum);
    }
};
