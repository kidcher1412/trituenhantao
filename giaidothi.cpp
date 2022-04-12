#include <bits/stdc++.h>
using namespace std;
#define maxn 1000
#define maxf 1000000000

int a[maxn][maxn],n,m,s,t;
int f[maxn],trace[maxn],check2[maxn];
void read()
{
	fstream inp("giaidothi.inp");
	inp>>n>>m>>s>>t;
	for(int i=1; i<=n;i++)
	for(int j=1; j<=n;j++) a[i][j]=-1;
	
	for(int i=1;i<=m;i++)
	{
	int u,v;
	inp>>u>>v;
	inp>>a[u][v];
	a[v][u]=a[u][v];
	}
	inp.close();
	
}
void Path()
{
	for (int i=1;i<=n;i++)
	{
		f[i]=maxf;
		check2[i]=true;
		trace[i]=0;
	}
	f[s]=0;
	trace[s]=0;
	int v=s,fmin;
	while(v !=t)
	{
		fmin=maxf;
		for(int i=1;i<=n;i++)
		if(check2[i] && fmin>f[i])
		{
			fmin=f[i];
			v=i;
		}
		if(fmin==maxf) break;
		check2[v]=false;
		for(int i =1;i<=n;i++)
		if(a[v][i]>0 && f[i]>f[v]+a[v][i])
		{
			f[i]=f[v]+a[v][i];
			trace[i]=v;
		}
	}
}
void ketqua()
{
	if(f[t]==maxf) cout<<"khong co duong di";
	else{
		cout<<f[t]<<endl;
		int path[maxn],d=0;
		d++;
		path[d]=t;
		while(trace[t]!=0)
		{
			t=trace[t];
			d++;
			path[d]=t;
		}
		for(int i=d;i>0;i--)
		{
		cout<<"-> "<<path[i]<<endl;
		cout<<f[path[i]]<<endl;
	}
	cout<<"vay duong di cuooi cung la: ";
	for(int i=d;i>0;i--)
		{
		cout<<"-> "<<path[i];
	}
	}
	
}
int main()
{
	read();
	Path();
	ketqua();
	
	
}
