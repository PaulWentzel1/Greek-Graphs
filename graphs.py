import wrapper
import matplotlib.pyplot as plt
import numpy as np

s     = np.linspace(50, 150, 400)
k     = 100
expiries = [0.25, 0.5, 0.75, 1.0]
sigma = 0.2
r     = 0.04
b     = 0.04
LONG  =  1
SHORT = -1

data: dict[str, dict[str, dict[float, list[float]]]] = {
    "Delta": {
        "Long Call": {t: [wrapper.delta_call(i, k, b, sigma, t, r, LONG)  for i in s] for t in expiries},
        "Short Call": {t: [wrapper.delta_call(i, k, b, sigma, t, r, SHORT) for i in s] for t in expiries},
        "Long Put": {t: [wrapper.delta_put(i,  k, b, sigma, t, r, LONG)  for i in s] for t in expiries},
        "Short Put": {t: [wrapper.delta_put(i,  k, b, sigma, t, r, SHORT) for i in s] for t in expiries}
    },
    "Gamma": {
        "Long Call": {t: [wrapper.gamma(i, k, b, sigma, t, r, LONG)  for i in s] for t in expiries},
        "Short Call": {t: [wrapper.gamma(i, k, b, sigma, t, r, SHORT) for i in s] for t in expiries},
        "Long Put": {t: [wrapper.gamma(i, k, b, sigma, t, r, LONG)  for i in s] for t in expiries},
        "Short Put": {t: [wrapper.gamma(i, k, b, sigma, t, r, SHORT) for i in s] for t in expiries}
    },
    "Vega": {
        "Long Call": {t: [wrapper.vega(i, k, b, sigma, t, r, LONG)  for i in s] for t in expiries},
        "Short Call": {t: [wrapper.vega(i, k, b, sigma, t, r, SHORT) for i in s] for t in expiries},
        "Long Put": {t: [wrapper.vega(i, k, b, sigma, t, r, LONG)  for i in s] for t in expiries},
        "Short Put": {t: [wrapper.vega(i, k, b, sigma, t, r, SHORT) for i in s] for t in expiries}
    },
    "Theta": {
        "Long Call": {t: [wrapper.theta_call(i, k, b, sigma, t, r, LONG)  for i in s] for t in expiries},
        "Short Call":{t: [wrapper.theta_call(i, k, b, sigma, t, r, SHORT) for i in s] for t in expiries},
        "Long Put": {t: [wrapper.theta_put(i,  k, b, sigma, t, r, LONG)  for i in s] for t in expiries},
        "Short Put": {t: [wrapper.theta_put(i,  k, b, sigma, t, r, SHORT) for i in s] for t in expiries}
    },
    "Rho": {
        "Long Call": {t: [wrapper.rho_call(i, k, b, sigma, t, r, LONG)  for i in s] for t in expiries},
        "Short Call": {t: [wrapper.rho_call(i, k, b, sigma, t, r, SHORT) for i in s] for t in expiries},
        "Long Put": {t: [wrapper.rho_put(i,  k, b, sigma, t, r, LONG)  for i in s] for t in expiries},
        "Short Put": {t: [wrapper.rho_put(i,  k, b, sigma, t, r, SHORT) for i in s] for t in expiries}
    },
}

n_vertical_plots = len(data)
n_horizontal_plots = len(next(iter(data.values())))

fig, axes = plt.subplots(n_vertical_plots, n_horizontal_plots, figsize=(15,16))
greeks = list(data.keys())

for row_idx, greek_name in enumerate(greeks): # row-wise (greek-wise) iteration
    for col_idx, (label, values) in enumerate(data[greek_name].items()): # col-wise (call/put long/short) iteration
        ax = axes[row_idx, col_idx]

        ax.set_title(f"{greek_name} of a {label}")
        ax.set_xlabel("Spot Price")
        ax.set_ylabel(greek_name)
        ax.plot(s, values[0.25], label=f"T={0.25}")
        ax.plot(s, values[0.5], label=f"T={0.5}")
        ax.plot(s, values[0.75], label=f"T={0.75}")
        ax.plot(s, values[1], label=f"T={1}")


handles, labels = axes[0, 0].get_legend_handles_labels()
fig.legend(handles, labels, loc="lower center", ncol=4, bbox_to_anchor=(0.5, 0.01))

plt.tight_layout(rect=[0, 0.05, 1, 1])
plt.savefig("option_greeks.png")
plt.savefig("option_greeks_transparent.png", transparent=True)