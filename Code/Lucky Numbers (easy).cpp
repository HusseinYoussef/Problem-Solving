#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
	
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	vector<string> words;
	vector<string> sorted_words;
	vector<string> rp;
	string s;
	bool rep = false;
	cin >> s;
	while (s != "#") {
		words.push_back(s);
		string m = s;
		sort(m.begin(), m.end());
		sorted_words.push_back(m);
		cin >> s;
	}
	for (int i = 0; i<words.size(); i++) {
		for (int j = 0; j<words.size(); j++) {
			if (i == j) continue;
			if (sorted_words[i] == sorted_words[j]) {
				rep = true;
				break;
			}
		}
		if (!rep) {
			rp.push_back(words[i]);
		}
	}
	sort(rp.begin(), rp.end());
	for (int i = 0; i<rp.size(); i++) {
		cout << rp[i] << endl;
	}
	return 0;
}

