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
    TreeNode* invertTree(TreeNode* root) 
    {
        invertTreeInternal(root);
        return root;
    }

    void invertTreeInternal( TreeNode * node)
    {
        if ( !node )
          return;
        //Используем preorder
        std::swap(node->left, node->right);
        invertTreeInternal(node->left);
        invertTreeInternal(node->right);
    }
};
