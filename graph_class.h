#pragma once
#ifndef Graph_H
#define Graph_H
using namespace std;

vector<string> visited;
vector<int> edit;

class Node
{
private:
    vector<string> neighbours;
    vector<int> wayToNeighbour;
    int value;
    string name;
public:
    Node();
    Node(string namek);
    string getName();
    void addNeighbour(string s);
    void addNeighbour(string s, int way);
    friend class Graph;
    friend void DFS(Graph mas, Node elem);
};
class Graph
{
public:
    vector<Node> nodes;
    int getSize();
    Node getElementByName(string name);
    Node node(int index);
    void addNode(Node elem);
};

bool isInVisited(Node elem);
void DFS(Graph mas, Node elem);
void printVisited();
#endif
