#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int abs (int x) {
	return x < 0 ? - x : x;
}

int min(int a, int b) {
	return a > b ? b : a;
}

int price(vector<int> cuts, int g, int d) {
	int target = (g + d + 1) / 2;
	int dist = INT_MAX;
	int minx = -1;

	for (int i = 0; i < cuts.size(); i++) {
		if (cuts[i] >= d) break;
		if (cuts[i] > g) {
			int d = abs(target - cuts[i]);
			if (d < dist) {
				dist = d;
				minx = i;
			}
			else if (d == dist) {
				int res = d - g;	
				int v1 = price(cuts, g, cuts[i]) + price(cuts, cuts[i], d);
				int v2 = price(cuts, g, cuts[minx]) + price(cuts, cuts[minx], d);
				return res + min(v1, v2);
			}
		}
	}

	int res = 0;

	if (minx != -1) {
		res += d - g;
		res += price(cuts, g, cuts[minx]);
		res += price(cuts, cuts[minx], d);
	}
	
	return res;
}

int main() {
	int size;
	int nb, cut;
	while (cin >> size) {
		if (size == 0) break;
		cin >> nb;
		vector<int> cuts;

		for (int i = 0; i < nb; i++) {
			cin >> cut;
			cuts.push_back(cut);
		}

		cout << price(cuts, 0, size) << endl;
	}	
	return 0;
}
