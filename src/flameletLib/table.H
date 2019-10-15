#ifndef TABLE_H
#define TABLE_H

#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class table
{
public:
    //Constructor
    table(std::ifstream& tableFile);

    //Member function
    void findYcScope( double Yc_ ); //find the lower and upper values of Yc at each table Zi , input Yc_; 

    double lookupT() const
    {
        return weight_H * T_[position_H] + weight_L * T_[position_L];   
    }

    double lookupYc() const
    {
		return weight_H * Yc_[position_H] + weight_L * Yc_[position_L];
    }

    double lookupY(size_t i) const
    { 
		return weight_H * Y[i][position_H] + weight_L * Y[i][position_H]
    }

	size_t ColumnNum() const
	{
		return ColumnNum;
	}

	double getZ()
	{
		return Zi_;
	}

private:
	//Private member function:
	void read(); //read informations in lookup table;

	//Class members:
	std::ifstream& tableFile_;

    size_t position_L; //the position of smaller Yc in the table Zi;
    size_t position_H; //the position of larger Yc in the table Zi;
    double weight_H;   //weight coeff.
    double weight_L;   //weight coeff. 
    double Yc_h;       //the value of larger Yc in the table Zi;
    double Yc_l;       //the value of smaller Yc ind the table Zi;
	double Yc_;        //Yc convected from lookupTable.H, Yc_=YcCells[celli];
	double Zi_;         //read Z from each table and save in the Z_;

    std::vector<double> T_;
    std::vector<double> OmegaYc_;
    std::vector<std::vector<double>> Y_;
    std::vector<double> Yc_Index;//from table Zi;
    double tableZ;//vector contains Zi

    size_t nColumn;
	size_t columnNum;
    std::string firstLine_;
};

#endif