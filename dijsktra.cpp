void Dijkstra(int s, int n, vector<int> &dist, vector<int> &parent, vector<pair<int, int>> &adj) {
	dist.assign(n, 1e9);
	parent.assign(n, -1);
	dist[s] = 0;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, s});
	while (!q.empty()) {
		pair<int, int> here = q.top();
		q.pop();
		int v = here.ss;
		int d_v = here.ff;
		if (d_v != dist[v])
			continue;
		for (auto edge : adj[v]) {
			if (dist[v] + edge.ss < dist[edge.ff]) {
				dist[edge.ff] = dist[v] + edge.ss;
				parent[edge.ff] = v;
				q.push({dist[edge.ff], edge.ff});
			}
		}
	}
}
