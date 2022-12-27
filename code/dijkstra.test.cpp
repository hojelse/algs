#include "dijkstra.cpp"
// Test on https://open.kattis.com/problems/shortestpath1
int main(void) {
  ll n, m, q, s;
  while (true)
  {
    cin >> n >> m >> q >> s;
    if (n==0 && m==0 && q==0 && s==0) break;

    // Create adj
    mii adj;
    ll v1, v2, w;
    for (ll i = 0; i < n; i++)
      adj.push_back(vii{});

    for (ll i = 0; i < m; i++) {
      cin >> v1 >> v2 >> w;
      adj[v1].push_back(ii{v2, w});
    }
    
    // Run single source shortest-paths dijkstra
    vector<ll> distTo = sssp_dijkstra(adj, s);

    // Run queries on distTo
    ll queryVertex;
    for (ll i = 0; i < q; i++) {
      cin >> queryVertex;
      if (distTo[queryVertex] == inf)
        cout << "Impossible" << endl;
      else
        cout << distTo[queryVertex] << endl;
    }
    cout << endl;
  }
  return 0;
}