void dfs(int i,vector<vector<int>>&adjacencyList,vector<int>&visited,vector<int>&temp)
{
    if(!visited[i])
    {
        visited[i]=true;
        temp.push_back(i);
    }
    for(auto neighbour:adjacencyList[i])
    {
        if(!visited[neighbour])
        {
        dfs(neighbour,adjacencyList,visited,temp);    
        }
    }
}
vector<int> bfs(int i,vector<vector<int>>&adjacencyList,vector<int>&visited)
{
    vector<int>ans;
    queue<int>q;
    q.push(i);
    ans.push_back(i);
    visited[i]=true;
    while(!q.empty())
    {

        int y=q.front();
        q.pop();      
        //Travel Neighbours
        for (int neighbor : adjacencyList[y]) {
        if (!visited[neighbor]) {
            q.push(neighbor);
            visited[neighbor] = true;
            ans.push_back(neighbor);
        }
        }
    }
    return ans;
}
vector<vector<int>> connectedcomponents(int v, vector<vector<int>>& edges) {
    //create visited array
    vector<int>visited(v,false);
    //convert to adjaceny list
    vector<vector<int>>adjacencyList(v);
    for(auto edge:edges)
    {
        adjacencyList[edge[0]].push_back(edge[1]);
        adjacencyList[edge[1]].push_back(edge[0]);

    }
    //travel each vertex
    
    vector<vector<int>>ans;
    for(int i=0;i<v;i++)
    {
        // vector<int>temp;
        if(!visited[i])
        {
            // temp=bfs(i,adjacencyList,visited);
            vector<int>temp;
            dfs(i,adjacencyList,visited,temp);
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
    }
    return ans;
}