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
    int maxDepth(TreeNode* root) 
    {
        return maxDepthRecursive(root);
    }
    int maxDepthRecursive( TreeNode * node )
    {
        //В отличии от minDepth, нужно убедиться лишь в том, что мы дошли до несуществующего узла
        return node? 1 + std::max( maxDepthRecursive(node->left), maxDepthRecursive(node->right) ) : 0;
    }
};
