//Смысл задачи найти следующий элемент после указанного. 
//Указанный элемент точно присутствует, а вот следующий может быть:
//1) Родителем текущего
//2) Правым потомком
//3) Его может вообще не быть
//Идея решения в том, чтобы обойти дерево наоборот (справа налево). Это позволит не угадывать, существует ли следующий элемент, ведь теперь для нас он предыдущий.
//Решается как inorder, только сначала заходим в правую ноду
BinaryTreeNode<int> *traverse(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node, BinaryTreeNode<int> *& prev )
{
    if ( !root )
      return root;
    auto res = traverse( root->right, node, prev );
    if ( res )
      return res;
    if ( root == node )
      return prev;
    prev = root;
    return traverse( root->left, node, prev );
}

BinaryTreeNode<int> *inorderSuccesor(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node)
{
    BinaryTreeNode<int> * prev = nullptr;
    return traverse(root,node, prev );
}
