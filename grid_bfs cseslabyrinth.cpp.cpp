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
int n,m;

bool is_valid(int i,int j,vector<vector<int>> &vis,vector<vector<char>> &vec){
	if(i==-1 || j==-1 || j==m || i==n) return false;

	if(vis[i][j]==1 || vec[i][j]=='#') return false;
	return true;
}


void solve(){

	cin>>n>>m;
	vector<vector<char>>vec(n,vector<char>(m));
	pair<int,int>start,end;
	fo(i,n){
		fo(j,m){
			cin>>vec[i][j];
			if(vec[i][j]=='A') start.f=i, start.ss=j;
			if(vec[i][j]=='B') end.f=i, end.ss=j;
		}
	}
	vector<vector<int>>vis(n,vector<int>(m));
	queue<pair<int,int>>q;

	vector<vector<int>>par(n,vector<int>(m));
	
	vis[start.f][start.ss]=1;
	q.push({start.f,start.ss});
	int dx[4]={-1, 0, 1, 0};
	int dy[4]={0, 1, 0, -1};  //urdl

	string s="URDL";

	while(!q.empty()){
		int row=q.front().f;
		int col=q.front().ss;
		q.pop();
		

		fo(i,4){
			if(is_valid(row+dx[i] , col+dy[i], vis, vec)){
				int new_row = row+dx[i];
				int new_col = col+dy[i];
				par[new_row][new_col] = i;
				
				vis[new_row][new_col] = 1;
				q.push({new_row, new_col});
			}
		}
	}

	if(vis[end.f][end.ss]){
		YES
		string ans;
		while(end != start){
			int p=par[end.f][end.ss];
			ans+=s[p];
			end={end.f - dx[p], end.ss - dy[p]};
		}
		cout<<ans.sz<<endl;
		reverse(all(ans));
		cout<<ans<<endl;
	}else {
		NO
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

