#include <iostream>
#include <cstring>

using namespace std;

int mat[51][51];
bool vis[51];

void visite(int int_) {
  vis[int_] = true;
  for (int i = 0; i < 51; i++) {
    if (mat[int_][i] && !vis[i]) {
      visite(i);
    }
  }
}

void affiche(int int_) {
  for (int i = 0; i < 51; i++) {
    if (mat[int_][i]) {
      mat[int_][i]--;
      mat[i][int_]--;
      affiche(i);
      cout << i << " " << int_ << "\n";
    }
  }
}

int main() {
  int T, case_=1,compteur=0;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    compteur = 0;
    int deg[51] = {};
    memset(mat, 0, sizeof(mat));
    memset(vis, 0, sizeof(vis));
    cout << "Case #" << case_ << "\n";
    case_++;
    while (N--) {
      int a, b;
      cin >> a >> b;
      compteur++;
      deg[a]++;
      deg[b]++;
      mat[a][b]++;
      mat[b][a]++;
    }
    bool impossible = true;
    for (int i = 0; i < 51; i++) {
      if (deg[i]) {
        impossible = false;
      }
    }
    if (impossible) {
      for (int i = 0; i < 51; i++) {
        if (deg[i]) {
          visite(i);
          for (int j = 0; j < 51; j++) {
            if (deg[j] && !vis[j]) {
              impossible = false;
            }
          }
          if (impossible) {
            affiche(i);
          }
          break;
        }
      }
    }
    if (!impossible) {
      cout << "some beads may be lost" << "\n";
    }
    if (T) {
      cout << "\n";
    }
  }
  return 0;
}
