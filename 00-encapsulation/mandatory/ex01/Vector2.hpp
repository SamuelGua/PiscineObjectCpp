#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include "Graph.hpp"
#include <utility>

struct Vector2
{
	private:
		float x;
		float y;
		std::pair<float, float> points;
		Vector2();
		friend class Graph;

	public:
		Vector2(float, float);
		~Vector2();
		const float &getX() const;
		const float &getY() const;
		
};

Vector2::Vector2(float xP, float yP) : x(xP), y(yP)  {
	this->points.first = x;
	this->points.second = y;
}

Vector2::~Vector2() {}

const float &Vector2::getY() const {
	return (y);
}

const float &Vector2::getX() const {
	return (x);
}


#endif