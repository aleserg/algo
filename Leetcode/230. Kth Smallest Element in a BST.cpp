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
  int idxFromBegin{ 1 };
  int val{ -1 };
  //Идея решения в том, чтобы пройтись inorder по всему дереву, прибавляя по 1 за каждый пройденный узел
  int traverse( TreeNode* node, int k )
  {
    if ( !node || val != -1 )
      return val;
    val = traverse( node->left, k );
    //Проверка на то, что нашли искомый узел. По сути это:
    // if ( idxFromBegin == k ) val = node->val; 
    // idxFromBegin++;
    val = idxFromBegin++ == k ? node->val : val;
    val = traverse( node->right, k );
    return val;
  }
  int kthSmallest( TreeNode* root, int k )
  {
    return traverse( root, k );
  }
};
