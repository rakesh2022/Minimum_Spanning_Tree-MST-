#include<bits/stdc++.h>

using namespace std;

long long n,m,z;
typedef long long ll;
vector<pair<ll,pair<int, int> > > edges;
int w[1<<20];
int ans;

int get(int x)
{
	if (x==w[x])
		return x;
	return w[x]=get(w[x]);
}

void merge(int a,int b, vector<int>&rank)
{
	int u=get(a);
  int v=get(b);
  if(rank[u]>rank[v]){
    w[v]=u;
  }
  else if(rank[u]<rank[v]){
    w[u]=v;
  }
  else{
    rank[u]++;
    w[v]=u;
}
 
}

int main(){
ios_base::sync_with_stdio(0);

cin>>n>>m>>z;
vector<int>rank(1<<20,-1);
for (int i=1;i<=m;i++)
{
	int a,b;
  ll c;
	cin>>a>>b>>c;
	edges.push_back(make_pair(c,make_pair(a,b)));
}

sort(edges.begin(),edges.end());


for (int i=1;i<=n;i++)
	w[i]=i;

ans=n-1;

if (z<n-1)
	ans=1e9;
	
for (int i=0;i<edges.size();i++)
{
	int a,b;
  ll c;
	a=edges[i].second.first;
	b=edges[i].second.second;
	c=edges[i].first;
	a=get(a);
	b=get(b);
	if (a==b)
		continue;
	merge(a,b,rank);
	--n;
	z-=c;
	if (z>=n-1)
		ans=n-1;
}

if (n>1||ans>1e7)
	ans=-1;

cout<<ans<<endl;


//cin.get();cin.get();
return 0;}
