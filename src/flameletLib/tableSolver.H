#ifndef TABLESOLVER_H
#define TABLESOLVER_H

#include "table.H"

class tableSolver
{
public:
    //Constructor
    tableSolver(double Zi_);

    //member function
	void collectTables(double Zi_);

    void find(double Z_, double Yc_);//Z_ = ZCells[Celli] in lookupTable.H;

    double lookupT() const
    {
        return table_[position_H]->lookupT() * weightH_ +
                table_[position_L]->lookupT() * weightL_;
    }
    double lookupOmegaYc() const
    {
        return table_[position_H]->lookupYc() * weightH_ +
                table_[position_L]->lookupYc() * weightL_;
    }
    double lookupY(size_t i) const
    {
        return table_[position_H]->lookupY(i) * weightH_ +
                table_[position_L]->lookupY(i) * weightL_;
    }

private:
    size_t position_L;
    size_t position_H;
    double Z_h; //lower Z;
    double Z_l; //upper Z;
    double Zi_; //Z value derived from table i;
    double weight_H;
    double weight_L;

	size_t sizeZ = table_[0].vectorSize();//column size of each table;

    std::vector<table> table_ //table¡ª¡ª>tableSolver//Each element of vector table_ is table type;
};

#endif