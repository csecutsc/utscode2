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

int R,C,ans,cnt;
bool G[6][6],vis[6][6];

void rec1(int i,int j)
{
	int y,x;
	vis[i][j]=1;
	cnt++;
		FoxI(y,i-1,i+1)
			FoxI(x,j-1,j+1)
				if ((y>=0) && (y<R+2) && (x>=0) && (x<C+2) && (G[y][x]) && (!vis[y][x]) && (Abs(y-i)+Abs(x-j)==1))
					rec1(y,x);
}

void rec2(int i,int j)
{
	int y,x;
	vis[i][j]=1;
	cnt++;
		FoxI(y,i-1,i+1)
			FoxI(x,j-1,j+1)
				if ((y>=0) && (y<R+2) && (x>=0) && (x<C+2) && (!G[y][x]) && (!vis[y][x]))
					rec2(y,x);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	Read(R),Read(C);
	int N=R*C;
	int b,i,j;
		Fox1(b,(1<<N)-1)
		{
			int b2=b;
				Fox1(i,R)
					Fox1(j,C)
					{
						G[i][j]=b2&1;
						b2>>=1;
					}
			Fill(vis,0);
			cnt=0;
				Fox(i,R+2)
					Fox(j,C+2)
						if (G[i][j])
						{
							rec1(i,j);
							goto Out1;
						}
Out1:;
				Fox(i,R+2)
					Fox(j,C+2)
						if (!G[i][j])
						{
							rec2(i,j);
							goto Out2;
						}
Out2:;
				if (cnt==(R+2)*(C+2))
					ans++;
		}
	printf("%d\n",ans);
	return(0);
}