#include "mapa.h"

Mapa::Mapa() {
	// Sobrecarga
}

Mapa::Mapa(int N) {
    //-> Guarda numero de nós em N, atribuindo numero de vertices
	this->N = N;

	for (int i=0; i < MAXNOS; ++i) {
		for (int j=0; j < MAXNOS; ++j) adj[i][j] = false;
	}
}

int Mapa::getCidade(string cidade) const{
	int k = -1;

	for (int i = 0; i < MAXNOS; ++i) {
		if (cidades_matrix[i] == cidade) k = i;
	}
	
	return k;
}

void Mapa::une(string a, string b, double distancia)  {
	if (validos(a,b)) {
		cidades_matrix[getCidade(a)].push_back(getCidade(b));
		cidades_matrix[getCidade(b)].push_back(getCidade(a));
		//TODO Fazer para cidades_distancias tambem
	}
}

void Mapa::remove(string a, string b) {
	//TODO Fazer Remove
}

bool Mapa::adjacente(string a, string b) const {
	if (validos(a,b)) return adj[getCidade(a)][getCidade(b)];
	else return false;
}

void Mapa::addCidade(string nomeCidade) {
    cidades_matrix[N++] = nomeCidade;
}

bool Mapa::validos(string a, string b) const {
    bool condicaoA = getCidade(a) > -1 && getCidade(a) < MAXNOS;
    bool condicaoB = getCidade(b) > -1 && getCidade(b) < MAXNOS;
	return (condicaoA && condicaoB);
}
