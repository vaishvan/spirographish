#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#define PI  3.14159265358979323846

std::vector<sf::Vector2f> points;


std::vector<sf::Vector2f> calculateSpirographPoints(float r, float d, float R, float cx, float cy, float theta, float omega, float dT, int numPoints, std::string sign);
void drawSpirograph(sf::RenderWindow& window, const std::vector<sf::Vector2f>& points, sf::Color color, float lineWidth);


int main() {
	
	int width = 800;
	int lineWidth, tempX, tempY, count, red, blue, green;
	float x, y, X, Y, cx, cy, r, d, R, theta, omega, dT, temp;
	std::string lineA, lineB, sign;
	std::vector <std::string> vecLine;

	theta = 0.0f;
	omega = 0.0f;
	dT = PI / 50;



	std::cout << "input r, d, R, cx, cy, red, blue, green, sign, width and number of points";
	
	for (int i = 0; i <10 ; i++) {
		std::string a;
		std::cin >> a;
		vecLine.push_back(a);
	}
	
	//define values to each r, d etc

	r = std::stof(vecLine[0]);
	d = std::stof(vecLine[1]);
	R = std::stof(vecLine[2]);
	cx = std::stof(vecLine[3]);
	cy = std::stof(vecLine[4]);
	red = std::stoi(vecLine[5]); 
	green = std::stoi(vecLine[6]);
	blue = std::stoi(vecLine[7]);
	sign = vecLine[8];
	lineWidth = std::stoi(vecLine[9]);

	int numPoints;

	std::cin >> numPoints;

	points = calculateSpirographPoints(r, d, R, cx, cy, theta, omega, dT, numPoints, sign);

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "spiro");


	//game loop

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			
		}

		window.clear();
		// Update angles for animation
		theta += dT;
		omega += dT;

		// Recalculate points
		points = calculateSpirographPoints(r, d, R, cx, cy, theta, omega, dT, numPoints, sign);

		drawSpirograph(window, points, sf::Color(red, green, blue, 200), lineWidth);

		window.display();
	}

}

std::vector<sf::Vector2f> calculateSpirographPoints(float r, float d, float R, float cx, float cy, float theta, float omega, float dT, int numPoints, std::string sign) {
	float k = r / R;
	float e = d / R;

	for (int i = 0; i < numPoints; ++i) {
		theta += dT;
		omega += k * dT;

		float x = (R - r) * cos(theta) + e * r * cos((1 - k) * theta);
		float y = (R - r) * sin(theta) - e * r * sin((1 - k) * theta);

		points.push_back(sf::Vector2f(cx + x, cy + y));
	}

	return points;
}


void drawSpirograph(sf::RenderWindow& window, const std::vector<sf::Vector2f>& points, sf::Color color, float lineWidth) {

		sf::Vector2f windowCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);

		for (size_t i = 1; i < points.size(); ++i) {
			sf::Vector2f direction = points[i] - points[i - 1];
			float angle = std::atan2(direction.y, direction.x);
			float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);


			sf::RectangleShape line(sf::Vector2f(length, lineWidth));
			line.setPosition(points[i - 1]);
			line.setRotation(angle * 180 / PI);
			line.setFillColor(color);
			window.draw(line);
		}
}

