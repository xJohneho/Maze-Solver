#pragma once
#ifndef DFSMAZEGENERATOR_H
#define DFSMAZEGENERATOR_H

#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <stack>
#include <fstream>
#include <vector>
#include<sstream>

using namespace std;

//Increase maze size to increase difficulty
#define MAZESIZE 23


class MazeGenerator
{
private:
	int size;
	bool visited;
	bool t_wall;//Top
	bool b_wall;//Bottom
	bool l_wall;//Left
	bool r_wall;//Right
	char display;
public: 
	void initializeMaze(MazeGenerator Level[][MAZESIZE]);
	void clearConsole();
	void processingMaze(MazeGenerator Level[][MAZESIZE]);
	void generateMaze(MazeGenerator Level[][MAZESIZE], int &posX, int &posY, int &goalX, int &goalY);
	void prepareMazeForRunner(MazeGenerator Level[][MAZESIZE]);
	void runMazeGen(MazeGenerator Level[][MAZESIZE], string filename);
	void mazeToFile(MazeGenerator Level[][MAZESIZE], string filename);
	void mazeFromFile(string file, char maze[][101], int x, int y);
	//vector<std::vector<MazeGenerator>> Level;

	// Add an abstract method for Decorator
	

};


class MazeFunctionality
{
public:
	virtual void maze_time() = 0;
};


class MTimer : public MazeFunctionality
{
	clock_t start_Timer, end_Timer;
	double duration_sec;
   public:
	   MTimer()
	   {
		   start_Timer = clock();

		  
		 
	   }

	   void maze_time()
	   {
		   system("cls");
		   end_Timer = clock();
		   double duration_sec = double(end_Timer - start_Timer) / CLOCKS_PER_SEC;
		   cout << duration_sec << " seconds" << endl;
	   }



};

class Decorator : public MazeFunctionality
{
	MazeFunctionality *dec;

     public:
		 Decorator(MazeFunctionality *d)
		 {
			 dec = d;
		 }

		 void draw()
		 {
			 dec->maze_time();
		 }

};


void MazeGenerator::initializeMaze(MazeGenerator Level[][MAZESIZE]) {
	for (int i = 0; i < MAZESIZE; i++) {
		for (int j = 0; j < MAZESIZE; j++) {
			Level[i][j].display = '#';
			Level[i][j].visited = false;
			Level[i][j].t_wall = true;
			Level[i][j].b_wall = true;
			Level[i][j].l_wall = true;
			Level[i][j].r_wall = true;
		}
	}
	for (int i = 1; i < MAZESIZE - 1; i++) {
		for (int j = 1; j < MAZESIZE - 1; j++) {
			// Border Cells have fewer accessible walls
			Level[1][j].t_wall = false;
			Level[MAZESIZE - 2][j].b_wall = false;
			Level[i][1].l_wall = false;
			Level[i][MAZESIZE - 2].r_wall = false;
		}
	}
}


void MazeGenerator::processingMaze(MazeGenerator Level[][MAZESIZE]) {
	for (int i = 0; i < MAZESIZE; i++) {
		cout << endl;
		for (int j = 0; j < MAZESIZE; j++)
			cout << " " << Level[i][j].display;
	}
}


