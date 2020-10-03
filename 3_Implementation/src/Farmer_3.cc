#include "Farmer_3.h"
#include <iostream>
using namespace std;
//assuming 10 Rs is paid to the Farmer3
void Farmer_3::UpdateCoverCropCost()
{
double cost;
cost=getCoverCropCost();
cost+=10;
setCoverCropCost(cost);
}
//assuming Farmer_3 get 10 RS per task
void Farmer_3::UpdateIncome()
{
double Income;
Income=getIncome();
Income+=10;
setIncome(Income);
}
//assuming out 40% is expenditure out of 100%
void Farmer_3::UpdateSavings()
{
double Savings,Income;
Income=getIncome();
Savings=Income*(40/100.0);
setSavings(Savings);
}
//Farmer Id, Famer Name, Work
void Farmer_3::Display()
{
cout<<Farmer::getFarmer_Id()<<","<<Farmer_name<<","<<Farmer::getFarmer_work()<<endl;
}

//Filling holes
int Farmer_3::Dowork()
{
int holes;
holes=getholesEmpty();
holes--;
setholesEmpty(holes);
return 0;
}

//shovel roll out
bool Farmer_3::passShovel()
{
 if(hasShovel)
 {
 hasShovel=false;
 }
 else
 {
 hasShovel=true;
 }
}


Farmer_3::Farmer_3(int id,string w,double in,double sav,double ccc,string name,bool sh):Farmer(id,w,in,sav,ccc),Farmer_name(name),hasShovel(sh){}
Farmer_3::Farmer_3():Farmer(0,"",0.0,0.0,0.0),Farmer_name(""),hasShovel(false){}
