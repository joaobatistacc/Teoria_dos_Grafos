#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grafo; // Definindo o grafo na forma de vetor de vetores de inteiros para ficar dinâminco de acordo com entrada
vector<int> caminho; //Definindo um vetor para caminho
vector<bool> visitado; // Vetor visitado dinâmico pra redimencionado de acordo com a entrada bool para controle das visitas no dfs

bool dfs(int v, int n, int atual)
{
    if (atual == n)
    {
        // Verifica se o último vértice é adjacente ao primeiro
        return find(grafo[v].begin(), grafo[v].end(), caminho[0]) != grafo[v].end();
    }

    for (int u : grafo[v])
    {
        if (!visitado[u])
        {
            visitado[u] = true;
            caminho.push_back(u);
            if (dfs(u, n, atual + 1))
                return true;
            visitado[u] = false;
            caminho.pop_back();
        }
    }
    return false;
}

bool temCicloHamiltoniano()
{
    fill(visitado.begin(), visitado.end(), false);
    caminho.clear();

    int n = grafo.size();
    for (int i = 0; i < n; ++i)
    {
        visitado[i] = true;
        caminho.push_back(i);
        if (dfs(i, n, 1))
            return true;
        visitado[i] = false;
        caminho.pop_back();
    }
    return false;
}

// Função para imprimir a solução
void printSolution() {
    cout << "Ciclo Hamiltoniano encontrado: ";
    for (int i = 0; i < caminho.size(); i++)
        cout << caminho[i] << " ";
    cout << caminho[0] << endl;  // Para mostrar o ciclo fechando
}

void leituraGrafo(int m)
{
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
}

void escritaGrafo()
{
    int n = grafo.size();
    cout << "Matriz de Adjacencia:" << endl;
    cout << "   ";
    for (int u = 0; u < n; u++)
    {
        cout << u << " ";
    }
    cout << endl;
    for (int u = 0; u < n; u++)
    {
        cout << u << ": ";
        for (int v : grafo[u])
        {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    // Redimensiona o grafo e o vetor visitado de acordo com o tamanho da entrada
    grafo.resize(n);
    visitado.resize(n);
    
    leituraGrafo(m);
    escritaGrafo();
    
    cout << "Total Vertices: " << n << endl;
    cout << "Total Arestas: " << m << endl;

    if (temCicloHamiltoniano()) {
        printSolution();
    } else {
        cout << "Nenhum ciclo Hamiltoniano encontrado." << endl;
    }

    return 0;
}
