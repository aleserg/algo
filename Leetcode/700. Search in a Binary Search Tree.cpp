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
    //Найти узел, равный val в бинарном дереве поиска
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        auto cur = root;
        while ( cur && cur->val != val )
            cur = cur->val > val? cur->left : cur->right;
        return cur;
    }
};
