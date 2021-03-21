#include<iostream>
#include<cmath>
#include <iomanip>
#include<cstring>
#include<string>
const int MAX=1000;
const int INF=999999;

using namespace std;
int n,m,s,G[MAX][MAX];
bool vis[MAX]={false};
int d[MAX];

void Dijkstra(int s){
	fill(d,d+MAX,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false && d[j<MIN]){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1) return;//¹ÂÁ¢µã
		vis[u]=true;
		for(int v=0;v<n;v++) {
			if(vis[v]==false && G[u][v]!=INF && d[u]+G[u][v]<d[v]){
				d[v]=d[u]+G[u][v];
			}
		}
	}
} 

int main(){
	int u,v,w;
	cin >> n>>m>>s;
	fill(G[0],G[0]+MAX*MAX,INF);
	for(int i=0;i<m;i++){
		cin >> u>>v>>w;
		G[u][v]=w;
	}
	Dijkstra(s);
	for(int i=0;i<n;i++){
		cout<<d[i]<<" ";
	}
	

	return 0;
}

