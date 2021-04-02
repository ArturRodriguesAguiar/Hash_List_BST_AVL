using namespace std;

typedef struct bst_node{

	int key; 
	struct bst_node *left, *right; 
} BST_Node;

BST_Node * BST_New_Node(int item){
	
	BST_Node * temp = (BST_Node *)malloc(sizeof(BST_Node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
}

BST_Node * BST_Insert(BST_Node * node, int key){

	if(node == NULL) return BST_New_Node(key); 
	if(key < node->key) node->left = BST_Insert(node->left, key); 
	else if(key > node->key) node->right = BST_Insert(node->right, key); 

	return node; 
}

BST_Node * BST_Search(BST_Node * root, int x){
	
    if(root == NULL || root->key == x) return root;
    else if(x > root->key) return BST_Search(root->right, x);
    else return BST_Search(root->left, x);
}

BST_Node * BST_Min_Value(BST_Node * node){
	
    BST_Node * current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

BST_Node * BST_Remove(BST_Node * root, int x){
	
    if(root==NULL) return NULL;
    if(x > root->key) root->right = BST_Remove(root->right, x);
    else if(x < root->key) root->left = BST_Remove(root->left, x);
    else{
        if(root->left == NULL && root->right == NULL){
        	
            free(root);
            return NULL;
        }
        else if(root->left == NULL || root->right == NULL){
        	
            BST_Node * temp;
            if(root->left == NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }
        else{
        	
            BST_Node * temp = BST_Min_Value(root->right);
            root->key = temp->key;
            root->right = BST_Remove(root->right, temp->key);
        }
    }
    return root;
}

void BST_In_Order(BST_Node * root){
	
	if(root != NULL){
		
		BST_In_Order(root->left); 
		printf("%d\n", root->key); 
		BST_In_Order(root->right); 
	}
}

void BST_Pre_Order(BST_Node * node){
	
	if(node == NULL) return;
	printf("%d\n", node->key);
	BST_Pre_Order(node->left);
	BST_Pre_Order(node->right);
}

void BST_Post_Order(BST_Node * node){
	
	if(node == NULL) return;
	BST_Post_Order(node->left);
	BST_Post_Order(node->right);
	printf("%d\n", node->key);
}

void Lancar_BST(int Vetor[], unsigned Tamanho){
    
    unsigned i;
    double duration;
	clock_t start;
	BST_Node * BST = NULL;
	BST = BST_Insert(BST, Vetor[0]);

	start = std::clock();	
	for(i = 1; i < Tamanho; i++)
		BST_Insert(BST, Vetor[i]);		
	for(i = 0; i < Tamanho; i++)
		BST_Search(BST, Vetor[i]);		
	for(i = 0; i < Tamanho; i++)	
		BST = BST_Remove(BST, Vetor[i]);
		
    duration = (clock() - start)/(double) CLOCKS_PER_SEC;
    cout << "Insercao, busca e remocao da BST concluidos em: " << duration << " segundos." << endl;
    
	BST = BST_Insert(BST, Vetor[0]);
	for(i = 1; i < Tamanho; i++)
		BST_Insert(BST, Vetor[i]);
		
	cout << "Pressione Enter para efetuar a impressao In Order da BST:" << endl;
	getchar();
 	BST_In_Order(BST);
	cout << "Pressione Enter para efetuar a impressao Pre Order da BST:" << endl;
	getchar();	
 	BST_Pre_Order(BST);
	cout << "Pressione Enter para efetuar a impressao Post Order da BST:" << endl;
	getchar();	
	BST_Post_Order(BST);			
}
