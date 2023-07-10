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
    TreeNode * root_{};
    int target{};
    //Один из вариантов решения - пройти все ноды и попробовать найти такую пару, что nodeA->val + nodeB->val = k
    //Time: Nlog(N), т.к. обойти надо всё дерево и за log(N) попробовать найти пару. 
    //Mem: log(N), т.к. дерево - BST. Для 10^4 узлов это 14.
    bool find( int val, TreeNode * self )
    {
        auto cur = root_;
        while ( cur )
        {
            if ( cur->val == val )
              return cur != self;
            cur = val > cur->val? cur->right : cur->left;
        }
        return false;
    }
    bool traverse( TreeNode * node )
    {
        if ( !node )
          return false;
        return find( target - node->val, node ) || traverse(node->left) || traverse(node->right);
    }
    bool findTarget(TreeNode* root, int k) 
    {
        root_ = root;
        target = k;
        return traverse(root);

    }
};
