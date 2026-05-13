cdef extern from "lib.h":
    double calc_delta_call(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign)
    double calc_delta_put(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign)
    double calc_gamma(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign)
    double calc_vega(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign)
    double calc_theta_call(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign)
    double calc_theta_put(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign)
    double calc_rho_call(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign)
    double calc_rho_put(const double s, const double k, const double b, const double sigma, const double t, const double r, const int sign)

def delta_call(s: float, k: float, b: float, sigma: float, t: float, r: float, sign: int) -> float:
    return calc_delta_call(s, k, b, sigma, t, r, sign)

def delta_put(s: float, k: float, b: float, sigma: float, t: float, r: float, sign: int) -> float:
    return calc_delta_put(s, k, b, sigma, t, r, sign)

def gamma(s: float, k: float, b: float, sigma: float, t: float, r: float, sign: int) -> float:
    return calc_gamma(s, k, b, sigma, t, r, sign)

def vega(s: float, k: float, b: float, sigma: float, t: float, r: float, sign: int) -> float:
    return calc_vega(s, k, b, sigma, t, r, sign)

def theta_call(s: float, k: float, b: float, sigma: float, t: float, r: float, sign: int) -> float:
    return calc_theta_call(s, k, b, sigma, t, r, sign)

def theta_put(s: float, k: float, b: float, sigma: float, t: float, r: float, sign: int) -> float:
    return calc_theta_put(s, k, b, sigma, t, r, sign)

def rho_call(s: float, k: float, b: float, sigma: float, t: float, r: float, sign: int) -> float:
    return calc_rho_call(s, k, b, sigma, t, r, sign)

def rho_put(s: float, k: float, b: float, sigma: float, t: float, r: float, sign: int) -> float:
    return calc_rho_put(s, k, b, sigma, t, r, sign)
