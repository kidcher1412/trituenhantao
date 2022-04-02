#include <bits/stdc++.h>
using namespace std;

int n,m,s,t;
vector<int> adj[100];
bool visited[100];
int parent[100];
void dfs(int u)
{
	visited[u]=true;
	for(int v : adj[u])
	{
		if(!visited[v]){
			parent[v]=u;
			dfs(v);
			
		}
	}
}
void bfs(int u)
{
	queue<int> q;
	q.push(u);
	visited[u]=true;
	while(!q.empty())
	{
		int v=q.front(); q.pop();
		for(int x : adj[v])
		{
			if(!visited[x]){
			
			q.push(x);
			visited[x]=true;
			parent[x]=v;
			}
		}
	}
}
void Path(int s, int t)
{
	memset(visited,false,sizeof(visited));
	memset(parent,0,sizeof(parent));
	bfs(s);  //nhanh nhat
	//dfs(s);		//ngan nhat
	if(!visited[t])
	{
		cout<<"khong co duong di!!!";
		
	}
	else{
		vector<int> path;
		while(t != s){
			path.push_back(t);
			t=parent[t];
		}
		path.push_back(s);
		reverse(path.begin(),path.end());
		for(int x : path){
			cout<<x<<"  ";
		}
	}
}

/*
9 8
1 9
1 4
2 3
2 5
4 7
5 6
5 8
6 9
7 8
*/
int main()
{
	cout<<"nhap lan luot: so dinh, so canh, dinh bat dau, dinh ket thuc la lan luot cac cap so dinh so canh lien ke"<<endl;
	
	cin>>n>>m>>s>>t;
	for(int i=0;i<m;i++)
	{
		int x,y; cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	Path(s,t);
	return 0;
}
