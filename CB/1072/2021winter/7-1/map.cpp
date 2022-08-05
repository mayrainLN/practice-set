#include <iostream>
#include <map>
using namespace std;
int a[10010], vis[10010];
int m1ain() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, x;
	cin >> n >> m;
	while(m--) {
		int maxn = 0;
		map<int, int> b;
		for(int i = 0; i < n; ++i){
			cin >> a[i];
			b[a[i]]++;
		}
		for(int i = 0; i < n; ++i) {
			maxn = max(maxn, n - b[a[i]]);
		}
		for(int i = 0; i < n; ++i) {
			if(n - b[a[i]] == maxn)
				vis[i + 1]++;
		}
	}
	int ans = 1;
	for(int i = 2; i <= n; ++i){
		if(vis[i] > vis[ans])
			ans = i;
	}
	cout << ans;
}
