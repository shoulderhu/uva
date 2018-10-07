#include <iostream>
#include <algorithm>

using namespace std;

class disjointSet {

	struct student {

		int g, t;
	}S[30000];

public:
	inline void init(int n) {

		for (int i = 0; i < n; ++i) {

			S[i].g = i;
			S[i].t = 1;
		}
	}

	inline int find(int s) {

		if (S[s].g == s) { return s; }
		else { return S[s].g = find(S[s].g); }
	}

	inline void unit(int a, int b) {

		a = find(a), b = find(b);
		if (a > b) { swap(a, b); }

		if (a != b) {

			S[b].g = a;
			S[a].t += S[b].t;
		}
	}

	inline int getSuspect() {

		return S[0].t;
	}
}djs;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k, a, b;

	while (cin >> n >> m && !(n == 0 && m == 0)) {

		djs.init(n);

		for (int i = 0; i < m; ++i) {

			cin >> k >> a;

			for (int j = 1; j < k; ++j) {

				cin >> b;
				djs.unit(a, b);
			}
		}

		cout << djs.getSuspect() << '\n';
	}

	return 0;
}
