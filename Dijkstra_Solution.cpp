class Solution {
public:
    // Dijkstra's algorithm to compute shortest paths from source node 'i' to all other nodes
    vector<int> dijkstra(int i, unordered_map<int, vector<pair<int, int>>>& mp, int n) {
        // Min-heap priority queue to get the node with the smallest cost
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.push({0, i});

        vector<int> ans(n, INT_MAX);  // Store shortest distances
        ans[i] = 0;                   // Distance to source is 0

        while (!q.empty()) {
            auto top = q.top();
            q.pop();
            int node = top.second;
            int cost = top.first;

            for (auto a : mp[node]) {
                int nodeint = a.first;
                int costint = a.second;
                // Relaxation: update if a shorter path is found
                if (ans[nodeint] > cost + costint) {
                    ans[nodeint] = cost + costint;
                    q.push({cost + costint, nodeint});
                }
            }
        }
        return ans;
    }

    // Determines for each edge whether it lies on *any* shortest path from node 0 to node n-1
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> mp;

        // Build adjacency list from edge list
        for (auto edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int cost = edge[2];
            mp[from].emplace_back(to, cost);
            mp[to].emplace_back(from, cost);
        }

        // Run Dijkstra from node 0 and node n-1
        vector<int> first = dijkstra(0, mp, n);
        vector<int> second = dijkstra(n - 1, mp, n);

        int lastans = first[n - 1]; // Shortest distance from 0 to n-1
        vector<bool> ans;

        // Check for each edge if it can be part of any shortest path from 0 to n-1
        for (auto edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int cost = edge[2];
            bool valid = false;

            if (first[from] != INT_MAX && second[to] != INT_MAX &&
                first[from] + cost + second[to] == lastans)
                valid = true;

            if (first[to] != INT_MAX && second[from] != INT_MAX &&
                first[to] + cost + second[from] == lastans)
                valid = true;

            ans.push_back(valid);
        }

        return ans;
    }
};
