#include <iostream>
#include <list>
using namespace std;

int main(){
    int N; // numero de usuarios
    int i = 0, seguidor, id_user_analisado;
    
    cin >> N;
    string nomes_users[N];
    for(i = 0 ; i < N; i++){
        getline(cin >> ws, nomes_users[i]);
    }
    
    list<int> rede[N];
    list<int>::iterator it;
    for(i = 0; i < N; i++){
        cin >> seguidor;
        while(seguidor != -1){
            rede[i].push_back(seguidor);
            cin >> seguidor;
        }
    }
    cin >> id_user_analisado;
    for(i = 0; i < N; i++){
        for(it = rede[i].begin(); it != rede[i].end(); it++){
            if(*it == id_user_analisado){
                cout << nomes_users[i] << endl;
            }
        }
    }

    return 0;
}