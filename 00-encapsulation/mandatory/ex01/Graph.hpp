#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Vector2.hpp"
#include <iostream>
#include <vector>
#include <string>

// gerer les negatifs

class Graph
{
	private:
		Vector2 size;
		std::vector<Vector2> points;
		Graph();
		std::pair <float, float> maxDraw;
	public:
		Graph(float, float);
		~Graph();

		void addPoints(float, float);
		void drawGraph() const;
};

Graph::Graph(float x, float y) : size(x, y) {}

Graph::~Graph() {}

void Graph::addPoints(float x, float y) {
    if ((size.getX() >= x && size.getY() >= y) && (x >= 0 && y >= 0)) {
        std::vector<Vector2>::iterator it = points.begin();
        while (it != points.end()) {
			if (x == it->getX() && y == it->getY())
				return;
            if (x < it->getX() || (x == it->getX() && y < it->getY())) {
                ++it;
            } else {
                break;
            }
        }
        points.insert(it, Vector2(x, y));
    } else {
        std::cerr << "Graph: Incorrect size\n";
        return;
    }

    maxDraw.first = std::max(maxDraw.first, x + 1);
    maxDraw.second = std::max(maxDraw.second, y + 1);
}

// faire une execption si new failed ?
void Graph::drawGraph() const {
	for (std::vector<Vector2>::const_iterator it = points.begin(); it != points.end(); ++it)
		std::cout << "X: " << it->getX() << " Y: " << it->getY() << std::endl;
	char **grid = new char*[(int)size.getY() + 1];
	for (int y = 0; y <= size.getY(); ++y)
	{
		grid[y] = new char[(int)size.getX() + 1];
		int x = 0;
		while (x <= size.getX()) {
			grid[y][x] = '.';
			x++;
		}
	}
	for (std::vector<Vector2>::const_iterator it = points.begin(); it != points.end(); ++it)
		grid[(int)(it)->getY()][(int)(it)->getX()] = 'X';
	int x = 0;
	int y = size.getY(); 
	while (y >= 0) {
		x = 0;
		std::cout << y;
		while (x <= size.getX()) {
			std::cout << "  ";
			std::cout << grid[y][x];
			x++;
		}
		y--;
		std::cout << std::endl;
	}
	std::cout << " ";
	for (int i = 0; i <= size.getX(); ++i)
		std::cout << "  " << i;
	std::cout << std::endl;
	for (int i = 0; i <= size.getY(); i++)
		delete [] grid[i];
	delete [] grid;
}

#endif

echo "# PiscineObjectCpp" >> README.md
git init
git add .
git commit -m "first commit"
git branch -M main
git remote add origin git@github.com:SamuelGua/PiscineObjectCpp.git
git push -u origin main