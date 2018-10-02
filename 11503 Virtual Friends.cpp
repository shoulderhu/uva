#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct people {

	int t;
	string g;
}p;

unordered_map<string, people> friends;

string getRoot(string s) {

	if (friends[s].g == s) { return s; }
	else {

		return friends[s].g = getRoot(friends[s].g);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, F;
	string a, b;

	cin >> T;

	for (int i = 0; i < T; ++i) {

		cin >> F;
		friends.clear();

		for (int j = 0; j < F; ++j) {

			cin >> a >> b;

			if (friends.find(a) == friends.end()) {

				p.t = 1;
				p.g = a;
				friends[a] = p;
			}

			if (friends.find(b) == friends.end()) {

				p.t = 1;
				p.g = b;
				friends[b] = p;
			}

			a = getRoot(a);
			b = getRoot(b);
			
			if (a != b) {

				friends[b].g = a;
				friends[a].t += friends[b].t;
			}

			cout << friends[a].t << '\n';
		}
	}

	return 0;
}
