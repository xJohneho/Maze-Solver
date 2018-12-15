#include <iostream>
#include <string>
#include "DFSMazeGenerator.h"
#include "MazeSolverDFS.h"



int main()
{
	MazeGenerator test;
	MazeSolver runner;
	MazeGenerator Level[MAZESIZE][MAZESIZE];

	

	// Creating file with Maze works
	//test.runMazeGen(Level, "test43.txt");

	// Runs, just have to remember to fix print
	
	runner.testMazeSolver("test43.txt");
	
	

	
	return 0;


}