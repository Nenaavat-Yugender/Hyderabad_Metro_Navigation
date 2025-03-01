#ifndef STATIONS_H
#define STATIONS_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Station {
public:
    string name;
    double latitude, longitude;

    Station() : name(""), latitude(0.0), longitude(0.0) {}
    Station(string n, double lat, double lon) : name(n), latitude(lat), longitude(lon) {}
};

void loadStations(const string& filename, unordered_map<string, Station>& stations);
void displayStations(const unordered_map<string, Station>& stations);

#endif
