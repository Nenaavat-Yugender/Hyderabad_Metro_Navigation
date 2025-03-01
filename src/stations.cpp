#include "../include/stations.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void loadStations(const string& filename, unordered_map<string, Station>& stations) {
    ifstream file("data/station_coordinates.txt"); // ✅ Updated file path
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    string line, name;
    double lat, lon;

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, name, ',');
        ss >> lat;
        ss.ignore();
        ss >> lon;
        stations[name] = Station(name, lat, lon);
    }
    file.close();
}

void displayStations(const unordered_map<string, Station>& stations) {
    cout << "Metro Stations:\n";
    for (const auto& station : stations) {
        cout << station.second.name << " (Lat: " << station.second.latitude << ", Lon: " << station.second.longitude << ")\n";
    }
}
