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
    int caminho[vertices];
    int tam = 0;
    atual = destino;
    // guarda o caminho destino -> origem
    while(atual != -1){
        caminho[tam++] = atual;
        atual = pai[atual];
    }
    // imprime origem -> destino
    cout << "Menor caminho: ";
    for(int i = tam - 1; i >= 0; i--){
        cout << caminho[i];
        if(i != 0) cout << " ";
    }
    cout << endl;
  return distancia[destino];
}

int main(){
    int vertices, orientado, o, d, p;
    int no_inicial, no_destino;
    cin >> vertices >> orientado >> no_inicial >> no_destino;
    list<Aresta> grafo[vertices];

    cin >> o >> d >> p;
    while(o != -1 && d != -1 && p != -1){
        grafo[o].push_front({o,d,p});
        if(orientado == 0){
            grafo[d].push_front({d,o,p});
        }
        cin >> o >> d >> p;
    }
    
    int r = dijkstra_lista(grafo, vertices, no_inicial, no_destino);
    cout << "Custo: " << r << endl;
    
    return 0;
}