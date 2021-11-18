#include "mapa.h"

Mapa::Mapa(int num_nos) {
    N = num_nos;

	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) adj[i][j] = false;
	}
}

bool Mapa::validos(int a, int b) const {
    return (a>=0 && a<N && b>=0 && b<N);
}

void Mapa::une(int a, int b) {
	if (validos(a,b)) adj[a][b] = true;
}

void Mapa::remove(int a, int b) {
	if (validos(a,b)) adj[a][b] = false;
}

bool Mapa::adjacente(int a, int b) const {
	if (validos(a,b)) return adj[a][b];
	else return false;
}

void Mapa::largura(int v0) {
	// i => estado
	vector<EstadoLargura> estado(N, EstadoLargura::nao_visitado);

	queue<int> f;
	f.push(v0);
	estado[v0] = EstadoLargura::identificado;

	while (!f.empty()) {
		int u = f.front();
		f.pop();
		estado[u] = EstadoLargura::visitado;
		cout << u << " "; 	// Visita o nó U

		for (int i = 0; i < N; ++i) {
			if (adjacente(u,i)) {
				// I eh adjacente a U
				if (estado[i] == EstadoLargura::nao_visitado) {
					estado[i] = EstadoLargura::identificado;
					f.push(i);
				}
			}
		}
	}
}

void Mapa::profundidade(int v0) {
	vector<EstadoProfundidade> estado(N,EstadoProfundidade::nao_visitado_p);
	profundidade_rec(v0, estado);
}

void Mapa::profundidade_rec(int v0, vector<EstadoProfundidade>& estado) {
	estado[v0] = EstadoProfundidade::sendo_visitado_p;

	cout << v0 << " ";

	for (int i=0; i<N; ++i) {
		if (adjacente(v0,i) && estado[i] == EstadoProfundidade::nao_visitado_p) {
			estado[i] = EstadoProfundidade::sendo_visitado_p;
			profundidade_rec(i, estado);
		}
	}
	estado[v0] = EstadoProfundidade::visitado_p;
}

std::ostream& operator<<(std::ostream& os, const Mapa& g) {
	for (int i=0; i<g.N; ++i) {
		for (int j=0; j<g.N; ++j)
			os << g.adjacente(i,j);
		os << endl;
	}
	return os;
}