#include <iostream>
#include <algorithm>

using namespace std;

int n;
int tree[200000], bleft[100000], bright[100000];

void setTree() {

	for (int i = n - 1; i > 0; --i) {

		tree[i] = max(tree[2 * i], tree[2 * i + 1]);
	}
}

int getTree(int i, int j) {

	int m = 0;

	for (i += n, j += n; i <= j; i /= 2, j = (j - 1) / 2) {

		if (i % 2 != 0) {

			m = max(m, tree[i]);
			++i;
		}
		if (j % 2 == 0) {

			m = max(m, tree[j]);
			--j;
		}
	}

	return m;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int q, ii, jj, last, now, fre, Max;

	while (cin >> n && n != 0) {

		cin >> q;
		last = -100001;
		fre = 1;

		for (int i = 0; i < n; ++i) {

			cin >> now;
			tree[i + n] = 0;
			bright[i] = 0;

			if (now == last) {

				bleft[i] = bleft[i - 1];
				++fre;

				if (i == n - 1) {

					bright[i] = i;
					tree[i + n] = fre;
				}
			}
			else {

				bleft[i] = i;

				if (i - 1 >= 0) {

					bright[i - 1] = i - 1;
					tree[i - 1 + n] = fre;
					fre = 1;
				}
			}

			last = now;
		}

		for (int i = n - 2; i >= 0; --i) {

			if (tree[i + n] == 0) {

				tree[i + n] = tree[i + 1 + n];
				bright[i] = bright[i + 1];
			}
		}

		setTree();

		for (int i = 0; i < q; ++i) {

			cin >> ii >> jj;
			--ii;
			--jj;
			Max = 0;

			if (bleft[ii] == bleft[jj]) {

				cout << jj - ii + 1 << '\n';
			}
			else {

				if (ii > bleft[ii]) {

					Max = max(Max, bright[ii] - ii + 1);
					ii = bright[ii] + 1;
				}
				if (jj < bright[jj]) {

					Max = max(Max, jj - bleft[jj] + 1);
					jj = bleft[jj] - 1;
				}
				if (ii > jj) {

					cout << Max << '\n';
				}
				else {

					cout << max(Max, getTree(ii, jj)) << '\n';
				}
			}
		}
	}

	return 0;
}