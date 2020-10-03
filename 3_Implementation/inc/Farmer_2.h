#ifndef FARMER_2_H_INCLUDED
#define FARMER_2_H_INCLUDED
#include "Farmer.h"
class Farmer_2:public Farmer
{
    string Farmer_name;
    int No_of_plants;
public:
    Farmer_2();
    Farmer_2(int,string,double,double,double,string,int);
    void UpdateCoverCropCost();
    void UpdateCoverCropCost(int );
    void UpdateIncome();
    void UpdateSavings();
    void Display();
    int Dowork();
    int BuyPlants(int);
};



#endif // FARMER_2_H_INCLUDED
