#pragma once

class H_coupling
{
private:
	af::array Hev;
public:
	H_coupling();
	void calculation();
	af::array getHev();
};