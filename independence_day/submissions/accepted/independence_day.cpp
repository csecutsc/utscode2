//ADVANCED BATTLESHIPS - Official Solution
//By Jacob Plachta

#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

int main()
{
	//vars
	int n,sy,sx,sz,a,b,c,y,x,tot=0;
	char ch;
	static int field[501][501];
	static int cnt[250000];
	queue < pair<int,int> > Q;
	//input
	cin >> sy >> sx >> sz;
		for (a=0; a<sy; a++)
			for (b=0; b<sx; b++)
			{
				cin >> ch;
				field[a][b]=(ch=='X'?-2:-1);
			}
	//floodfill to find ships
	n=0;
		for (a=0; a<sy; a++)
			for (b=0; b<sx; b++)
				if (field[a][b]==-2)
				{
					Q.push(make_pair(a,b));
						while (!Q.empty())
						{
							y=Q.front().first,x=Q.front().second;
							Q.pop();
								if ((y<0) || (y==sy) || (x<0) || (x==sx) || (field[y][x]!=-2))
									continue;
							field[y][x]=n;
							Q.push(make_pair(y-1,x));
							Q.push(make_pair(y+1,x));
							Q.push(make_pair(y,x-1));
							Q.push(make_pair(y,x+1));
						}
					n++;
				}
	//simulate snatches row-by-row
		for (a=0; a+sz<=sy; a++)
		{
			//first snatch
			memset(cnt,0,sizeof(cnt));
			c=0;
				for (y=a; y<a+sz; y++)
					for (x=0; x<sz; x++)
						if (field[y][x]>=0)
						{
								if (!cnt[field[y][x]])
									c++;
							cnt[field[y][x]]++;
						}
			tot+=c;
			//left-to-right...
				for (x=0; x+sz<sx; x++)
				{
					//delete old col, and insert new col
						for (y=a; y<a+sz; y++)
						{
							if (field[y][x]>=0)
							{
								cnt[field[y][x]]--;
									if (!cnt[field[y][x]])
										c--;
							}
							if (field[y][x+sz]>=0)
							{
									if (!cnt[field[y][x+sz]])
										c++;
								cnt[field[y][x+sz]]++;
							}
						}
					tot+=c;
				}
		}
	//output
	cout << fixed << setprecision(9) << tot/double((sy-sz+1)*(sx-sz+1)) << endl;
	return(0);
}