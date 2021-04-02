#include "BST.c"

BST_Node * BST_New_Node(int item);
BST_Node * BST_Insert(BST_Node * node, int key);
BST_Node * BST_Search(BST_Node * root, int x);
BST_Node * BST_Min_Value(BST_Node * node);
BST_Node * BST_Remove(BST_Node * root, int x);
void BST_In_Order(BST_Node * root);
void BST_Preorder(BST_Node * node);
void BST_Postorder(BST_Node * node);
void Lancar_BST(unsigned Vetor[], unsigned Tamanho);
