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
    std::vector<TreeNode*> arr;
    //Идея решения в том, дерево уже сбалансированное, т.е. узлы идут в возрастающем порядке
    //Их нужно сложить в массив, а затем рекурсивно бинарным поиском находить центральную ноду 
    //(смысл дерева в том, что слева и справа от каждой ноды должно быть примерно одинаковое число потомков, что и обеспечивает бинарный поиск)
    TreeNode* balanceBST(TreeNode* root) 
    {
        convertToArrInorder(root);
        return convertToTree( 0, arr.size() - 1 );
    }
    void convertToArrInorder( TreeNode * node )
    {
        if ( !node )
          return;
        convertToArrInorder(node->left);
        arr.push_back(node);
        convertToArrInorder(node->right);
    }
    TreeNode* convertToTree( int left, int right )
    {
        if ( left > right )
          return nullptr;
        int mid = left + (right - left)/2;
        auto midNode = arr[mid];
        midNode->left = convertToTree(left, mid-1);
        midNode->right = convertToTree(mid+1, right);
        return midNode;
    }
};
