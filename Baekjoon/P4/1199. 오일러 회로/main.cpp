#include <bits/stdc++.h>
#define sync() ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
#define ends " "
#define pb push_back
using namespace std;

typedef vector<int>  vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int N;
vii linked[1001];
bool isVisited[1001][1001];

bool isValid() {
    vi oddNodes;

    for (int i = 1; i <= N; ++i) {
        int sum = 0;
        for (auto [next, size]: linked[i])
            sum += (size % 2);

        if (sum % 2) oddNodes.pb(i);
    }

    return oddNodes.size() == 0;
}

void dfs(int cur) {
    cout << cur << ends;
    for (auto [next, size]: linked[cur]) {
        if (size == 0 || isVisited[cur][next]) continue;
        isVisited[cur][next] = isVisited[next][cur] = true;

        for (int i = 0; i < size / 2; ++i)
            cout << next << ends << cur << ends;

        if (size % 2) dfs(next);
    }
}

int main() {
    sync(); cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int num; cin >> num;
            linked[i].pb({ j, num });
        }
    }

    if (isValid()) {
        cout << -1 << endl;
    }

    dfs(1);
}