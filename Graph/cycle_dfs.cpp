#include<iostream>
#include<list>
#include<vector>

class Graph
{
    int _v;
    std::list<int> *adj;
    bool cyclicHelper(int v, std::vector<bool> &visited, std::vector<bool> &stack);
public:
    Graph(int v);
    void addEdge(int u, int v);
    bool isCyclic();
};

Graph::Graph(int v): _v(v)
{
    adj = new std::list<int> [_v];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

bool Graph::cyclicHelper(int v, std::vector<bool> &visited, std::vector<bool> &stack)
{
    if(!visited[v])
    {
        visited[v] = true;
        stack[v] = true;
        std::list<int>::iterator it;
        for(it = adj[v].begin(); it != adj[v].end(); it++)
        {
            if(!visited[*it])
                {
                    if(cyclicHelper(*it, visited, stack))
                    return true;
                }
                
            else if (stack[*it])
                    return true;
        }

    }
    stack[v] = false;
    return false;
}

bool Graph::isCyclic()
{
    std::vector<bool> visited(_v, false);
    std::vector<bool> rec_stack(_v, false);
    for (int i =0; i< _v; i++)
          if(cyclicHelper(i, visited, rec_stack)) 
            return true;
    return false;
}

int main(int argc, char *argv[])
{
    Graph G(4);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.addEdge(3,0);
   // G.addEdge(2);

    bool result = G.isCyclic();
    if(result) std::cout << "Cycle is there" << std::endl;
    else std::cout << "Cycle is not there" << std::endl;

    return 0;
}