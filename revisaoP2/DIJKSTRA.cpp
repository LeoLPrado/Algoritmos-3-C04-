#define INF 99999
#include <iostream>
#include <list>
using namespace std;

struct Aresta{
  int origem, destino, peso;
};

int dijkstra_lista(list<Aresta> grafo[], int vertices, int origem, int destino, int H, double IDH[]){
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
      if(!visitado[d] && distancia[atual] + p < distancia[d] && IDH[d] >= H){
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
    int C, E, Co, Cd, D, Vo, Vd;
    double H;
    int i = 0;
    cin >> C;
    
    string cidade[C];
    double IDH[C];
    
    while(i<C){
        cin >> cidade[i] >> IDH[i];
        i++;
    }
    
    cin >> E;
    list<Aresta> grafo[C];
    
    i = 0;
    while(i<E){
        cin >> Co >> Cd >> D;
        grafo[Co].push_back({Co, Cd, D});
        grafo[Cd].push_back({Cd, Co, D});
        i++;
    }
    
    cin >> Vo >> Vd >> H;
    
    int r = dijkstra_lista(grafo, C, Vo, Vd, H, IDH);
    cout << r << endl;
    
    return 0;
}