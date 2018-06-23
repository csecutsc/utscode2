// D - GOOD CODE
// Official Solution

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
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

#define For(i,n) for (i=0; i<int(n); i++)
#define ForR(i,n) for (i=int(n)-1; i>=0; i--)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x < 0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }

const int INF = (int)1e9;
const LD EPS = 1e-9;
const LD PI = acos(-1.0);

#define DEBUG 0
#define LIM 1000001

int main()
{
		if (DEBUG)
		{
			freopen("in-7.txt","r",stdin);
			freopen("out-7.txt","w",stdout);
		}
	//vars
	int N;
	LL M;
	int i;
	LL c,x,j;
	char s[20];
	static int ln[LIM];		//this line of code (-1: label | 0: c++ | positive: goto)
	static int loc[LIM];	//location of this label
	static LL val[LIM];	//value of c at this line
	//input
	scanf("%d%lld\n",&N,&M);
		For(i,N)
		{
			cin.getline(s,20);
				if (s[0]=='c')
					ln[i]=0;
				else
				if (s[0]=='g')
				{
						for (j=5,x=0; s[j]!=';'; j++)
							x=x*10 + s[j]-'0';
					ln[i]=x;
				}
				else
				{
					ln[i]=-1;
						for (j=x=0; s[j]!=':'; j++)
							x=x*10 + s[j]-'0';
					loc[x]=i;
				}
		}
	//simulate
	Fill(val,-1);
	c=i=j=0;
		while (i<N)
		{
			//entered a loop?
				if ((val[i]>=0) && (!j))
				{
					j=c-val[i];
						if (!j)
						{
							printf("TLE\n");
							return(0);
						}
					x=(M-1)-c;
					c+=(x/j)*j;
				}
			val[i]=c;
			//handle this line
				if (ln[i]==0)
				{
					c++;
						if (c==M)
						{
							printf("%d\n",i+1);
							return(0);
						}
				}
				if (ln[i]>0)
					i=loc[ln[i]];
			i++;
		}		
	printf("WA\n");
	return(0);
}