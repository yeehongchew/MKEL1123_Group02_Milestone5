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
Hence, a few features are highlighted to take note of while implementing image classification on Edge Impulse.  

### Data Acquisition  
The fresh and stale fruits / vegetables are obtained from [Kaggle](https://www.kaggle.com/datasets/raghavrpotdar/fresh-and-stale-images-of-fruits-and-vegetables) and uploaded to Edge Impulse. Be mindful on the size of the images uploaded that is able to fit to the RAM of your board. Alternatively, you may use an external SD card to sustain a more accurate dataset.   

![image](https://user-images.githubusercontent.com/64217618/178151313-aeea6674-8443-4e7a-a6f7-20cd69916569.png)

### Transfer Learning Model Configuration
Since we are only using minimum amount of dataset, transfer learning is highly recommended to compute a model with higher accuracy. Nonetheless, this might induce a higher FLASH/RAM memory due to larger amount of trainsets needed to achieve a certain accuracy. Alternatively, you may select *Classification* under *Learning Block*.  
![image](https://user-images.githubusercontent.com/64217618/178151565-3d905129-14ad-4284-a72b-9c85eefcd843.png)   

When you click on the *Generate Features* tab, if the dataset is well clustered, it will be easier for the machine learning model to train trainsets with similar features.  

![image](https://user-images.githubusercontent.com/64217618/178151691-24d8f417-9cf2-426a-be05-51d09872a440.png)    

For a good default value in configuring the transfer learning model, refer the diagram below. If the accuracy does not achieved as expected, increase the number of training cycles (This will not increase memory usage). Another tip to optimize the memory usage is to setup for a smaller transfer learning model. This can be done in  Neural Network Architecture --> *Choose a different model*  --> MobileNetV1 96x96 0.2 .  

![image](https://user-images.githubusercontent.com/64217618/178152155-773c1a54-3da9-410c-bc89-b28739d28221.png)  

### Model Testing and Validation 


### Deployment Of CMSIS Pack From Edge Impulse To STM32CubeIDE
Before exporting the CMSIS-pack to CubeIDE,  the FLASH and RAM usage is required to maintain within the capability of the Nucleo Board to prevent 'FLASH' overflowed issue and unable to load the code into the board.  

![image](https://user-images.githubusercontent.com/64217618/178114672-4fd0b92f-d0ef-452e-aa6e-b02eb244e91d.png)  




## LED With Switch Button Pre-Work
The Morpho Headers are chosen to be the STM32 pinout selection according to [2]. 

The switches act as a temporarily replacement to react according to the given inputs, which in reality **Push Button 1=Fresh** and **Push Button2=Stale/Rotten** and the output response will be the LED, where **RED=Stale** and **GREEN=Fresh". In the proposed subsystem integration, the switch button is removed as the output of the image classification that is also the input of LED, shall be properly implemented. 

| Hardware      | Pinout              |  
| ------------- | -------------       |
| RED LED       | PC0 -  GPIO_OUTPUT  |
| GREEN LED     | PC1 -  GPIO_OUTPUT  |
| PUSH BUTTON 1 | PC13 - GPIO_INPUT   |
| PUSH BUTTON 2 | PC12 - GPIO_INPUT   |  


To change the pinout configurations, before allowing the IDE to generate C/C++ code, change the Pinout view as followed by right-clicking any GPIO pins and select GPIO_OUTPUT for LED and GPIO_INPUT for PUSH BUTTON and change the pull-down (resistor to GND)/pull-up (resistor to VDD) based on your hardware configuration:  

![image](https://user-images.githubusercontent.com/64217618/178117171-0041471c-6940-44c3-824f-bd0d0b0482df.png)  


After saving the Pinout View, [main.h](https://github.com/yeehongchew/MKEL1123_Group02_Milestone5/blob/main/LED/Core/Inc/main.h) where the external components are defined (Line 60 to Line 77), should be updated based on your own configuration automatically. Line 101 to Line 125 on [main.c](https://github.com/yeehongchew/MKEL1123_Group02_Milestone5/blob/main/LED/Core/Src/main.c) is hard-coded accordingly depending on your pull-up/pull-down configuration as well. 

## Quick Links 
* [YouTube Demo Video Submitted](https://youtu.be/jqhI_9lisJs)


## Reference ##  
[1] [Image Classification Using Edge Impulse](https://docs.edgeimpulse.com/docs/tutorials/image-classification)  
[2] [STM32F410RB Pinout](https://os.mbed.com/platforms/ST-Nucleo-F410RB/)  
[3] [LED Configuration](https://www.youtube.com/watch?v=iMsMYHoFKBE)
 


