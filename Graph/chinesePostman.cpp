#include <bits/stdc++.h>
using namespace std;
// Function to calculate shortest distances between all pairs of nodes
// using the Floyd-Warshall algorithm.
vector<vector<int>> floydWarshalls(vector<vector<pair<int, int>>> &g, int n) {
    // Initializing the distances matrix with infinity.
    vector<vector<int>> d(n, vector<int>(n, INT_MAX));

    // Setting the diagonal to 0 (distance from a node to itself).
    for (int i = 0; i < n; i++)
        d[i][i] = 0;

    // Updating the matrix with direct edges from adjacency list.
    for (int i = 0; i < n; i++) {
        for (auto &p : g[i]) {
            // Taking minimum if multiple edges exist between same nodes.
            d[i][p.first] = min(d[i][p.first], p.second);
        }
    }

    // Floyd-Warshall algorithm to compute shortest paths.
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (d[i][k] == INT_MAX)
                continue; // Skip unreachable paths.
            for (int j = 0; j < n; j++) {
                if (d[k][j] == INT_MAX)
                    continue;
                // Relaxation step.
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    // Returning the shortest distance matrix.
    return d;
}

// Helper function to generate all possible perfect matchings of odd degree nodes.
void genPairs(vector<int> &odd, int idx, vector<pair<int, int>> &curr,
              vector<vector<pair<int, int>>> &res, vector<bool> &used) {
    int n = odd.size();

    // Base case: If all odd nodes are paired, add current matching to result.
    if (idx == n) {
        res.push_back(curr);
        return;
    }

    // If current odd node already matched, skip to next.
    if (used[idx]) {
        genPairs(odd, idx + 1, curr, res, used);
        return;
    }

    // Mark current node as used.
    used[idx] = true;

    // Pair it with all remaining unused odd nodes.
    for (int j = idx + 1; j < n; j++) {
        if (!used[j]) {
            used[j] = true;

            // Add the pair to current matching list.
            curr.push_back({odd[idx], odd[j]});

            // Recurse for next index.
            genPairs(odd, idx + 1, curr, res, used);

            // Backtrack.
            curr.pop_back();
            used[j] = false;
        }
    }

    // Unmark current node for future matchings.
    used[idx] = false;
}

class Solution {
  public:
    // Main function to solve the Chinese Postman Problem (CPP).
    int chinesePostmanProblem(vector<vector<int>> &e, int n) {
        vector<vector<pair<int, int>>> g(n); // Graph adjacency list.
        int sum = 0; // Variable to store sum of all edge weights.

        // Building the graph and computing total edge weight.
        for (auto &x : e) {
            int a = x[0] - 1, b = x[1] - 1, w = x[2];
            sum += w;

            // Adding edges (undirected graph).
            g[a].push_back({b, w});
            g[b].push_back({a, w});
        }

        // Finding all nodes with odd degree.
        vector<int> odd;
        for (int i = 0; i < n; i++) {
            if (g[i].size() % 2)
                odd.push_back(i);
        }

        // If no odd nodes ? graph is already Eulerian.
        if (odd.empty())
            return sum;

        // Generate all perfect matchings of odd degree nodes.
        vector<vector<pair<int, int>>> allPairs;
        vector<pair<int, int>> curr;
        vector<bool> used(odd.size(), false);

        genPairs(odd, 0, curr, allPairs, used);

        // Compute all-pairs shortest path matrix.
        auto d = floydWarshalls(g, n);

        int best = INT_MAX; // Minimum extra cost to add.

        // Evaluate each perfect matching.
        for (auto &pairs : allPairs) {
            int tmp = 0;

            for (auto &p : pairs) {
                // If odd nodes are unreachable ? CPP impossible.
                if (d[p.first][p.second] == INT_MAX) {
                    tmp = INT_MAX;
                    break;
                }
                // Summing shortest distances for matched odd pairs.
                tmp += d[p.first][p.second];
            }

            // Storing best possible minimum added distance.
            best = min(best, tmp);
        }

        // If no possible eulerian augmentation.
        if (best == INT_MAX)
            return -1;

        // Final answer = sum of all edges + min extra cost of pairing odd nodes.
        return sum + best;
    }
};