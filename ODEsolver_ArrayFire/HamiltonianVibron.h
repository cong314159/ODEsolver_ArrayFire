#pragma once

class H_vibron
{
private:
	af::array Hv;
public:
	H_vibron();
	void calculation();
	af::array getHv();
};