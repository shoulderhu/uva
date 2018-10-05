#include <iostream>

using namespace std;

int N;
int tree[200000];

void setTree() {

	for (int i = N - 1; i > 0; --i) {

		tree[i] = tree[2 * i] * tree[2 * i + 1];
	}
}

void uptTree(int I, int V) {

	I = I + N;
	tree[I] = V;

	for (I /= 2; I > 0; I /= 2) {

		tree[I] = tree[2 * I] * tree[2 * I + 1];
	}
}

int getTree(int I, int J) {

	int product = 1;

	for (I += N, J += N; I <= J; I /= 2, J = (J - 1) / 2) {

		if (I % 2 != 0) {

			product *= tree[I];
			++I;
		}
		if (J % 2 == 0) {

			product *= tree[J];
			--J;
		}
	}

	return product;
}

int getNormal(int X) {

	if (X > 0) { return 1; }
	else if (X < 0) { return -1; }
	else { return 0; }
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int K, X, I, J;
	char command;
	
	while (cin >> N >> K) {

		for (int i = 0, j = N; i < N; ++i, ++j) {

			cin >> X;
			tree[j] = getNormal(X);
		}

		setTree();

		for (int i = 0; i < K; ++i) {

			cin >> command >> I >> J;

			if (command == 'C') {

				uptTree(I - 1, getNormal(J));
			}
			else {

				X = getTree(I - 1, J - 1);
				if (X > 0) { cout << '+'; }
				else if (X < 0) { cout << '-'; }
				else { cout << 0; }
			}
		}

		cout << '\n';
	}

	return 0;
}
