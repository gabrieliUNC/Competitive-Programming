#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10000]; //adj[node] -> tell u neighbors of node
long long dist[10000];

//weight of the edge between nodes x and y
//fun fact: weight of 1 makes dijkstra equal to a breadth-first-search
int weightFunc(int x, int y) {
    int ret = 1;
    return ret;
}

int main() {
    //create adjacency list (usually given in the problem)

    int sourceNode = 1;
    //set the distance array to infinity for every node
    fill(dist, dist + 10000, INT_MAX); 
    dist[sourceNode] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nodes; //{weight, node}, min heap
    nodes.push({0, sourceNode});
    //while not empty
    while (nodes.size()) {
        auto [weight, node] = nodes.top(); nodes.pop();

        if (dist[node] != weight) {
            continue;
        }

        for (int u : adj[node]) {
            //can we optimize the distance for node u?
            if (dist[u] > dist[node] + weightFunc(node, u)) {
                dist[u] = dist[node] + weightFunc(node, u);
                nodes.push({dist[u], u});
            }
        }   
    }
    //you can just do dist[node], and it'll give u the shortest distance from the sourceNode to `node`

}