#include <iostream>
#include <algorithm>

using namespace std;

struct student {

	int g, t;
}students[30000];

int getRoot(int i) {

	if (students[i].g == i) { return i; }
	else { return students[i].g = getRoot(students[i].g); }
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k, a, b;

	while (cin >> n >> m && !(n == 0 && m == 0)) {

		for (int i = 0; i < n; ++i) {

			students[i].g = i;
			students[i].t = 1;
		}

		for (int i = 0; i < m; ++i) {

			cin >> k >> a;

			for (int j = 1; j < k; ++j) {

				cin >> b;				
				a = getRoot(a);
				b = getRoot(b);
				if (a > b) { swap(a, b); }

				if (a != b) {
					
					students[b].g = a;
					students[a].t += students[b].t;
				}
			}
		}

		cout << students[0].t << '\n';
	}

	return 0;
}