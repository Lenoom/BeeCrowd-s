// Alunos: João Gabriel e Leonardo Oliveira

#include <iostream>
#include <vector>

using namespace std;

// Adiciona as arestas em ambas as direções.
void addAresta(vector<vector<int> > &grafo, int c1, int c2){
    grafo[c1].push_back(c2);
    grafo[c2].push_back(c1);
}

// Busca em profundidade
void dfs(vector<vector<int> > &grafo,int start,vector<bool> &visita){
    visita[start] = true;
    cout << char(start + 'a') << ',';

    for(auto c: grafo[start]){
        if(!visita[c]){
            dfs(grafo,c,visita);
        }
    }
}

int main(){
    int N,V,E;
    char c1,c2;
    int components = 0, cases = 0;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> V >> E;
        // Cria um Grafo utilizando lista de adjacência e um vetor booleano;
        vector<vector<int> > grafo(V);
        vector<bool> visita(V, false);

        // Adiciona as arestas;
        for(int c = 0; c < E; c++){
            cin >> c1 >> c2;
            addAresta(grafo,c1-'a',c2-'a'); // (c1-'a') transforma a letra em c1 em um número, com base na tabela ASCII.
        }
        cout << "Case #" << ++cases << ":" << endl;

        // Para cada elemento do grafo, se não for visitado, chama a DFS nele;
        for(int c = 0; c < size(grafo); c++){
            if(!visita[c]){
                dfs(grafo,c,visita);
                cout << endl;
                components++;
            }
        }
        cout << components << " connected components" << endl;
    }
    return 0;
}