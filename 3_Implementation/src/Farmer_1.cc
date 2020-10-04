#include "../inc/Farmer_1.h"

Farmer_1::Farmer_1(int id,const string& w,double in,double sav,const string& name,bool sh):Farmer(id,w,in,sav),Farmer_name(name),hasShovel(sh) {}
Farmer_1::Farmer_1():Farmer(0,"",0.0,0.0),Farmer_name(""),hasShovel(false) {}
//assuming 15 Rs is paid to the Farmer1
void Farmer_1::UpdateCoverCropCost() {
    double cost;
    cost=getCoverCropCost();
    cost+=15;
    setCoverCropCost(cost);
//CoverCropCost+=15;
}
//assuming Farmer_1 get 15 RS per task
void Farmer_1::UpdateIncome() {
    double Income;
    Income=getIncome();
    Income+=15;
    setIncome(Income);
}
//assuming out 50% is expenditure out of 100%
void Farmer_1::UpdateSavings() {
    double Savings,Income;
    Income=getIncome();
    Savings=Income*(50/100.0);
    setSavings(Savings);
}
//Farmer Id, Famer Name, Work
void Farmer_1::Display() {

    cout<<"Id: "<<Farmer::getFarmer_Id()<<", Name: "<<Farmer_name<<", Work: "<<Farmer::getFarmer_work()<<endl;
    cout<<"Income: "<<Farmer::getIncome()<<", Savings: "<<Farmer::getSavings()<<endl;


}



//Digging holes

int Farmer_1::Dowork() {

    sem_wait(&F1_shovel);
//pthread_mutex_lock(&mutex);
//cout<<f1<<f2<<f3;
//cout<<f1<<f2<<f3;

    int before=getholesEmpty();
    int holes;
    holes=getholesEmpty();
    holes++;
    setholesEmpty(holes);
    cout<<"Digging: Empty holes before: "<<before<<", Holes Empty After: "<<getholesEmpty()<<", Holes Planted : "<<getholesPlanted()<<endl;
    passShovel();
    sem_post(&F2_work);
//pthread_mutex_unlock(&mutex);


}

//shovel roll out
bool Farmer_1::passShovel() {
    hasShovel=false;
    sem_post(&F3_shovel);
}
