#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Produto {
	char nomeProduto[90];
	int quantidade;
	float precoUnitario;
};

void salvarProdutoPrintar(int valor) {
	int tamanho;
	int quantidade = valor;
	float precoTotal = 0;
	char rNome[90];
	int rQuantidade;
	float rPrecoUnitario;

	struct Produto* endereco;
	endereco = (struct Produto*)malloc(tamanho*sizeof(struct Produto*));

	for (int i = 0; i < quantidade; i++) {
		cout << endl << ">>> Produto #" << i + 1 << " <<< ";
		cout << endl << "Insira o nome: ";
		cin >> rNome;
		cout << "Insira a quantidade: ";
		cin >> rQuantidade;
		cout << "Insira o preco: ";
		cin >> rPrecoUnitario;
		cout << endl << "=======================================" << endl;

		if (endereco != NULL) {
			strcpy ((endereco+i)->nomeProduto, rNome);
			(endereco+i)->quantidade = rQuantidade;
			(endereco+i)->precoUnitario = rPrecoUnitario;
		}
	}

	for (int j = 0; j < valor; j++) {
		cout << endl << "Nome do produto #" << j + 1 << ": " << (endereco+j)->nomeProduto << endl;
		cout << "Quantidade: " << (endereco+j)->quantidade << endl;
		cout << "Preco: " << (endereco+j)->precoUnitario << endl;
	}

	for (int k = 0; k < valor; k++) {
		precoTotal += (endereco+k)->precoUnitario * (endereco+k)->quantidade;
	}

	cout << endl << "+++++++++++++++++++++++++++++++++++++++" << endl << endl;
	cout << "Preco total: " << precoTotal << endl;
	cout << endl << "+++++++++++++++++++++++++++++++++++++++" << endl;
	free(endereco);
};

void inserirProduto() {
	int valor;
	cout << "Insira a quantidade desejada para cadastrar: ";
	cin >> valor;
	cout << endl << "=======================================" << endl;
	salvarProdutoPrintar(valor);
}

int main(int argc, char** argv) {
	inserirProduto();
	cout << endl << "--- END ---" << endl;
	return 0;
}
