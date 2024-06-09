#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30; // Constante para definir o tamanho máximo do grafo 

vector<int> grafo[MAXN];
vector<int> caminho; //cria um vetor de inteiro
bool visitado[MAXN];

bool dfs(int v, int n, int atual)
{
    if (atual == n)
    {
        // Verifica se o último vértice é adjacente ao primeiro condição minima necessaria para que haja ciclo hamiltoniano
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

bool temCicloHamiltoniano(vector<vector<int>> &path)
{
    memset(visitado, false, sizeof(visitado));
    caminho.clear();

    for (int i = 0; i < path.size(); ++i)
    {
        visitado[i] = true;
        caminho.push_back(i);
        if (dfs(i, path.size(), 1))
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

void leituraGrafo(vector<vector<int>> &G, int m)
{
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
}

void escritaGrafo(vector<vector<int>> &G)
{
    int n = G.size();
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
        for (int v = 0; v < n; v++)
        {
            cout << G[u][v] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> Grafo;
    Grafo.assign(n, vector<int>(n, 0));
    leituraGrafo(Grafo, m);
    escritaGrafo(Grafo);
    cout << "Total Vertices: " << n << endl;
    cout << "Total Arestas: " << m << endl;

    if (temCicloHamiltoniano(Grafo)) {
        printSolution(); //imprime o ciclo ecncontrado
    } else {
        cout << "Nenhum ciclo Hamiltoniano encontrado." << endl;
    }

    return 0;
}
