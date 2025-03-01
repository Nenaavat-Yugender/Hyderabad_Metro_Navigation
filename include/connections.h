#ifndef CONNECTIONS_H
#define CONNECTIONS_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Connection {
public:
    string station1, station2;
    double distance;

    Connection(string s1, string s2, double d) : station1(s1), station2(s2), distance(d) {}
};

void loadConnections(const string& filename, unordered_map<string, vector<pair<string, double>>>& adjList);
pair<vector<string>, double> findShortestPath(const unordered_map<string, vector<pair<string, double>>>& adjList, const string& src, const string& dest);

#endif
