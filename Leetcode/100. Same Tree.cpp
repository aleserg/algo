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
    bool isSameTree( TreeNode* left, TreeNode* right ) 
    {
        if ( !left || !right )
          return left == right; //Обе ноды nullptr тоже ОК
        //Сравниваем val и проваливаемся в рекурсию по соответствующим направлениям
        return left->val == right->val && isSameTree(left->right, right->right) && isSameTree(left->left, right->left);
    }
};
