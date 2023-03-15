bool ok=true;
vector<int> color(n+5,-1);
for(int i=0;i<n;i++)
{
    if(color[i]==-1)
    {
        queue<int> bfs;
        bfs.push(i);
        color[i]=0;

        while(!bfs.empty())
        {
            int node=bfs.front();
            bfs.pop();

            for(auto child : g[node])
            {
                if(color[child]==-1)
                {
                    color[child]=1-color[node];
                    bfs.push(child);
                }
                else if(color[child]==color[node])
                    ok=false;
            }
        }
    }
}
