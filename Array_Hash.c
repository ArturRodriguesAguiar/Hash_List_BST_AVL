#define SIZE 50

typedef struct hash_item{
	
   int data;   
   int key;
} Array_Hash_Item;

Array_Hash_Item * hashArray[SIZE]; 
Array_Hash_Item * dummyItem;
Array_Hash_Item * item;

int Array_Hash_Code(int key){return key % SIZE;}

Array_Hash_Item * Array_Hash_Search(int key){

	int hashIndex = Array_Hash_Code(key);  	
	while(hashArray[hashIndex] != NULL) {
	
		if(hashArray[hashIndex]->key == key)
        return hashArray[hashIndex]; 
		++hashIndex;
		hashIndex %= SIZE;
	}
	return NULL;        
}

void Array_Hash_Insert(int key, int data){

   Array_Hash_Item * item = (Array_Hash_Item*) malloc(sizeof(Array_Hash_Item));
   item->data = data;
   item->key = key;

   int hashIndex = Array_Hash_Code(key);
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1){

      ++hashIndex;
      hashIndex %= SIZE;
   }
   hashArray[hashIndex] = item;
}

Array_Hash_Item * Array_Hash_Remove(Array_Hash_Item * item){
	
   int key = item->key;
   int hashIndex = Array_Hash_Code(key);
   while(hashArray[hashIndex] != NULL){
	
      if(hashArray[hashIndex]->key == key){
      	
         Array_Hash_Item * temp = hashArray[hashIndex]; 
         hashArray[hashIndex] = dummyItem; 
         return temp;
      }
      ++hashIndex;		
      hashIndex %= SIZE;
   }      
   return NULL;        
}

void Array_Hash_Print(){
		
	for(int i = 0; i<SIZE; i++){	
		if(hashArray[i] != NULL)
			printf("Chave: %d, Valor: %d\n", hashArray[i]->key, hashArray[i]->data);
   }
}

void Lancar_Array_Hash(int Vetor[], unsigned Tamanho){

    unsigned i;
    double duration;
	clock_t start;
	start = std::clock();
	
	for(i = 0; i < Tamanho; i++)
		Array_Hash_Insert(i, Vetor[i]);
	for(i = 0; i < Tamanho; i++)
		Array_Hash_Search(Array_Hash_Code(Vetor[i]));
	for(i = 0; i < Tamanho; i++)	
		Array_Hash_Remove(Array_Hash_Search(i));

    duration = (clock() - start)/(double) CLOCKS_PER_SEC;
    cout << "Insercao, busca e remocao da tabela Hash com array concluidos em: " << duration << " segundos." << endl;		
}
