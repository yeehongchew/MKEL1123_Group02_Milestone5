/*
 * 0V7670_control.h
 *
 *  Created on: Jun 18, 2022
 *      Author: elisi
 */

#include "stm32f4xx.h"
#include "stm32f4xx_hal_rcc.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_i2c.h"
#include "stm32f4xx_hal_dma.h"
#include <stdbool.h>

// SCCB write address
#define SCCB_REG_ADDR 			0x01

// OV7670 camera settings
#define OV7670_REG_NUM 			121
#define OV7670_WRITE_ADDR 	0x42

// Image settings
#define IMG_ROWS   					144
#define IMG_COLUMNS   			174

// Image buffer
extern volatile uint16_t frame_buffer[IMG_ROWS*IMG_COLUMNS];

/*
* Initialize MCO1 (XCLK)
*/
extern void MCO1_init(void);

/*
* Initialize SCCB
*/
extern void SCCB_init(void);

/*
* Initialize OV7670 camera
*/
extern bool OV7670_init(void);

/*
* Initialize DCMI bus, DMA transfer
*/
extern void DCMI_DMA_init(void);
