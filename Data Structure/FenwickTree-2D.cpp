// Template-based 2D Fenwick Tree (Binary Indexed Tree)
template <typename T = int>
struct Fenwick_Tree {
    vector<vector<T>> Tree; // 2D vector to store tree nodes
    int n, m;               // Dimensions of the tree
    T DEFAULT;              // Default value (0 for addition)

    // Constructor to initialize Fenwick Tree with given dimensions
    Fenwick_Tree(int rows = 0, int cols = 0) {
        n = rows + 1;
        m = cols + 1;
        DEFAULT = 0;
        Tree.assign(n + 10, vector<T>(m + 10, DEFAULT)); // Initialize with default values
    }

    // Returns the lowest set bit (LSB) of the index
    int lowest_bit(int idx) {
        return (idx & -idx);
    }

    // Builds the Fenwick Tree from a given 2D vector
    void build(vector<vector<T>>& nums) {
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < nums[0].size(); j++)
                add(i + 1, j + 1, nums[i][j]);
    }

    // Defines the operation to be performed (addition in this case)
    T operation(T a, T b) {
        return a + b;
    }

    // Adds a value to the element at index (idx, jdx)
    void add(int idx, int jdx, T val) {
        int i = idx + 1, j;
        while (i <= n) {
            j = jdx + 1;
            while (j <= m) {
                Tree[i][j] = operation(Tree[i][j], val); // Update the tree
                j += lowest_bit(j); // Move to the next column index
            }
            i += lowest_bit(i); // Move to the next row index
        }
    }

    // Gets the prefix sum from (0, 0) to (idx, jdx)
    T get_sum(int idx, int jdx) {
        T sum = DEFAULT; // Initialize result with default value
        int i = idx + 1, j;
        while (i) {
            j = jdx + 1;
            while (j) {
                sum = operation(sum, Tree[i][j]); // Accumulate results
                j -= lowest_bit(j); // Move to the parent column index
            }
            i -= lowest_bit(i); // Move to the parent row index
        }
        return sum; // Return the prefix sum
    }

    // Queries the sum in the rectangle defined by (x1, y1) to (x2, y2)
    T query(int x1, int y1, int x2, int y2) {
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        return get_sum(x2, y2) - get_sum(x1 - 1, y2) - get_sum(x2, y1 - 1) + get_sum(x1 - 1, y1 - 1);
    }
};