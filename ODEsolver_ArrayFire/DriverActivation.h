#pragma once

class DrvActiv
{
private:
	double m_act;
public:
	DrvActiv();
	void setParam(double act);
	double getActiv();
	double getActiv(double t);
};