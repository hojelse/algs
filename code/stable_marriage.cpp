// Gale-Shapley - STABLE MARRIAGE
// terminates after at most n^2 iterations of the While
// Assumes: 2 equal sized sets, full ranking, no ties
#include "header.hpp"
struct stable_marriage {
	ll N;
	mi proposers_rank_rejectors;
	mi rejectors_proposers_rank;
	vi next;
	map<ll, ll> matching;
	stable_marriage(ll N): 
		N(N),
		proposers_rank_rejectors(N, vi(N)),
		rejectors_proposers_rank(N, vi(N)),
		next(N, 0)
	{}
	vii gale_shapley() {
		queue<ll> free_proposers; for (ll i = 0; i < N; i++) free_proposers.push(i);
		while (!free_proposers.empty()) {
			ll p = free_proposers.front(); free_proposers.pop();
			if (next[p] >= N) continue;
			ll r = proposers_rank_rejectors[p][next[p]];
			bool r_is_free = matching.find(r) == matching.end();
			if (r_is_free) {
				matching[r] = p;
			} else {
				ll p1 = matching[r];
				bool r_refers_p1_to_p = rejectors_proposers_rank[r][p1] < rejectors_proposers_rank[r][p];
				if (r_refers_p1_to_p) {
					free_proposers.push(p);
					next[p]++;
				} else {
					free_proposers.push(p1);
					matching[r] = p; }}}
		vii pairs(N);
		int i = 0;
		for (auto [r, p] : matching)
			pairs[i++] = ii(p, r);
		return pairs; }};
