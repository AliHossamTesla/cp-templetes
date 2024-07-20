typedef long long ll;
const ll LINF = LLONG_MAX;

ll F(ll m) {
    // Define the function to compare the two halves in the range [L, R]
    return m;
}

ll Ternary_Search(ll L, ll R) {
    while (R - L >= 10) {
        ll m1 = L + (R - L) / 3;
        ll m2 = R - (R - L) / 3;
        if (F(m1) < F(m2)) {
            R = m2;
        } else {
            L = m1;
        }
    }
    ll ans = LINF;
    for (ll i = L; i <= R; i++) {
        ans = min(ans, F(i));
    }
    return ans;
}
const double LINF = 1e18;
const double EPS = 1e-9;

double F(double m) {
    // Define the function to compare the two halves in the range [L, R]
    return m;
}

double Ternary_Search(double L, double R) {
    double ans = LINF;
    while (R - L >= EPS) {
        double m1 = L + (R - L) / 3;
        double m2 = R - (R - L) / 3;
        double f1 = F(m1);
        double f2 = F(m2);
        if (f1 < f2) {
            R = m2;
        } else {
            L = m1;
        }
        ans = min({ans, f1, f2});
    }
    return ans;
}