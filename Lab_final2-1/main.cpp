#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int findSet(int u) {
        if (parent[u] != u) {
            parent[u] = findSet(parent[u]);
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = findSet(u);
        int rootV = findSet(v);

        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                swap(rootU, rootV);
            }
            parent[rootV] = rootU;
            if (rank[rootU] == rank[rootV]) {
                rank[rootU]++;
            }
        }
    }
};

int minChocolatesToSpreadRumor(int n, int m, vector<int>& chocolates, vector<pair<int, int>>& friendships) {
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({chocolates[u - 1] + chocolates[v - 1], {u, v}});
    }

    sort(edges.begin(), edges.end());

    DisjointSet disjointSet(n);
    int totalChocolates = 0;

    for (const auto& edge : edges) {
        int cost = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (disjointSet.findSet(u) != disjointSet.findSet(v)) {
            totalChocolates += cost;
            disjointSet.unionSets(u, v);
        }
    }

    return totalChocolates;
}

int main() {
    ifstream file("input.txt");
    int n, m;
    file >> n >> m;

    vector<int> chocolates(n);
    for (int i = 0; i < n; ++i) {
        file >> chocolates[i];
    }

    vector<pair<int, int>> friendships(m);
    for (int i = 0; i < m; ++i) {
        file >> friendships[i].first >> friendships[i].second;
    }

    file.close();

    int result = minChocolatesToSpreadRumor(n, m, chocolates, friendships);
    cout << result << endl;

    return 0;
}
