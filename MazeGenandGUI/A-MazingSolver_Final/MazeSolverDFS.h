#pragma once
#ifndef MAZESOLVERDFS_H
#define MAZESOLVERDFS_H
#include<iostream>
#include<vector>
#include<stack>
#include "DFSMazeGenerator.h"

#define HEIGHT 100
#define WIDTH 100

using namespace std;

//Node   Added Note: change factory pointer to Node class 
class MazeSolver;
class Node {
public:
	char type;
	bool visited;
	int x, y;
};
class MazeSolver{

public:
	Node start;  // Added
	Node endNode; // Added
	ofstream outFile;
	//Prototypes  Added
	bool EndFound(vector<vector<Node> > maze, int x, int y);
	vector<Node> CheckNeighbors(vector<vector<Node> > maze, int x, int y);
	char MazeArray[HEIGHT][WIDTH + 1] ={};
	vector<vector<Node> > Maze(char maze[HEIGHT][WIDTH + 1]);
	void Display(vector<vector<Node> > maze, int x, int y);
	bool DFS_Recursive(vector<vector<Node>> maze, int x, int y);
	void testMazeSolver(string filename);
};
//Maze Char Array  Added




//Maze  Added
vector<vector<Node> > MazeSolver::Maze(char maze[HEIGHT][WIDTH + 1]) {

	vector<vector<Node> > nodeMaze;
	for (int y = 0; y < HEIGHT; y++) {
		vector<Node> temp;
		for (int x = 0; x < sizeof(maze[y]); x++) {

			Node tNode;
			tNode.type = maze[y][x];
			tNode.x = x;
			tNode.y = y;
			tNode.visited = false;
			temp.push_back(tNode);

			//assign start and end
			if (maze[y][x] == 'S') {
				start.x = x;
				start.y = y;
				start.visited = false;
				start.type = 'S';
			}
			if (maze[y][x] == 'E') {
				endNode.x = x;
				endNode.y = y;
				endNode.visited = false;
				endNode.type = 'E';
			}
		}
		nodeMaze.push_back(temp);
	}

	return nodeMaze;
}

//Display  Added
void MazeSolver::Display(vector<vector<Node> > maze, int x, int y) {

	for (int h = 0; h < HEIGHT; h++)
	{
		for (int w = 0; w < WIDTH; w++)
		{
			if (maze[h][w].x == x && maze[h][w].y == y) {
				cout << "@";
				outFile << "@";
			}
			else {
				cout << maze[h][w].type;
				outFile << maze[h][w].type;
			}
		}
		cout << endl;
		outFile << endl;
	}
	cout << endl;
	outFile << endl;
}

//DFS
bool MazeSolver::DFS_Recursive(vector<vector<Node>> maze, int x, int y) { //I need to either use ptr of Node or pass-by-reference

	Display(maze, x, y);

	if (EndFound(maze, x, y) == true) {
		return true;
	}
	else { //begin search
		//n.visited = true;
		maze[y][x].visited = true;

		//CheckNeighbors
		vector<Node> adj = CheckNeighbors(maze, x, y);

		for (Node v : adj) //vector of adjacent nodes
		{
			//cout << n.type << endl;
			if (v.type == '.' && v.visited == false) { //if node not visited, recursive search
				cout << "searching neighbor...\n";
				DFS_Recursive(maze, v.x, v.y);
			}
		}
	}
}

//CheckNeighbors   Added
vector<Node> MazeSolver::CheckNeighbors(vector<vector<Node> > maze, int x, int y) { //I need to either use ptr of Node or pass-by-reference
	vector<Node> adj;

	if ((maze[y][x].y - 1 >= 0) && (maze[y][x].type != '#')) //up
		adj.push_back(maze[y - 1][x]);
	if ((maze[y][x].y + 1 < HEIGHT) && (maze[y][x].type != '#')) //down
		adj.push_back(maze[y + 1][x]);
	if ((maze[y][x].x - 1 >= 0) && (maze[y][x].type != '#')) //left
		adj.push_back(maze[y][x - 1]);
	if ((maze[y][x].y + 1 < WIDTH) && (maze[y][x].type != '#')) //right
		adj.push_back(maze[y][x + 1]);

	/*for (Node n : adj) {
		cout << n.type;
	}

	cout << endl;*/

	return adj;
}

//EndFound    Added
bool MazeSolver::EndFound(vector<vector<Node> > maze, int x, int y) {
	if (maze[y][x].type == 'E') {
		cout << "PATH FOUND!\n";
		return true;
	}
	else
		return false;
}
void MazeSolver::testMazeSolver(string filename) {
	//Creat char 2d array
	//call mazefromfile
	// check array is filled
	// if it is, stick it in Maze(argument)

	//MazeGenerator Level[MAZESIZE][MAZESIZE];
	MazeGenerator test = MazeGenerator();
	/*
	test.runMazeGen(Level);
	_getch();
	//char tester[][100];

	*/
	char Mazetest[HEIGHT][WIDTH + 1];
	int x = 0;
	int y = 0;
	
	test.mazeFromFile(filename, Mazetest, x, y);

	/*for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH + 1; j++) {
			cout << Mazetest[i][j];
		}
		cout << endl;
	}*/

	cout << endl;

	vector<vector<Node> > maze = Maze(Mazetest);

	//Display(maze, start.x, start.y);
	cout << endl;

	//begin DFS_Recursive
	//MazeFunctionality *check = new MTimer();

	if (DFS_Recursive(maze, start.x, start.y) == false) {
		cout << "No path found\n";
	}
	else {
		cout << "Path found!\n";
		outFile << "Path found\n";

	}

	
	//check->maze_time();
}


#endif // !MAZESOLVERDFS_H
