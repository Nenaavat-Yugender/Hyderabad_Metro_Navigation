// #include "../include/connections.h"
// #include <fstream>
// #include <sstream>
// #include <iostream>
// #include <queue>
// #include <algorithm>

// using namespace std;

// void loadConnections(const string &filename, unordered_map<string, vector<pair<string, double>>> &adjList)
// {
//     ifstream file("data/station_connections.txt"); // ✅ Updated file path
//     if (!file)
//     {
//         cerr << "Error opening file: " << filename << endl;
//         exit(1); // Terminate if file is missing
//     }

//     string line, station1, station2;
//     double distance;

//     while (getline(file, line))
//     {
//         stringstream ss(line);
//         getline(ss, station1, ',');
//         getline(ss, station2, ',');
//         ss >> distance;

//         adjList[station1].emplace_back(station2, distance);
//         adjList[station2].emplace_back(station1, distance); // Undirected graph
//     }
//     file.close();
// }

// pair<vector<string>, double> findShortestPath(const unordered_map<string, vector<pair<string, double>>> &adjList,
//                                               const string &src, const string &dest)
// {
//     if (adjList.find(src) == adjList.end())
//     {
//         cerr << "Error: Starting station '" << src << "' not found in network.\n";
//         exit(1);
//     }
//     if (adjList.find(dest) == adjList.end())
//     {
//         cerr << "Error: Destination station '" << dest << "' not found in network.\n";
//         exit(1);
//     }

//     unordered_map<string, double> dist;
//     unordered_map<string, string> parent;
//     priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> pq;

//     for (const auto &station : adjList)
//     {
//         dist[station.first] = numeric_limits<double>::infinity();
//     }
//     dist[src] = 0;
//     pq.emplace(0, src);

//     while (!pq.empty())
//     {
//         string current = pq.top().second;
//         pq.pop();

//         if (current == dest)
//             break;

//         if (adjList.find(current) == adjList.end())
//         {
//             cerr << "Warning: '" << current << "' has no connections.\n";
//             continue;
//         }

//         for (const auto &neighbor : adjList.at(current))
//         { // ⚠️ This line caused the crash
//             string nextStation = neighbor.first;
//             double weight = neighbor.second;

//             if (dist[current] + weight < dist[nextStation])
//             {
//                 dist[nextStation] = dist[current] + weight;
//                 parent[nextStation] = current;
//                 pq.emplace(dist[nextStation], nextStation);
//             }
//         }
//     }

//     if (dist[dest] == numeric_limits<double>::infinity())
//     {
//         cerr << "Error: No path found from '" << src << "' to '" << dest << "'.\n";
//         exit(1);
//     }

//     vector<string> path;
//     double totalDistance = dist[dest];

//     for (string at = dest; at != ""; at = parent[at])
//     {
//         path.push_back(at);
//         if (at == src)
//             break;
//         }
//     reverse(path.begin(), path.end());

//     cout << "\n";
//     return {path, totalDistance};
// }


#include "../include/connections.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void loadConnections(const string &filename, unordered_map<string, vector<pair<string, double>>> &adjList)
{
    ifstream file("data/station_connections.txt"); // ✅ Updated file path
    if (!file)
    {
        cerr << "Error opening file: " << filename << endl;
        exit(1); // Terminate if file is missing
    }

    string line, station1, station2;
    double distance;

    while (getline(file, line))
    {
        stringstream ss(line);
        getline(ss, station1, ',');
        getline(ss, station2, ',');
        ss >> distance;

        adjList[station1].emplace_back(station2, distance);
        adjList[station2].emplace_back(station1, distance); // Undirected graph
    }
    file.close();
}

pair<vector<string>, double> findShortestPath(const unordered_map<string, vector<pair<string, double>>> &adjList,
                                              const string &src, const string &dest)
{
    if (adjList.find(src) == adjList.end())
    {
        cerr << "Error: Starting station '" << src << "' not found in network.\n";
        exit(1);
    }
    if (adjList.find(dest) == adjList.end())
    {
        cerr << "Error: Destination station '" << dest << "' not found in network.\n";
        exit(1);
    }

    unordered_map<string, double> dist;
    unordered_map<string, string> parent;
    priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> pq;

    for (const auto &station : adjList)
    {
        dist[station.first] = numeric_limits<double>::infinity();
    }
    dist[src] = 0;
    pq.emplace(0, src);

    while (!pq.empty())
    {
        string current = pq.top().second;
        pq.pop();

        if (current == dest)
            break;

        if (adjList.find(current) == adjList.end())
        {
            cerr << "Warning: '" << current << "' has no connections.\n";
            continue;
        }

        for (const auto &neighbor : adjList.at(current))
        { // ⚠️ This line caused the crash
            string nextStation = neighbor.first;
            double weight = neighbor.second;

            if (dist[current] + weight < dist[nextStation])
            {
                dist[nextStation] = dist[current] + weight;
                parent[nextStation] = current;
                
                // ✅ Debugging statement: Prints updates when distances are changed
                cout << "Updating: " << current << " -> " << nextStation 
                     << " | Distance: " << dist[nextStation] << " km" << endl;
                
                pq.emplace(dist[nextStation], nextStation);
            }
        }
    }

    if (dist[dest] == numeric_limits<double>::infinity())
    {
        cerr << "Error: No path found from '" << src << "' to '" << dest << "'.\n";
        exit(1);
    }

    vector<string> path;
    double totalDistance = dist[dest];

    for (string at = dest; at != ""; at = parent[at])
    {
        path.push_back(at);
        if (at == src)
            break;
    }
    reverse(path.begin(), path.end());

    cout << "\n"; // ✅ Ensuring an extra line gap after the shortest distance output
    return {path, totalDistance};
}

