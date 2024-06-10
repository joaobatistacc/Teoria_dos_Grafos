#include <bits/stdc++.h>
using namespace std;

vector<int> caminho; //Definindo um vetor para caminho
vector<bool> visitado; // Vetor para controle das visitas no dfs tipo bool true ou false


// DFS busca em profundidade para encontrar ciclo Hamiltoniano
bool dfs(int v, int n, int atual, vector<vector<int>> &grafo)
{
    if (atual == n) // Se todos os vértices foram visitados
    {
        // Verifica se o último vértice é adjacente ao primeiro para fechar o ciclo
        return grafo[v][caminho[0]] == 1;
    }

    // Itera sobre todos os vértices para verificar adjacências
    for (int u = 0; u < grafo.size(); ++u)
    {
        // Verificar se o vértice u é adjacente ao vértice v e ainda não foi visitado
        if (grafo[v][u] == 1 && !visitado[u])
        {
            visitado[u] = true; // Marca o vértice u como visitado
            caminho.push_back(u); // Adiciona o vértice u ao caminho
            // Continua a busca a partir do vértice u
            if (dfs(u, n, atual + 1, grafo))
                return true;
            visitado[u] = false; // Desmarca o vértice u (backtrack)
            caminho.pop_back(); // Remove o vértice u do caminho (backtrack)
        }
    }
    return false; // Se não encontrar um ciclo Hamiltoniano, retorna false
}

// Função para verificar se existe um ciclo Hamiltoniano no grafo 
bool procurarCicloHamiltoniano(vector<vector<int>> &grafo)
{
    fill(visitado.begin(), visitado.end(), false); // Inicializa todos os vértices como não visitados
    caminho.clear(); // Limpa o caminho

    int n = grafo.size(); // Número de vértices no grafo
    for (int i = 0; i < n; ++i)
    {
        visitado[i] = true; // Marca o vértice i como visitado
        caminho.push_back(i); // Adiciona o vértice i ao caminho
        // Inicia a busca a partir do vértice i
        if (dfs(i, n, 1, grafo))
            return true; // Se encontrar um ciclo Hamiltoniano, retorna true
        visitado[i] = false; // Desmarca o vértice i para não visitado
        caminho.pop_back(); // Remove o vértice i do caminho 
    }
    return false; // Se nenhum ciclo Hamiltoniano for encontrado, retorna false
}

// Função para imprimir o ciclo
void imprimeCiclo() {
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
        G[a][b] = 1;
        G[b][a] = 1;
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

    visitado.resize(n); // Redimensiona o vetor visitado para o tamanho do grafo

    if (procurarCicloHamiltoniano(Grafo)) {
        imprimeCiclo();
    } else {
        cout << "Nenhum ciclo Hamiltoniano encontrado no grafo fornecido." << endl;
    }

    return 0;
}
