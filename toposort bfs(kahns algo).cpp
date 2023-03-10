#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int                          long long
#define fo(i, n)                     for (int i = 0; i < n; i++)
#define fo2(i, z, n)                 for (int i = z; i <= n; i++)
#define pb                           push_back
#define all(var)                     var.begin(), var.end()
#define desc                         greater<int>()
#define set_bits                     __builtin_popcountll
#define YES                          cout << "YES\n";
#define NO                           cout << "NO\n";
#define Yes                          cout << "Yes\n";
#define No                           cout << "No\n";
#define sz                           size()
#define sqrt(x)                      sqrtl(x)
#define f                            first
#define ss                           second
#define ndl                          cout << "\n";
typedef vector<pair<int, int>>       vpi;
typedef vector<int>                  vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // *s.find_by_order(), order_of_key()
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)


/*-----------------------------------------------------*/
int M=1e9+7;
int po(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int inv(int x){ return po(x,M-2,M);}
int add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mult(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int div1(int x, int y){ return mult(x,inv(y),M); }
/*-----------------------------------------------------*/



void solve(){
    int n,m;
    cin>>n>>m;
    vi adj[n+1];
    vi in_degree(n+1);
    fo(i,m){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        in_degree[v]++;
    }
    queue<int>q;
    fo2(i,1,n){
        if(in_degree[i]==0) q.push(i);
    }
    vi topo;

    while(!q.empty()){
        int node=q.front();
        topo.pb(node);
        q.pop();
        for(auto it : adj[node]){
            in_degree[it]--;
            if(in_degree[it]==0) q.push(it);
        }
    }
}


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //int T; cin >> T; while (T--)
    {
        solve();
    }
}

