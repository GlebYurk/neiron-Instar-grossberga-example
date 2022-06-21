#include <vector>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h> 

struct point
{
	double x, y;
};

class Instar {
private:
	double eta;// Learning Rate
	std::vector<double> x, y;
	point w;
protected:
	void norm(point* p)
	{
		double TempNorml;
		if (!(p->x == 0 && p->y == 0))
		{
			TempNorml = sqrt((p->x) * (p->x) + (p->y) * (p->y));
			p->x = p->x / TempNorml;
			p->y = p->y / TempNorml;
		}
	}
public:
	double angle1(double ax, double ay, double bx, double by)
	{
		double  mdla, mdlb, mdlab, ccos, ugl, cos1;
		int gr = 0, mn = 0, sc = 0;
		mdla = sqrt(ax * ax + ay * ay); //formula for vector length
		mdlb = sqrt(bx * bx + by * by);
		mdlab = mdla * mdlb;
		ccos = (ax * bx + ay * by) / mdlab; // formula for the cosine of the angle between vectors
		ugl = acos(ccos) * 180 / M_PI; // get the angle using the formula for converting radians to degrees
		std::cout << ugl << std::endl;
		return sc;
	}
	Instar(double a)
	{
		eta = a;
		w.x = 0;
		w.y = 0;
	}
	void Study(std::vector<point> Point)
	{
		for (int i = 1; i < Point.size(); i++) {
			w.x = w.x + eta * (Point[i].x - w.x);
			w.y = w.y + eta * (Point[i].y - w.y);

		}
		norm(&w);
	}
	int Test(double x, double y)
	{
		double outvalue;
		point z;
		z.x = x;
		z.y = y;
		norm(&z);
		angle1(w.x, w.y, z.x, z.y);
		return 1;
	}

};

