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
    int sumTree( TreeNode * node, int sum )
    {
        //Проверка охватывает базовый случай, когда на входе nullptr в виде корня дерева, также избавляет от последующих проверок left и right (если там nullptr, то это не повлияет на результат)
        if ( !node )
          return 0;
        sum = sum * 10 + node->val;
        return isLeaf(node)? sum : sumTree(node->left, sum ) + sumTree(node->right, sum);
    }
    int sumNumbers(TreeNode* root) 
    {
        return sumTree(root,0);
    }
};
