#pragma once

class DrvPolar
{
private:
	double m_T;
public:
	DrvPolar();
	void setParam(double T);
	double getPolar(double t);
};