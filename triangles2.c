#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Vertices is 1, side lengths is 2


bool isValidVertices(double x1, double y1, double x2, double y2, double x3, double y3);
bool isValidSides(double a, double b, double c);
bool isIdentical(double a, double b, double c, double d, double e, double f);


int main(void)
{
	double x11, y11, x12, y12, x13, y13, a1, b1, c1;
	double x21, y21, x22, y22, x23, y23, a2, b2, c2;
	double circumference1, circumference2;
	double side11, side12, side13, side21, side22, side23;
	int triangle1, triangle2;

	printf("Triangle #1:\n");
	if (scanf(" { %lf , %lf , %lf }", &a1, &b1, &c1) == 3)
	{
		if (a1 >= 0 && b1 >= 0 && c1 >= 0)
		{
			if (isValidSides(a1, b1, c1) == false)
			{
				printf("Invalid triangle.\n");
				return 1;
			}		
		
			triangle1 = 2;
		}

		else
		{
			printf("Invalid input.\n");
			return 1;
		}
	}

	else if (scanf(" [ %lf ; %lf ] , [ %lf ; %lf ] , [ %lf ; %lf ] }", &x11, &y11, &x12, &y12, &x13, &y13) == 6)
	{
		if (isValidVertices(x11, y11, x12, y12, x13, y13) == false)
		{
			printf("Invalid triangle.\n");
			return 1;
		}

		triangle1 = 1;
	}

	else
	{
		printf("Invalid input.\n");
		return 1;	
	}
	
	printf("Triangle #2:\n");
	if (scanf(" { %lf , %lf , %lf }", &a2, &b2, &c2) == 3)
	{
		if (a2 >= 0 && b2 >= 0 && c2 >= 0)
		{
			if (isValidSides(a2, b2, c2) == false)
			{
				printf("Invalid triangle.\n");
				return 1;
			}

			triangle2 = 2;
		}

		else
		{
			printf("Invalid input.\n");
			return 1;
		}	
	}

	else if (scanf(" [ %lf ; %lf ] , [ %lf ; %lf ] , [ %lf ; %lf ] }", &x21, &y21, &x22, &y22, &x23, &y23) == 6)
	{
		if (isValidVertices(x21, y21, x22, y22, x23, y23) == false)
		{
			printf("Invalid triangle.\n");
			return 1;
		}

		triangle2 = 1;
	}

	else
	{
		printf("Invalid input.\n");
		return 1;	
	}

// Input handling is done here and actual program starts.

	if (triangle1 == 1)
	{	
		side11 = sqrt((x11 - x12)*(x11 - x12) + (y11 - y12)*(y11 - y12));
		side12 = sqrt((x11 - x13)*(x11 - x13)+(y11 - y13)*(y11 - y13));
		side13 = sqrt((x12 - x13)*(x12 - x13) + (y12- y13)*(y12 - y13));
		
		circumference1 = side11 + side12 + side13;
	}
	
	else
	{
		circumference1 = a1 + b1 + c1;
	}

	if (triangle2 == 1)
	{	
		side21 = sqrt((x21 - x22)*(x21 - x22) + (y21 - y22)*(y21 - y22));
		side22 = sqrt((x21 - x23)*(x21 - x23)+(y21 - y23)*(y21 - y23));
		side23 = sqrt((x22 - x23)*(x22 - x23) + (y22- y23)*(y22 - y23));
		
		circumference2 = side21 + side22 + side23;
	}

	else
	{
		circumference2 = a2 + b2 + c2;
	}

	
	if (triangle1 == 1 && triangle2 == 1)
	{
		if (isIdentical(side11, side12, side13, side21, side22, side23) == true)
		{
			printf("The triangles are identical.\n");
			return 0;
		}
	}

	else if (triangle1 == 1 && triangle2 == 2)
	{
		if (isIdentical(side11, side12, side13, a2, b2, c2) == true)
		{
			printf("The triangles are identical.\n");
			return 0;
		}
	}

	else if (triangle1 == 2 && triangle2 == 1)
	{
		if (isIdentical(a1, b1, c1, side21, side22, side23) == true)
		{
			printf("The triangles are identical.\n");
			return 0;
		}
	}

	else if (triangle1 == 2 && triangle2 == 2)
	{
		if (isIdentical(a1, b1, c1, a2, b2, c2) == true)
		{
			printf("The triangles are identical.\n");
			return 0;
		}
	}

	if (fabs(circumference1 - circumference2) < 0.0000000000000001)
	{
		printf("The triangles are not identical, however, they have the same circumference.\n");
		return 0;
	}

	else
	{
		if (circumference1 > circumference2)
		{
			printf("Triangle #1 has a longer circumference.\n");
			return 0;
		}

		else
		{
			printf("Triangle #2 has a longer circumference.\n");
			return 0;
		}
	}

	return 0;
}

bool isValidVertices(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double ab1, ac1, ab2, ac2, controller;
	
	ab1 = x2 - x1;
	ab2 = y2 - y1;
	ac1 = x3 - x1;
	ac2 = y3 - y1;

	controller = (ab1 * ac2) - (ab2 * ac1);

	if (fabs(controller - 0) < 0.0000000000000001)
	{
		return false;
	}
	
	else
	{
		return true;
	}
}

bool isValidSides(double a, double b, double c)
{
	if (fabs(a + b - c) <= 0.0000000000000001 || fabs(a + c - b) <= 0.0000000000000001 || fabs(b + c - a) <= 0.0000000000000001)
	{
		return false;
	}

	else
	{
		return true;
	}
}

bool isIdentical(double a, double b, double c, double d, double e, double f)
{
	if (fabs(a - d) < 0.0000000000000001)
	{
		if(fabs(b - e) < 0.0000000000000001)
		{
			if(fabs(c - f) < 0.0000000000000001)
			{
				return true;
			}
		}

		else if (fabs(b - f) < 0.0000000000000001)
		{
			if (fabs(c - e) < 0.0000000000000001)
			{
				return true;
			}
		}
	}

	else if (fabs(a - e) < 0.0000000000000001)
	{
		if (fabs(b - d) < 0.0000000000000001)
		{
			if (fabs(c - f) < 0.0000000000000001)
			{
				return true;
			}
		}

		else if (fabs(b - f) < 0.0000000000000001)
		{
			if (fabs(c - d) < 0.0000000000000001)
			{
				return true;
			}
		}
	}

	else if (fabs(a - f) < 0.0000000000000001)
	{
		if (fabs(b - d) < 0.0000000000000001)
		{
			if (fabs(c - e) < 0.0000000000000001)
			{
				return true;
			}
		}

		else if (fabs(b - e) < 0.0000000000000001)
		{
			if (fabs(c - d) < 0.0000000000000001)
			{
				return true;
			}
		}
	}

	return false;
}
