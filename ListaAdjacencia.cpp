#include <iostream>
#include <list>
using namespace std;

struct no
{
    int v; // vertice adjacente
    int peso; // peso da aresta
};

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado){
    no No = {v, p};
    adj[u].push_back(No);
    if(orientado == 0){
        no NoCorrespondente = {u, p};
        adj[v].push_back(NoCorrespondente);
    }
}

int main (){
    int N; // numero de vertices
    int orientado;
    int u, v, p;
    
    cin >> N >> orientado;
    list<no> grafo[N];
    list<no>::iterator it;
    
    while(true){
        cin >> u >> v >> p;
        if(u == -1 && v == -1 && p == -1) break;

        cria_aresta(grafo, u, v, p, orientado);
    }
    
    for(int i = 0; i < N; i++){
        for(it = grafo[i].begin(); it != grafo[i].end(); it++){
            cout << i << " " << it->v << " " << it->peso << endl;
        }
    }
    return 0;
}