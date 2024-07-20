deque<int> dq; // Stores indices
dq.push_back(0);

for (int i = 1; i < n; i++) {
    // Remove elements not within the window
    while (!dq.empty() && dq.front() < i - r) {
        dq.pop_front();
    }

    // Current minimum in the window
    if (!dq.empty()) {
        dp[i] = dp[dq.front()] + d[i];
    }

    // Maintain deque order and remove useless elements
    while (!dq.empty() && dp[dq.back()] >= dp[i]) {
        dq.pop_back();
    }

    dq.push_back(i);
}