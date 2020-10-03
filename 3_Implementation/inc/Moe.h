#ifndef MOE_H_INCLUDED
#define MOE_H_INCLUDED
class Moe: public Shovel {
int plant_number;
int F_id;
public:
    int shift_hold();
    void check_stats();
    virtual void display()=0;
};


#endif // SHOVEL_H_INCLUDED
