#include "Fila.cpp"
/*
1. Escreva um programa que simule o controle de uma pista de decolagem de aviões em um aeroporto. Neste programa, o usuário deve ser capaz de realizar as seguintes tarefas:
*/


// a) Listar o número de aviões aguardando na fila de decolagem;
void quantosAvioesAguardam(Fila *f);

// b) Autorizar a decolagem do primeiro avião da fila;
void autorizarDecolagem(Fila *f);

// c) Adicionar um avião à fila de espera;
void adicionarAviaoFilaDecolagem(Fila *f);

// d) Listar todos os aviões na fila de espera;
void listarAvioesFilaDecolagem(Fila *f);

// e) Listar as características do primeiro avião da fila;
void caracteristicasProximoDecolar(Fila *f);

// Menu interativo para acesso às funções.
int menuAeroporto(Fila *f);