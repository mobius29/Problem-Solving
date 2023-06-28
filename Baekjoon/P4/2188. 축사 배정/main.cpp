#include <bits/stdc++.h>
#define sync() ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
#define ends " "
#define pb push_back
#define MAX 201
using namespace std;

typedef pair<int ,int> pii;
typedef vector<int>  vi;
typedef vector<bool> vb;

const int INF = 0x3f3f3f3f;

int N, M, ans;
int matched_stable[MAX];
vi wanted_stable_list[MAX];

void solve(int current) {
  if (current > N) return;

  int start = current;
  for (auto stable: wanted_stable_list[current]) {
    while(true) {
      int stabled_cow = matched_stable[start];
      if (stabled_cow == 0) {
      }
    }
  }
}

int main() {
  sync(); cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    int S; cin >> S;

    wanted_stable_list[i].assign(S, 0);
    for (int j = 1; j <= S; ++j)
      cin >> wanted_stable_list[i][j];
  }

  for (int i = 1; i <= N; ++i) {
    solve(i);
  }
}