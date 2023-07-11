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
 class Solution
 {
 public:
   TreeNode* mergeTrees( TreeNode* node1, TreeNode* node2 )
   {
     if ( !node1 || !node2 )
       return std::max( node1, node2 ); //Если какой-то ноды нет, то возвращаем существующую (либо nullptr, если нет обеих)
     //Если обе ноды есть, то собираем всё в первую (можно и во вторую, это не принципиально)
     node1->val += node2->val;
     node1->left = mergeTrees( node1->left, node2->left );
     node1->right = mergeTrees( node1->right, node2->right );
     return node1;
   }
 };
