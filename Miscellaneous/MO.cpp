#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005; // Adjust based on the problem constraints
const int BLOCK_SIZE = 320; // Block size, typically sqrt(MAXN)

struct Query {
    int L, R, idx;
    bool operator<(const Query& other) const {
        int block_own = L / BLOCK_SIZE;
        int block_other = other.L / BLOCK_SIZE;
        if (block_own != block_other)
            return block_own < block_other;
        return R < other.R;
    }
};

vector<int> answer(MAXN); // To store answers of queries
int arr[MAXN]; // Input array
int freq[MAXN]; // Frequency array
int current_answer = 0; // Variable to store the current answer

// Add an element to the current segment
void add(int pos) {
    freq[arr[pos]]++;
    if (freq[arr[pos]] == 1) // Change the condition based on the problem
        current_answer++;
}

// Remove an element from the current segment
void remove(int pos) {
    if (freq[arr[pos]] == 1) // Change the condition based on the problem
        current_answer--;
    freq[arr[pos]]--;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; // Size of the array
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Read the array
    }

    int q; // Number of queries
    cin >> q;

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].L >> queries[i].R;
        queries[i].L--; // Converting to 0-based index
        queries[i].R--;
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end());

    int current_L = 0, current_R = -1;

    for (const auto& query : queries) {
        while (current_R < query.R) {
            current_R++;
            add(current_R);
        }
        while (current_R > query.R) {
            remove(current_R);
            current_R--;
        }
        while (current_L < query.L) {
            remove(current_L);
            current_L++;
        }
        while (current_L > query.L) {
            current_L--;
            add(current_L);
        }
        answer[query.idx] = current_answer; // Store the answer for the current query
    }

    for (int i = 0; i < q; i++) {
        cout << answer[i] << '\n'; // Output all answers
    }

    return 0;
}
