#ifdef LOCAL_CERR_TO_COUT
#define cerr cout
#endif


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(char *x) {cerr << '\"' << x << '\"';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

// Declarations
template<typename T>    void __print(const T &x);
template<typename T>    void __print(const T &x);
void _print();
template <typename T, typename... V>    void _print(T t, V... v);
template<>              void __print(const vector<bool> &v);
template<typename T>    void __print(stack<T> s);
template<typename T>    void __print(queue<T> q);

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}

template<>
void __print(const vector<bool> &v) {int f = 0; cerr << '{'; while (f < (int)v.size()) cerr << (f ? "," : ""), __print(v[f]), ++f; cerr << "}";}

template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
template<typename T>
void __print(stack<T> s) {int f = 0; cerr << '{'; while (!s.empty()) cerr << (f++ ? "," : ""), __print(s.top()), s.pop(); cerr << "}";}
template<typename T>
void __print(queue<T> q) {int f = 0; cerr << '{'; while (!q.empty()) cerr << (f++ ? "," : ""), __print(q.front()), q.pop(); cerr << "}";}

template<typename T, typename V>
void _print_a(T a, V sz) { int i = -1, f = 0; cerr << '['; while (++i < sz) cerr << (f++ ? "," : ""), __print(a[i]); cerr << "]";}
template<typename T, typename V, typename... W>
void _print_a(T a, V sz, W... szs) { int i = -1, f = 0; cerr << '['; while (++i < sz) cerr << (f++ ? "," : ""), _print_a(a[i], szs...); cerr << "]";}

#define debug(x...) cerr << __LINE__ << ". [" << #x << "] = ["; _print(x);
#define debug_arr(x...) cerr << __LINE__ << ". [ARR[" << #x << "]] = "; _print_a(x); cerr << "\n";
