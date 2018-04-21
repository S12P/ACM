#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int min(int a, int b) {
	return b < a ? b : a;
}

int main() {
	int P, T;
	int p1, p2, l;

	while (cin >> P >> T) {
		// matric de liaison
		vector<vector<int> > mat(P);
		for (int i = 0; i < P; i++)
			for (int j = 0; j < P; j++)
				mat[i].push_back(INT_MAX);

		while(T--) {
			cin >> p1 >> p2 >> l;
			mat[p1][p2] = mat[p2][p1] = l;
		}

		vector<int> dists(P);
		vector<bool> seen(P);
		vector<int> counts(P);

		for (int i = 1; i < P; i++) {
			dists[i] = INT_MAX;
			seen[i] = false;
			counts[i] = 0;
		}

		dists[0] = 0;
		counts[0] = 1;
		seen[0] = false;


		for (int i = 0; i < P; i++) {
			// recherche du min
			int max = -1;
			int mind = INT_MAX;
			int path;

			for (int k = 0; k < P; k++) {
				if (dists[k] < mind && !seen[k]) {
					mind = dists[k];
					max = k;
					path = counts[k];
				}
			}

			if (max == -1) break;

			seen[max] = true;

			for (int j = 0; j < P; j++) {
				if (!seen[j]) {
					if (mat[max][j] != INT_MAX) {
						int nl = dists[max] + mat[max][j];
						if (nl < dists[j]) {
							dists[j] = nl;
							counts[j] = path;
						}
						else if (nl == dists[j]) {
							counts[j] += path;
						}
					}
				}
			}
		}

		int min_length = dists[P - 1];

		cout << 2 * counts[P - 1] * min_length << endl;

	}
}
