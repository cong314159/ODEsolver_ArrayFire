#pragma once

class ClockField
{
private:
	double m_T;
	double m_amp;

public:
	ClockField();
	void setParam(double T, double amp);
	double getField(double t);
};