// Template-based Fenwick Tree (Binary Indexed Tree)
template <typename T = int>
struct Fenwick_Tree {
    vector<T> Tree; // Vector to store tree nodes
    int n;          // Size of the tree
    T DEFAULT;      // Default value (0 for addition)

    // Constructor to initialize Fenwick Tree with a given size
    Fenwick_Tree(int sz = 0) {
        n = sz + 1;
        DEFAULT = 0;
        Tree = vector<T>(n + 10, DEFAULT); // Initialize with default values
    }

    // Defines the operation to be performed (addition in this case)
    T operation(T a, T b) {
        return a + b;
    }

    // Returns the lowest set bit (LSB) of the index
    int lowest_bit(int idx) {
        return (idx & -idx);
    }

    // Builds the Fenwick Tree from a given vector
    void build(vector<T>& nums) {
        for (int i = 0; i < nums.size(); i++)
            add(i, nums[i]);
    }

    // Adds a value to the element at index idx
    void add(int idx, T val) {
        idx++; // Increment index to match tree structure
        while (idx <= n) {
            Tree[idx] = operation(Tree[idx], val); // Update the tree
            idx += lowest_bit(idx); // Move to the next index
        }
    }

    // Gets the prefix sum from 0 to idx
    T get_ans(int idx) {
        T ans = DEFAULT; // Initialize result with default value
        idx++; // Increment index to match tree structure
        while (idx) {
            ans = operation(ans, Tree[idx]); // Accumulate results
            idx -= lowest_bit(idx); // Move to the parent index
        }
        return ans; // Return the prefix sum
    }

    // Queries the sum in the range [l, r]
    T query(int l, int r) {
        if (l > r) return DEFAULT; // Invalid range, return default
        return get_ans(r) - get_ans(l - 1); // Compute range sum
    }

    // Gets the value at a specific index
    T get(int idx) {
        return query(idx, idx); // Query the value at a single index
    }
};