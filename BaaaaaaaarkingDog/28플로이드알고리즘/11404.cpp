#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int city[105][105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(city[0], &city[104][105], -1);
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (city[a][b] == -1) {
            city[a][b] = c;
        }
        else {
            city[a][b] = min(city[a][b], c);
        }
    }
 
    for(int i = 1; i <= n; i++) city[i][i] = 0; // 같은 자리면 0으로 만들어주기

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                int fp = city[j][i];
                int sp = city[i][k];
                if (fp == -1 || sp == -1) continue;
                if (city[j][k] == -1) {
                    city[j][k] = fp+sp;
                }
                else {
                    city[j][k] = min(city[j][k], fp + sp);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (city[i][j] == -1) cout << "0 "; // 무한이면 0으로 만들어야함.
            else cout << city[i][j] << " ";
        }
        cout << "\n";
    }
} 