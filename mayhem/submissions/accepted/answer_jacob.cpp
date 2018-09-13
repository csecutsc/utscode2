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

int R,C;
char G[2001][2001];
vector<PR> con[2001][2001];
queue<PR> Q;

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int i,j,p,x,y,z,x2,y2,ans=0;
	Read(R),Read(C);
		Fox(i,R)
			scanf("%s",&G[i]);
		Fox(i,R)
		{
			p=-1;
				Fox(j,C)
					if (G[i][j]=='x')
						if (p<0)
							p=j;
						else
						{
							con[i][j].pb(mp(i,p));
							con[i][p].pb(mp(i,j));
						}
		}
		Fox(i,C)
		{
			p=-1;
				Fox(j,R)
					if (G[j][i]=='x')
						if (p<0)
							p=j;
						else
						{
							con[j][i].pb(mp(p,i));
							con[p][i].pb(mp(j,i));
						}
		}
		Fox(i,R)
			Fox(j,C)
				if (G[i][j]=='x')
				{
					ans--;
					Q.push(mp(i,j)),G[i][j]='.';
						while (!Q.empty())
						{
							y=Q.front().x;
							x=Q.front().y;
							Q.pop();
							ans++;
								Fox(z,Sz(con[y][x]))
								{
									y2=con[y][x][z].x;
									x2=con[y][x][z].y;
										if (G[y2][x2]=='x')
											Q.push(mp(y2,x2)),G[y2][x2]='.';
								}
						}
				}
	printf("%d\n",ans);
	return(0);
}