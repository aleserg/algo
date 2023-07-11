/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 class Solution
 {
   public:
   TreeNode* lowestCommonAncestor( TreeNode* root, TreeNode* p, TreeNode* q )
   {
     //Если root соответствует любому из узлов, то возвращаем этот узел (т.к. p или q могут быть ответом по условию задачи)
     if ( !root || root == p || root == q )
       return root;
     //Если значения p и q находятся по одну сторону поддерева (то есть слева или справа, то продолжаем поиски)
     if ( p->val > root->val && q->val > root->val )
       return lowestCommonAncestor( root->right, p, q ); //продолжаем поиск вправо
     if ( p->val < root->val && q->val < root->val )
       return lowestCommonAncestor( root->left, p, q );  //продолжаем поиск влево
     return root; //Одна из нод (p или q) находится в левом поддереве, другая в правом. Ответом является текущая нода
   }
 };
