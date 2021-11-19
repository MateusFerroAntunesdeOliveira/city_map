#ifndef MAPA_H
#define MAPA_H

#include <iostream>

#define INFINITO 10000000

using namespace std;

constexpr int MAXNOS = 200; //-> Max de cidades

class Mapa {

private:
	int N;	                            		//-> número de vértices (pontos de ref) do grafo
	bool adj[MAXNOS][MAXNOS];           		//-> Adjacencia entre cidades
	string cidades_matrix[MAXNOS];		 		//-> Armaza as cidades (listas de adjacencias)
	bool validos(string a, string b) const;
	int getCidade(string cidade) const;

public:
	Mapa();
	Mapa(int N);
	void une(string a, string b, double distancia);
	void remove(string a, string b);
	bool adjacente(string a, string b) const;
	void addCidade(string nomeCidade);
};

#endif
