#include<iostream>
#include<list>
using namespace std;

struct Aresta {
	int origem, destino, peso;
};

bool bfs(list<Aresta> grafo[], int vertices, int origem){
	bool visitado[vertices];
	list<int> fila_visitacao;
	list<Aresta>::iterator it;
	
	for(int i=0;i<vertices;i++)
		visitado[i] = false;
	
	fila_visitacao.push_back(origem);
	visitado[origem] = true;
	
	while(!fila_visitacao.empty()){
		int atual = fila_visitacao.front();
		fila_visitacao.pop_front();
		
		cout << atual << endl; // imprime vértice
		
		for(it = grafo[atual].begin(); it != grafo[atual].end(); it++){
			int destino = it->destino;
			
			cout << atual << " " << destino << endl; // imprime TODAS arestas
			
			if(!visitado[destino]){
				fila_visitacao.push_back(destino);
				visitado[destino] = true;
			}
		}
	}
	
	return true;
}

int main(){
	int vertices, origem, destino, peso, no_inicial;
	
	cin>>vertices>>no_inicial;
	list<Aresta> grafo[vertices];
	list<Aresta>::iterator it;
	
    while(true){
        cin >> origem >> destino >> peso;
        if(origem == -1 && destino == -1 && peso == -1)
            break;
          
        grafo[origem].push_back({origem, destino, peso});
        grafo[destino].push_back({destino, origem, peso});
    }
    
    bfs(grafo, vertices, no_inicial);
	return 0;
}