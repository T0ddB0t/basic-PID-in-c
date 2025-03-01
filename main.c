#include "pid.h"

int main(){
    struct PID pid = {.Kp = 1.0, .Ki = 0.1, .Kd = 0.05, .integ = 0.015, .pre_er = 0.1};
    int limit, pv, sp;
    
    printf("Enter limit for PID calculations: ");
    scanf("%d", &limit);
    
    printf("Enter process value: ");
    scanf("%d", &pv);

    printf("Enter setpoint value: ");
    scanf("%d", &sp);

    for(int i = 0; i < limit; i++){
        float output = calculatePID(&pid, pv, sp);
        printf("PID output: %f\n", output);

        pv += output * 0.1;

        if(fabs(sp - pv) < 0.01){
            printf("PID coverage to setpoint\n");
            break;
        }
        Sleep(100);
    }
    return 0;
}
