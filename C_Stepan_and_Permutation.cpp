#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> p[i];

        vector<vector<int>> adj(n + 1);

        for (int i = 1; i <= n; i++) {
            if (i + x <= n) {
                adj[i].push_back(i + x);
                adj[i + x].push_back(i);
            }
            if (i + y <= n) {
                adj[i].push_back(i + y);
                adj[i + y].push_back(i);
            }
        }

        vector<int> comp(n + 1, -1);
        int id = 0;

        for (int i = 1; i <= n; i++) {
            if (comp[i] != -1) continue;

            queue<int> q;
            q.push(i);
            comp[i] = id;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (comp[v] == -1) {
                        comp[v] = id;
                        q.push(v);
                    }
                }
            }
            id++;
        }

        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (comp[i] != comp[p[i]]) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}