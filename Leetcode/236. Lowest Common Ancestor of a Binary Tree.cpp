/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        //Если текущая нода является p или q, то возвращаемся, т.к. по условию задачи p и q сами могут быть ответом (т.е. если вторая нода где-то ниже текущей, это не важно, пересечение мы уже нашли)
        if ( !root || root == p || root == q )
          return root;
        auto p1 = lowestCommonAncestor(root->left, p, q);  //Вернет p или q или nullptr
        auto p2 = lowestCommonAncestor(root->right, p, q); //Вернет p или q или nullptr
        if ( p1 && p2 )  //Если обе ноды не nullptr, значит текущая нода и есть их первая общая
          return root;
        return p1? p1 : p2;  //Если хотя бы одна нода nullptr, то возвращаем вторую (даже если она тоже nullptr, это будет значить, что в левом и правом поддереве нет ни p, ни q)
    }
};
