#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int MAXNOS = 100;
enum EstadoLargura {nao_visitado, identificado, visitado};
enum EstadoProfundidade {nao_visitado_p, sendo_visitado_p, visitado_p};

class Mapa {
public:
	Mapa(int num_nos);
	void une(int a, int b);
	void remove(int a, int b);
	bool adjacente(int a, int b) const;

	void largura(int v0);		// percorre em largura a partir de v0
	void profundidade(int v0);	// percorre em prof. a partir de v0
	void profundidade_rec(int v0, vector<EstadoProfundidade>& estado);	// percorre em prof. a partir de v0

	// para imprimir adj usando operador <<
	friend std::ostream& operator<<(std::ostream& os, const Mapa& g);
private:
	bool adj[MAXNOS][MAXNOS];
	int N;	// número de vértices do grafo
	bool validos(int a, int b) const;
};

#endif
