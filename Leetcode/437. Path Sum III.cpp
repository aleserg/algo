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
    /*   
    Идея решения в том, чтобы на каждом шаге строить префиксный массив и заносить его в мапу.
    Затем по формуле curSum - target (по сути поиск требуемой суммы в префиксном массиве) доставать нужное количество совпадающих сумм
    { 0, 1 } здесь для того, чтобы обрабатывать случаи, когда нужна сумма собирается от рута до последней ноды:
     Дерево:
       1
      2 3
     4 
     target = 7
     curSum = 7 (в ноде со значением 4)
     curSum - target = 0 ( подходит, но в мапе просто нету ноды с суммой 0, поэтому мы её добавим изначально)    
    */
    std::unordered_map<int64_t,int> pathList{ { 0, 1 } }; //Здесь будут храниться префиксные суммы всех узлов по ветке от рута до текущей ноды
    int count{};
    void pathSum( TreeNode* node, int targetSum, int64_t curSum )
    {
        if ( !node )
          return;
        curSum += (int64_t)node->val;
        auto it = pathList.find( curSum - targetSum );
        if ( it != pathList.end() )
           count += it->second; 
        pathList[curSum]++;   
        pathSum( node->left, targetSum, curSum );
        pathSum( node->right, targetSum, curSum );
        pathList[curSum]--;  //Обязательно убираем, т.к. путь должен быть "прямой". От вышестоящей ноды до любой нижестоящей. Нельзя строить путь из разных поддеревьев
    }
    int pathSum(TreeNode* root, int targetSum) 
    {
        pathSum( root, targetSum, 0 );
        return count;
    }
};
