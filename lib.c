
#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LONG 1
#define SHORT -1

static const long double INV_SQRT_2PI = 0.398942280401432685732823757440712597599485889077186584472656253L; // Precalculated 1 / sqrt(2 * M_PI)
static const long double SQRT_2 = 1.41421356237309504876378807303183293697657063603401184082031250L; // Precalculated value of sqrt(2)

double standardNormalPDF(const double z)
{
    return INV_SQRT_2PI * expl(-0.5L * z * z);
}

double standardNormalCDF(const double z)
{
    return 0.5 *  erfcl(-z / SQRT_2);
}

double d1(const double s, const double k, const double b, const double sigma, const double t)
{
    return (log(s / k) + (b + (sigma * sigma) / 2) * t) / (sigma * sqrt(t));
}

double d2(const double s, const double k, const double b, const double sigma, const double t)
{
    return d1(s, k, b, sigma, t) - sigma * sqrt(t);
}

double calc_delta_call(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign)
{
    return exp((b - r) * t) * standardNormalCDF(d1(s, k, b, sigma, t)) * sign;
}

double calc_delta_put(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign)
{
    return -exp((b - r) * t) * standardNormalCDF(-d1(s, k, b, sigma, t)) * sign;
}

double calc_gamma(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign)
{
    return (standardNormalPDF(d1(s, k, b, sigma, t)) * exp((b - r) * t)) / (s * sigma * sqrt(t)) * sign;
}

double calc_vega(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign)
{
    return (s * exp((b - r) * t) * standardNormalPDF(d1(s, k, b, sigma, t)) * sqrt(t) * sign) / 100;
}

double calc_theta_call(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign)
{
    return ((-((s * exp((b - r) * t) * standardNormalPDF(d1(s, k, b, sigma, t)) * sigma) / (2 * sqrt(t))) - (b - r) * s * exp((b - r) * t) * standardNormalCDF(d1(s, k, b, sigma, t)) - r * k * exp(-r * t) * standardNormalCDF(d2(s, k, b, sigma, t))) * sign) / 365;
}

double calc_theta_put(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign)
{
    return ((-((s * exp((b - r) * t) * standardNormalPDF(d1(s, k, b, sigma, t)) * sigma) / (2 * sqrt(t))) + (b - r) * s * exp((b - r) * t) * standardNormalCDF(-d1(s, k, b, sigma, t)) + r * k * exp(-r * t) * standardNormalCDF(-d2(s, k, b, sigma, t))) * sign) / 365;
}

double calc_rho_call(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign)
{
    return t * k * exp(-r * t) * standardNormalCDF(d2(s, k, b, sigma, t)) * sign;
}

double calc_rho_put(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign)
{
    return -t * k * exp(-r * t) * standardNormalCDF(-d2(s, k, b, sigma, t)) * sign;
}
