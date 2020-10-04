#include "Farmer.h"
#ifndef FARMER_3_H_INCLUDED
#define FARMER_3_H_INCLUDED
class Farmer_3:public Farmer {
    string Farmer_name;
    bool hasShovel;
  public:
    Farmer_3();
    Farmer_3(int,const string&,double,double,const string&,bool);
    void UpdateCoverCropCost() override;
    void UpdateIncome() override;
    void UpdateSavings()override;
    void Display()override;
    int Dowork()override;
    bool passShovel();
};
#endif // FARMER_3_H_INCLUDED
