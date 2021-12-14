#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
using ll = long long int;

class UnionFind {
public:
    vector<ll> par, siz;
    UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; i++) {
            par[i] = i;
        }
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);
        for (ll i = 0; i < sz_; i++) {
            par[i] = i;
        }
    }

    ll root(ll x) {
        while(x != par[x]) {
            x = par[x];
            par[x] = par[par[x]];
        }
        return x;
    }

    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) {
            swap(x, y);
        }
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    bool issame(ll x, ll y) {
        return root(x) == root(y);
    }

    ll size(ll x) {
        return siz[root(x)];
    }

};

int main() {

}