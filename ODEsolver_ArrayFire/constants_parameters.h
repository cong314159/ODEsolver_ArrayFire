#pragma once

double qe = 1.602e-19; // [C] elementry charge
double amu2eV = 931.5e6;
double epsilon0 = 8.854e-12; // [F / m] vacuum permittivity
double c_cms = 2.997e10; // [cm / s] speed of light in cm
double c_nms = 2.997e17; // [nm / s] speed of light in nm
double hbar_eVs = 6.582e-16; // [eV*s / rad] reduced planck constant
double kb = 8.617e-5; // [eV / K] boltzmann constant in eVs

double a = 1; // [nm]
double temp = 300; // [K]
double f_inv_cms = 298; // [1 / cms]
double m_amu = 5.58; // [amu]
double lambda = 440; // [meV]
double gamma = 0.1; // [eV]
double amp_clk = 1; // [V / nm] Clocking field amplitude
double a_drv = 0.9; // [] driver cell activation
double n_clock = 3; // [] number of clock periods
double errorTolerance = 0.01; //

double f = 0;
double omega = 0;
double tau = 0;
double T_clk = 0;
double T_drv = 0;
double T_total = 0;
double T_lindblad = 0;
double hbw = 0;
double m = 0;

int Nv = 21;
int Ne = 3;