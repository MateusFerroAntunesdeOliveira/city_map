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
	string cidades_matrix[MAXNOS];		//-> Armaza as cidades (listas de adjacencias)

	//-> Métodos
	int getCidade(string cidade) const;
	// TODO Adicionar método para pegar Distancia
public:
	//-> Métodos
	Mapa();
	Mapa(int N);
	void une(string a, string b, double distancia);
	void remove(string a, string b);
	void addCidade(string nomeCidade);
	bool adjacente(string a, string b) const;
	bool validos(string a, string b) const;
	double dijkstra(string a, string b, vector<string> &rota);
};

#endif
