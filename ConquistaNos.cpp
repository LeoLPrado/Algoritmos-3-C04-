#include <iostream>
using namespace std;

int main() {

    int N, M;
    cin >> N >> M;

    int grafo[100][100];

    // inicializa matriz com 0
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            grafo[i][j] = 0;
        }
    }

    int A, B;

    // leitura das arestas
    for(int i = 0; i < M; i++) {
        cin >> A >> B;

        grafo[A][B] = 1;
        grafo[B][A] = 1; // grafo não direcionado
    }

    // impressão da matriz
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << grafo[i][j];

            if(j < N)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}