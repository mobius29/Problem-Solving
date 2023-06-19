#include <bits/stdc++.h>
#define sync() ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
#define ends " "
#define fs first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define getx(x, i) get<(x)>(i)
using namespace std;

typedef long long ll;
typedef pair<int ,int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef vector<int>  vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<pil> vil;
typedef tuple<int, int, int> ti;
typedef tuple<ll, ll, ll> tl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int N, M;
vll updrafts_pos, updrafts_neg;

int main() {
  sync(); cin >> N >> M;

  updrafts_pos.pb({ 0, 0 }); updrafts_neg.pb({ 0, 0 });
  for(int i = 0; i < N; ++i) {
    ll x, p; cin >> x >> p;

    if (x < 0) updrafts_neg.pb({ -x, p });
    else updrafts_pos.pb({ x, p });
  }

  sort(all(updrafts_neg));
  sort(all(updrafts_pos));

  vector<vll> dp[2];
  for (int i = 0; i < 2; ++i)
    dp[i].assign(updrafts_pos.size() + 1, vll(updrafts_neg.size() + 1, { -LINF, -LINF }));

  dp[0][0][0] = dp[1][0][0] = { M, M };
  for (int i = 1; i <= updrafts_pos.size(); ++i) {
    auto [xi, pi] = updrafts_pos[i];
    auto [max_height, cur_height] = dp[0][i-1][0];

    ll distance = xi - updrafts_pos[i-1].first;
    if (cur_height < distance) break;

    ll next_height = cur_height == distance ? 0 : cur_height - distance + pi;
    dp[0][i][0] = { max_height + pi, next_height };

    if (next_height == 0) break;
  }

  for (int j = 1; j <= updrafts_pos.size(); ++j) {
    auto [xi, pi] = updrafts_neg[j];
    auto [max_height, cur_height] = dp[0][0][j-1];

    ll distance = xi - updrafts_neg[j-1].first;
    if (cur_height < distance) break;

    ll next_height = cur_height == distance ? 0 : cur_height - distance + pi;
    dp[1][0][j] = { max_height + pi, next_height };

    if (next_height == 0) break;
  }

}