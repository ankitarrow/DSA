// Given an undirected graph with V nodes and E edges, create and return an adjacency list of the graph. 0-based indexing is followed everywhere.

// Example 1:

// Input:
// V = 5, E = 7
// edges = [[0,1], [0,4], [4,1], [4,3], [1,3], [1,2], [3,2]]

// Output: 
// [[1,4], [0,2,3,4], [1,3], [1,2,4], [0,1,3]]
// Explanation:
// Node 0 is connected to 1 and 4.
// Node 1 is connected to 0,2,3 and 4.
// Node 2 is connected to 1 and 3.
// Node 3 is connected to 1,2 and 4.
// Node 4 is connected to 0,1 and 3.
// Example 2:

// Input:
// V = 4, E = 3
// edges = [[0,3], [0,2], [2,1]]


// Output: 
// [[2,3], [2], [0,1], [0]]
// Explanation:
// Node 0 is connected to 2 and 3.
// Node 1 is only connected to 2.
// Node 2 is connected to 0 and 1.
// Node 3 is only connected to 0.
// Constraints:
// 1 ≤ V, E ≤ 105

//Solution
vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
    //Declare adjacenylist for V node
    vector<int>adjacencyList[V];
    for(auto edge:edges)
    {
        //Undirected_graph
        adjacencyList[edge.first].push_back(edge.second);
        adjacencyList[edge.second].push_back(edge.first);
    }
    vector<vector<int>>result;
    for(auto vertex:adjacencyList)
    {
        result.push_back(vertex);
    }
    return result;
    
}