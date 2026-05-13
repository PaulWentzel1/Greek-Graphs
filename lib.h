double standardNormalCDF(const double z);
double standardNormalPDF(const double z);
//double normalCDF(const double x, const double mu, const double sigma);
//double normalPDF(const double x, const double mu, const double sigma);

double d1(const double s, const double k, const double b, const double sigma, const double t);
double d2(const double s, const double k, const double b, const double sigma, const double t);

double calc_delta_call(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign);
double calc_delta_put(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign);
double calc_gamma(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign);
double calc_vega(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign);
double calc_theta_call(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign);
double calc_theta_put(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign);
double calc_rho_call(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign);
double calc_rho_put(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign);