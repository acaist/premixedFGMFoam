#include "tableSolver.H"

void table::findZScope(double Z_)
{
    if( Z_ > Z_Index[0] && Z_ < Z_Index.back() )
    {
        position_L = lower_bound(Z_Index.begin(),Z_Index.end(),Z_) - Z_Index.begin() - 1;
        position_H = lower_bound(Z_Index.begin(),Z_Index.end(),Z_) - Z_Index.begin();

		Z_h = Z_Index[position_H];
        Z_l = Z_Index[position_L];

		weight_H = (Z_ - Z_l) / (Z_h - Z_l);
		weight_L = (Z_h - Z_) / (Z_h - Z_l);
    }

    else if(Z_ <= Z_Index[0])
    {
		position_L = 0;
		position_H = 0;

		Z_h = Z_Index[0];
        Z_l = Z_Index[0];

		weight_H = 0.5;
		weight_L = 0.5;
    }

    else
    {
		position_L = sizeZ - 1;
		position_H = sizeZ - 1;

        Z_h = Z_Index.back();
        Z_l = Z_Index.back();

		weight_H = 0.5;
		weight_L = 0.5;
    }

}
