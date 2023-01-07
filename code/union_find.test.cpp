// Test on https://itu.kattis.com/problems/itu.disjointsets
#include "union_find.cpp"
int main() {
  int n, m;
  cin >> n >> m;

  auto uf = union_find(n);

  int op, s, t;
  for (int i = 0; i < m; i++)
  {
    cin >> op >> s >> t;
    if (op == 0) cout << ((uf.find(s) == uf.find(t)) ? 1 : 0) << endl;
    if (op == 1) uf.uni(s, t);
    if (op == 2) uf.move(s, t);
  }
  return 0;
}