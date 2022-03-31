#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,s,t;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];
void dfs(int u)
{
	visited[u]=true;
	for(int v: adj[u])
	{
		if(!visited[u])
		{
			parent[v]=u;
			dfs(v);
		}
	}
}
void path(int s,int t)
{
	menset(visited,false,sizeof(visited));
	menset(parent,0,sizeof(parent));
	dfs(s);
	if(!visited[t])
	{
		cout<<"khong co duong di !";
		
	}
	else
	{
		vector<int> Path;
		while(t != s)
		{
			Path.push_back(t);
			t=parent[t];
		}
		reverse(path.begin(),Path.end());
	}
}
//10 8
//1 2
//2 3
//2 4
//3 6
//3 7
//6 7
//5 8
//8 9
int main()
{
	cin>>n>>m>>s>>t;
	for(int i=0,i<m;i++)
	{
		int x,y; cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	path(s,t);
	return 0;
}
