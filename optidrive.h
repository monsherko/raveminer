#ifndef __OPTIDRIVE_H__
#define __OPTIDRIVE_H__

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
