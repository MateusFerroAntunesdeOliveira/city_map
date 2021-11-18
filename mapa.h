#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <vector>
#include <queue>
#include <list>

#define INFINITO 10000000

using namespace std;

constexpr int MAXNOS = 200; //-> Max de cidades

class Mapa {
public:
	Mapa();
	Mapa(int num_nos);
	void une(string a, string b, double distancia);
	void remove(string a, string b);
	bool adjacente(string a, string b) const;
	void addCidade(string nomeCidade);

private:
	bool validos(string a, string b) const;
    list<pair<int, int>> *cidades;      //-> Armaza as cidades
	int N;	                            //-> número de vértices (pontos de ref) do grafo
	bool adj[MAXNOS][MAXNOS];           //-> Adjacencia entre cidades
};

#endif
