#ifndef _MAIN_H
#define _MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////

#include <zephyr/drivers/gpio.h>
#include <zephyr/device.h>


#define LED0_NODE DT_ALIAS(led0)


//////////////////////////////////////////////////
#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
