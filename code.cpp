#include <bits/stdc++.h>
using namespace std;

// Define the Location class
class Location
{
private:
    double latitude;
    double longitude;

public:
    Location(double lat, double lon) : latitude(lat), longitude(lon) {}

    // Accessor methods
    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }
};

// Define the Cab class
class Cab
{
private:
    int id;
    Location location;
    bool available;
    bool onRide;

public:
    // Constructor
    Cab(int id_, const Location &loc) : id(id_), location(loc), available(true), onRide(false) {}

    // Accessor methods
    int getId() const { return id; }
    bool isAvailable() const { return available; }
    Location getLocation() const { return location; }
    bool isOnRide() const { return onRide; }

    // Methods to update cab status
    void startRide()
    {
        onRide = true;
        available = false;
    }
    void endRide()
    {
        onRide = false;
        available = true;
    }
};

// Define the Employee class
class Employee
{
private:
    int id;
    Location location;

public:
    // Constructor
    Employee(int id_, const Location &loc) : id(id_), location(loc) {}

    // Accessor methods
    int getId() const { return id; }
    Location getLocation() const { return location; }
};

// Define the DistanceCalculator class
class DistanceCalculator
{
public:
    // Static method to calculate distance between two locations
    static double calculateDistance(const Location &loc1, const Location &loc2)
    {
        return sqrt(pow(loc1.getLatitude() - loc2.getLatitude(), 2) + pow(loc1.getLongitude() - loc2.getLongitude(), 2));
    }
};

// Function to find the nearest available cab to an employee
Cab findNearestCab(const vector<Cab> &cabs, const Employee &employee)
{
    double minDistance = numeric_limits<double>::max();
    Cab nearestCab = cabs[0];
    for (const Cab &cab : cabs)
    {
        if (cab.isAvailable() && !cab.isOnRide())
        {
            double distance = DistanceCalculator::calculateDistance(cab.getLocation(), employee.getLocation());
            if (distance < minDistance)
            {
                minDistance = distance;
                nearestCab = cab;
            }
        }
    }
    return nearestCab;
}

int main()
{
    // Define cab and employee locations
    Location cabLocation1(37.7749, 122.4194); // First location
    Location cabLocation2(37.7739, 122.4184); // Nearby location
    Location cabLocation3(37.7755, 122.4180); // Another nearby location

    // Create cab objects
    Cab cab1(1, cabLocation1);
    Cab cab2(2, cabLocation2);
    Cab cab3(3, cabLocation3);

    // Define employee locations
    Location employeeLocation1(37.7760, 122.4000); // Employee's location
    Employee employee1(101, employeeLocation1);

    Location employeeLocation2(40.677, 60.2872);
    Employee employee2(102, employeeLocation2);

    // Create vector of available cabs
    vector<Cab> availableCabs = {cab1, cab2, cab3};

    // Check if availableCabs vector is empty
    if (availableCabs.empty())
    {
        cout << "No Cabs Available for Employee " << employee1.getId() << endl;
        return 0;
    }
    // Find the nearest cab to employee1
    Cab nearestCab1 = findNearestCab(availableCabs, employee1);
    double distance1 = DistanceCalculator::calculateDistance(nearestCab1.getLocation(), employee1.getLocation());
    if (distance1 > 100 || nearestCab1.getId() == 0)
    {
        cout << "No Cabs Available for Employee " << employee1.getId() << endl;
    }
    else
    {
        cout << "Available Cabs for Employee " << employee1.getId() << ":" << endl;
        for (const auto &cab : availableCabs)
        {
            if (cab.isAvailable() && !cab.isOnRide())
            {
                cout << "Cab ID: " << cab.getId() << " at Location: (" << cab.getLocation().getLatitude() << ", " << cab.getLocation().getLongitude() << ")" << endl;
            }
        }
        cout << "Nearest Cab ID: " << nearestCab1.getId() << endl;
        cout << "Distance between Cab and Employee1: " << distance1 << endl;
        availableCabs[nearestCab1.getId() - 1].startRide();
    }
    // Check if availableCabs vector is empty
    if (availableCabs.empty())
    {
        cout << "No Cabs Available for Employee " << employee2.getId() << endl;
        return 0;
    }
    // Find the nearest cab to employee2
    Cab nearestCab2 = findNearestCab(availableCabs, employee2);
    double distance2 = DistanceCalculator::calculateDistance(nearestCab2.getLocation(), employee2.getLocation());
    if (distance2 > 100 || nearestCab2.getId() == 0)
    {
        cout << "No Cabs Available for Employee " << employee2.getId() << endl;
    }
    else
    {
        cout << "Available Cabs for Employee " << employee2.getId() << ":" << endl;
        for (const auto &cab : availableCabs)
        {
            if (cab.isAvailable() && !cab.isOnRide())
            {
                cout << "Cab ID: " << cab.getId() << " at Location: (" << cab.getLocation().getLatitude() << ", " << cab.getLocation().getLongitude() << ")" << endl;
            }
        }
        cout << "Nearest Cab ID: " << nearestCab2.getId() << endl;
        cout << "Distance between Cab and Employee2: " << distance2 << endl;
    }

    return 0;
}
