#include <bits/stdc++.h>
#include "Polynomial.h"

using namespace std;

double limit = 323./1.5625;

const double obszar_lower = 1/4.;
const double obszar_upper = 1/2.;
const double obszar_jump = 1/4.;
const double zakres = 5;

int counter = 0;
long nrPoly = 0;


void checkPoint(double a, double d, double c);

void checkPolynomial(const double& a, const double& b, const double& c, const double& d, const double& e, const double& f, const double& g, const double& h, const double& i);

int main() {
    //orginalny punkt x=1/2 y=1/4 z=1/4
    //freopen("test2", "r", stdin);
    //freopen("output.txt", "w", stdout);

//    checkPolynomial(9 ,-4 ,-4 ,9, 9, -9, -9 ,2, 2  );

    auto start = std::chrono::system_clock::now();

    checkPoint( 0.5,0.25,0.25 );

        //checkPolynomial( -3 ,-3 ,6 ,-6 ,6 ,6 ,1.5 ,1.5 ,-6 );

//    for (double a=obszar_lower ; a<=obszar_upper ; a+=obszar_jump) {
//        for (double b=obszar_lower ; b<=obszar_upper ; b+=obszar_jump) {
//            for (double c=obszar_lower ; c<=obszar_upper ; c+=obszar_jump) {
//
//                checkPoint(a, b, c);
//            }
//        }
//
//        std::cout << a<<"\n";
//
//    }
//

    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double>elapsed = end - start;

    double average = nrPoly/elapsed.count();

    cout << elapsed.count()<<"\n";

    cout << "average (mil/s) =" << average/1.0e+06 << "\n";

    return 0;


}

void checkPoint(double v1, double v2, double v3) {


    for (int a=-zakres ; a<=zakres ; a++) {
        for (int b=-zakres ; b<=zakres ; b++) {
            for (int c=-zakres ; c<=zakres ; c++) {
                for (int d=-zakres ; d<=zakres ; d++) {
                    for (int e=-zakres ; e<=zakres ; e++) {
                        for (int f=-zakres ; f<=zakres ; f++) {
                            checkPolynomial(a, b, c, d, e, f, -v1*2*a,-v2*2*b,-v3*2*c);
                            nrPoly++;
                        }
                    }
                }
            }
        }

        std::cout << a << "\n";

    }
}

void checkPolynomial(const double& a, const double& b, const double& c, const double& d, const double& e, const double& f, const double& g, const double& h, const double& i) {

    Polynomial polynomial(a,b,c,d,e,f,g,h,i,0);

    Polynomial euklidesSquare = polynomial.getEuklides();

    polynomial.setMax();

    euklidesSquare.setMax();

    polynomial.setJ();

    //double j = polynomial.getJ();

    //double euklidesSquareMax = euklidesSquare.getMax();

    //double maxAbs = polynomial.getMax();

    if( euklidesSquare.getMax() / ( polynomial.getMax() * polynomial.getMax() ) >= limit  ) {

        limit = euklidesSquare.getMax() / (polynomial.getMax() * polynomial.getMax());

        cout << "Wielomian numer " << counter++ << endl;
        cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << " "
             << polynomial.getJ() << "\n";
        cout << sqrt(euklidesSquare.getMax() / (polynomial.getMax() * polynomial.getMax())) << "\n" << "\n";
    }
}