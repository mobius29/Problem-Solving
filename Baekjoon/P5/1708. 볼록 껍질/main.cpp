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
typedef vector<int>  vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef tuple<int, int, int> ti;
typedef tuple<ll, ll, ll> tl;
typedef pii point;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int N, ans;


double getDist(point p, point start, point end) {
  int a = end.second - start.second, b = start.first - end.first;
  int c = start.second * end.first - start.first * end.second;

  int q = a * p.first + b * p.second + c;
  int a_sqaure = a * a, b_square = b * b;

  return (double)q / (a_sqaure + b_square);
}

void find(vector<point> list, point start, point end) {
  vector<pii> new_list;
  int max_point_idx = -1;
  double max = -1;

  for(int i = 0; i < list.size(); ++i) {
    double dist = getDist(list[i], start, end);

    if (dist > 0) {
      new_list.pb(list[i]);
      if (dist > max) {
        max_point_idx = i;
        max = dist;
      }
    }
  }

  if (max_point_idx == -1) return;
  
  ++ans;

  find(new_list, start, list[max_point_idx]);
  find(new_list, list[max_point_idx], end);
}

int main() {
  sync(); cin >> N; ans = 2;
  vector<point> point_list;

  for (int i = 0; i < N; ++i) {
    point p; cin >> p.first >> p.second;
    point_list.pb(p);
  }

  point min, max;
  min = max = point_list[0];
  for(int i = 1; i < N; ++i) {
    if (point_list[i].first < min.first) min = point_list[i];
    if (point_list[i].first > max.first) max = point_list[i];
  }

  find(point_list, min, max);
  find(point_list, max, min);

  cout << ans << endl;
}

/*
8
1 1
1 2
1 3
2 1
2 2
2 3
3 1
3 2

5
*/