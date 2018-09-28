#ifndef __OPTIDRIVE_H__
#define __OPTIDRIVE_H__

//num_cards != const !!!
#define FAN_GPU_CONTROL_BASHSCRIPT "\
#!/bin/bash   \n\
#export DISPLAY=:0 \n\
        NUM_CARDS=2 \n\
NS=\"/usr/bin/nvidia-settings\" \n\
while true \n\
do \n\
for ((i=0; i<$NUM_CARDS;i++)) \n\
{ \n\
GPU_TEMP=`nvidia-smi -i $i --query-gpu=temperature.gpu  --format=csv,noheader` \n\
FAN_SPEED=`nvidia-smi -i $i --query-gpu=fan.speed  --format=csv,noheader,nounits` \n\
if(($GPU_TEMP > 50)); then \n\
        $NS -a [gpu:$i]/GPUFanControlState=1 -a [fan:$i]/GPUTargetFanSpeed=100 >/dev/null 2>&1 \n\
fi \n\
if(($GPU_TEMP < 50)); then \n\
(($GPU_TEMP!=$FAN_SPEED)) && $NS -a [gpu:$i]/GPUFanControlState=1 -a [fan:$i]/GPUTargetFanSpeed=$GPU_TEMP >/dev/null 2>&1 \n\
fi \n\
} \n\
sleep 5 \n\
done \
"

//use   system(FAN_GPU_CONTROL_BASHSCRIPT)


typedef struct sign_drive {
    //FLAGS
    bool USE_COLOR;
    //..
};

/*
  stucture for option gpu
*/
void get_sys_info();

/*
  function for optimal setting gpu
*/

void init_opt_settings();
/*
  function for fast cooling
*/
void fast_cool(void*);

#endif
