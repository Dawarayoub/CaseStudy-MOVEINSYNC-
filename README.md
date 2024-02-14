# CaseStudy-MOVEINSYNC-
CPP Program to find the nearest Cab available to an employee 
Title: Smart Cab Allocation System.


This programme replicates a basic cab allocation system, with cabs and personnel represented as objects. The algorithm locates the nearest accessible cab for each employee and assigns rides accordingly.


Classes: 1. Location: - Identifies a geographical location using latitude and longitude coordinates.
    - Attributes:
        - latitude: Locations's latitude coordinates.
        - longitude: Location's longitude coordinates.
    - Methods:
        - Constructor: Initialises the latitude and longitude.
        - getLatitude() returns the latitude coordinate.
        - getLongitude() returns the longitude coordinate.

2. Cab:

    - Each cab has a unique ID, location, and availability status.
    - Attributes:

        - id: A unique identity for the cab.
        - position: An object reflecting the cab's current location.
        - availability: A Boolean value that indicates if the cab is available for a ride.
      - onRide: A Boolean that indicates whether the cab is currently on a ride
- Methods:
        - Constructor: initialises the cab ID, location, and availability status.
        - getId() returns the cab's ID.
        - isAvailable() returns true if the cab is available.
        - getLocation(): Returns the current location of the cab.
        - isOnRide(): Returns true if the cab is currently on a ride.
        - updateLocation(): Updates the location of the cab.
        - startRide(): Sets the cab as on a ride and unavailable.
        - endRide(): Sets the cab as available after completing a ride.
3. Employee: - Represents an employee with a unique ID and location.  
	-Attributes: - id: Unique identifier for the employee.
	-location: Location object representing the current location of the employee.
	- Methods: - Constructor: Initializes employee ID and location.
	- getId(): Returns the ID of the employee.
	- getLocation(): Returns the current location of the employee. 
	- updateLocation(): Updates the location of the employee.
4. DistanceCalculator: Utility class for calculating distance between two places using the Euclidean distance algorithm.
    - Methods:
        - calculateDistance(): A static function that returns the Euclidean distance between two Location objects.
Functions: 
	1. findNearestCab(): - Locates the closest available cab to a specified employee depending on their location.
    	- Parameters: 
        - Cabs: A vector of Cab objects that represent available cabs.
        - employee: An object that represents the seeking employee.
    	- Returns the nearest available Cab object to the employee.
Main functionality: 
1. Creates cabs and employees with defined locations.
2. Creates a vector of available Cab and tests whether it is empty.
3. Determines the closest available cab for each employee and calculates the distance using the Euclidean distance method.
4. Assigns transportation to employees depending on the closest available cabs.
5. Prints important information such as cab ID, distance, and availability status.
