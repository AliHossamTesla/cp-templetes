#include <bits/stdc++.h>
using namespace std;

// Struct to handle Lowest Common Ancestor (LCA) queries
struct LCA {
    vector<int> height, euler, first, segtree; // vectors to store node heights, Euler tour, first occurrence, and segment tree
    vector<bool> visited; // to mark visited nodes during DFS
    int n; // number of nodes

    // Constructor to initialize the LCA structure
    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n); // resize height vector to hold height of all nodes
        first.resize(n); // resize first occurrence vector
        euler.reserve(n * 2); // reserve space for Euler tour
        visited.assign(n, false); // initialize visited vector to false
        dfs(adj, root); // start DFS from the root node
        int m = euler.size();
        segtree.resize(m * 4); // resize segment tree to handle the Euler tour
        build(1, 0, m - 1); // build the segment tree
    }

    // DFS to populate height, first occurrence, and Euler tour
    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true; // mark node as visited
        height[node] = h; // set the height of the current node
        first[node] = euler.size(); // record the first occurrence of the node
        euler.push_back(node); // add the node to the Euler tour
        for (int to : adj[node]) { // visit all adjacent nodes
            if (!visited[to]) {
                dfs(adj, to, h + 1); // recursive call for the child node with increased height
                euler.push_back(node); // add the node again to the Euler tour after returning from the child
            }
        }
    }

    // Build the segment tree based on Euler tour
    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b]; // if it's a leaf node, set the value directly
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid); // build the left child
            build(node << 1 | 1, mid + 1, e); // build the right child
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r; // set the current node to the node with the minimum height
        }
    }

    // Query the segment tree to find the node with the minimum height in the range
    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1; // out of range
        if (b >= L && e <= R)
            return segtree[node]; // completely within range
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R); // query left child
        int right = query(node << 1 | 1, mid + 1, e, L, R); // query right child
        if (left == -1) return right; // if left is out of range, return right
        if (right == -1) return left; // if right is out of range, return left
        return height[left] < height[right] ? left : right; // return the node with the minimum height
    }

    // Function to find the LCA of two nodes
    int lca(int u, int v) {
        int left = first[u], right = first[v]; // get the first occurrences of u and v in the Euler tour
        if (left > right)
            swap(left, right); // ensure left is less than right
        return query(1, 0, euler.size() - 1, left, right); // query the segment tree to find the LCA
    }
};

int main() {
    // Number of nodes
    int n = 7;

    // Adjacency list representation of the tree
    vector<vector<int>> adj(n);

    // Example tree
    //    0
    //   / \
    //  1   2
    // /|   |\
    // 3 4   5 6

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(5);
    adj[2].push_back(6);

    // Root of the tree
    int root = 0;

    // Create the LCA instance
    LCA lca(adj, root);

    // Query for LCAs
    int u = 3, v = 4;
    cout << "LCA of " << u << " and " << v << " is " << lca.lca(u, v) << endl; // Output: 1

    u = 3, v = 5;
    cout << "LCA of " << u << " and " << v << " is " << lca.lca(u, v) << endl; // Output: 0

    u = 4, v = 6;
    cout << "LCA of " << u << " and " << v << " is " << lca.lca(u, v) << endl; // Output: 0

    u = 5, v = 6;
    cout << "LCA of " << u << " and " << v << " is " << lca.lca(u, v) << endl; // Output: 2

    return 0;
}
