#include "mapa.h"

Mapa::Mapa() {
	// Sobrecarga
}

Mapa::Mapa(int num_nos) {
    //-> Cria nova lista onde cada uma é um pair. Cada pair é formado pela cidade B e pela distância
    cidades = new list<pair<int, int>>[N];
    //-> Guarda numero de nós em N
    N = num_nos;

	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) adj[i][j] = false;
	}
}

void Mapa::une(string a, string b, double distancia) {
    // cidades[a].push_back(make_pair(b, distancia));
	// if (validos(a,b)) adj[a][b] = true;
}

void Mapa::remove(string a, string b) {
	// if (validos(a,b)) adj[a][b] = false;
}

bool Mapa::adjacente(string a, string b) const {
	// if (validos(a,b)) return adj[a][b];
	// else return false;
}

void addCidade(string nomeCidade) {
    // cidades[++N] = nomeCidade;
}

bool Mapa::validos(string a, string b) const {
    // return (a>=0 && a<N && b>=0 && b<N);
}
