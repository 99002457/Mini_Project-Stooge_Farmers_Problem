#include "../inc/Farmer_2.h"
#include<iostream>

Farmer_2::Farmer_2(int id,const string& w,double in,double sav,const string &name,int sh):Farmer(id,w,in,sav),Farmer_name(name),No_of_plants(sh) {}
Farmer_2::Farmer_2():Farmer(0,"",0.0,0.0),Farmer_name(""),No_of_plants(0) {}
using namespace std;
//assuming 20 Rs is paid to the Farmer2
void Farmer_2::UpdateCoverCropCost() {
    double cost;
    cost=getCoverCropCost();
    cost+=20;
    setCoverCropCost(cost);
}

//assuming Farmer_2 get 20 RS per task
void Farmer_2::UpdateIncome() {
    double Income;
    Income=getIncome();
    Income+=20;
    setIncome(Income);
}
//assuming out 45% is expenditure out of 100%
void Farmer_2::UpdateSavings() {
    double Savings,Income;
    Income=getIncome();
    Savings=Income*(45/100.0);
    setSavings(Savings);
}
//Farmer Id, Famer Name, Work
void Farmer_2::Display() {
    cout<<"Id: "<<Farmer::getFarmer_Id()<<", Name: "<<Farmer_name<<", Work: "<<Farmer::getFarmer_work()<<endl;
    cout<<"Income: "<<Farmer::getIncome()<<", Savings: "<<Farmer::getSavings()<<endl;


}

//Planting seed

int  Farmer_2::Dowork() {
    sem_wait(&F2_work);
    if(getholesEmpty()>0 && getholesEmpty()!=getholesPlanted()) {
//cout<<f1<<f2<<f3;
//pthread_mutex_lock(&mutex);

        int before=getholesEmpty();
        if(No_of_plants==0)
            BuyPlants(10);
        No_of_plants--;
        int num=getholesPlanted();
        num+=1;
        setholesPlanted(num);
        cout<<"Planting: Empty holes before: "<<before<<", Holes Empty After: "<<getholesEmpty()<<", Holes Planted : "<<getholesPlanted()<<endl;
//pthread_mutex_unlock(&mutex);
    }
    sem_post(&F3_work);
}

//shovel roll out
int Farmer_2::BuyPlants(int plants) {
    No_of_plants+=plants;
    int cost=No_of_plants*100;
    UpdateCoverCropCost(cost);
}

//update crop cost after planting

void Farmer_2::UpdateCoverCropCost(int cost) {
    double cost1;
    cost1=getCoverCropCost();
    cost1+=cost;
    setCoverCropCost(cost1);
}
