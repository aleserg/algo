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
    std::vector<string> res;
    //Проверка, что нода является листом, то есть не имеет дочерних узлов
    bool isLeaf( TreeNode * node )
    {
        return !node->left && !node->right;
    }
    //Path копируем при входе в метод, т.к. если метод вызван, то node != nullptr и path в будет изменен в любом случае (исключаем влияние разных поддеревьев на path)
    void traverse( TreeNode * node, std::string path )
    {
        path.append( std::to_string( node->val ) );
        if ( isLeaf(node) )   
            res.push_back(std::move(path));
        else
        {
            //Если сюда попали, то значит одна из нод точно не nullptr, поэтому дописываем ->
            path.append("->");
            if ( node->left )
               traverse( node->left, path );
            if ( node->right )
               traverse( node->right, path );
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        traverse(root, "");
        return res;
    }
};
