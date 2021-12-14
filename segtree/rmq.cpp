#include <iostream>
#include <vector>
#include <limits>
#include <functional>
using namespace std;
using ll = long long int;


/* SegTreeLazy<X,M>(n,fx,fa,fm,ex,em): モノイド(集合X, 二項演算fx,fa,fm, 単位元ex,em)についてサイズnで構築
    set(int i, X x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b):  [a,b) 全てにfxを作用させた値を取得。O(log(n))
*/
template <typename X, typename M>
struct SegTreeLazy {
    using FX = function<X(X,X)>;
    using FA = function<X(X,M)>;
    using FM = function<M(M,M)>;
    int n;
    FX fx;
    FA fa;
    FM fm;
    const X ex;
    const M em;
    vector<X> dat;
    vector<M> lazy;
    SegTreeLazy(int n_, FX fx_, FA fa_, FM fm_, X ex_, M em_)
        : n(), fx(fx_), fa(fa_), fm(fm_), ex(ex_), em(em_), dat(4*n_, ex), lazy(4*n_, em) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }

    void set(int i, X x) {
        dat[i] = x;
    }
    void build() {
        for (int i = n/2-1; i >= 0; i--) {
            dat[i] = fx(dat[i*2+1], dat[i*2+2]);
        }
    }

    void eval(int k) {
        if (lazy[k] == em) return;
        if (k < n - 1) {
            lazy[k*2+1] = fm(lazy[k*2+1],dat[k]);
            lazy[k*2+2] = fm(lazy[k*2+2],dat[k]);
        }
    }

    void update(int a, int b, M x) { update_sub(a, b, x, 0, 0, n); }
}


int main() {
    return 0;
}