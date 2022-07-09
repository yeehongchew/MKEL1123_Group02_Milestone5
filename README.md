# MKEL1123_Group02_Milestone5
## Image Classification on Freshness of Fruits and Vegetables
> This README file documented the [equipment used](#hardware) and the detail procedure including [configuring Edge Impulse interface](#image-classification-using-edge-impulse), [exporting CMSIS pack to STM32CubeIDE](#deployment-of-cmsis-pack-from-edge-impulse-to-stm32cubeide) and [LED configuration](#led-and-button-pre-work) before integrating with the other subsystem. Although we could not properly implement the integration of the subsystem due to distance-learning and time-constraint, the [proposed code integration]() is still documented to be further tested. The [demo video](#quick-links) and [useful references](#reference) can also be found at the end of this page. 

## Group Members: 
1. CHEW YEE HONG (MKE211074)
2. ELISIA THO JIA YEE (MKE211108)  


### Hardware 
- STM32F410RB
- Breadboard 
- Female-To-Male Wires 
- Resistors (10kΩ for push button, 220Ω for LED)
- LED (Red AND Green) 
- Push Button

### Software
- [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)
- [Edge Impulse](https://www.edgeimpulse.com/) 



## Image Classification Using Edge Impulse 
A complete tutorial on how to classify images in Edge Impulse is well-documented by the vendor in https://docs.edgeimpulse.com/docs/tutorials/image-classification  

Thus, only the essential methodology to be mindful of is highlighted: 


### Deployment Of CMSIS Pack From Edge Impulse To STM32CubeIDE
Before exporting the CMSIS-pack to CubeIDE,  the FLASH and RAM usage is required to maintain within the capability of the Nucleo Board to prevent 'FLASH' overflowed issue and unable to load the code into the board.  

![image](https://user-images.githubusercontent.com/64217618/178114672-4fd0b92f-d0ef-452e-aa6e-b02eb244e91d.png)  


## LED With Switch Button Pre-Work
The Morpho Headers are chosen to be the STM32 pinout selection according to [2]. 

LED pins as output and switch pin as INPUT. The switches act as a temporarily replacement to react according to the given inputs, which in reality **Push Button 1=Fresh** and **Push Button2=Stale/Rotten**. In the proposed subsystem integration, the switch button is removed as the output of the image classification that is also the input of LED, shall be properly implemented. 

| Hardware      | Pinout              |  
| ------------- | -------------       |
| RED LED       | PC0 -  GPIO_OUTPUT  |
| GREEN LED     | PC1 -  GPIO_OUTPUT  |
| PUSH BUTTON 1 | PC13 - GPIO_INPUT   |
| PUSH BUTTON 2 | PC12 - GPIO_INPUT   |  


To change the pinout configurations, before allowing the IDE to generate C/C++ code, change the Pinout view as followed by right-clicking any GPIO pins and select GPIO_OUTPUT for LED and GPIO_INPUT for PUSH BUTTON and change the pull-down (resistor to GND)/pull-up (resistor to VDD) based on your hardware configuration:  

![image](https://user-images.githubusercontent.com/64217618/178117171-0041471c-6940-44c3-824f-bd0d0b0482df.png)  


After saving the Pinout View, [main.h]() where the external components are defined, should be updated based on your own configuration. Line 101 to Line 125 on [main.c]() is hard-coded accordingly depending on your pull-up/pull-down configuration as well. 

## Quick Links 
* [YouTube Demo Video Submitted](https://youtu.be/jqhI_9lisJs)


## Reference ##  
[1] [Image Classification Using Edge Impulse](https://docs.edgeimpulse.com/docs/tutorials/image-classification)  
[2] [STM32F410RB Pinout](https://os.mbed.com/platforms/ST-Nucleo-F410RB/)  
[3] [LED Configuration](https://www.youtube.com/watch?v=iMsMYHoFKBE)
 


