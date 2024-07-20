/*
 * Description : trie implementations for some applications.
 */
/*
 * Search Engine auto complete based on weight.
 * source : @Tesla
 * Verification : https://shorturl.at/CGNVh
 */
#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
	TrieNode* child[ALPHABET_SIZE]{};
	int weight;
	TrieNode() : weight(-1) {
		fill(begin(child), end(child), nullptr);
	}
};

void insert_key(TrieNode* root, const string& s, int w) {
	TrieNode* current_node = root;
	for (char c : s) {
		if (current_node->child[c - 'a'] == nullptr) {
			current_node->child[c - 'a'] = new TrieNode();
		}
		current_node = current_node->child[c - 'a'];
		current_node->weight = max(current_node->weight, w); // Update weight during insertion
	}
	current_node->weight = max(current_node->weight, w); // Ensure the end node has the correct weight
}

int search_prefix(TrieNode* root, const string& s) {
	TrieNode* current_node = root;
	for (char c : s) {
		if (current_node->child[c - 'a'] == nullptr) {
			return -1;
		}
		current_node = current_node->child[c - 'a'];
	}
	return current_node->weight;
}

int main() {
	int n, m;
	cin >> n >> m;
	TrieNode* root = new TrieNode();
	for (int i = 0; i < n; i++) {
		string s;
		int w;
		cin >> s >> w;
		insert_key(root, s, w);
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		int ans = search_prefix(root, s);
		cout << ans << '\n';
	}
	// Memory cleanup (not required in competitive programming but good practice)
	// TODO: Implement memory cleanup if needed
}

// general one :
const int ALPHABET_SIZE = 26 ;
struct TrieNode{
	struct TrieNode* child[ALPHABET_SIZE]{};
	// This will keep track of number of strings that are
	// stored in the Trie from root node to any Trie node.
	int word_count;
	TrieNode(){
		word_count = 0 ;
		for(auto &i : child)
			i = nullptr ;
	}
};
void insert_key(TrieNode* root, string& s){
	TrieNode* current_node = root ;
	for(auto c : s){
		// Check if the node exist for the current
		// character in the Trie.
		if(current_node->child[c - 'a'] == nullptr){
			// If node for current character does not exist
			// then make a new node
			auto* new_node = new TrieNode() ;
			// Keep the reference for the newly created
			// node.
			current_node->child[c - 'a'] = new_node;
		}
		// Now, move the current node pointer to the newly
		// created node.
		current_node = current_node->child[c - 'a'];
	}
	// Increment the wordEndCount for the last currentNode
	// pointer this implies that there is a string ending at
	// currentNode.
	current_node->word_count ++ ;
}
bool search_prefix(TrieNode* root, string& s){
	TrieNode* current_node = root ;
	for(auto c : s){
		if(current_node->child[c - 'a'] == nullptr){
			return false;
		}
		current_node = current_node->child[c - 'a'] ;
	}
	return true ;
}
bool search_key(TrieNode* root, string& s){
	TrieNode* current_node = root ;
	for(auto c : s){
		if(current_node->child[c - 'a'] == nullptr){
			return false;
		}
		current_node = current_node->child[c - 'a'] ;
	}
	return (current_node->word_count > 0) ; // check if there is word end here ;
}
bool delete_key(TrieNode* root, string& s){
	TrieNode* current_node = root;
	TrieNode* last_branch_node = nullptr;
	char last_branch_char = 'a' ;

	for(auto c : s){
		if(current_node->child[c - 'a'] == nullptr) return false ;
		else{
			int cnt = 0 ;
			for(auto i : current_node->child)
				if(i != nullptr)
					cnt ++ ;
			if(cnt > 1){
				last_branch_char = c ;
				last_branch_node = current_node ;
			}
			current_node = current_node->child[c - 'a'] ;
		}
	}

	int cnt = 0 ;
	for(auto i : current_node->child){
		if(i != nullptr)
			cnt ++ ;
	}

	// The deleted word is a prefix of other words in Trie.
	if(cnt > 0){
		current_node->word_count -- ;
		return true ;
	}

	// The deleted word shares a common prefix with other words in Trie.
	if(last_branch_node != nullptr){
		last_branch_node->child[last_branch_char - 'a'] = nullptr ;
		return true ;
	}

		// The deleted word does not share any common prefix with other words in Trie.
	else{
		root->child[s[0] - 'a'] = nullptr ;
		return true ;
	}
}

/*
 * Trie for maximum xor sub array
 * verification :https://codeforces.com/contest/1847/problem/C
 */
const int INT_SIZE = 32 ;
struct TrieNode{
	int val ;
	TrieNode* child[2]{} ;
	TrieNode(){
		val = 0 ;
		child[0] = child[1] = nullptr ;
	}
};
void insert(TrieNode* root,int pref_xor){
	auto current_node = root ;
	for(int i = INT_SIZE - 1 ; i >= 0 ; i --){
		if(current_node->child[pref_xor >> i & 1] == nullptr)
			current_node->child[pref_xor >> i & 1] = new TrieNode() ;
		current_node = current_node->child[pref_xor >> i & 1] ;
	}
	current_node->val = pref_xor ;
}
int query(TrieNode* root,int pref_xor){
	auto current_node = root ;
	for(int i = INT_SIZE - 1 ; i >= 0 ; i --){
		if(current_node->child[1 - (pref_xor >> i & 1)] != nullptr)
			current_node = current_node->child[1 - (pref_xor >> i & 1)] ;
		else
			current_node = current_node->child[pref_xor >> i & 1] ;
	}
	return pref_xor ^ (current_node->val) ;
}
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc ; cin >> tc ;
	while(tc--){
		int n ; cin >> n ;
		auto root = new TrieNode() ;
		insert(root,0) ;
		int ans = -inf,pref_xor = 0 ;
		for(int i = 0 ; i < n ; i ++){
			int vl ; cin >> vl ;
			pref_xor ^= vl ;
			ans = max(ans, query(root,pref_xor)) ;
			insert(root,pref_xor) ;
		}
		cout << ans << '\n' ;
	}
	return 0;
}
// Dictionary trie + dp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(x) begin(x), end(x)
const int inf = 1e18;
const int MOD1 = 1000000007;
const int MOD2 = 998244353;
const int ALPHABET_SIZE = 26;
struct TrieNode {
	struct TrieNode* child[ALPHABET_SIZE]{};
	int word_count;
	TrieNode() {
		word_count = 0;
		for (auto& i : child)
			i = nullptr;
	}
};

void insert_key(TrieNode* root, string& s) {
	TrieNode* current_node = root;
	for (auto c : s) {
		if (current_node->child[c - 'a'] == nullptr) {
			auto* new_node = new TrieNode();
			current_node->child[c - 'a'] = new_node;
		}
		current_node = current_node->child[c - 'a'];
	}
	current_node->word_count++;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	int n;
	cin >> n;
	TrieNode* root = new TrieNode();
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		insert_key(root, t);
	}
	n = s.size();
	vector<int> dp(n + 1, 0);
	dp[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		TrieNode* current_node = root;
		for (int j = i; j < n; j++) {
			if (current_node == nullptr) break;
			current_node = current_node->child[s[j] - 'a'];
			if (current_node != nullptr && current_node->word_count > 0) {
				dp[i] = (dp[i] + dp[j + 1]) % MOD1;
			}
		}
	}
	cout << dp[0] << '\n';
	return 0;
}

