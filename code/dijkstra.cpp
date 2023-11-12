// Dijkstra - SINGLE SOURCE SHORTEST PATHS
// O(E log V) time O(V) space
#include "header.hpp"
vi sssp_dijkstra(mii &adj, ll &s) {
	vi distTo;
	priority_queue<ii, vii, greater<ii>> pq;
	for (ll i = 0; i < adj.size(); i++)
		distTo.push_back(inf);
	pq.push(ii{0, s});
	distTo[s] = 0;
	while (!pq.empty()) {
		auto [prio, v1] = pq.top();
		pq.pop();
		// relax vertex
		for (ii edge : adj[v1]) {
			auto [v2, w] = edge;
			if (prio > distTo[v2])
				continue;
			if (distTo[v2] > distTo[v1] + w) {
				distTo[v2] = distTo[v1] + w;
				pq.push(ii{distTo[v2], v2}); }}}
	return distTo; }