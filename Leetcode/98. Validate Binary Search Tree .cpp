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
    bool isInRange( TreeNode * node, int64_t leftBracket, int64_t rightBracket )
    {
        return node->val > leftBracket && node->val < rightBracket;
    }
    bool traverse( TreeNode * node, int64_t leftBracket, int64_t rightBracket )
    {
        if ( !node )
          return true;
        if ( !isInRange( node, leftBracket, rightBracket ) )
          return false;
        //Для левой ноды текущая является верхней границой, для правой - нижней
        return traverse( node->left, leftBracket, node->val ) && traverse(  node->right, node->val, rightBracket );
    }
    //Проверяет, является ли дерево Binary Search Tree. 
    //Для этого все элементы слева ноды должны быть меньше, чем значение ноды, а все ноды справа - больше
    bool isValidBST(TreeNode* root) 
    {
        return traverse(root, INT64_MIN, INT64_MAX );
    }
};
