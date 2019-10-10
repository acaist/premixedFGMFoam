#include "tableSolver.H"

void table::findZScope(double Z_)
{
    if( Z_ > Z_Index[0] && Z_ < Z_Index.back() )
    {
        Z_position_l = lower_bound(Z_Index.begin(),Z_Index.end(),Z_) - Z_Index.begin() - 1;
        Z_position_r = lower_bound(Z_Index.begin(),Z_Index.end(),Z_) - Z_Index.begin();
        Z_high = Z_Index[Z_position_r];
        Z_low = Z_Index[Z_position_l];  
        std::cout << Z_position_l << std::endl;
        std::cout << Z_position_r << std::endl;
    }

    else if(Z_ <= Z_Index[0])
    {
        Z_high = Z_Index[0];
        Z_low  = Z_Index[0];
    }

    else
    {
        Z_high = Z_Index.back();
        Z_low  = Z_Index.back();
    }

}
