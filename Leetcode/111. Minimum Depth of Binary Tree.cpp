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
        return node->left || node->right;
    }
    //Идея поиска минимальной глубины дерева в том, чтобы проверять на отсутствие дочерних узлов и возвращать текущую глубину. 
    //Распространенная ошибка: проверять сразу при входе в метод на nullptr и возвращать depth. Не сработает, т.к. в этом случае у нас нет гарантии, что родительский узел - лист.
    int minDepth( TreeNode * node, int depth )
    {
        depth++;
        if ( !isLeaf(node) )
          return depth;
        return std::min( node->left? minDepth( node->left, depth ) : INT_MAX, node->right? minDepth( node->right, depth ) : INT_MAX );        
    }
    int minDepth(TreeNode* root) 
    {
        return root? minDepth(root,0) : 0;
    }
};
