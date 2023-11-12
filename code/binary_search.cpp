// Binary Search - SEARCH
// O(log2 n) time _ space
// Assumes: A is sorted
#include "header.hpp"
struct res {ll exact; ll floor; ll ceil;};
res binary_search(vi& A, ll x) {
	ll n = A.size();
	ll lo = 0;
	ll hi = n-1;
	while (lo <= hi) {
		ll mid = (lo+hi)/2;
		if (A[mid] == x) return (struct res){mid, mid, mid};
		if (A[mid] > x) hi = mid-1;
		else lo = mid+1; }
	return (struct res){-1, hi, (lo<n)?lo:-1}; }
// Example: auto [i, f, c] = binary_search(A, x);
