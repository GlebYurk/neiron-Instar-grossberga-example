#include "instar.cpp"
#include <random>
std::vector<point> generator1(int count, double x);//Генерация чисел для обучения (левого нижнего круга)
std::vector<point> generator2(int count, double x);//Генерация чисел для обучения (правого нижнего круга)
std::vector<point> generator3(int count, double x);//Генерация чисел для обучения (левого верхнего круга)
std::vector<point> generator4(int count, double x);//Генерация чисел для обучения (правого верхнего круга)
int main()
{
	point p; // Центр первого круга
	double eta; // Коэффицент обучения
	int count; // Количество точек
	do {
		std::cout << "x and y first circle centre=>1" << std::endl;
		std::cin >> p.x;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (p.x <= 1);
	p.y = p.x;
	std::vector<point> Point1 = generator1(500000, p.x);
	std::vector<point> Point2 = generator2(500000, p.x);
	std::vector<point> Point3 = generator3(500000, p.x);
	std::vector<point> Point4 = generator4(500000, p.x);
	std::cout << "0,X. Enter X. 0,X=Learning rate" << std::endl;
	std::cin >> eta;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (eta > 1)
	{
		eta = eta / 10;
	}
	Instar instar1(eta);
	Instar instar2(eta);
	Instar instar3(eta);
	Instar instar4(eta);
	double x = 0, y;
	instar1.Study(Point1);
	instar2.Study(Point2);
	instar3.Study(Point3);
	instar4.Study(Point4);
	while (x != -1) {
		std::cout << "x="; std::cin >> x;
		std::cout << "y="; std::cin >> y;
		instar1.Test(x, y);
		instar2.Test(x, y);
		instar3.Test(x, y);
		instar4.Test(x, y);
	}
}
std::vector<point> generator1(int count, double x)//Генерация чисел для обучения (левого нижнего круга)
{
	double z = x + 1;
	double d, y1, y2;
	point p;
	std::vector<point> Point;
	for (int i = 0; i < count; i++) {
		std::random_device rd;
		std::default_random_engine Rgenerator(rd());
		std::uniform_real_distribution<double> distribution(1, (x + z));
		p.x = distribution(Rgenerator);  // generates number in the range 1..6
		//p.x=rand() % (x + z) + (x - z);
		p.y = (p.x - z) * (p.x - z) - x * x + z * z;
		d = 2 * z * 2 * z - 4 * p.y;
		y1 = (2 * z + sqrt(d)) / 2;
		y2 = (2 * z - sqrt(d)) / 2;
		if (y1 > y2)
		{
			std::uniform_real_distribution<double> distribution2(y2, y1);
			p.y = distribution2(Rgenerator);
		}
		else {
			std::uniform_real_distribution<double> distribution2(y1, y2);
			p.y = distribution2(Rgenerator);
		}

		Point.push_back(p);

	}
	return Point;
}
std::vector<point> generator2(int count, double x)//Генерация чисел для обучения (левого верхнего круга)
{
	double z = x + 1;
	double d, y1, y2;
	point p;
	std::vector<point> Point;
	for (int i = 0; i < count; i++) {
		std::random_device rd;
		std::default_random_engine Rgenerator(rd());
		std::uniform_real_distribution<double> distribution((x + z + 2), (3 * x + z + 2));
		p.x = distribution(Rgenerator);  // generates number in the range 1..6
		//p.x=rand() % (x + z) + (x - z);
		p.y = (p.x - z * 3) * (p.x - z * 3) - x * x + z * z;
		d = 2 * z * 2 * z - 4 * p.y;
		y1 = (2 * z + sqrt(d)) / 2;
		y2 = (2 * z - sqrt(d)) / 2;
		if (y1 > y2)
		{
			std::uniform_real_distribution<double> distribution2(y2, y1);
			p.y = distribution2(Rgenerator);
		}
		else
		{
			std::uniform_real_distribution<double> distribution2(y1, y2);
			p.y = distribution2(Rgenerator);
		}

		Point.push_back(p);
	}
	return Point;
}
std::vector<point> generator3(int count, double x)//Генерация чисел для обучения (левого верхнего круга)
{
	double z = x + 1;
	double d, y1, y2;
	point p;
	std::vector<point> Point;
	for (int i = 0; i < count; i++) {
		std::random_device rd;
		std::default_random_engine Rgenerator(rd());
		std::uniform_real_distribution<double> distribution(1, (x + z));
		p.x = distribution(Rgenerator);  // generates number in the range 1..6
		//p.x=rand() % (x + z) + (x - z);
		p.y = (p.x - z) * (p.x - z) - x * x + z * z * 9;
		d = 2 * z * 2 * z * 9 - 4 * p.y;
		y1 = (2 * z * 3 + sqrt(d)) / 2;
		y2 = (2 * z * 3 - sqrt(d)) / 2;
		if (y1 > y2)
		{
			std::uniform_real_distribution<double> distribution2(y2, y1);
			p.y = distribution2(Rgenerator);
		}
		else
		{
			std::uniform_real_distribution<double> distribution2(y1, y2);
			p.y = distribution2(Rgenerator);
		}

		Point.push_back(p);
	}
	return Point;
}
std::vector<point> generator4(int count, double x)//Генерация чисел для обучения (правого верхнего круга)
{
	double z = x + 1;
	double d, y1, y2;
	point p;
	std::vector<point> Point;
	for (int i = 0; i < count; i++) {
		std::random_device rd;
		std::default_random_engine Rgenerator(rd());
		std::uniform_real_distribution<double> distribution((x + z + 2), (3 * x + z + 2));
		p.x = distribution(Rgenerator);  // generates number in the range 1..6
		//p.x=rand() % (x + z) + (x - z);
		p.y = (p.x - z * 3) * (p.x - z * 3) - x * x + z * z * 9;
		d = 2 * z * 2 * z * 9 - 4 * p.y;
		y1 = (2 * z * 3 + sqrt(d)) / 2;
		y2 = (2 * z * 3 - sqrt(d)) / 2;
		if (y1 > y2)
		{
			std::uniform_real_distribution<double> distribution2(y2, y1);
			p.y = distribution2(Rgenerator);
		}
		else {
			std::uniform_real_distribution<double> distribution2(y1, y2);
			p.y = distribution2(Rgenerator);
		}

		Point.push_back(p);
	}
	return Point;
}
