# TEAM AMERICA FINAL PROJECT - Road Trip

Members: Paulo Lemus, Kevin Liu, Christopher Amendola
Logins : plemus, liukevin, camendol
Date   : May 3rd, 2017

# Description

The program first parses everything from each file into
an adjacency list. The adjacency lists are directed, so a link from node a to b does not mean there is a link from b to a.
We then pass the adjacency list into out shortest and longest Path functions, as well as
the starting city and the ending city.

Both pathplannning functions are top-down recursive functions. Here is how they work:
If a function's start is its goal, then it returns a pointer to a copy of that node. This is an optimal path from start to goal. If it is not the goal, then it calls iself on all adjacent nodes, with those nodes as the start. This means that for any function call, it returns the optimal path from start to finish.
The program basically splits the optimal path problem into many smaller optimal path problems, then joins them together.

The program should work with any number of edges and with any start and goal nodes. However, we are limited to only choosing from the 8 cities, as we use enums to identify them.
The program also will not work if there are any cycles in the graph unfortunately.

# Files

## RoatTrip.c
This is the main driver program of the project.

## filoIO.c / fileIO.h
This contains the string of the three files that are parsed in, as well as the function that parses them and creates an adjacency list with the information.

## Node.c / Node.h
This contains the enum for the 8 cities, as well as the Node struct that is used to make various lists.

## pathplanning.c / pathplanning.h
Contains the two functions, shortest and longest path.
