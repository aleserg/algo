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
    bool isBal = true;
    bool isBalanced(TreeNode* root) 
    {
        findDepth(root, 0);
        return isBal;
    }
    int findDepth( TreeNode* node, int prevDepth )
    {
        if ( !node )
           return prevDepth;
        prevDepth++;
        int left = findDepth(node->left, prevDepth );
        int right = findDepth(node->right, prevDepth );
        if ( abs(left - right) <= 1)
           return std::max( left, right );
        isBal = false;
        return 0;
    }

};
