/*
 * NodeType.h
 * Adnan Bseisu
 * PSET #6
 * 06/04/2023
 * CPSC 223
 * 
 *
 * Small struct that is part of a Linked List class
 *
 */

#include "Station.h"
using namespace std;

#ifndef NODETYPE
#define NODETYPE

struct NodeType
{
    Station info;
    NodeType *next;
};

#endif
