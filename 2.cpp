#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int n, k1, k2;
int const max_n = 200000;
vector<int> adj[max_n];
 
bool is_vis[max_n];
 
int _size[max_n];
void calc_size(int node, int parent) {
  _size[node] = 1;
  for(auto child: adj[node]) {
    if(child == parent || is_vis[child]) continue;
    calc_size(child, node);
    _size[node] += _size[child];
  }
}
 
int find_centroid(int node, int parent, int subgraph_size) {
  for(auto child: adj[node]) {
    if(child == parent || is_vis[child] || _size[child] <= subgraph_size / 2) continue;
    return find_centroid(child, node, subgraph_size);
  }
  return node;
}
 
void collect(int node, int parent, int depth, vector<int> &cnt) {
  if(depth > k2) return;
  if(depth >= cnt.size()) {
    cnt.resize(depth + 1, 0);
  }
  cnt[depth]++;
  for(auto child: adj[node]) {
    if(child == parent || is_vis[child]) continue;
    collect(child, node, depth + 1, cnt);
  }
}
 
ll conquer(int somewhere) {
  calc_size(somewhere, -1);
  auto centroid = find_centroid(somewhere, -1, _size[somewhere]);
  is_vis[centroid] = true;
 
  ll result = 0;
 
  vector<int> cnt = {1};
  for(auto child: adj[centroid]) {
    if(is_vis[child]) continue;
    result += conquer(child);
 
    vector<int> child_cnt;
    collect(child, centroid, 1, child_cnt);
 
    int window = 0;
    for(int i = k1; i <= k2 - 1 && i < cnt.size(); i++) {
      window += cnt[i];
    }
    for(int i = 1; i < child_cnt.size(); i++) {
      if(0 <= k1 - i && k1 - i < cnt.size()) {
        window += cnt[k1 - i];
      }
      result += (ll) child_cnt[i] * window;
      if(k2 - i < cnt.size()) {
        window -= cnt[k2 - i];
      }
    }
 
    if(cnt.size() < child_cnt.size()) {
      cnt.swap(child_cnt);
    }
    for(int i = 0; i < child_cnt.size(); i++) {
      cnt[i] += child_cnt[i];
    }
  }
 
  is_vis[centroid] = false;
  return result;
};
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  cin >> n >> k1 >> k2;
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
 
  cout << conquer(0) << "\n";
}