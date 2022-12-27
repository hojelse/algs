#include "ford_fulkerson.cpp"
// Test on https://open.kattis.com/problems/maxflow
int main() {
  ll n, m, s, t;
  cin >> n >> m >> s >> t;

  Flow G = Flow(n, s, t);
  ll u, v, c;
  for (ll i = 0; i < m; i++) {
    cin >> u >> v >> c;
    G.add_edge(u, v, c);
  }

  ll maxflow = G.max_flow();

  vector<Edge> solution_edges;
  for (auto edge : G.es)
    if (edge.f > 0)
      solution_edges.push_back(edge);

  cout << n << " " << maxflow << " " << solution_edges.size() << endl;
  for (auto e : solution_edges)
    cout << e.u << " " << e.v << " " << e.f << endl;

  return 0;
}
