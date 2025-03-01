#include "../include/stations.h"
#include "../include/connections.h"

int main() {
    unordered_map<string, Station> stations;
    unordered_map<string, vector<pair<string, double>>> adjList;

    loadStations("../data/station_coordinates.txt", stations);
    loadConnections("../data/station_connections.txt", adjList);

    cout << "Enter starting station: ";
    string start, end;
    getline(cin, start);

    cout << "Enter destination station: ";
    getline(cin, end);

    auto [path, distance] = findShortestPath(adjList, start, end);

    if (path.size() < 2) {
        cout << "No valid path found!\n";
    } else {
        cout << "Shortest path: ";
        for (const string& station : path) {
            cout << station << " -> ";
        }
        cout << "End\n";
        cout << "Total shortest distance: " << distance << " km\n\n";
    }

    return 0;
}
