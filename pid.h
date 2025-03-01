#ifndef PID_H
#define PID_H

#include <math.h>
#include <Windows.h>
#include <stdio.h>


struct PID{
  float Kp,Ki,Kd;  
  float der, er;
  float integ, pre_er;
};

//Pretty simple PID calculations 

float calculatePID(struct PID *pid, int pv, int sp){
    pid->er = sp - pv;

    pid->integ += pid->er;
    if(fabs(pid->er) < 0.02){
        pid->integ = 0.0;
    }

    pid->der = pid->er - pid->pre_er;

    float Pout = pid->Kp * pid->er;
    float Iout = pid->Ki * pid->integ;
    float Dout = pid->Kd * pid->der;
    float uT = Pout + Iout + Dout;

    pid->pre_er = pid->er;

    return uT;
}


#endif