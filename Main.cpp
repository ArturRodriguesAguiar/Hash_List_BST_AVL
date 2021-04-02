#include <bits/stdc++.h>
#include "BST.h"
#include "AVL.h"
#include "Array_Hash.h"
#include "Linked_List_Hash.h"

/*C++ tem fun��es HEAP nativas, mas a l�gica de ambas as estruturas
(�rvores Bin�rias e a Heap) foram elaboradas na sintaxe C99. Usei
o C++ s� pra fun��es que usam buffer, que oferece mais praticidade.*/

int main(){
	
	unsigned Tamanho, i;
		
    ifstream Arquivo("Entrada.txt");
    Arquivo >> Tamanho;
	int Vetor[Tamanho];	
	for(i = 0; i < Tamanho; i++)
		Arquivo >> Vetor[i];
	
	Lancar_BST(Vetor, Tamanho);
	Lancar_AVL(Vetor, Tamanho);
	Lancar_Array_Hash(Vetor, Tamanho);
	//Lancar_Linked_List_Hash(Vetor);
	return 0; 
}
