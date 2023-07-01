/* 
 * Station.cpp
 * Adnan Bseisu
 * PSET #6
 * 06/04/2023
 * CPSC 223
 * Implementation of the Station class
 * 
 */

#include "Station.h"

// Constructor
Station::Station(){
	name = "NoName";
    access = false;
}

// Parameterized Constructor
Station::Station(string input_name, bool input_access){
    name = input_name;
    access = input_access;
}

// Function: isEqual
// Input: a Station s
// Returns: a bool
// Does: Returns if s is identical to the station invoking isEqual
bool Station::isEqual(Station s){
    return (name == s.getName() and access == s.getAccess());
}

// Function: print
// Input: reference to ostream object
// Returns: void
// Does: prints station name and availability of accessibilitity options
void Station::print(ostream &outfile){
    // if the station has accessibility options, print its name followed by "A"
    if (access) 
    {
        outfile << name << " A";
    } 
    // if it doesn't, print its name followed by "U"
    else 
    {
        outfile << name << " U";
    }
}


