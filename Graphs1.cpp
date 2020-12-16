#include<iostream>
#include<fstream>
#include<vector>
#include "graph_class.cpp"
using namespace std;
int main()
{
    Graph graph;
    int i = 0, size = 0,j=0,k=0,d;
    string s,s1;
    ifstream file;
    file.open("TestGraph.txt");
    file >> s;
    file >> s;
    while(1)
    {
        file >> s;
        graph.addNode(Node(s));

        file >> s1;
        graph.addNode(Node(s1));

        for (i = 0; i < graph.nodes.size(); i++)
        {
            if (graph.nodes[i].getName() == s)
                graph.nodes[i].addNeighbour(s1);
            if (graph.nodes[i].getName() == s1)
                graph.nodes[i].addNeighbour(s);
        }
        if (file.eof())
            break;
    }
    for (i = 0; i < graph.getSize(); i++)
    {
        if (!(isInVisited(graph.node(i))))
        {
            cout << "Graph " << k << ":" << endl;
            k++;
            DFS(graph, graph.node(i));
        }
    }
    cout << endl;

}
