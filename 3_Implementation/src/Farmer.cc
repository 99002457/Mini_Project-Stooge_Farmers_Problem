#include "../inc/Farmer.h"


void Farmer::setCoverCropCost(double cost) {
    CoverCropCost=cost;
}

void Farmer::setIncome(double nincome) {
    income=nincome;
}

void Farmer::setSavings(double save) {
    savings=save;
}

void Farmer::setholesEmpty(int holes) {
    holesEmpty=holes;
}

void Farmer::setholesPlanted(int hplant) {
    holesPlanted=hplant;
}

double Farmer::getCoverCropCost() {
    return CoverCropCost;
}

double Farmer::getIncome() {
    return income;
}

double Farmer::getSavings() {
    return savings;
}


int Farmer::getholesEmpty() {
    return holesEmpty;
}

int Farmer::getholesPlanted() {
    return holesPlanted;
}

int Farmer::getFarmer_Id() {
    return Farmer_Id;
}

string Farmer::getFarmer_work() {
    return Farmer_work;
}

Farmer::Farmer():Farmer_Id(0),Farmer_work(""),income(0.0),savings(0.0) {}
Farmer::Farmer(int id,const string& work,double in,double sav) : Farmer_Id(id),Farmer_work(work),income(in),savings(sav) {}

//Farmer(Farmer&);
