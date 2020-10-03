#include "Farmer_1.h"
#include "Farmer_2.h"
#include "Farmer_3.h"
#include<iostream>
using namespace std;
int main()
{
    Farmer *ftp;
   Farmer_1 Larry(101,"Dig",0,0,0,"Larry",true);
   ftp=&Larry;
   (ftp)->Display();
   Farmer_2 Moe(102,"plant",0,0,0,"Moe",0);
    Farmer_3 Curley(103,"fill",0,0,0,"Curley",false);
   cout<<"No of holes Empty"<<ftp->getholesEmpty()<<endl;
   int a=ftp->Dowork();
   cout<<"No of holes Empty"<<ftp->getholesEmpty()<<endl;
   ftp=&Moe;
   (ftp)->Display();
   cout<<"No of holes planted"<<ftp->getholesPlanted()<<endl;
    a=ftp->Dowork();
   cout<<"No of holes planted"<<ftp->getholesPlanted()<<endl;
   ftp=&Curley;
   (ftp)->Display();
   cout<<"No of holes Empty"<<ftp->getholesEmpty()<<endl;
    a=ftp->Dowork();
   cout<<"No of holes Empty"<<ftp->getholesEmpty()<<endl;

}
