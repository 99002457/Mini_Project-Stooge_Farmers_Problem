#include "../inc/Farmer_1.h"
#include "../inc/Farmer_2.h"
#include "../inc/Farmer_3.h"
#include<iostream>

sem_t F1_shovel;
sem_t F3_shovel;
sem_t F1_work;
sem_t F2_work;
sem_t F3_work;
pthread_mutex_t mutex;
using namespace std;

Farmer_1 Larry(101,"Dig",0,0,"Larry",true);
Farmer_2 Moe(102,"plant",0,0,"Moe",0);
Farmer_3 Curley(103,"fill",0,0,"Curley",false);
Farmer *ftp1=&Larry;
Farmer *ftp2=&Moe;
Farmer *ftp3=&Curley;
void* ld(void *pp) {

    ftp1->Dowork();
    ftp1->UpdateIncome();
    ftp1->UpdateSavings();
    ftp1->UpdateCoverCropCost();

}
void* md(void *pp) {

    ftp2->Dowork();
    ftp2->UpdateIncome();
    ftp2->UpdateSavings();
    ftp2->UpdateCoverCropCost();
}
void* cd(void *pp) {

    ftp3->Dowork();
    ftp3->UpdateIncome();
    ftp3->UpdateSavings();
    ftp3->UpdateCoverCropCost();
}
int main() {

    //pthread_attr_setschedpolicy(&tattr, SCHED_OTHER);
    //pthread_attr_setdetachstate(&tattr,PTHREAD_CREATE_DETACHED);


    pthread_mutex_init(&mutex,NULL);
    sem_init(&F1_shovel,0,1);
    sem_init(&F3_shovel,0,0);
    sem_init(&F1_work,0,MAX);
    sem_init(&F2_work,0,0);
    sem_init(&F3_work,0,0);

    pthread_t dig[MAX],seed[MAX],fillh[MAX];

    int i=0;
    while(i!=MAX) {

        ftp1=&Larry;
        pthread_create(&dig[i],NULL,ld,NULL);

        ftp2=&Moe;
        pthread_create(&seed[i],NULL,md, (void*)ftp1);

        ftp3=&Curley;
        pthread_create(&fillh[i],NULL,cd, nullptr);
        i++;

    }
    i=0;
    while (i!=MAX) {
        pthread_join(dig[i], NULL);
        pthread_join(seed[i], NULL);
        pthread_join(fillh[i], NULL);

        i++;
    }
    ftp1->Display();
    ftp2->Display();
    ftp3->Display();
    cout<<"CropCoverCost "<<ftp1->getCoverCropCost()<<" for planting "<<MAX<<" Plants"<<endl<<endl;
    //pthread_mutex_destroy(&mutex);
    sem_destroy(&F1_work);
    sem_destroy(&F1_shovel);
    sem_destroy(&F3_shovel);
    sem_destroy(&F2_work);
    sem_destroy(&F3_work);
    /*cout<<"No of holes Empty"<<ftp->getholesEmpty()<<endl;
    int a=ftp->Dowork();
    ftp->UpdateCoverCropCost();
    ftp->UpdateIncome();
    ftp->UpdateSavings();
    cout<<ftp->getIncome()<<","<<ftp->getSavings()<<","<<ftp->getCoverCropCost()<<endl;
    cout<<"No of holes Empty"<<ftp->getholesEmpty()<<endl;
    (ftp)->Display();
    ftp=&Moe;
    (ftp)->Display();
    cout<<"No of holes planted"<<ftp->getholesPlanted()<<endl;
     a=ftp->Dowork();
    ftp->UpdateCoverCropCost();
    ftp->UpdateIncome();
    ftp->UpdateSavings();
    cout<<ftp->getIncome()<<","<<ftp->getSavings()<<","<<ftp->getCoverCropCost()<<endl;
    cout<<"No of holes planted"<<ftp->getholesPlanted()<<endl;
    ftp=&Curley;
    (ftp)->Display();
    cout<<"No of holes Empty"<<ftp->getholesEmpty()<<endl;
     a=ftp->Dowork();
    ftp->UpdateCoverCropCost();
    ftp->UpdateIncome();
    ftp->UpdateSavings();
    cout<<ftp->getIncome()<<","<<ftp->getSavings()<<","<<ftp->getCoverCropCost()<<endl;
    cout<<"No of holes Empty"<<ftp->getholesEmpty()<<endl;
    */
    return 0;
}
