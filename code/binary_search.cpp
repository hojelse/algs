/*
  Binary search
  time O(log2 N)
  Assumes A is sorted
*/
#include "header.hpp"
ll binary_search(vector<ll>& A, ll x) {
	ll lo = 0;
	ll hi = A.size()-1;
	while (lo <= hi) {
		ll mid = (lo+hi)/2;
		if (A[mid] == x) return mid;
		if (A[mid] > x) hi = mid-1;
		else lo = mid+1;
	}
	return -1;
}