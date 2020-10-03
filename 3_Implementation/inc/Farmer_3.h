#ifndef FARMER_3_H_INCLUDED
#define FARMER_3_H_INCLUDED
#include "Farmer.h"
class Farmer_3:public Farmer
{
    string Farmer_name;
    bool hasShovel;
public:
    Farmer_3();
    Farmer_3(int,string,double,double,double,string,bool);
    void UpdateCoverCropCost();
    void UpdateIncome();
    void UpdateSavings();
    void Display();
    int Dowork();
    bool passShovel();
};
#endif // FARMER_3_H_INCLUDED
