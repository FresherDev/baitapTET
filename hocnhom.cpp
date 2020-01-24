#include<bits/stdc++.h>
using namespace std;
#define maxN 1000
#define maxM 1000
#define inf 999999999
typedef pair<int, int> ii;
int td[4]={1,-1,0,0};
int tc[4]={0,0,1,-1};

int n,m,u,v,si,sj,fi,fj,res,x,y;
char table[maxN][maxM];
ii Bpos, Apos, Npos;
int d[maxN][maxM];
bool mark[maxN][maxM];

struct node{
    int i,j,w;
    node(int i,int j,int w){
        this->i=i;
        this->j=j;
        this->w=w;
    }
};
bool operator>(const node &v1,const node &v2){
    return v1.w>v2.w;
}
bool check(int i,int j){
    return (i>=1&&i<=n&&j>=1&&j<=m);
}

void dijkstra(int si, int sj){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            d[i][j]=inf;
            mark[i][j]=false;
        }
    priority_queue<node, vector<node>, greater<node> > pq;
    d[si][sj]=0;
    pq.push(node(si,sj,0));
    while(!pq.empty()){
        int ui=pq.top().i;
        int uj=pq.top().j;
        pq.pop();
        if (mark[ui][uj]) continue;
		mark[ui][uj]=true;

        for(int k=0; k<4; k++){
            int vi=ui+td[k];
            int vj=uj+tc[k];
			int w=1;
			if (table[vi][vj] == '#' || mark[vi][vj] == true) continue;
			if (table[vi][vj] == 'A') w += x;
			if (table[vi][vj] == 'N') w += y;
			if ('1' <= table[vi][vj] && table[vi][vj] <= '9') w += table[vi][vj] - '0';
            if (d[vi][vj]>d[ui][uj]+w){
                d[vi][vj]=d[ui][uj]+w;
                pq.push(node(vi,vj,d[vi][vj]));
            }
        }

    }
}

int main()
{
    freopen("hocnhom.inp","r",stdin);
    freopen("hocnhom.out","w",stdout);
    cin >> n >> m >> x >> y;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin >> table[i][j];
            if (table[i][j] == 'A') Apos = ii(i, j);
            if (table[i][j] == 'B') Bpos = ii(i, j);
            if (table[i][j] == 'N') Npos = ii(i, j);

        }
    dijkstra(Bpos.first, Bpos.second);
    if (d[Apos.first][Apos.second] == inf || d[Npos.first][Npos.second] == inf){
        cout << "NO";
        return 0;
    }else res = d[Apos.first][Apos.second] + d[Npos.first][Npos.second];

    dijkstra(Apos.first, Apos.second);
    res += d[Npos.first][Npos.second] - y;
    cout << res << endl;
    return 0;
}
