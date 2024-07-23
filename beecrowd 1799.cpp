// Alunos: João Gabriel e Leonardo Oliveira

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

// Função Para adicionar aresta no grafo
void addAresta(unordered_map<string, vector<string> > &grafo,string d1, string d2){
    grafo[d1].push_back(d2);
    grafo[d2].push_back(d1);
}

// Função para buscar em largura a partir de um start até chegar a um destination
int bfs(unordered_map<string,vector<string> > &grafo,string start,string destination,unordered_map<string,bool> &visita,unordered_map<string,int> peso){
    
    // Criando fila de elementos e adjacentes
    queue<string> q;

    // Coloca o start na fila, marca ele como visitado e define o peso dele como 0;
    q.push(start);
    visita[start] = true;
    peso[start] = 0;

    /* Enquanto tiver elementos na fila, coloca os pesos de seus adjacentes como
    o peso do atual +1, e marca os mesmos como visitados */
    while(!q.empty()){
        string v = q.front();
        q.pop();
    
        for(auto adj : grafo[v]){
            if(!visita[adj]){
                peso[adj] = (peso[v]+1);
                visita[adj] = true;
                q.push(adj);
            }
        }
    }
    // Retorna o peso do destino.
    return peso[destination];
}

int main(){
    int V, A;
    string c1,c2;
    // Inicia o grafo como um map de vetores de strings;
    unordered_map<string,vector<string> > grafo;

    // Inicia um mapa booleano para guardar os visitados;
    unordered_map<string,bool> visita;
    unordered_map<string,bool> visita2;

    // Inicia o mapa dos pesos de cada vértice;
    unordered_map<string,int> peso1;
    unordered_map<string,int> peso2;

    cin >> V >> A;
    // Adiciona as Arestas (A);
    for(int i = 0; i<A; i++){
        cin >> c1 >> c2;
        addAresta(grafo,c1,c2);
    }
    // Chama o primeiro BFS da Entrada até o Queijo (*);
    int value1 = bfs(grafo,"Entrada","*",visita,peso1);

    // Chama o segundo BFS do Queijo até a Saída;
    int value2 = bfs(grafo,"*","Saida",visita2,peso2);
    cout << (value1 + value2) << endl;
    
    return 0;
}