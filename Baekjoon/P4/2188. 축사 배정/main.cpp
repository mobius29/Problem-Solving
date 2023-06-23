#include <bits/stdc++.h>
#define sync() ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
#define ends " "
#define pb push_back
#define MAX 200
using namespace std;

typedef pair<int ,int> pii;
typedef vector<int>  vi;
typedef vector<bool> vb;

const int INF = 0x3f3f3f3f;

int N, M, ans;
vi wanted_stable_list[MAX];

int main() {
  sync(); cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    int S; cin >> S;

    wanted_stable_list[i].assign(S, 0);
    for (int j = 0; j < S; ++j)
      cin >> wanted_stable_list[i][j];
  }

  
}