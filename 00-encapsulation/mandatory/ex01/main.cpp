#include "Graph.hpp"
#include "Vector2.hpp"


int main() {
	Graph tabs(5, 5);

	tabs.addPoints(1, 1);
	tabs.addPoints(2, 1);
	tabs.addPoints(2, 3);
	tabs.addPoints(2, 3);
	tabs.addPoints(4, 4);
	tabs.addPoints(4, 4);
	tabs.addPoints(4, 4);
	tabs.addPoints(4, 4);
	tabs.addPoints(0, 0);
	tabs.addPoints(1, 4);
	tabs.drawGraph();
}