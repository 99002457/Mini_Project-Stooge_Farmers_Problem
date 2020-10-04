#include "Farmer.h"
#ifndef FARMER_2_H_INCLUDED
#define FARMER_2_H_INCLUDED
class Farmer_2:public Farmer {
    string Farmer_name;
    int No_of_plants;
  public:
    Farmer_2();
    Farmer_2(int,const string&,double,double,const string&,int);
    void UpdateCoverCropCost() override;
    void UpdateCoverCropCost(int );
    void UpdateIncome() override;
    void UpdateSavings() override;
    void Display() override;
    int Dowork()override;
    int BuyPlants(int);
};



#endif // FARMER_2_H_INCLUDED
