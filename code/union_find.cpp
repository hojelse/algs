/* 
  Union-Find - Weighted quick-union with path-compression
 */
#include "header.hpp"
struct union_find
{
	const int N;
	vi p;

	union_find(int n) : N(n), p(n, -1) { }

	int find(int x) {
		return p[x] < 0 ? x : p[x] = find(p[x]);
	}

	void uni(int x, int y) {
		int i = find(x);
		int j = find(y);
		if (i == j) return;
		if (p[i] < p[j]) swap(i, j);
		p[j] += p[i];
		p[i] = j;
	}

	void move(int s, int t) {
		int S = find(s);
		int T = find(t);
		if (S == T) return;
		int newSizeS = p[S]+1;
		int i = 0;
		if (s == S) // set first child of s as new root
		for (; i < N; i++) if (p[i] == s) { S = i; break; }
		for (; i < N; i++) if (p[i] == s) p[i] = S;
		p[S] = newSizeS;
		p[T]--;
		p[s] = T;
	}

	int size(int x) {
		return -p[find(x)];
	}
};