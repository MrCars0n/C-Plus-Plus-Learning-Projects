#include<iostream>
#include"Shape.h"
#include"Rectangle.h"
#include"Circle.h"
#include"Triangle.h"
#include<vector>

using namespace std;
int main()
{
	// Creating a shape object
	// Shape s;
	// s.draw();

	// Creating a rectangle object
	Rectangle r("Rectangle", 1, 1);
	r.draw();

	// Creating a rectangle pointer
	Rectangle* rPtr{ new Rectangle("Rectangle2", 2, 2) };
	rPtr->draw();

	// Creating a vector of shape poointers and adding rectangles and circles to it
	vector<Shape*> shapes;

	shapes.push_back(new Rectangle);
	shapes.push_back(new Circle);
	shapes.push_back(new Shape);
	shapes.push_back(new Triangle("Triangle4", 1, 3)); // Add your right triangle here

	cout << "\n\nThese are the shapes in the Shapes vector: " << endl;
	for (Shape* shapePtr : shapes)
	{
		shapePtr->draw();
	}

	system("pause");
	return 0;
}