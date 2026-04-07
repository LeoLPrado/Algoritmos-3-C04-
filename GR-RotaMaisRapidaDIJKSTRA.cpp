#define INF 99999
#include <iostream>
#include <list>
using namespace std;

struct Aresta{
  int origem, destino, peso;
};

int dijkstra_lista(list<Aresta> grafo[], int vertices, int origem, int destino){
  bool visitado[vertices];
  int pai[vertices], distancia[vertices], atual;
  list<Aresta>::iterator it;

  for(int i=0; i<vertices; i++){
    visitado[i] = false;
    pai[i] = -1;
    distancia[i] = INF;
  }
  distancia[origem] = 0;
  atual = origem;

  while(!visitado[atual]){
    visitado[atual] = true;
    for(it = grafo[atual].begin(); it != grafo[atual].end(); it++){
      int d = it->destino, p = it->peso;
      if(!visitado[d] && distancia[atual] + p < distancia[d]){
        distancia[d] = distancia[atual] + p;
        pai[d] = atual;
      }
    }
    int menor_distancia = INF;
    for(int i=0; i<vertices; i++){
      if(!visitado[i] && distancia[i] < menor_distancia){
        menor_distancia = distancia[i];
        atual = i;
      }
    }
  }
  return distancia[destino];
}

int main(){
  int N, M, u, v, t; // N -> vertices, M -> Arestas (estradas)
  cin >> N >> M;
  list<Aresta> grafo[N];
  for(int i=0; i<M; i++){
    cin >> u >> v >> t;
    u--; v--;
    grafo[u].push_front({u,v,t});
    grafo[v].push_front({v,u,t});
  }
  int A, B;
  cin >> A >> B;
  A--; B--;
  cout << dijkstra_lista(grafo, N, A, B) << endl;
  return 0;
}