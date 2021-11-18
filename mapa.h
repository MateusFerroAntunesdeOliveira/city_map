#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <queue>
#include <list>
#include <vector>
#define INFINITO 10000000

using namespace std;

constexpr int MAXNOS = 200; //-> Max de cidades
enum EstadoLargura {nao_visitado, identificado, visitado};
enum EstadoProfundidade {nao_visitado_p, sendo_visitado_p, visitado_p};

class Mapa {
public:
	Mapa();
	Mapa(int num_nos);
	void une(string a, string b, double distancia);
	void remove(string a, string b);
	bool adjacente(string a, string b) const;
    void addCidade(string nomeCidade);
	int menorCaminho(string a, string b, int precede[]);

	void largura(int v0);		// percorre em largura a partir de v0
	void profundidade(int v0);	// percorre em prof. a partir de v0
	void profundidade_rec(int v0, vector<EstadoProfundidade>& estado);	// percorre em prof. a partir de v0

	// para imprimir adj usando operador <<
	friend std::ostream& operator<<(std::ostream& os, const Mapa& g);

private:
	bool validos(string a, string b) const;
    list<pair<int, int>> *cidades;      //-> Armaza as cidades
	int N;	                            //-> número de vértices (pontos de ref) do grafo
	bool adj[MAXNOS][MAXNOS];           //-> Adjacencia entre cidades
};

#endif
