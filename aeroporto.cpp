#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "aeroporto.h"

using namespace std;

void quantosAvioesAguardam(Fila *f){
	system("clear");
	if(!estahVazia(f)){
		cout << f->qtdItens << " Avioes estao aguardando para decolar." << endl;
	}else{
		cout << "Nao ha avioes aguardando para decolar." << endl;
	}
	cout << endl;
	sleep(2);
	menuAeroporto(f);
}

void autorizarDecolagem(Fila *f){
	Item *i;
	char *nm[30];
	int *num;

	system("clear");
	if (!estahVazia(f)){
		desenfileirar(f, nm, num);
		cout << "Aviao [Numero: " << num << "] [Nome: " << nm << "] | Autorizado a decolar." << endl;
	}else{
		cout << "Nao existem avioes para decolar." << endl;
	}
	sleep(2);
	menuAeroporto(f);
}

void adicionarAviaoFilaDecolagem(Fila *f){
	char nm[30];
	int num=0;

	system("clear");
	cout << "Digite os dados do aviao a ser inserido na Fila de Decolagem" << endl;
	cout << "Numero: ";
	cin >> num;
	cout << endl;
	cout << "Nome: ";
	cin >> nm;
	enfileirar(f, num, nm);
	system("clear");
	cout << "Aviao [" << num << "] [" << nm << "] adicionado com sucesso." << endl;
	sleep(2);
	menuAeroporto(f);
}

void listarAvioesFilaDecolagem(Fila *f){
	Item *i;
	if(!estahVazia(f)){
		system("clear");
		i = f->primeiro;
		while(i != f->ultimo){
			cout << "[" << i->numero << "] [" << i->nome << "] | ";
			i=i->prox;
		}
		cout << "[" << i->numero << "] [" << i->nome << "]" << endl;
	}else{
		cout << "Nao existem avioes para decolar." << endl;
	}
	sleep(2);
	menuAeroporto(f);
}

void caracteristicasProximoDecolar(Fila *f){
	if(!estahVazia(f)){
		system("clear");
		cout << "O proximo a decolar sera:" << endl;
		mostrarCaracteristicas(f);
	}else{
		cout << "Nao existem avioes para decolar." << endl;
	}
	sleep(2);
	menuAeroporto(f);
}

int menuAeroporto(Fila *f){
	int opt=1;
	while(opt != 6){
		system("clear");
		if(opt < 1 || opt > 6){
			cout << "Opcao errada." << endl;
			cout << "Escolha entre 1 e 6." << endl;
		}
		
		opt = 1;
		cout << "1 - Quantos Avioes estao aguardando." << endl;
		cout << "2 - Autorizar proxima decolagem." << endl;
		cout << "3 - Adidionar aviao a espera." << endl;
		cout << "4 - Ver avioes aguardando." << endl;
		cout << "5 - Detalhes do proximo a decolar." << endl;
		cout << "6 - Sair." << endl;
		cout << endl;
		cout << "Opcao: ";
		cin >> opt;
		switch(opt){
			case 1:
				quantosAvioesAguardam(f);
				break;
			case 2:
				autorizarDecolagem(f);
				break;
			case 3:
				adicionarAviaoFilaDecolagem(f);
				break;
			case 4:
				listarAvioesFilaDecolagem(f);
				break;
			case 5:
				mostrarCaracteristicas(f);
				break;
			case 6:
				cout << "Fechando aplicacao, aguarde..." << endl;
				sleep(3);
				return 0;
				break;
			default:
				menuAeroporto(f);
				break;
		}
	}
	return 0;
}