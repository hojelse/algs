#include "kruskal.cpp"
// Test on https://itu.kattis.com/problems/minspantree
bool cmp_by_u_then_v(const Edge& a, const Edge& b) {
  if (a.u == b.u) return a.v < b.v;
  return a.u < b.u;
}
int main() {
  ll n, m;
  while (true) {
    cin >> n >> m;
    if (n == 0 && m == 0) return 0;

    UndirectedEdgeWeigtedGraph G = UndirectedEdgeWeigtedGraph(n);

    ll u, v, w;
    for (ll i = 0; i < m; i++) {
      cin >> u >> v >> w;
      G.add_edge(u, v, w);
    }

    vector<Edge> mst;
    ll W = 0;
    if (kruskal(G, mst, W)) {
      cout << W << endl;
      // Transform edges such that u < v
      for (ll i = 0; i < mst.size(); i++) {
        Edge e = mst[i];
        if (e.u > e.v) mst[i] = Edge{e.v, e.u, e.w};
      }
      // sort edges in lexicographic order
      sort(mst.begin(), mst.end(), cmp_by_u_then_v);
      // print edges
      for (auto [u, v, w] : mst) cout << u << " " << v << endl;
    } else {
      cout << "Impossible" << endl;
    }
  }
  return 0;
}