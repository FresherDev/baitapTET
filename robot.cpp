#include <bits/stdc++.h>

using namespace std;

#define maxN 111
#define maxM 111
#define inf 1e9
int td[5]={0,-1,0,1,0};
int tc[5]={0,0,1,0,-1};

int n,m,u,v,si,sj,ti,tj,w,fst;
int a[maxN][maxM];
int d[maxN][maxM];
int mark[maxN][maxM], g[11][11][11];

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
		if (ui==ti&&uj==tj) break;
		mark[ui][uj]=true;

        for(int k=1; k<=4; k++){
            int vi=ui+td[k];
            int vj=uj+tc[k];
			if (a[vi][vj] == 1) w = 3;
			if (a[vi][vj] == 2) w = 5;
			if (a[vi][vj] == 3) w = 2;
			if (a[vi][vj] == 4) w = 7;
            if (check(vi,vj) && d[vi][vj]>d[ui][uj]+w && g[a[ui][uj]][a[vi][vj]][k]){
                d[vi][vj]=d[ui][uj]+w;
                pq.push(node(vi,vj,d[vi][vj]));
            }
        }

    }
}

int main()
{
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);

    cin >> n >> m >> si >> sj >> ti >> tj;
    memset(g, 63, sizeof g);
    g[1][2][2] = 0;
    g[1][2][1] = 0;
    g[2][1][3] = 0;
    g[2][1][4] = 0;
    g[3][4][1] = 0;
    g[3][3][4] = 0;
    g[4][3][2] = 0;
    g[4][3][3] = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char tmp;
            cin >> tmp;
            if (tmp == 'A') a[i][j] = 1;
            if (tmp == 'B') a[i][j] = 2;
            if (tmp == 'C') a[i][j] = 3;
            if (tmp == 'D') a[i][j] = 4;
        }
    }

    dijkstra(si, sj);

    if (a[si][sj] == 1) fst = 3;
    if (a[si][sj] == 2) fst = 5;
    if (a[si][sj] == 3) fst = 2;
    if (a[si][sj] == 4) fst = 7;

    cout << d[ti][tj] + fst;

    return 0;
}
