// Rain Man
// Solution #1 (bignums) by Jacob Plachta

#define DEBUG 0

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define Fox(i,n) for (i=0; i<n; i++)
#define Fox1(i,n) for (i=1; i<=n; i++)
#define FoxI(i,a,b) for (i=a; i<=b; i++)
#define FoxR(i,n) for (i=(n)-1; i>=0; i--)
#define FoxR1(i,n) for (i=n; i>0; i--)
#define FoxRI(i,a,b) for (i=b; i>=a; i--)
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x<0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }
string plural(string s) { return(Sz(s) && s[Sz(s)-1]=='x' ? s+"en" : s+"s"); }

const int INF = (int)1e9;
const LD EPS = 1e-12;
const LD PI = acos(-1.0);

#if DEBUG
#define GETCHAR getchar
#else
#define GETCHAR getchar_unlocked
#endif

bool Read(int &x)
{
	char c,r=0,n=0;
	x=0;
		for(;;)
		{
			c=GETCHAR();
				if ((c<0) && (!r))
					return(0);
				if ((c=='-') && (!r))
					n=1;
				else
				if ((c>='0') && (c<='9'))
					x=x*10+c-'0',r=1;
				else
				if (r)
					break;
		}
		if (n)
			x=-x;
	return(1);
}

const int BASE = 100000000;
const int MaxN = 1003;

class BigNum {
public:
  LL a[ MaxN ];
  int n;
  
  BigNum() { n = 0; }   
  BigNum( int x ) {
    n = 0;
    do {
      a[ n++ ] = x % BASE;
      x /= BASE;
    } while( x );
  };
  
  void trim() {
    LL tmp = 0;
    for( int i = 0; i < n; ++i ) {
      a[i] += tmp;
      tmp = a[i] / BASE;
      a[i] %= BASE;
    }
    
    while( tmp ) {
      a[ n++ ] = tmp % BASE;
      tmp /= BASE;
    } 
  };
  
  void operator += ( const BigNum &b ) {
    for( int i = 0; i < b.n; ++i )
      a[i] += b.a[i];
    
    Max(n,b.n);
    trim();
  }
     
  void operator *= ( const int &b ) {      
    for( int i = 0; i < n; ++i )
      a[i] *= b;
    trim();
  }
  
  void add( const int &x, const BigNum &b ) {
    for( int i = 0; i < n; ++i )
      a[i] *= x; 
    for( int i = 0; i < b.n; ++i )
      a[i] += b.a[i];
    Max(n,b.n);
    trim();
  }
  
  int len() {
	  int d=(n-1)*8,v=a[ n - 1 ];
		while (v)
			d++,v/=10;
	  return(d);
  }
};

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int T,N;
	int i,j,p;
	Read(T);
		while (T--)
		{
			Read(N);
				Fox(i,N+1)
				{
					BigNum v(1);
						Fox(j,N)
						{
							p=j<i ? 2 : 11;
							v*=p;
						}
						if (v.len()==N)
						{
								Fox(j,N)
								{
									p=j<i ? 2 : 11;
									printf("%d%c",p,j==N-1 ? '\n' : ' ');
								}
							break;
						}
				}
		}
	return(0);
}