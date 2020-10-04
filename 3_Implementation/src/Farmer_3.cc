#include "Farmer_3.h"
#include <iostream>

using namespace std;

//assuming 10 Rs is paid to the Farmer3
void Farmer_3::UpdateCoverCropCost() {
    double cost;
    cost=getCoverCropCost();
    cost+=10;
    setCoverCropCost(cost);
}
//assuming Farmer_3 get 10 RS per task
void Farmer_3::UpdateIncome() {
    double Income;
    Income=getIncome();
    Income+=10;
    setIncome(Income);
}
//assuming out 40% is expenditure out of 100%
void Farmer_3::UpdateSavings() {
    double Savings,Income;
    Income=getIncome();
    Savings=Income*(40/100.0);
    setSavings(Savings);
}
//Farmer Id, Famer Name, Work
void Farmer_3::Display() {
    cout<<"Id: "<<Farmer::getFarmer_Id()<<", Name: "<<Farmer_name<<", Work: "<<Farmer::getFarmer_work()<<endl;
    cout<<"Income: "<<Farmer::getIncome()<<", Savings: "<<Farmer::getSavings()<<endl;


}

//Filling holes
int Farmer_3::Dowork() {
    sem_wait(&F3_shovel);
    sem_wait(&F3_work);
    if(getholesPlanted()>0) {
//cout<<f1<<f2<<f3;
//pthread_mutex_lock(&mutex);
        int before=getholesEmpty();
        int holes;
        holes=getholesEmpty();
        holes--;
        setholesEmpty(holes);
        holes=getholesPlanted();
        holes--;
        setholesPlanted(holes);
       cout<<"Filling: Empty holes before: "<<before<<", Holes Empty After: "<<getholesEmpty()<<", Holes Planted : "<<getholesPlanted()<<endl<<endl;
//cout<<f1<<f2<<f3;


//sem_post(&F1_shovel);

//pthread_mutex_unlock(&mutex);

//sem_post(&F1_work);
    }
    passShovel();
}

//shovel roll out
bool Farmer_3::passShovel() {
    hasShovel=false;
    sem_post(&F1_shovel);
    return true;
}


Farmer_3::Farmer_3(int id,const string &w,double in,double sav,const string &name,bool sh):Farmer(id,w,in,sav),Farmer_name(name),hasShovel(sh) {}
Farmer_3::Farmer_3():Farmer(0,"",0.0,0.0),Farmer_name(""),hasShovel(false) {}
