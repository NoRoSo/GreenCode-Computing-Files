#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=10000+10,maxm=100000+10;

int ans[maxn],d[maxn],now[maxn],a[maxn],b[maxn],c[maxn];
int h[maxn],go[maxm*2],nex[maxm*2];
bool bz[maxn]; //visited
int i,j,k,w,l,t,n,m,tot,ca;

int read(){
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

int random(int x){
    int t=rand()%10000;
    t=t*10000+rand()%10000;
    return t%x;
}

void add(int x,int y){
    d[y]++;
    go[++tot]=y;
    nex[tot]=h[x];
    h[x]=tot;
}

int main(){
    n=read();m=read();
    for(int i = 1; i <= m; i++){
        j=read();k=read();
        add(j,k);add(k,j);
    }
    ca=800;
    while (ca--){
        for(int i = 1; i <= n; i++)
            now[i]=d[i],bz[i]=0;
        k=random(n)+1;
        w=k;
        a[a[0]=1]=k;
        bz[k]=1;
        while (1){
            c[0]=0;
            j=0;
            t=h[k];
            while (t){
                now[go[t]]--;
                if (now[go[t]]==1&&!bz[go[t]]) j=go[t];
                if (!bz[go[t]]) c[++c[0]]=go[t];
                t=nex[t];
            }
            if (!c[0]) break;
            if (!j) j=c[random(c[0])+1];
            bz[j]=1;
            a[++a[0]]=j;
            k=j;
        }
        k=w;
        b[b[0]=1]=k;
        while (1){
            c[0]=0;
            j=0;
            t=h[k];
            while (t){
                if (k!=w) now[go[t]]--;
                if (now[go[t]]==1&&!bz[go[t]]) j=go[t];
                if (!bz[go[t]]) c[++c[0]]=go[t];
                t=nex[t];
            }
            if (!c[0]) break;
            if (!j) j=c[random(c[0])+1];
            bz[j]=1;
            b[++b[0]]=j;
            k=j;
        }
        if (a[0]+b[0]-1>ans[0]){
            ans[0]=a[0]+b[0]-1;
            for(int i = a[0]; i >= 1; i--)
                ans[a[0]-i+1]=a[i];
            for(int i = 2; i <= b[0]; i++)
                ans[a[0]+i-1]=b[i];
        }
    }
    printf("%d\n",ans[0]);
    for(int i = 1; i <= ans[0]; i++)
        printf("%d ",ans[i]);
    printf("\n");
}
