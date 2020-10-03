#ifndef FARMER_1_H_INCLUDED
#define FARMER_1_H_INCLUDED
#include "Farmer.h"
class Farmer_1:public Farmer
{
    string Farmer_name;
    bool hasShovel;
public:
    Farmer_1();
    Farmer_1(int,string,double,double,double,string,bool);
    void UpdateCoverCropCost();
    void UpdateIncome();
    void UpdateSavings();
    void Display();
    int Dowork();
    bool passShovel();
};


#endif // FARMER_1_H_INCLUDED
