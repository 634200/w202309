void dfs(int u, int fa)
{
    if (color.find(c[u]) != color.end())
        ok[u] = 0;
    color.insert(c[u]);
    for (auto ne : G[u])
        if (ne != fa)
        {
            dfs(ne, u);
        }
    color.erase(color.find(c[u]));
}