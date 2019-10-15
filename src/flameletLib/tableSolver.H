#ifndef TABLESOLVER_H
#define TABLESOLVER_H

#include "table.H"

class tableSolver
{
public:
    //Constructor
	tableSolver();

    //member function
	void collectTables();

	void find(double Z_, double Yc_);

	double lookupT() const
    {
		return table_[position_H].lookupT() * weight_H + table_[position_L].lookupT() * weight_L;
    }
	double lookupOmegaYc() const
    {
		return table_[position_H].lookupOmegaYc() * weight_H + table_[position_L].lookupOmegaYc() * weight_L;
    }
	double lookupY(size_t i) const
    {
		return table_[position_H].lookupY(i) * weight_H + table_[position_L].lookupY(i) * weight_L;
    }

private:
	size_t tableNum;//number of tables;
    size_t position_L;
    size_t position_H;
    double Z_h; //lower Z;
    double Z_l; //upper Z;
    double weight_H;
    double weight_L;

	std::vector<double> Z_Index;//与csv文件一一对应的容器；
	std::vector<table> table_ //table——>tableSolver//Each element of vector table_ is table type;
};

#endif