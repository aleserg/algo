#include <bits/stdc++.h> 
/*************************************************************
    Following is the Binary Search Tree node structure

    class BinaryTreeNode {

      public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {

            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************
void findClosestElement( BinaryTreeNode<int>* node, int k, int & closest )
{
    if ( !node )
      return;
    auto curDiff = std::abs( node->data - k );
    auto oldDiff = std::abs( closest - k );
    if ( curDiff < oldDiff || curDiff == oldDiff && node->data < closest )
      closest = node->data;
    if ( k < node->data )
      findClosestElement( node->left, k, closest );
    else
      findClosestElement( node->right, k, closest );
}

//Решается поиском, на каждом шаге считаем разницу и запоминаем ближайшее число
int findClosestElement(BinaryTreeNode<int>* node, int k)
{
    int closest = -100001;  // число именно такое из-за того, что в констрейтах  0 <= node->data <= 10e5. Иначе может оказаться, что начальное число ближе, чем 10e5
    findClosestElement( node, k, closest );
    return closest;    
}
