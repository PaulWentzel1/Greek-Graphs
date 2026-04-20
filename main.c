#include <stdio.h>
#include <math.h>


extern double normalCDF(const double x, const double mu, const double sigma);
extern double normalPDF(const double x, const double mu, const double sigma);

extern double standardNormalCDF(const double x);
extern double standardNormalPDF(const double x);

extern double d1(const double s, const double k, const double b, const double t, const double sigma);
extern double d2(const double d1, const double sigma, const double t);



double normalCDF(const double x, const double mu, const double sigma)
{
    double z = (x - mu) / sigma;
    return exp(-0.5 * z * z) / (sigma * sqrt(2.0 * M_PI));

    //replace ** with pow()
    return (1.0 / sqrt(2.0 * M_PI * sigma ** 2)) * exp(-((x - mu) ** 2 / 2.0 * sigma ** 2   ))
}