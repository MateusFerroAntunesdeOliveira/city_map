#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <vector>

#define INFINITO 10000000

using namespace std;

constexpr int MAXNOS = 200; //-> Max de cidades

class Mapa {

private:
	//-> Variaveis
	int N;	                           	//-> número de vértices (pontos de ref) do grafo
	bool adj[MAXNOS][MAXNOS];          	//-> Adjacencia entre cidades
	double dist[MAXNOS][MAXNOS];		//-> Distancia entre cidades
	string cidades_matrix[MAXNOS];		//-> Armaza as cidades (listas de adjacencias)
public:
	//-> Métodos
	Mapa();
	Mapa(int N);
	int getCidade(string cidade) const;
	void une(string a, string b, double distancia);
	void addCidade(string nomeCidade);
	bool adjacente(string a, string b) const;
	bool validos(string a, string b) const;
	string retornaRota(string a, string b, vector<string> &rota);
	double distancia(string a, string b);
	double dijkstra(string a, string b, vector<string> &rota);
};

#endif
