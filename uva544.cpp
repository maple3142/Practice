#include <memory.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int ID = 1;
unordered_map<string, int> MP;
int get_id(string& name) {
	if (MP.find(name) == MP.end()) {
		MP[name] = ID;
		return ID++;
	}
	return MP[name];
}

// disjoint set
int par[205] = {};
int find_par(int n) {
	if (par[n] == n)
		return n;
	return par[n] = find_par(par[n]);
}
void uni(int a, int b) {
	par[find_par(a)] = find_par(b);
}
inline void init_disj(int n) {
	for (int i = 1; i <= n; i++)
		par[i] = i;
}

struct Edge {
	int a, b, w;
};
Edge edges[20000];

// use kruskal to find maximum spanning tree until start and end is connected
int main(void) {
	ios::sync_with_stdio(false);
	int n, r, T = 1;
	while (cin >> n >> r) {
		if (n == r && r == 0)
			break;
		init_disj(n);
		for (int i = 1; i <= r; i++) {
			string na, nb;
			int w;
			cin >> na >> nb >> w;
			edges[i] = {get_id(na), get_id(nb), w};
		}
		sort(edges + 1, edges + 1 + r,
		     [](Edge& a, Edge& b) { return a.w > b.w; });
		string sstart, sdest;
		cin >> sstart >> sdest;
		int start = get_id(sstart), dest = get_id(sdest);
		int mnw = 0x3f3f3f3f;
		int i = 1;
		while (find_par(start) != find_par(dest)) {
			Edge e = edges[i++];
			uni(e.a, e.b);
			mnw = min(mnw, e.w);
		}
		cout << "Scenario #" << T++ << endl;
		cout << mnw << " tons" << endl << endl;
	}
	return 0;
}
