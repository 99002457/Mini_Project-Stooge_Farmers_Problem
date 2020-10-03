#include "Farmer_1.h"
 Farmer_1::Farmer_1(int id,string w,double in,double sav,double ccc,string name,bool sh):Farmer(id,w,in,sav,ccc),Farmer_name(name),hasShovel(sh){}
 Farmer_1::Farmer_1():Farmer(0,"",0.0,0.0,0.0),Farmer_name(""),hasShovel(false){}
//assuming 15 Rs is paid to the Farmer1
void Farmer_1::UpdateCoverCropCost()
{
double cost;
cost=getCoverCropCost();
cost+=15;
setCoverCropCost(cost);
}
//assuming Farmer_1 get 15 RS per task
void Farmer_1::UpdateIncome()
{
double Income;
Income=getIncome();
Income+=15;
setIncome(Income);
}
//assuming out 50% is expenditure out of 100%
void Farmer_1::UpdateSavings()
{
double Savings,Income;
Income=getIncome();
Savings=Income*(50/100.0);
setSavings(Savings);
}
//Farmer Id, Famer Name, Work
void Farmer_1::Display()
{

  cout<<Farmer::getFarmer_Id()<<","<<Farmer_name<<","<<Farmer::getFarmer_work()<<endl;
}



//Digging holes

int Farmer_1::Dowork()
{
if(Farmer_1::hasShovel)
{
int holes;
holes=getholesEmpty();
holes++;
setholesEmpty(holes);
}
return 0;

}

//shovel roll out
bool Farmer_1::passShovel()
{
 if(hasShovel)
 {
 hasShovel=false;
 Shovel=1;
 return true;
 }
}
