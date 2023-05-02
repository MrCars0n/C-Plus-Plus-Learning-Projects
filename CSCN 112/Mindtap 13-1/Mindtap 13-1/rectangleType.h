class rectangleType
{
private:
	int length, height;
public:
	rectangleType(int length, int height)
	{
		this->length = length;
		this->height = height;
	}
	int getlength();
	int getheight();
	int area()
	{
		return length * height;
	}
	rectangleType& operator++();
	rectangleType& operator--();
	rectangleType& operator++(int);
	rectangleType& operator--(int);
	rectangleType operator-(const rectangleType& rt);
	bool operator==(const rectangleType& rt);
	bool operator!=(const rectangleType& rt);
	bool operator>(rectangleType& rt);
	bool operator<(rectangleType& rt);
	bool operator>=(rectangleType& rt);
	bool operator<=(rectangleType& rt);
	void show();
};
