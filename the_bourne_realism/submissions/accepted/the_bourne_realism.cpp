//TRAFFIC LIGHTS - Official Solution
//By Jacob Plachta

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

struct state
{
	int l,d;
};

bool operator<(const state &a, const state &b)
{
	return(a.d > b.d);
}

int main()
{
	//vars
	//ifstream cin ("traffic - 10.in");
	int n,n2,a,b,c,d;
	int ncon[1001]={0};			//# of roads from this intersection
	static int conL[1001][1001];//endpoints of roads from this intersection
	static int conD[1001][1001];//distances of roads from this intersection
	int lg[1001],lr[1001];		//traffic light timing
	bool done[1001]={0};		//been here already?
	state tmp;					//current dijkstra's state
	priority_queue <state> Q;	//dijkstra's heap
	//input
	cin >> n2 >> n;
		while (n2--)
		{
			cin >> a >> b >> c;
			a--;
			b--;
			conL[a][ncon[a]]=b;
			conD[a][ncon[a]++]=c;
			conL[b][ncon[b]]=a;
			conD[b][ncon[b]++]=c;
		}
		for (a=0; a<n; a++)
		{
			cin >> lg[a] >> lr[a];
			lr[a]+=lg[a];
		}
	//init
	tmp.l=0;
	tmp.d=0;
	Q.push(tmp);
	//dijkstra's
		while (true)
		{
			//take closest intersection
			tmp=Q.top();
			Q.pop();
			a=tmp.l;
			b=tmp.d;
			//been here already?
				if (done[a])
					continue;
			//been here now
			done[a]=true;
			//done?
				if (a==n-1)
				{
					cout << b << endl;
					return(0);
				}
			//go on
				for (c=0; c<ncon[a]; c++)
				{
					d=conL[a][c];
						if (!done[d])
						{
							tmp.l=d;
							tmp.d=b+conD[a][c];
								if (lr[d])
									if (tmp.d%lr[d]>=lg[d])
										tmp.d+=lr[d]-tmp.d%lr[d];
							Q.push(tmp);
						}
				}
		}
	return(0);
}