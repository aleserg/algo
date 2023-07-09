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
    std::vector<int> path;             //Путь, чтобы не прокидывать в виде ссылки по стеку
    std::vector<std::vector<int>> res; //Возвращаемое значение
    bool isLeaf( TreeNode * node )
    {
        return !node->left && !node->right;
    }
    void pathSum( TreeNode * node, int targetSum, int curSum )
    {
        if ( !node )
          return;
        curSum += node->val;
        path.push_back(node->val);
        if ( isLeaf(node) )
        {
            //Если текущая нода - лист, проверим на соответствие условию
            if ( curSum == targetSum )
              res.push_back(path);
        }
        else
        {
            pathSum( node->left, targetSum, curSum );
            pathSum( node->right, targetSum, curSum );
        }
        path.pop_back(); //Вне зависимости от того, добавлен ли путь в результат, необходимо убрать текущее значение из пути
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        pathSum( root, targetSum, 0 );
        return res;
    }
};
