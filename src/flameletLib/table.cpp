#include "table.H"

table::table
(
	std::ifstream& tableFile
):
	tableFile_(tableFile)
{
	read();
}

void table::findYcScope( double Yc_ )
{
    if( (Yc_ > Yc_Index[0]) && (Yc_ < Yc_Index.back()) )
    {
        position_L = lower_bound(Yc_Index.begin(),Yc_Index.end(),Yc_) - Yc_Index.begin() - 1;
        position_H = lower_bound(Yc_Index.begin(),Yc_Index.end(),Yc_) - Yc_Index.begin();

        Yc_h = Yc_Index[position_H];
        Yc_l = Yc_Index[position_L];  

        weight_H = (Yc_ - Yc_l) / (Yc_h - Yc_l); 
        weight_L = (Yc_h - Yc_) / (Yc_h - Yc_l);
    }
    else if(Yc_ <= Yc_Index[0])
    {
		position_L = 0;
		position_H = 0;

        Yc_h = Yc_Index[0];
        Yc_l = Yc_Index[0];

		weight_H = 0.5;
		weight_L = 0.5;
    }
    else
    {
		position_H = sizeYc - 1;
		position_L = sizeYc - 1;

        Yc_h = Yc_Index.back();
        Yc_l = Yc_Index.back();

		weight_H = 0.5;
		weight_L = 0.5;
    }
}

void table::read()
{
    std::string line, str;
    std::getline(tableFile_, firstLine_);
    nColumn = std::count(firstLine_.begin(), firstLine_.end(),',') + 1; //column number of lookup table;
    Y_.resize(nColumn - 4);
    while(std::getline(tableFile_,line))
    {
        size_t n = 0;
        std::istringstream buffer(line);
        while(std::getline(buffer, str, ','))
        {
            if(n == 0)
                T_.push_back(std::stod(str));
            else if(n == 1)
                OmegaYc_.push_back(std::stod(str));
            else if(n == 55)
                Yc_Index.push_back(std::stod(str));
            else if(n == 56)
                Z_Index.push_back(std::stod(str));
            else
                Y_[n-2].push_back(std::stod(str));
            n++;   
        }
		
		sizeYc = Yc_Index.size();
    }
}
