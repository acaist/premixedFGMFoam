#ifndef TABLESOLVER_H
#define TABLESOLVER_H

#include "table.H"

class table
{
public:
    //Constructor
    tableSolver();
    //member function
    void findZScope(double Z_);

    double lookupT() const
    {
        return table_[Z_position_h]->lookupT() * weightH_ +
                table_[Z_position_l]->lookupT() * weightL_;
    }
    double lookupOmegaYc() const
    {
        return table_[Z_position_h]->lookupYc() * weightH_ +
                table_[Z_position_l]->lookupYc() * weightL_;
    }
    double lookupY(size_t i) const
    {
        return table_[Z_position_h]->lookupY(i) * weightH_ +
                table_[Z_position_l]->lookupY(i) * weightL_;
    }

private:
    size_t Z_position_l;
    size_t Z_position_h;
    double Z_high;
    double Z_low;
    double Zi_; //Z value derived from table i;
    double weightH_;
    double weightL_;

    std::vector<table> table_ 
};

#endif