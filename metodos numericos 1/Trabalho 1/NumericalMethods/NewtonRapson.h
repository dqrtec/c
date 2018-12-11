#ifndef NEWTONRAPSON_H
#define NEWTONRAPSON_H

#include <iostream>
#include <cmath>

using namespace std;

class NewtonRapson {

private:
	double fitParam;
	double x0;
	double e;
	int maxIter;

public:
	NewtonRapson (double fit, double error, double iters) {
		fitParam = fit;
		e = error;
		maxIter = iters;
	}

	/* 'd' - is the offset measured in centimeter
	 * 'a' - is a paramter of fit for keep safe a rocket
	 * 		 with the max safety and possible efficiency
	 */
	double f (double d, double a) {
		return a * d - d * log(d);
	}


	double fLine(double d, double a){
		return a - log(d) - 1;
	}

	double phi(double d, double a){
		return d - (f(d, a) / fLine(d, a));
	}


	void initPoint (double fit) {
		double a = 0.000001;
		double b = 1;

		double fa = f(a, fit);
		double fb = f(b, fit);

		while (fa * fb > 0) {
			a = b;
			b += 1;

			fa = f(a, fit);
			fb = f(b, fit);
		}

		this->x0 = a + 0.5;
	}


	double newtonRapson () {
		initPoint(this->fitParam);

		double x0 = this->x0;
		double fitParam = this->fitParam;
		double e = this->e;
		int maxIter = this->maxIter;

		double fx0 = f(x0, fitParam);

		if(abs(fx0) < e) return x0;

		int k = 1;
		double x1;
		double fx1;

		while (k < maxIter){
			x1 = phi(x0, fitParam);
			fx1 = f(x1, fitParam);

			if (abs(x1 - x0) < e or abs(fx1) < e ){
				return x1;
			}

			x0 = x1;
			k += 1;
		}

		return x1;
	}
};

#endif