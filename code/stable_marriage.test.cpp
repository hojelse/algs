// test on small examples from Algorithm Design (Klienberg Tardos)
#include "stable_marriage.cpp"
int main() {
  ll N, P, R;
  cin >> N;

  stable_marriage sm(N);

  for (ll p = 0; p < N; p++) {
    for (ll rank = 0; rank < N; rank++) {
      cin >> R;
      sm.proposers_rank_rejectors[p][rank] = R;
    }
  }

  for (ll r = 0; r < N; r++) {
    for (ll rank = 0; rank < N; rank++) {
      cin >> P;
      sm.rejectors_proposers_rank[r][P] = rank;
    }
  }
  
  auto pairs = sm.gale_shapley();
  for (auto [p, r] : pairs) {
    cout << p << " " << r << endl;
  }
}
