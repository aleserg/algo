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
    //Решаем как level-order, только здесь нам не нужно запоминать все пройденные ноды по уровням. Достаточно последнюю встреченную при порядке обхода сначала left, затем right
    vector<int> rightSideView(TreeNode* root) 
    {
        std::vector<int> res;
        std::list<std::pair<TreeNode*, int>> q;
        q.push_back({root,0});
        while ( !q.empty() )
        {
            auto [node,lvl] = q.front();
            q.pop_front();
            if ( !node )
              continue;
            if ( lvl == res.size() )
              res.push_back(node->val); //Если это первая нода на уровне
            else
              res[lvl] = node->val;    //Если на уровне уже были другие ноды
            lvl++;
            q.push_back( { node->left, lvl } );
            q.push_back( { node->right, lvl } );
        }
        return res;
    }
};
