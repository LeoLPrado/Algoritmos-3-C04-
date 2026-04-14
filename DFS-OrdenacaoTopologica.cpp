#define MAX_V 100
#include<iostream>
#include<list>
using namespace std;

struct Aresta{
	int origem, destino;
};

// necessarios para imprimir os valores de ordenacao topologica
int f[MAX_V];
int pos;

void dfs(list<Aresta> grafo[], int vertices, int origem, bool visitado[]){
	visitado[origem] = true;
	list<Aresta>::iterator it;

    for(it=grafo[origem].begin(); it != grafo[origem].end(); it++){
    	int destino = it->destino;
    	if( !visitado[destino]){
				dfs(grafo, vertices, destino, visitado);
		}
	}
	f[pos--] = origem;
}

void ordenacao_topologica(int f[], int nVertices){
    for(int i = 0; i <nVertices; i++) cout << f[i] << " ";
}

int main(){
    int vertices, orientado, origem, destino;
    cin >> vertices>>orientado;
    
    list<Aresta> grafo[vertices];
    
    cin >> origem >> destino;
    while(origem != -1 && destino != -1){
        grafo[origem].push_back({origem, destino});
        
        if(orientado == 0){
            grafo[destino].push_back({destino, origem});   
        }
        cin >> origem >> destino;
    }
    
    
   bool visitado[vertices];
   for(int i = 0; i < vertices; i++){
       visitado[i] = false;
   }
    
    pos = vertices - 1;
    for(int i = 0; i < vertices; i++){
        if(!visitado[i]){
            dfs(grafo, vertices, i, visitado);
        }
    }
    
    ordenacao_topologica(f, vertices);
    return 0;
}