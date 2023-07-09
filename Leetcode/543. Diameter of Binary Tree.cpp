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
    int maxDiameter{0};
    int getDepthAndUpdateDiam( TreeNode* node ) 
    {
        if ( !node )
          return 0;
        int leftDepth = getDepthAndUpdateDiam( node->left );
        int rightDepth = getDepthAndUpdateDiam( node->right );
        //Идея в том, чтобы в каждой ноде обновлять значение диаметра путем сложения глубины left и right
        maxDiameter = std::max( maxDiameter, leftDepth + rightDepth );
        return 1 + std::max( leftDepth, rightDepth ); //Возвращаем глубину, чтобы родительский узел мог обновить maxDiameter
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        getDepthAndUpdateDiam(root);
        return maxDiameter;
    }
};
