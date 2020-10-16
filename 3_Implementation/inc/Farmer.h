#include <iostream>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#ifndef FARMER_H_INCLUDED
#define FARMER_H_INCLUDED
#define MAX 8
static int holesEmpty;
static int holesPlanted;
static double CoverCropCost;
using namespace std;
extern sem_t F1_shovel;
extern sem_t F3_shovel;
extern sem_t F1_work;
extern sem_t F2_work;
extern sem_t F3_work;
extern pthread_mutex_t mutex;
class Farmer {
    int Farmer_Id;
    string Farmer_work;
    double income;
    double savings;
  public:
    Farmer();
    Farmer(int,const string&,double,double);
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
    int getFarmer_Id();//first fix
    int getholesEmpty();
    int getholesPlanted();
    string getFarmer_work();
    virtual int Dowork()=0;
};


#endif // FARMER_H_INCLUDED
