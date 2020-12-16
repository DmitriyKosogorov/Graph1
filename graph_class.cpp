#include<iostream>
#include<vector>
#include<string>
#include"graph_class.h"


Node::Node()
{
    name = "";
    value = 0;
}

Node::Node(string namek)
{
    name = namek;
    value = -1;
}

void Node::addNeighbour(string s)
{
    for (int i = 0; i < neighbours.size(); i++)
        if (neighbours[i] == s)
        {
            return;
        }
    neighbours.push_back(s);
    wayToNeighbour.push_back(1);
    return;
}

void Node::addNeighbour(string s, int way)
{
    for (int i = 0; i < neighbours.size(); i++)
        if (neighbours[i] == s)
        {
            cout << "Node already is in Neighbours" << endl;
            return;
        }
    neighbours.push_back(s);
    wayToNeighbour.push_back(way);
}

string Node::getName()
{
    return(name);
}

int Graph::getSize()
{
    return nodes.size();
}

Node Graph::getElementByName(string name)
{
    for (int i = 0; i < nodes.size(); i++)
        if (nodes[i].getName() == name)
            return(nodes[i]);
}

Node Graph::node(int index)
{
    return nodes[index];
}

bool isInVisited(Node elem)
{
    for (int i = 0; i < visited.size(); i++)
        if (visited[i] == elem.getName())
            return true;
    return false;
}

void Graph::addNode(Node elem)
{
    for (int i = 0; i < nodes.size(); i++)
        if (nodes[i].getName() == elem.getName())
            return;
    nodes.push_back(elem);
}

void DFS(Graph mas, Node elem)
{
    if (!(isInVisited(elem)))
    {
        visited.push_back(elem.getName());
        cout << elem.getName() << endl;
        for (int i = 0; i < elem.neighbours.size(); i++)
            DFS(mas, mas.getElementByName(elem.neighbours[i]));
    }
}
void printVisited()
{
    for (int i = 0; i < visited.size(); i++)
        cout << visited[i] << " ";
    cout << endl;
}

