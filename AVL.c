using namespace std;

typedef struct avl_node{
	
    int key, height;
    struct avl_node *left, *right;
} AVL_Node;

AVL_Node * AVL_New_Node(int key){
	
    AVL_Node * node = (AVL_Node *)malloc(sizeof(AVL_Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int AVL_Node_Height(AVL_Node *N){
	
    if(N == NULL) return 0;
    return N -> height;
}

int AVL_Get_Balance(AVL_Node * N){
	
    if(N == NULL) return 0;
    return AVL_Node_Height(N->left) - AVL_Node_Height(N->right);
}

int Max(int a, int b){return (a > b)? a : b;}

AVL_Node * AVL_Right_Rotate(AVL_Node *y){
	
    AVL_Node * x = y->left;
    AVL_Node * T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = Max(AVL_Node_Height(y->left), AVL_Node_Height(y->right)) + 1;
    x->height = Max(AVL_Node_Height(x->left), AVL_Node_Height(x->right)) + 1;
    return x;
}

AVL_Node * AVL_Left_Rotate(AVL_Node * x){
	
    AVL_Node * y = x->right;
    AVL_Node * T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = Max(AVL_Node_Height(x->left), AVL_Node_Height(x->right)) + 1;
    y->height = Max(AVL_Node_Height(y->left), AVL_Node_Height(y->right)) + 1;
    return y;
}

AVL_Node * AVL_Insert(AVL_Node * node, int key){
	
    if(node == NULL) return(AVL_New_Node(key));
 
    if(key < node->key) node->left  = AVL_Insert(node->left, key);
    else if(key > node->key) node->right = AVL_Insert(node->right, key);
    else return node;
 
    node->height = 1 + Max(AVL_Node_Height(node->left), AVL_Node_Height(node->right));
    int balance = AVL_Get_Balance(node);

    if(balance > 1 && key < node->left->key) return AVL_Right_Rotate(node);
    if(balance < -1 && key > node->right->key) return AVL_Left_Rotate(node);
 
    if(balance > 1 && key > node->left->key){
    	
        node->left =  AVL_Left_Rotate(node->left);
        return AVL_Right_Rotate(node);
    }
    if(balance < -1 && key < node->right->key){
    	
        node->right = AVL_Right_Rotate(node->right);
        return AVL_Left_Rotate(node);
    }
    return node;
}

AVL_Node * AVL_Min_Value(AVL_Node * node){
	
    AVL_Node * current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

AVL_Node * AVL_Remove(AVL_Node * root, int key){
	
    if(root == NULL)
        return root; 
    if(key < root->key)
        root->left = AVL_Remove(root->left, key);
    else if(key > root->key)
        root->right = AVL_Remove(root->right, key);
    else{

        if((root->left == NULL) || (root->right == NULL)){
        	
            AVL_Node * temp = root->left ? root->left : root->right;
            if (temp == NULL){
            	
                temp = root;
                root = NULL;
            }
            else *root = *temp;
            free(temp);
        }
        else{

            AVL_Node * temp = AVL_Min_Value(root->right);
            root->key = temp->key;
            root->right = AVL_Remove(root->right, temp->key);
        }
    }
    if(root == NULL)
      return root;
    root->height = 1 + Max(AVL_Node_Height(root->left), AVL_Node_Height(root->right));
    int balance = AVL_Get_Balance(root);
  
    if(balance > 1 && AVL_Get_Balance(root->left) >= 0)
        return AVL_Right_Rotate(root);

    if(balance > 1 && AVL_Get_Balance(root->left) < 0){
    	
        root->left =  AVL_Left_Rotate(root->left);
        return AVL_Right_Rotate(root);
    }
    if(balance < -1 && AVL_Get_Balance(root->right) <= 0)
        return AVL_Left_Rotate(root);
    if(balance < -1 && AVL_Get_Balance(root->right) > 0){
    	
        root->right = AVL_Right_Rotate(root->right);
        return AVL_Left_Rotate(root);
    }
    return root;
}

AVL_Node * AVL_Search(AVL_Node * root, int x){
	
	if(root != NULL){
		if(root->key == x) return root;
    	else if(root->key< x) AVL_Search(root->right, x);
		else AVL_Search(root->left, x); 	
	}
	return NULL;
}

void AVL_Pre_Order(AVL_Node * root){
	
	if(root != NULL){
		
		printf("%d\n", root->key);
		AVL_Pre_Order(root->left);
		AVL_Pre_Order(root->right);
	}
}

void AVL_In_Order(AVL_Node * root){
	
    if(root != NULL){
    	
        AVL_In_Order(root->left);
        printf("%d\n", root->key);
        AVL_In_Order(root->right);
    }
}

void AVL_Post_Order(AVL_Node * root){
	
    if(root != NULL){
    	
        AVL_Post_Order(root->left);
        AVL_Post_Order(root->right);
        printf("%d\n", root->key);
    }
}

void Lancar_AVL(int Vetor[], unsigned Tamanho){

    unsigned i;
    double duration;
	clock_t start;
	AVL_Node * AVL = NULL;
	AVL = AVL_Insert(AVL, Vetor[0]);
	start = std::clock();
				
	for(i = 1; i < Tamanho; i++)
		AVL_Insert(AVL, Vetor[i]);
	for(i = 0; i < Tamanho; i++)
		AVL_Search(AVL, Vetor[i]);
	for(i = 0; i < Tamanho; i++)	
		AVL = AVL_Remove(AVL, Vetor[i]);

    duration = (clock() - start)/(double) CLOCKS_PER_SEC;
    cout << "Insercao, busca e remocao da AVL concluidos em: " << duration << " segundos." << endl;
		
	AVL = AVL_Insert(AVL, Vetor[0]);
	for(i = 1; i < Tamanho; i++)
		AVL_Insert(AVL, Vetor[i]);
		
	cout << "Pressione Enter para efetuar a impressao In Order da AVL:" << endl;
	getchar();
 	AVL_In_Order(AVL);
	cout << "Pressione Enter para efetuar a impressao Pre Order da AVL:" << endl;
	getchar();
 	AVL_Pre_Order(AVL);
	cout << "Pressione Enter para efetuar a impressao Post Order da AVL:" << endl;
	getchar();	
	AVL_Post_Order(AVL);		
}
