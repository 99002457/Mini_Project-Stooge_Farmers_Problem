#ifndef SHOVEL_H_INCLUDED
#define SHOVEL_H_INCLUDED

class shovel{
int S_Id;
int F_shovel_hold;
int empty_holes;
public:
    int shift_hold();
    virtual void display()=0;
    virtual void check_status()=0;
};


#endif // SHOVEL_H_INCLUDED
