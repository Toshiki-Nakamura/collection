#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP

#include <vector>
#include <map>

struct UnionFind {
	vector<long> par; // par[i]:iの親の番号 (例) par[3] = 2 : 3の親が2
	map<long, long> mp;
	UnionFind(long N) : par(N) { //最初は全てが根であるとして初期化
		for(long i = 0; i < N; i++) par[i] = i;
	}

	long root(long x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	void unite(long x, long y) { // xとyの木を併合
		long rx = root(x); //xの根をrx
		long ry = root(y); //yの根をry
		if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
		par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
	}

	bool same(long x, long y) { // 2つのデータx, yが属する木が同じならtrueを返す
		long rx = root(x);
		long ry = root(y);
		return rx == ry;
	}
	long	&operator[](long v) {
		return mp[v];
	}
};

#endif
