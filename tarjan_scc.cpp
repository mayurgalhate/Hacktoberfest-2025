// tarjan_scc.cpp
// Tarjan's Algorithm - Strongly Connected Components (SCC)
// Compile: g++ -std=c++17 tarjan_scc.cpp -O2 -o tarjan_scc
// Example: ./tarjan_scc

#include <bits/stdc++.h>
using namespace std;

class TarjanSCC {
    int n;
    vector<vector<int>> adj;
    vector<int> disc, low, st;
    vector<char> inStack;
    int timeCounter = 0;
    vector<vector<int>> sccs;

    void dfs(int u) {
        disc[u] = low[u] = ++timeCounter;
        st.push_back(u);
        inStack[u] = 1;

        for (int v : adj[u]) {
            if (disc[v] == 0) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (inStack[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }

        if (low[u] == disc[u]) {
            vector<int> comp;
            while (true) {
                int v = st.back();
                st.pop_back();
                inStack[v] = 0;
                comp.push_back(v);
                if (v == u) break;
            }
            sccs.push_back(comp);
        }
    }

public:
    TarjanSCC(int n): n(n), adj(
