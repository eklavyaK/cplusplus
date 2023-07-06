const int N = 3e5;
int tree[N*4], lazy[N*4], dp[N];
void pushdown(int node){
    lazy[2*node] += lazy[node];
    tree[2*node] += lazy[node];
    lazy[2*node+1] += lazy[node];
    tree[2*node+1] += lazy[node];
    lazy[node] = 0;
}
void update(int node, int l, int r, int st, int en, int c){
    if(en<st || st>r || en<l) return;
    if(st<=l && en>=r){
        tree[node]+=c, lazy[node]+=c;
        return;
    }
    pushdown(node);
    int mid = (l+r)>>1;
    update(2*node,l,mid,st,en,c);
    update(2*node+1,mid+1,r,st,en,c);
    tree[node] = min(tree[2*node],tree[2*node+1]);
}
int query(int node, int l, int r, int st, int en){
    if(en<st || st>r || en<l) return LLONG_MAX;
    if(st<=l && en>=r) return tree[node];
    pushdown(node);
    int mid = (l+r)>>1;
    return min(query(2*node,l,mid,st,en),query(2*node+1,mid+1,r,st,en));
}