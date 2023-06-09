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
vector<point> ans_list;

double getDist(point p, point start, point end) {
  int a = end.second - start.second, b = start.first - end.first;
  int c = start.second * end.first - start.first * end.second;

  int q = a * p.first + b * p.second + c;
  int a_sqaure = a * a, b_square = b * b;

  return (double)q / (a_sqaure + b_square);
}

void solve(vector<point> list, point start, point end) {
  int size = list.size();

  int max_point_idx = 0; double max_dist = 0;
  for(int i = 0; i < size; ++i) {
    double dist = getDist(list[i], start, end);

    if (dist > max_dist) {
      max_dist = dist;
      max_point_idx = i;
    }
  }
  
  vector<point> left, right;
  point max_point = list[max_point_idx]; ans_list.pb(max_point);

  for(int i = 0; i < size; ++i) {
    if (i > max_point_idx) {
      double dist = getDist(list[i], start, max_point);
      if (dist > 0) left.pb(list[i]);
    }
    else if (i < max_point_idx) {
      double dist = getDist(list[i], max_point, end);
      if (dist > 0) right.pb(list[i]);
    }
  }

  if (left.size() > 0) solve(left, start, max_point);
  if (right.size() > 0) solve(right, max_point, end);
}

int compare(point a, point b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}

int main() {
  sync(); cin >> N;
  vector<point> point_list;
  for (int i = 0; i < N; ++i) {
    point p; cin >> p.first >> p.second;
    point_list.pb(p);
  }

  sort(all(point_list), compare);
  ans_list.pb(point_list[0]);
  ans_list.pb(point_list[N-1]);

  vector<point> up, down;
  for(int i = 1; i < N - 1; ++i) {
    double dist = getDist(point_list[i], point_list[0], point_list[N-1]);
    if (dist > 0) up.pb(point_list[i]);
    else if (dist < 0) down.pb(point_list[i]);
  }

  if (up.size() > 0) solve(up, point_list[0], point_list[N-1]);
  if (down.size() > 0) solve(down, point_list[N-1], point_list[0]);

  // cout << endl;
  // for(int i = 0; i < ans_list.size(); ++i) {
  //   cout << ans_list[i].first << ends << ans_list[i].second << endl;
  // }
  cout << ans_list.size() << endl;
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