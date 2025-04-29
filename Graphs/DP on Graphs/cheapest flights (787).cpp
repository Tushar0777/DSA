#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    const int INF = 1e9;
    vector<int> prev(n, INF);
    prev[src] = 0;

    // Relax edges up to K+1 times (at most K stops means K+1 edges)
    for (int i = 0; i <= K; ++i) {
        vector<int> curr = prev; // copy previous state
        for (auto& flight : flights) {
            int u = flight[0], v = flight[1], w = flight[2];
            if (prev[u] != INF) {
                curr[v] = min(curr[v], prev[u] + w);
            }
        }
        prev = curr; // move to next stage
    }

    return (prev[dst] == INF) ? -1 : prev[dst];
}
