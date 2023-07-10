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
    vector<vector<int>> res;
    std::list<std::pair<TreeNode*,int>> q;
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        q.push_back({root,0});
        while ( !q.empty() )
        {
            auto [node,lvl] = q.front();
            q.pop_front();
            if ( !node )
              continue;
            if ( res.size() == lvl )
               res.push_back({});
            res[lvl].push_back(node->val);
            lvl++;
            q.push_back( { node->left, lvl } );
            q.push_back( {node->right, lvl } );
        }
        //Это единственное отличие от levelOrder. Асимптотика решения никак не поменяется
        std::reverse(res.begin(), res.end());
        return res;
    }
};
