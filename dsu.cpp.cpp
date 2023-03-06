vector<int> par(300001);  
vector<int> sze(300001);

void make(int u){
    par[u]=u;
    sze[u]=1;
}
int find(int u){
    if(par[u]==u) return u;
    return par[u]=find(par[u]);
}
void Union(int u,int v){
    
    u=find(u);
    v=find(v);
    if(u!=v){
        if(sze[u]<sze[v]) swap(u,v);
        par[v]=u;
        sze[u]+=sze[v];
    }
} 



