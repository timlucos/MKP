

// MKPlr1.cpp : тут все начало и конец 

#include <fstream>
#include <cmath>
#include <iostream>
const double e = 0.0084;
const long double Pi = 3.14159265358;
const double eps = 0.00001;
double excentricToTrue(double E)
{
	return atan(sqrt((1 + e) / (1 - e)) * tan(E / 2)) * 2;
}
double iterationMethod(double Enext, double Enow, double M)
{
	
	if(fabs(Enow - Enext ) < eps)
	{
		std::cout << Enext << std::endl;
		return Enext;//запись в файл
	}
	else
	{
		return iterationMethod(e * sin(Enext) + M, Enext, M);
	}
}

double halfDivisionMethod(double a, double b, double M)

{
	if (fabs(b - a) < 2 * eps || fabs(((a + b) / 2) - e * sin((a + b) / 2) - M) < eps)
	{
		return b + a / 2;
	}
	else if ((a - e * sin(a) - M) * (((a + b) / 2) - e * sin((a + b) / 2) - M) < 0)
	{
		return halfDivisionMethod(a, (a + b) / 2, M);
	}
	else
	{
		return halfDivisionMethod((a + b )/ 2, b, M);
	}
}

double goldenRatioMethod(double a, double b, double X, double M)
{
	if (fabs(b - a) < 2 * eps || fabs(((a + b) / 2) - e * sin((a + b) / 2) - M) < eps)
	{
		return a + (b - a) / X;
	}
	else if ((a - e * sin(a) - M) * (((a + b) / 2) - e * sin((a + b) / 2) - M) < 0)
	{
		return goldenRatioMethod(a, a + (b - a) / X, X, M);
	}
	else
	{
		return goldenRatioMethod(a + (b - a) / X, b, X, M);
	}
}

double newtonMethod(double dif, double E, double M)
{
	if (dif < eps)
	{
		return E - dif;
	}
	else
	{
		return newtonMethod((E - e * sin(E) - M) / ((eps - e * sin(E + eps) - e * sin(E)) / eps), E - (E - e * sin(E) - M) / ((eps - e * sin(E + eps) - e * sin(E)) / eps), M);
	}
}

int main()
{
	std::ofstream fout;
	std::ifstream fin;
	fout.open("iterationMethod.txt");
	if (fout.is_open())
	{
		for (int i = 0; i <= 360; i++)
		{
			double E1 = e * sin(i * 2 * Pi / 360) + (i * 2 * Pi / 360);
			double E0 = i * 2 * Pi / 360;
			fout << halfDivisionMethod(E1, E0, i * 2 * Pi / 360) << std::endl;
		}
	}
	fout.close();
	fin.open("iterationMethod.txt");
	fout.open("trueIterationMethod.txt");


  
	if (fin.is_open())
	{
		for (int i = 0; i <= 360; i++)
		{
			char ch[50];
			fin.getline(ch, 50);
			std::string str = ch;
			char* ptrEnd;
			fout << excentricToTrue(strtod(ch, &ptrEnd)) << std::endl;
		}
	}
	fin.close();
	fout.close();

	fout.open("halfDivisionMethod.txt");


  
	if (fout.is_open())
	{
		for (int i = 0; i <= 360; i++)
		{
			fout << halfDivisionMethod((i - 10) * 2 * Pi / 360, (i + 10) * 2 * Pi / 360, i * 2 * Pi / 360) << std::endl;
		}
	}
	fout.close();
	fin.open("halfDivisionMethod.txt");
	fout.open("trueHalfDivisionMethod.txt");



  
	if (fin.is_open())
	{
		for (int i = 0; i <= 360; i++)
		{
			char ch[50];
			fin.getline(ch, 50);
			std::string str = ch;
			char* ptrEnd;
			fout << excentricToTrue(strtod(ch, &ptrEnd)) << std::endl;
		}
	}
	fin.close();
	fout.close();




  
	fout.open("goldenRatioMethod.txt");



  
	if (fout.is_open())
	{
		for (int i = 0; i <= 360; i++)
		{
			fout << goldenRatioMethod((i - 10) * 2 * Pi / 360, (i + 10) * 2 * Pi / 360, (pow(5, 0.5) + 1) / 2, i * 2 * Pi / 360) << std::endl;
		}
	}
	fout.close();
	fin.open("goldenRatioMethod.txt");
	fout.open("trueGoldenRatioMethod.txt");


  
	if (fin.is_open())
	{
    
		for (int i = 0; i <= 360; i++)
		{
			char ch[50];
			fin.getline(ch, 50);
			std::string str = ch;
			char* ptrEnd;
			fout << excentricToTrue(strtod(ch, &ptrEnd)) << std::endl;
		}
	}
	fin.close();
	fout.close();


  
	fout.open("newtonMethod.txt");
	if (fout.is_open())
	{
		for (int i = 0; i <= 360; i++)
		{
			fout << newtonMethod(((i + 20) * 2 * Pi / 360 - e * sin((i + 20) * 2 * Pi / 360) - i * 2 * Pi / 360) / ((eps - e * sin((i + 20) * 2 * Pi / 360 + eps) - e * sin((i + 20) * 2 * Pi / 360)) / eps), (i + 20) * 2 * Pi / 360, i * 2 * Pi / 360) << std::endl;
		}
	}


  
	fout.close();
	fin.open("newtonMethod.txt");
	fout.open("trueNewtonMethod.txt");


  
	if (fin.is_open())
	{
		for (int i = 0; i <= 360; i++)
		{
			char ch[50];
			fin.getline(ch, 50);
			std::string str = ch;
			char* ptrEnd;
			fout << excentricToTrue(strtod(ch, &ptrEnd)) << std::endl;
		}
	}
	fin.close();
	fout.close();

	

	return 0;
}

