#include <bits/stdc++.h>

#define inf 1e9

using namespace std;

int res[1000], d[1000], n, m, y, p, q, k, a[1000][1000], u, v, w, add, price, priA[100], priB[100], priC[100];
int resA[1000], resB[1000], resC[1000], resAB[1000], resAC[1000], resBC[1000], resAll[1000];
bool mark[1000], hasA[1000], hasB[1000], hasC[1000];

int getmin(){
    int minD=inf, u=0;
    for(int i=1;i<=n;i++)
        if (!mark[i]&&minD>d[i]){
            minD=d[i];
            u=i;
        }
    return u;
}

int dijkstra(int s,int f){
    for(int j=1; j<=n; j++){
        d[j]=inf; mark[j]=false;
    }
    d[s]=0;
    while(true){
        int u=getmin();
        if (u==0||u==f) return d[u];
        mark[u]=true;
        for(int v=1; v<=n; v++)
            if(!mark[v] && d[v]>d[u]+a[u][v]){
                d[v]=d[u]+a[u][v];
            }
    }
}

int main(){
    freopen("DVGH.INP", "r", stdin);
    freopen("DVGH.OUT", "w", stdout);

    cin >> n >> m >> y >> p >> q >> k;
    memset(resA, 62, sizeof resA);
    memset(res, 62, sizeof res);
    memset(resB, 62, sizeof resB);
    memset(resC, 62, sizeof resC);
    memset(resAB, 62, sizeof resAB);
    memset(resAC, 62, sizeof resAC);
    memset(resAll, 62, sizeof resAll);
    memset(resBC, 62, sizeof resBC);
    memset(hasA, false, sizeof hasA);
    memset(hasB, false, sizeof hasB);
    memset(hasC, false, sizeof hasC);

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j) a[i][j] = 0;
            else a[i][j] = inf;
        }
    }

    for (int i = 1; i <= m; i++){
        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
    }

    for (int i = 1; i <= p; i++){
        cin >> add >> price;
        hasA[add] = true;
        priA[add] = price;
    }
    for (int i = 1; i <= q; i++){
        cin >> add >> price;
        hasB[add] = true;
        priB[add] = price;
    }
    for (int i = 1; i <= k; i++){
        cin >> add >> price;
        hasC[add] = true;
        priC[add] = price;
    }

    for (int i = 1; i <= n; i++){
        if (hasA[i] && hasB[i] && hasC[i]){
            resAll[i] = priA[i] + priB[i] + priC[i] + dijkstra(y, i);
        }
        if(hasA[i] && hasB[i]){
            resAB[i] = priA[i] + priB[i] + dijkstra(y, i);
        }
        if (hasA[i] && hasC[i]){
            resAC[i] = priA[i] + priC[i] + dijkstra(y, i);
        }
        if (hasB[i] && hasC[i]){
            resBC[i] = priB[i] + priC[i] + dijkstra(y, i);
        }
        if (hasA[i]){
            resA[i] = priA[i] + dijkstra(y, i);
        }
        if (hasB[i]){
            resB[i] = priB[i] + dijkstra(y, i);
        }
        if (hasC[i]) {
            resC[i] = priC[i] + dijkstra(y, i);
        }
    }

    for (int i = 1; i <= n - 1; i++){
        for (int j = i + 1; j <= n; j++){
            if (resA[i] > resA[j]){
                int tam = resA[i];
                resA[i] = resA[j];
                resA[j] = tam;
            }
        }
    }
    for (int i = 1; i <= n - 1; i++){
        for (int j = i + 1; j <= n; j++){
            if (resB[i] > resB[j]){
                int tam = resB[i];
                resB[i] = resB[j];
                resB[j] = tam;
            }
        }
    }
    for (int i = 1; i <= n - 1; i++){
        for (int j = i + 1; j <= n; j++){
            if (resC[i] > resC[j]){
                int tam = resC[i];
                resC[i] = resC[j];
                resC[j] = tam;
            }
        }
    }
    for (int i = 1; i <= n - 1; i++){
        for (int j = i + 1; j <= n; j++){
            if (resAB[i] > resAB[j]){
                int tam = resAB[i];
                resAB[i] = resAB[j];
                resAB[j] = tam;
            }
        }
    }
    for (int i = 1; i <= n - 1; i++){
        for (int j = i + 1; j <= n; j++){
            if (resAC[i] > resAC[j]){
                int tam = resAC[i];
                resAC[i] = resAC[j];
                resAC[j] = tam;
            }
        }
    }
    for (int i = 1; i <= n - 1; i++){
        for (int j = i + 1; j <= n; j++){
            if (resBC[i] > resBC[j]){
                int tam = resBC[i];
                resBC[i] = resBC[j];
                resBC[j] = tam;
            }
        }
    }
    for (int i = 1; i <= n - 1; i++){
        for (int j = i + 1; j <= n; j++){
            if (resAll[i] > resAll[j]){
                int tam = resAll[i];
                resAll[i] = resAll[j];
                resAll[j] = tam;
            }
        }
    }

    cout << resA[1] << endl;
    int ABC = resA[1] + resB[1] + resC[1];
    ABC = min(ABC, resAB[1] + resC[1]);
    ABC = min(ABC, resAC[1] + resB[1]);
    ABC = min(ABC, resBC[1] + resA[1]);
    ABC = min(ABC, resAll[1]);
    cout << ABC << endl;
}
