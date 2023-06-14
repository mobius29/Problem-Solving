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

int N;
vii point_list, answer_list;

double get_distance(pii, pii, pii);
int find_max_distance_idx(vii, pii, pii, pii);
void solve(vii, pii, pii);

int main() {
  sync(); cin >> N;
  for(int i = 0; i < N; ++i) {
    int x, y; cin >> x >> y;
    point_list.pb({ x, y });
  }

  sort(all(point_list));

  vii left, right;
  for(int i = 0; i < N; ++i) {
    double dist = get_distance(point_list[0], point_list[N-1], point_list[i]);
    if (dist == 0) continue;

    if (dist > 0) right.pb(point_list[i]);
    else left.pb(point_list[i]);
  }

  if (left.size() > 0) solve(left, point_list[N-1], point_list[0]);
  if (right.size() > 0) solve(right, point_list[0], point_list[N-1]);

  answer_list.pb(point_list[0]); answer_list.pb(point_list[N-1]);
  cout << answer_list.size() << endl;
}

double get_distance(pii start, pii end, pii p) {
  ll x2_x1 = end.first - start.first, y2_y1 = end.second - start.second;
  ll y1_y0 = start.second - p.second, x1_x0 = start.first - p.first;

  ll denomi_x = x2_x1 * x2_x1, denomi_y = y2_y1 * y2_y1;
  ll denomi = denomi_x + denomi_y;

  ll numera_x = x2_x1 * y1_y0, numera_y = x1_x0 * y2_y1;
  ll numera = (numera_x - numera_y) * (numera_x - numera_y);

  return (double)numera / denomi;
}

int find_max_distance_idx(vii list, pii start, pii end) {
  int max_distance_idx = 0;
  double max_distance = 0;
  for (int i = 1; i < list.size(); ++i) {
    double dist = get_distance(start, end, list[i]);
    if (dist == 0) continue;

    if (dist > max_distance) {
      max_distance_idx = i;
      max_distance = dist;
    }
  }

  return max_distance_idx;
}

void solve(vii list, pii start, pii end) {
  int max_distance_idx = find_max_distance_idx(list, start, end);
  pii max_distance_point = list[max_distance_idx]; answer_list.pb(max_distance_point);
  bool is_left_to_right = end.first - start.first > 0;

  vii start_to_max_idx_list, max_idx_to_end_list;
  for (int i = 0; i < list.size(); ++i) {
    if (i == max_distance_idx) continue;

    if (is_left_to_right) {
      if (i < max_distance_idx) {
        double distance = get_distance(start, max_distance_point, list[i]);
        if (distance > 0) start_to_max_idx_list.pb(list[i]);
      } else {
        double distance = get_distance(max_distance_point, end, list[i]);
        if (distance > 0) max_idx_to_end_list.pb(list[i]);
      }
    }

    else {
      if (i < max_distance_idx) {
        double distance = get_distance(max_distance_point, end, list[i]);
        if (distance > 0) max_idx_to_end_list.pb(list[i]);
      } else {
        double distance = get_distance(start, max_distance_point, list[i]);
        if (distance > 0) start_to_max_idx_list.pb(list[i]); 
      }
    }
  }

  if (start_to_max_idx_list.size() > 0) solve(start_to_max_idx_list, start, max_distance_point);
  if (max_idx_to_end_list.size() > 0) solve(max_idx_to_end_list, max_distance_point, end);
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