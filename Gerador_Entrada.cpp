#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

int main(){

	cout << "Deseja gerar uma nova entrada?\n(Pressione 'S' para confirmar ou 'N' para cancelar.)\n";
	char Opcao = getch();
	int Min, Max;
	unsigned Qtd;
	if(Opcao == 'S' || Opcao == 's'){
		
		cout << "Qual o numero minimo possivel?\n";
		cin >> Min;
		cout << "Qual o numero maximo possivel?\n";
		cin >> Max;
		cout << "Quantos numeros sao?\n";
		cin >> Qtd;
		
		ofstream Arquivo("Entrada.txt");
		if (Arquivo.is_open()){
			
			Arquivo << Qtd << "\n";
			while(Qtd){
				
				Arquivo << Min + rand() / (RAND_MAX / (Max - Min + 1) + 1) << "\n";
				Qtd--;
			}
	    	Arquivo.close();
	    	cout << "Os numeros foram gerados com sucesso.\n";
	  	}
	  	else
		cout << "Nao foi possivel abrir o arquivo txt.\n";		
	}	
	return 0;
}
