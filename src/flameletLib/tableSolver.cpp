#include "tableSolver.H"

tableSolver::tableSolver()
{
	
	collectTables();
}

void tableSolver::collectTables()
{
	/*每次读入一个csv文件都记录一次*/
	tableNum = 0;
	while (true)
	{
		std::ifstream flameletTableFile("tableFile/table_" + std::to_string(tableNum) + ".csv");
		if (!flameletTableFile) break;
		tableNum++;
	}
	/*将每一个table所代表的Z存到Z_Index中*/
	for (size_t n = 0; n < (tableNum - 1); n++)
	{
		Z_Index[n] = table_[n].getZ();
	}
}

void tableSolver::find(double Z_, double Yc_)  //Z_=ZCells[celli], Yc_=YcCells[celli];
{
	/*****     find a scope between Z_high and Z_low which includes Z_     *****/
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
		position_L = tableNum() - 1;
		position_H = tableNum() - 1;

        Z_h = Z_Index.back();
        Z_l = Z_Index.back();

		weight_H = 0.5;
		weight_L = 0.5;
    }

	/*****     initiate Yc_ = YcCells[celli],and find position_H & position_L in Yc dirction     *****/
	table_[position_H].findYcScope(Yc_);
	table_[position_L].findYcScope(Yc_);
}
