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
vi answer;
vector<point> point_list;

double getDist(point p, point start, point end) {
  int a = end.second - start.second, b = start.first - end.first;
  int c = start.second * end.first - start.first * end.second;

  int q = a * p.first + b * p.second + c;
  int a_sqaure = a * a, b_square = b * b;

  return (double)q / (a_sqaure + b_square);
}

void solve(vi list, int start_idx, int end_idx, int max_idx, bool isLeftToRight) {
  answer.pb(max_idx);
  
  point start = point_list[start_idx], end = point_list[end_idx], max = point_list[max_idx];

  vi start_max, max_end;
  int start_max_idx = -1, max_end_idx = -1;
  double start_max_dist = -1, max_end_dist = -1;

  for (int i = 0; i < list.size(); ++i) {
    point cur = point_list[list[i]];

    if (isLeftToRight) {
      if (cur.first < max.first) {
        double dist = getDist(cur, start, max);
        if (dist > 0) {
          start_max.pb(list[i]);
          if (dist > start_max_dist) {
            start_max_idx = list[i];
            start_max_dist = dist;
          }        
        }
      }

      if (cur.first > max.first) {
        double dist = getDist(cur, max, end);
        if (dist > 0) {
          max_end.pb(list[i]);
          if (dist > max_end_dist) {
            max_end_idx = list[i];
            max_end_dist = dist;
          }
        }
      }
    }

    else {
      if (cur.first > max.first) {
        double dist = getDist(cur, start, max);
        if (dist > 0) {
          start_max.pb(list[i]);
          if (dist > start_max_dist) {
            start_max_idx = list[i];
            start_max_dist = dist;
          }        
        }
      }

      if (cur.first < max.first) {
        double dist = getDist(cur, max, end);
        if (dist > 0) {
          max_end.pb(list[i]);
          if (dist > max_end_dist) {
            max_end_idx = list[i];
            max_end_dist = dist;
          }
        }
      } 
    }
  }

  if (start_max.size() > 0) solve(start_max, start_idx, max_idx, start_max_idx, isLeftToRight);
  if (max_end.size() > 0) solve(max_end, max_idx, end_idx, max_end_idx, isLeftToRight);
}

int main() {
  sync(); cin >> N;
  int min_idx = 40001, max_idx = -40001;
  int min_x = -1, max_x = -1;

  for (int i = 0; i < N; ++i) {
    point p; cin >> p.first >> p.second;
    point_list.pb(p);


    if (p.first < min_x) {
      min_idx = i;
      min_x = p.first;
    }

    if (p.first > max_x) {
      max_idx = i;
      max_x = p.first;
    }
  }

  answer.pb(min_idx); answer.pb(max_idx);

  vi left, right;
  int max_left_idx = -1, max_right_idx = -1;
  double max_left_dist = -1, max_right_dist = -1;
  for (int i = 0; i < N; ++i) {
    double dist = getDist(point_list[i], point_list[min_idx], point_list[max_idx]);

    if (dist < 0) {
      left.pb(i);
      max_left_idx = i;
      max_left_dist = max(max_left_dist, abs(dist));
    }
    if (dist > 0) {
      right.pb(i);
      max_right_idx = i;
      max_right_dist = max(max_right_dist, dist);
    }
  }

  if(left.size() > 0) solve(left, max_idx, min_idx, max_left_idx, false);
  if(right.size() > 0 )solve(right, min_idx, max_idx, max_right_idx, true);

  cout << answer.size() << endl;
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