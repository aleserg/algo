/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 std::string bPath;  //Путь для числа B
 std::string cPath;  //Путь для числа C
 
 void tryFind( TreeNode * node, int B, int C, std::string & path )
 {
     if ( !node )
       return;
    if ( node->val == B ) { bPath = path; }
    if ( node->val == C ) { cPath = path; }
    path.push_back('l');
    tryFind( node->left, B, C, path );
    path.pop_back();
    path.push_back('r');
    tryFind( node->right, B, C, path );
    path.pop_back();
 }
 
 int getLCA( TreeNode * root )
 {
     int pos = 1;
     int maxPos = std::min( cPath.size(), bPath.size() );
     //В пути хранятся буквы l и r. Как только появится первое различие - это и есть ответ.
     while ( bPath[pos] == cPath[pos] && pos < maxPos )
     {
         //Проходим путь от корня до LCA
         if ( bPath[pos++] == 'l' )
           root = root->left;
         else
           root = root->right;
     }
     return root->val;
 }
 // time: O(n) mem: O(n). Придётся обойти все дерево. В первый раз при поиске нод B и C, второй раз при проходе по общей части пути (если у нас бамбук, то это N даже при точной оценке).
int Solution::lca(TreeNode* A, int B, int C) 
{
    bPath.clear();
    cPath.clear();
    std::string path("b"); //Первый символ нужен только для того, чтобы понимать, есть ли B и C вообще в дереве
    tryFind( A, B, C, path );
    //Здесь проверяем, что B и C присутствуют
    if ( bPath.empty() || cPath.empty() )
      return -1;
    return getLCA(A);
}
