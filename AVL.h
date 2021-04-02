#include "AVL.c"

AVL_Node * AVL_New_Node(int key);
int AVL_Node_Height(AVL_Node *N);
int AVL_Get_Balance(AVL_Node * N);
int Max(int a, int b);
AVL_Node * AVL_Right_Rotate(AVL_Node *y);
AVL_Node * AVL_Left_Rotate(AVL_Node * x);
AVL_Node * AVL_Insert(AVL_Node * node, int key);
AVL_Node * AVL_Min_Value(AVL_Node * node);
AVL_Node * AVL_Remove(AVL_Node * root, int key);
AVL_Node * AVL_Search(AVL_Node * root, int x);
void AVL_Pre_Order(AVL_Node * root);
void AVL_In_Order(AVL_Node * root);
void AVL_Post_Order(AVL_Node * root);
void Lancar_AVL(unsigned Vetor[], unsigned Tamanho);
