#ifndef FARMER_H_INCLUDED
#define FARMER_H_INCLUDED
#include <iostream>
static int holesEmpty;
static int holesPlanted;
static int Shovel;
using namespace std;

class Farmer
{
    int Farmer_Id;
    string Farmer_work;
    double income;
    double savings;
    double CoverCropCost;

public:
    Farmer();
    Farmer(int,string,double,double,double);
    //Farmer(Farmer&);
    virtual void UpdateCoverCropCost()=0;
    virtual void UpdateIncome()=0;
    virtual void UpdateSavings()=0;
    virtual void Display()=0;
    void setCoverCropCost(double);
    void setIncome(double);
    void setSavings(double);
    void setholesEmpty(int);
    void setholesPlanted(int);
    double getCoverCropCost();
    double getIncome();
    double getSavings();
    int getholesEmpty();
    int getholesPlanted();
    int getFarmer_Id();
    string getFarmer_work();
    virtual int Dowork()=0;
};


#endif // FARMER_H_INCLUDED
