#include "header.hpp"
void knapsack(mi& cache, vi& vs, vi& ws, ll N, ll W) {
	for (ll i = 1; i <= N; i++)
	for (ll w = 0; w <= W; w++)
	cache[i][w] =
		(w < ws[i-1])
		? cache[i-1][w]
		: max(cache[i-1][w], vs[i-1] + cache[i-1][w-ws[i-1]]);
}
vi get_idxs(mi& cache, vi& ws, ll N, ll W) {
	vi idxs;
	for (ll i = N, j = W; i > 0 && j >= 0; i--) {
		if(cache[i-1][j] >= cache[i][j]) continue;
		idxs.push_back(i-1);
		j -= ws[i-1];
	}
	return idxs;
}