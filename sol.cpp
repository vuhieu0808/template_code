#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug2.h"
#else
#define debug(...) 42
#endif // LOCAL

void setIO(const string& NAME = "") {
#ifdef LOCAL
    const string inp = ".in";
#else
    const string inp = ".inp";
#endif // LOCAL

    ios::sync_with_stdio(false);
    cin.tie(0);

    if ((int) NAME.length() && fopen((NAME + inp).c_str(), "r"))
        freopen((NAME + inp).c_str(), "r", stdin),
        freopen((NAME + ".out").c_str(), "w", stdout);
}

template<class X, class Y> bool ckmin(X &a, const Y& b) { return (b < a) ? a = b, 1 : 0; }
template<class X, class Y> bool ckmax(X &a, const Y& b) { return (b > a) ? a = b, 1 : 0; }

void vuhieu();

signed main(void) {
#ifdef LOCAL
    using namespace chrono;
    auto start = steady_clock::now();

    setIO("test");
#else
    setIO("");
#endif // LOCAL

    int test_cases = 1;
//    cin >> test_cases;
    for (int iTest = 1; iTest <= test_cases; ++iTest) {
//        cout << "Case #" << test << ": ";
        vuhieu();
    }

#ifdef LOCAL
    auto end = steady_clock::now();
    cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << " [ms]" << '\n';
#endif

    return 0^0;
}

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void vuhieu(void) {

}

/**

**/
