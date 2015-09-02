#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph 
{
  int V; // nr of verticies in graph
  list<int> *adj; // adjacency list
public:
  Graph(int V);
  void addEdge(int v, int w); // function to add edge v to w;
  void BFS(int s); // some print of traversal starting from s;
};

Graph::Graph(int V)
{
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w); // add w to v's list.
}

void Graph::BFS(int s)
{
  // mark all the verticies as not visited (white)
  vector<bool> visited (V, false);

  // create a queue for BFS
  list<int> queue;

  // Mark node as visited and enqueue it
  visited[s] = true;
  queue.push_back(s);
 
  while(!queue.empty())
    {
      // Dequeue a vertex from que
      s = queue.front();
      cout << s << " - ";
      queue.pop_front();

      // Get all adjacent vertices of the dequeued vertex s
      // If a adjacent has not been visited, then mark it visited
      // and enqueue it
      for(auto i = adj[s].begin(); i != adj[s].end(); ++i)
        {
	  if(!visited[*i])
            {
	      visited[*i] = true;
	      queue.push_back(*i);
            }
        }
    }
}


int main()
{
    // Create a graph
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "BFS traversal from vertex 2 \n";
    g.BFS(2);
    cout << endl;
 
    return 0;
}