void MazeGenerator::generateMaze(MazeGenerator Level[][MAZESIZE], int &posX, int &posY, int &goalX, int &goalY) {
	srand((unsigned)time(NULL));                                                                            // Pick random start cell
	int random = 0;
	int randomX = ((2 * rand()) + 1) % (MAZESIZE - 1);                                          // Generate a random odd number between 1 and SIZE
	int randomY = ((2 * rand()) + 1) % (MAZESIZE - 1);                                          
	posX = randomX;                                                                 // Save player's initial X  and Y positions
	posY = randomY;                                                                 
	int visitedCells = 1;
	int totalCells = ((MAZESIZE - 1) / 2)*((MAZESIZE - 1) / 2);
	int percent = 0;
	stack<int> back_trackX, back_trackY;                                            // Stack is used to trace the reverse path

	Level[randomY][randomX].display = 'S';                                          // Set A as the players starting point
	Level[randomY][randomX].visited = true;                                         // Set starting point as visited;

	while (visitedCells < totalCells)
	{
		if (((Level[randomY - 2][randomX].visited == false) && (Level[randomY][randomX].t_wall == true && Level[randomY - 2][randomX].b_wall == true)) ||
			((Level[randomY + 2][randomX].visited == false) && (Level[randomY][randomX].b_wall == true && Level[randomY + 2][randomX].t_wall == true)) ||
			((Level[randomY][randomX - 2].visited == false) && (Level[randomY][randomX].l_wall == true && Level[randomY][randomX - 2].r_wall == true)) ||
			((Level[randomY][randomX + 2].visited == false) && (Level[randomY][randomX].r_wall == true && Level[randomY][randomX + 2].l_wall == true)))
		{
			random = (rand() % 4) + 1;              // Decides on a random wall(1-4) to knock down

			 // Check top
			if ((random == 1) && (randomY > 1)) {
				if (Level[randomY - 2][randomX].visited == false) {        // If not visited
					Level[randomY - 1][randomX].display = ' ';        // Delete display
					Level[randomY - 1][randomX].visited = true;       // Mark cell as visited
					Level[randomY][randomX].t_wall = false;       // Knock down wall

					back_trackX.push(randomX);                      // Push X for back track
					back_trackY.push(randomY);                      // Push Y for back track

					randomY -= 2;                                   // Move to next cell
					Level[randomY][randomX].visited = true;         // Mark cell moved to as visited
					Level[randomY][randomX].display = ' ';          // Update path
					Level[randomY][randomX].b_wall = false;       // Knock down wall
					visitedCells++;                                 // Increase visitedCells counter
				}
				else
					continue;
			}

			// Check bottom
			else if ((random == 2) && (randomY < MAZESIZE - 2)) {
				if (Level[randomY + 2][randomX].visited == false) {        
					Level[randomY + 1][randomX].display = ' ';       
					Level[randomY + 1][randomX].visited = true;       
					Level[randomY][randomX].b_wall = false;       

					back_trackX.push(randomX);                     
					back_trackY.push(randomY);                      

					randomY += 2;                                  
					Level[randomY][randomX].visited = true;        
					Level[randomY][randomX].display = ' ';        
					Level[randomY][randomX].t_wall = false;       
					visitedCells++;                                
				}
				else
					continue;
			}

			// Check left
			else if ((random == 3) && (randomX > 1)) {
				if (Level[randomY][randomX - 2].visited == false) {        
					Level[randomY][randomX - 1].display = ' ';        
					Level[randomY][randomX - 1].visited = true;       
					Level[randomY][randomX].l_wall = false;    

					back_trackX.push(randomX);                     
					back_trackY.push(randomY);                    

					randomX -= 2;                                 
					Level[randomY][randomX].visited = true;        
					Level[randomY][randomX].display = ' ';         
					Level[randomY][randomX].r_wall = false;     
					visitedCells++;                                
				}
				else
					continue;
			}

			// Check right
			else if ((random == 4) && (randomX < MAZESIZE - 2)) {
				if (Level[randomY][randomX + 2].visited == false) {        
					Level[randomY][randomX + 1].display = ' ';       
					Level[randomY][randomX + 1].visited = true;      
					Level[randomY][randomX].r_wall = false;     

					back_trackX.push(randomX);                      
					back_trackY.push(randomY);                      

					randomX += 2;                                 
					Level[randomY][randomX].visited = true;        
					Level[randomY][randomX].display = ' ';         
					Level[randomY][randomX].l_wall = false;      
					visitedCells++;                                 
				}
				else
					continue;
			}

			//percent = (visitedCells * 100 / totalCells * 100) / 100;                // Progress in percentage
			//cout << "\nGenerating Maze:" << percent << "%" << endl;
		}
		else {
			randomX = back_trackX.top();
			back_trackX.pop();

			randomY = back_trackY.top();
			back_trackY.pop();
		}

		clearConsole();
		processingMaze(Level);
	}

	goalX = randomX;
	goalY = randomY;
	Level[goalY][goalX].display = 'E';//B is the exit
	system("cls");
	clearConsole();
	processingMaze(Level);
	cout << "\nA: Player\nB. Exit\n" << endl;
}

void MazeGenerator::clearConsole()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void MazeGenerator::runMazeGen(MazeGenerator Level[][MAZESIZE], string filename) {
	prepareMazeForRunner(Level);
	mazeToFile(Level, filename);

}

void MazeGenerator::prepareMazeForRunner(MazeGenerator Level[][MAZESIZE]) {
	int posX = 0;
	int posY = 0;
	int goalX = 0;
	int goalY = 0;
	//clock_t start_Timer, end_Timer;

	system("cls");

	initializeMaze(Level);
	processingMaze(Level);
	generateMaze(Level, posX, posY, goalX, goalY);
;
	//end_Timer = clock();
	//double duration_sec = double(end_Timer - start_Timer) / CLOCKS_PER_SEC;
	//cout << duration_sec << " seconds" << endl;
	//return duration_sec;
}
void MazeGenerator::mazeToFile(MazeGenerator Level[][MAZESIZE], string filename) {
	int response;
	ofstream out;
	//char file[100];
	//double d = prepareMazeForRunner(Level);
	out.open(filename);
	for (int i = 0; i < MAZESIZE; i++) {
		out << endl;
		for (int j = 0; j < MAZESIZE; j++) {
			out << Level[i][j].display << " ";
		}
	}
	//out << "\n" << d << " seconds" << endl;
	
	cout << "Your maze and results have been saved to" << "\"" << filename << "\"" << endl;
	out.close();
	
}

void MazeGenerator::mazeFromFile(string file, char maze[][101], int x, int y) {
	//string file;

	ofstream in_file;
	in_file.open(file, std::ofstream::out | std::ofstream::app);

	string line;
	int i = 0;
	//while (getline(in_file, line))
	//{
		//cout << line << endl;
	/*
		const char *tempArr = line.c_str();

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				maze[i][j] = tempArr[i];
				cout << tempArr[i] << endl;
			}
			//maze[i] = line.c_str();
			i++;
		}
		*/
		cout << "File read!\n";
		in_file.close();
		/*
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << maze[i][j];
			}
			cout << endl;
		}
		*/
		\
	//}

}
#endif // !DFSMAZEGENERATOR_H
