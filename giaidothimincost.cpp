#include <bits/stdc++.h>
using namespace std;
#define maxn 1000
#define maxf 1000000000

int a[maxn][maxn],h[maxn],F[maxn],n,m,s,t;
int f[maxn],parent[maxn],visited[maxn];
int struc[maxn][maxn];
void strucs()
{ int temp=1;
	for(int i=1;i<=n/3;i++)
		for(int j=1;j<=n/3;j++)
			{
			struc[j][i]=temp;
			temp++;
			}
}
void browser(int k)
{
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <=n; j++)
			if(k==struc[i][j]) cout<<"("<<i-1<<";"<<j-1<<")";
			}
void read()
{
	fstream inp("giaidothi.inp");
	inp>>n>>m>>s>>t;
	for(int i=1; i<=n;i++)
    {
        inp>>h[i];
	for(int j=1; j<=n;j++) 
    
        a[i][j]=-1;
    }
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
		visited[i]=false;
		parent[i]=0;
	}
	f[s]=0;
	F[s]=f[s]+h[s];
	parent[s]=0;
	int v=s,fmin;
	while(v !=t)
	{
		fmin=maxf;
		for(int i=1;i<=n;i++)
		if(!visited[i] && fmin>f[i])
		{
			fmin=f[i];
			v=i;
		}
		if(fmin==maxf) break;
		visited[v]=true;
		for(int i =1;i<=n;i++)
		if(a[v][i]>0 && f[i]+h[i]>F[v]+a[v][i]) 
		{
			f[i]=f[v]+a[v][i];
			F[i]=f[i]+h[i];
			parent[i]=v;
		}
	}
}
void ketqua()
{
	if(f[t]==maxf) cout<<"khong co duong di";
	else{
		int path[maxn],d=0;
		d++;
		path[d]=t;
		while(parent[t]!=0)
		{
			t=parent[t];
			d++;
			path[d]=t;
		}
		for(int i=d;i>0;i--)
		{
		cout<<"-> ";
		browser(path[i]);
		cout<<" Tong chi phi duong di f="<<F[path[i]]<<endl;
	}
	cout<<"vay duong di toi uu cuoi cung la: ";
	for(int i=d;i>0;i--)
		{
		browser(path[i]);
		if(i>1) cout<<" -> ";
		else cout<<"{target}";
	}
	}
	
}
int main()
{
	read();
	strucs();
	Path();
	ketqua();
	return 0;
	
}
