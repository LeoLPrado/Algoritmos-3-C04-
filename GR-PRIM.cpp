#include <iostream>
#include <list>
#define INF 999999
using namespace std;
struct Aresta{
  int origem, destino, peso;
};

int prim_lista(list<Aresta> grafo[], int vertices, int origem){  // 6 vertices, origem em 0
  bool visitado[vertices];// vai controlar se foi visitado ou não
  int pai[vertices], distancia[vertices], atual;
  for(int i=0; i<vertices; i++){
    visitado[i] = false;// começa com todas as posições não visitadas
    pai[i] = -1;// indicando que esse vértice de origem não tem pai, não venho ninguém antes
    distancia[i] = INF;// porque ainda não tenho a distante de um nó ao outro
  }
  atual = origem;
  distancia[atual] = 0;// posição da distância a origem é 0, sem distância
  while(!visitado[atual]){ // verifica se foi visitado ou não
    visitado[atual] = true;// visita o nó na origem, posição 0
    list<Aresta>::iterator it;
    for(it=grafo[atual].begin();it!=grafo[atual].end();it++){// verifica as adjacências do numero atual
      int d = it->destino, p = it->peso;// d é o nó para qual o nó vai, e o p guarda o peso dessa aresta
      if(!visitado[d] && p < distancia[d]){// se não foi visitado e o peso for menor do que a distancia
        distancia[d] = p;
        pai[d] = atual;// recebe o vértice atual
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
  
  cout << "Arvore Geradora Minima:" << endl;
  for(int i = 0; i < vertices; i++){
    if(pai[i] != -1){
      cout << pai[i] << " " << i << endl;
    }
  }
  
  int peso_mst = 0;
  for(int i=0; i<vertices; i++){
    peso_mst += distancia[i];
  }
  return peso_mst;
}

int main(){
    int vertices, arestas, origem, destino, peso, orientado, no_inicial;
    cin >> vertices >> orientado >> no_inicial;
   
    list<Aresta> grafo[vertices];
   
    while(true){
        cin >> origem >> destino >> peso;
        if(origem == -1 && destino == -1 && peso == -1)
            break;
            
        grafo[origem].push_back({origem, destino, peso});
        if(orientado == 0)
            grafo[destino].push_back({destino, origem, peso});
    }
    int r = prim_lista(grafo, vertices, no_inicial);
    cout << "Custo: " << r << endl;
    return 0;
}