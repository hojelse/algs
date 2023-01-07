/*
  Kruskal's Algorithm - Minimum Spanning Tree
  time O(E log E)
  space O(E)
*/
#include "header.hpp"
#include "union_find.cpp"
struct Edge { ll u, v, w; };
struct UndirectedEdgeWeigtedGraph {
  ll V;
  vector<vector<Edge>> g;
  UndirectedEdgeWeigtedGraph(ll V)
    : V(V), g(V) {}
  void add_edge(ll u, ll v, ll w) {
    g[u].push_back(Edge{u, v, w});
    g[u].push_back(Edge{v, u, w});
  }
};

ll kruskal(UndirectedEdgeWeigtedGraph& G, vector<Edge>& mst, ll& W) {
  if (G.V==1) return true;
  vector<Edge> es;
  for (auto l : G.g)
    for (auto e : l)
      es.push_back(e);
  sort(es.begin(), es.end(),
    [](Edge& a, Edge& b){return a.w < b.w;});
  union_find uf = union_find(G.V);
  for (auto edge : es) {
    if (mst.size() == G.V-1) return true;
    if (uf.find(edge.u) == uf.find(edge.v)) continue;
    uf.uni(edge.u, edge.v);
    mst.push_back(edge);
    W += edge.w;
  }
  return false;
}
