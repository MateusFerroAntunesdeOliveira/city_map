#include "mapa.h"

Mapa::Mapa() {
	//-> Sobrecarga
}

Mapa::Mapa(int N) {
    //-> Guarda numero de nós em N, atribuindo numero de vertices
	this->N = N;
	for (int i = 0; i < MAXNOS; ++i) for (int j = 0; j < MAXNOS; ++j) adj[i][j] = false;
}

int Mapa::getCidade(string cidade) const{
	int k = -1;
	for (int i = 0; i < MAXNOS; ++i) if (cidades_matrix[i] == cidade) k = i;
	return k;
}

void Mapa::une(string a, string b, double distancia)  {
	if (validos(a,b)) {
		adj[getCidade(a)][getCidade(b)] = adj[getCidade(b)][getCidade(a)] = true;
		dist[getCidade(a)][getCidade(b)] = dist[getCidade(b)][getCidade(a)] = distancia;
	}
}

void Mapa::remove(string a, string b) {
	if (validos(a,b)) {
		adj[getCidade(a)][getCidade(b)] = adj[getCidade(b)][getCidade(a)] = false;
		dist[getCidade(a)][getCidade(b)] = dist[getCidade(b)][getCidade(a)] = -1;
	}
}

void Mapa::addCidade(string nomeCidade) {
    cidades_matrix[N++] = nomeCidade;
}

bool Mapa::adjacente(string a, string b) const {
	if (validos(a,b)) return adj[getCidade(a)][getCidade(b)];
	else return false;
}

bool Mapa::validos(string a, string b) const {
    bool condicaoA = getCidade(a) > -1 && getCidade(a) < MAXNOS;
    bool condicaoB = getCidade(b) > -1 && getCidade(b) < MAXNOS;
	return (condicaoA && condicaoB);
}

double Mapa::distancia(string a, string b) {
	if (adj[getCidade(a)][getCidade(b)]) return dist[getCidade(a)][getCidade(b)];
	else return INFINITO;
}

double Mapa::dijkstra(string a, string b, vector<string> &rota) {
	double dist[MAXNOS];
	bool visitados[MAXNOS];

	for (int i = 0; i < MAXNOS; ++i) {
		dist[i] = INFINITO;
		visitados[i] = false;
	}

	//-> Distância: A para A é 0. E a respectiva cidade é visitada
	dist[getCidade(a)] = 0;
	visitados[getCidade(a)] = true;
    int corrente = getCidade(a);
	int precede[N];

	while (corrente != getCidade(b)) {
        double menordist = INFINITO;          		// menor das novas distâncias calculadas
        int k;                              		// próximo corrente (aquele com menor distância)
        double distCalculada = dist[corrente];   	// distância calculada de a até o nó corrente
        for (int i = 0; i < N; i++) {
            if (!visitados[i]) {
                double novadist = distCalculada + distancia(cidades_matrix[corrente], cidades_matrix[i]);
                if (novadist < dist[i]) {
                    dist[i] = novadist;
                    precede[i] = corrente;
                }
                if (dist[i] < menordist) {
                    menordist = dist[i];
                    k = i;
                }
            } // se já calculado não faz nada
        } // fim do for
        corrente = k;
        visitados[corrente] = true;
	}

	//TODO Fazer o menor caminho, pegando o destino final e precendo até chegar na origem

    return dist[getCidade(b)];
}
