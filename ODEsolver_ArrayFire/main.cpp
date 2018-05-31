#define _USE_MATH_DEFINES

#include <iostream>
#include <arrayfire.h>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>

#include "constants_parameters.h"
#include "ClockField.h"
#include "DriverPolarization.h"
#include "DriverActivation.h"
#include "HamiltonianVibron.h"
#include "HamiltonianCoupling.h"
#include "HamiltonianElectronic.h"
#include "kron.h"
#include "trace.h"
#include "MatrixPower.h"
#include "Factorial.h"
#include "expm.h"

int main()
{
	try
	{
		m = m_amu * amu2eV / c_nms / c_nms;
		f = f_inv_cms * c_cms;
		omega = 2 * f * M_PI;
		tau = (double)1 / f;
		T_clk = 10 * tau;
		T_drv = 20 * tau;
		T_total = n_clock * T_clk;
		T_lindblad = tau / 2;
		hbw = hbar_eVs * omega;

		ClockField cf;
		cf.setParam(T_clk, amp_clk);
		//std::cout << cf.getField(T_clk / 8) << std::endl;

		DrvPolar dp;
		dp.setParam(T_drv);
		//std::cout << dp.getPolar(T_drv / 8) << std::endl;

		DrvActiv da;
		da.setParam(a_drv);
		//std::cout << da.getActiv() << std::endl;

		H_vibron hv_object = H_vibron();
		hv_object.calculation();
		af::array Hv = hv_object.getHv();
		af::array Ie = af::identity(Ne, Ne, f64);
		//af_print(Hv);

		H_coupling hc_object = H_coupling();
		hc_object.calculation();
		af::array Hev = hc_object.getHev();
		//af_print(Hev.cols(0,9).rows(0,9));
		
		H_elect he_object = H_elect();
		af::array He = he_object.getHe(cf, dp, da, 0);
		af::array Iv = af::identity(Nv, Nv, f64);
		//af_print(he_object.getHe(cf, dp, da, (double)0.12354645677658));

		af::array Heq = Hev + kron(He, Iv) + kron(Ie, Hv);
		//af_print(Heq.cols(0,9).rows(0,9));

		//std::cout << trace(Heq) << std::endl;
		//af_print(matpow(Heq, 0));
		//std::cout << factorial(3) << std::endl;
		//std::cin.get();

		//af::array Z_array = expm(-Heq / kb / temp);
		//af_print(expm(-Heq / kb / temp).rows(0, 9).cols(0, 9));
		//af::cdouble Z = trace(Z_array);
		//af::array rho_eq = expm(-Heq / kb / temp) / Z;

		// read the thermal equilibrium density matrix instead
		std::ifstream file;
		file.open("rhoEq.txt");
		std::string line;
		if (file.fail())
		{
			std::cerr << "Error opening file" << std::endl;
			exit(1);
		}
		//double rho_eq_data[];
		while (std::getline(file, line))
		{
			std::istringstream iss(line);
			std::string word;
			while (iss >> word)
			{
				std::cout << word << std::endl;
			}
		}
	}
	catch (std::exception& e)
	{
		fprintf(stderr, "%s\n", e.what());
		throw;
	}

	return 0;
}