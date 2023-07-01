/*
 * LinkedList.cpp
 * Adnan Bseisu
 * PSET #6
 * 06/04/2023
 * CPSC 223
 * 
 * Implementation for Linked List of Green Line Extension Stations
 * 
 */

#include "LinkedList.h"
#include <iostream>
using namespace std;

// Default constructor
LinkedList::LinkedList(){
    length = 0;
    head = NULL;
    currPos = NULL;
}

// Destructor
LinkedList::~LinkedList() {
    // call makeEmpty, which deletes all memory associated with the list 
    makeEmpty();
}

// Assignment operator overloading
LinkedList & LinkedList::operator = (const LinkedList &l){
    NodeType *temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
    length = l.length;
    currPos = NULL;
    if (l.head == NULL)
        head = NULL;
    else{
        head = new NodeType;
        head->info = l.head->info;
        head->next = NULL;
        NodeType *curr = head;
        NodeType *orig = l.head;
        while (orig->next != NULL){
            curr->next = new NodeType;
            curr->next->info = orig->next->info;
            curr->next->next = NULL;
            orig = orig->next;
            curr = curr->next;
        }
    }
    return *this;
}

// Input: nothing
// Returns: the length
// Does: returns the length of the LL
int LinkedList::getLength() const{
    return length;
}

// Input: nothing
// Returns: true if currPos is NULL
// Does: determines if currPos is NULL or not
bool LinkedList::isCurrPosNull() const{
    return currPos == NULL;    
}

// Input: a Station s
// Returns: nothing
// Does: inserts Station s into the head of the linked list
void LinkedList::insertStation(Station s){
    // create new node, whose station will store information encoded in s
    NodeType *new_node= new NodeType;
    // copy values in s into new_node's station
    new_node->info = Station(s.getName(), s.getAccess());
    // new_node points to the current head
    new_node->next = head;
    // head now points to new_node, the first station in the list
    head = new_node;
    // increment length
    length++;
}

// Input: a Station S
// Returns: nothing
// Does: deletes first instance of a station in the list and equal to Station s
void LinkedList::removeStation(Station s){
    // if the list is empty, there is nothing to return
     if (head == nullptr) {
        return;
    }
    // two pointers to track current and previous node as we loop through list
    NodeType* current = head;
    NodeType* prev = nullptr;

    // loop through list until the current pointer is null
    while (current != nullptr) {
        // if the current pointer is equal to s, we want to remove it
        if ((current->info).isEqual(s)) {
            // if currPos is set to this position, reset it
            if (!isCurrPosNull() and (currPos->info).isEqual(current->info)){
                resetCurrPos();
            }
            // if we are removing the current head of the list, update head
            if (prev == nullptr) {
                head = current->next;
            } 
            // update node before removed node to point next to node after removed node
            else {
                prev->next = current->next;
            }
            // free memory associated with current node
            delete current;
            // decrement length
            length--;
            // return to break out of function, we're done
            return;
        }
        // if current station not equal to s, increment current and prev pointers
        prev = current;
        current = current->next;
    }
}


// Input: nothing
// Returns: a Station
// Does: returns the next station in the linked list after currPos
Station LinkedList::getNextStation(){
    // declare a station that will be returned
    Station ret;
    // if list is empty, return default Station
    if (head == nullptr) 
    {
        return Station(); 
    }
    // if currPos is null, return first station and set currPos to second station
    if (isCurrPosNull()) 
    {
        ret = Station(head->info.getName(), head->info.getAccess());
        currPos = head->next; 
    } 
    // set ret equal to current station, then increment current station
    else {
        ret = Station(currPos->info.getName(), currPos->info.getAccess());
        currPos = currPos->next;
    }
    // return next station, as outlined by criteria
    return ret; 

}

// Input: nothing; 
// Returns: nothing;
// Does: sets currPos to the null pointer
void LinkedList::resetCurrPos(){
   currPos = nullptr;
}

// Input: nothing
// Returns: nothing
// Does: Deletes all memory associated with the linked list
void LinkedList::makeEmpty(){
    NodeType *temp = nullptr;
    NodeType *current = head;
    while (current != nullptr) {
        temp = current;
	    current = current->next;
	    delete temp;
    }
    head = nullptr;
    length = 0;
}


// Input: a reference to an ostream object
// Returns: nothing
// Does: Prints all  stations in the list in order in the specified format
void LinkedList::print(ostream &out){
    // initialize pointer to head of the list
    NodeType* curr = head;
    // traverse the list until the end is reached
    while (curr != nullptr) {
        // print the station stored in the current node
        curr->info.print(out);
        // print a space between the station and the distance
        out << " ";
        // store distance from current node to end of list in variable
        int distance = calculateDistanceToEnd(curr);
        // print that distance
        out << distance;
        // print " == " if the current node is not the last node in the list
        if (curr->next != nullptr) {
            out << " == ";
        }
        // print newline character if current node is last node in the list
        else 
        {
            out << "\n";
        }
        // move to the next node in the list
        curr = curr->next;
    }
}

// Input: a node in the linked list
// Returns: an int
// Does: calculates  distance from the input node to the end of the list
int LinkedList::calculateDistanceToEnd(NodeType *curr){
    // initialize a variable to keep track of distance.
    int dist = 0;
    // traverse the list from the current node until the end is reached
    while (curr->next != nullptr)
    {
        // move to the next node
        curr = curr->next;
        // increment the distance counter
        dist++;
    }
    // return distance of current node to end of list
    return dist;
}


