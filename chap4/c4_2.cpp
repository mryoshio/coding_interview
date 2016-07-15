#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> edge;
typedef vector<edge> graph;

graph createDummyGraph() {
  graph g;
  g.push_back(make_pair(0, 1));
  g.push_back(make_pair(0, 3));
  g.push_back(make_pair(1, 2));
  g.push_back(make_pair(2, 4));
  g.push_back(make_pair(4, 3));
  g.push_back(make_pair(4, 5));
  g.push_back(make_pair(5, 1));
  return g;
}

void solve(graph g, int src, int dest) {
  cout << "start: " << src << ", dest: " << dest << endl;

  int maxV = -1;
  for (int i = 0; i < g.size(); i++) {
    cout << "edge[" << i << "] ("
         << g[i].first << ", " << g[i].second
         << ")" << endl;
    maxV = max(maxV, max(g[i].first, g[i].second));
  }

  vector<int> d(maxV + 1, -1); // distance

  d[src] = 0;
  queue<int> q;
  q.push(src);

  while (!q.empty()) {
    int cur_v = q.front();
    q.pop();

    for (int i = g.size() -1 ; i >= 0; i--) {
      if (d[g[i].second] < 0 && cur_v == g[i].first) {
        d[g[i].second] = d[cur_v] + 1;
        q.push(g[i].second);
        g.erase(g.begin() + i);
      }
    }
  }

  for (int i = 0; i < d.size(); i++) {
    if (i) cout << ' '; cout << d[i];
  }
  cout << endl;

  if (d[dest] > -1) cout << "path exists. distance: " << d[dest];
  else cout << "path not exist.";
  cout << endl;
}

int main() {
  srand((unsigned int)time(NULL));
  solve(createDummyGraph(), rand() % 6, rand() % 6);
}

