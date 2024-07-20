/*
 * Description: String Hashing - using binomial.
 * by: @Tesla.
 * verification: https://codeforces.com/contest/1950/submission/271266056
 */
class HashedString {
private:
	static const int A1 = 9973;
	static const int A2 = 10007;
	static int B1;
	static int B2;
	static vector<int> Mods;
	static vector<int> p1, p2;
	vector<int> h1, h2;

	void preparePowers(int size) {
		while (p1.size() <= size) {
			p1.push_back((p1.back() * A1) % B1);
			p2.push_back((p2.back() * A2) % B2);
		}
	}

public:
	HashedString(const string& s) : h1(s.size() + 1), h2(s.size() + 1) {
		preparePowers(s.size());

		h1[0] = 0;
		h2[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			h1[i + 1] = (h1[i] * A1 + s[i]) % B1;
			h2[i + 1] = (h2[i] * A2 + s[i]) % B2;
		}
	}

	pair<int, int> get_hash(int start, int end) { // 0-indexed
		int hash1 = (h1[end + 1] - (h1[start] * p1[end - start + 1]) % B1 + B1) % B1;
		int hash2 = (h2[end + 1] - (h2[start] * p2[end - start + 1]) % B2 + B2) % B2;
		return {hash1, hash2};
	}

	static void initialize() {
		// Initialize random device and engine
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distr(0, Mods.size() - 1);

		// Randomly select two different moduli from the list
		B1 = Mods[distr(gen)];
		do {
			B2 = Mods[distr(gen)];
		} while (B2 == B1);

		p1 = {1};
		p2 = {1};
	}
};

int HashedString::B1;
int HashedString::B2;
vector<int> HashedString::Mods = {
		1099999997, 1099999961, 1099999907, 1099999819, 1099999781, 1099999723, 1099999721, 1099999711,
		1099999657, 1099999613, 1099999601, 1099999573, 1099999561, 1099999543, 1099999531, 1099999507,
		1099999477, 1099999429, 1099999427, 1099999393, 1099999349, 1099999301, 1099999289, 1099999279,
		1099999267, 1099999231, 1099999189, 1099999151, 1099999141, 1099999111, 1099999079, 1099999067,
		1099999057, 1099999049, 1099999037, 1099998997, 1099998961, 1099998959, 1099998929, 1099998883,
		1099998877, 1099998871, 1099998859, 1099998847, 1099998827, 1099998733, 1099998727, 1099998709,
		1099998707, 1099998701, 1099998659, 1099998649, 1099998629, 1099998587, 1099998577, 1099998541,
		1099998533, 1099998511, 1099998509, 1099998467, 1099998443, 1099998409, 1099998377, 1099998371,
		1099998353, 1099998343, 1099998337, 1099998313, 1099998287, 1099998281, 1099998269, 1099998257,
		1099998227, 1099998169, 1099998157, 1099998149, 1099998131, 1099998083, 1099998041, 1099998037,
		1099998001, 1099997957, 1099997953, 1099997929, 1099997909, 1099997879, 1099997867, 1099997863,
		1099997861, 1099997849, 1099997813, 1099997741, 1099997737, 1099997719, 1099997693, 1099997687,
		1099997671, 1099997627, 1099997623, 1099997617, 892846183, 892846133, 892846111, 892846091,
		892846051, 892846021, 892845983, 892845979, 892845977, 892845949, 892845931, 892845917, 892845893,
		892845871, 892845869, 892845847, 892845817, 892845799, 892845769, 892845743, 892845727, 892845719,
		892845677, 892845641, 892845619, 892845617, 892845563, 892845529, 892845497, 892845469, 892845461,
		892845449, 892845427, 892845413, 892845391, 892845383, 892845361, 892845329, 892845319, 892845311,
		892845277, 892845259, 892845223, 892845221, 892845209, 892845139, 892845137, 892845071, 892845067,
		892845061
};
vector<int> HashedString::p1 = {1};
vector<int> HashedString::p2 = {1};

int main() {
	HashedString::initialize();
	string s = "example";
	HashedString hs(s);

	int start = 1, end = 3; // example substring "xam"
	pair<int, int> hash = hs.get_hash(start, end);

	cout << "Hash of substring: (" << hash.first << ", " << hash.second << ")" << endl;
	return 0;
}
/*
class HashedString {
private:
    static const int A1 = 9973;
    static const int A2 = 10007;
    static const int B1 = 1000000007; // example prime number
    static const int B2 = 1000000009; // example prime number
    static vector<int> p1, p2;
    vector<int> h1, h2;

    void preparePowers(int size) {
        while (p1.size() <= size) {
            p1.push_back((p1.back() * A1) % B1);
            p2.push_back((p2.back() * A2) % B2);
        }
    }

public:
    HashedString(const string& s) : h1(s.size() + 1), h2(s.size() + 1) {
        preparePowers(s.size());

        h1[0] = 0;
        h2[0] = 0;
        for (int i = 0; i < s.size(); i++) {
            h1[i + 1] = (h1[i] * A1 + s[i]) % B1;
            h2[i + 1] = (h2[i] * A2 + s[i]) % B2;
        }
    }

    pair<int, int> get_hash(int start, int end) { // 0-indexed
        int hash1 = (h1[end + 1] - (h1[start] * p1[end - start + 1]) % B1 + B1) % B1;
        int hash2 = (h2[end + 1] - (h2[start] * p2[end - start + 1]) % B2 + B2) % B2;
        return {hash1, hash2};
    }
};

vector<int> HashedString::p1 = {1};
vector<int> HashedString::p2 = {1};
*/
/*
 *  simple version.
	int A = 69420 ;
	int B = 1e9 + 9 ;
	vector<int> p(n);
	p[0] = 1;
	for (int i = 1; i < n; i++) {
		p[i] = (p[i - 1] * A) % B;
	}
	vector<int>pref(n + 1) ;
	for(int i = 1; i <= n ; i ++)
		pref[i] = ((pref[i - 1] * A + s[i - 1]))% B ;
	auto get_hash = [&](int st,int ed){
		int h = pref[ed + 1] - (p[ed - st + 1] * pref[st] % B) % B ;
		return h < 0 ? (h + B) % B : h;
	};
*/