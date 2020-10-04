#include "Farmer.h"
#ifndef FARMER_1_H_INCLUDED
#define FARMER_1_H_INCLUDED
class Farmer_1:public Farmer {
    string Farmer_name;
    bool hasShovel;
  public:
    Farmer_1();
    Farmer_1(int,const string&,double,double,const string&,bool);
    void UpdateCoverCropCost() override;
    void UpdateIncome() override;
    void UpdateSavings() override;
    void Display() override;
    int Dowork() override;
    bool passShovel();
};


#endif // FARMER_1_H_INCLUDED
