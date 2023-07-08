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

/*
По литкоду дерево пишется вот так: [ 1, 2, 3, 4, 5, null, null ] (как куча. left = 2 * parentIdx + 1, right = 2 * parentIdx + 2 )
Tree:
        1
    2       3
4     5   
Preorder traversal ( добавляем ноду в результат, идём в left, затем в right ):
[ 1, 2, 4, 5, 3 ]
Inorder traversal ( идём в left, добавляем ноду в результат, затем в right ):
[ 4, 2, 5, 1, 3 ]
Postorder traversal ( идём в left, затем в right, добавляем ноду в результат ):
[ 4, 5, 2, 1, 3 ]
*/

class Solution {
public:
   std::vector<int> res;
    void traverse( TreeNode* node )
    {
        if ( !node )
          return;
        traverse(node->left);
        res.push_back(node->val);
        traverse(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        traverse(root);
        return res;
    }
};
