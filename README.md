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
Hence, a few features are highlighted to take note of while implementing image classification on Edge Impulse. This training model on Edge Impulse can be found [here](https://studio.edgeimpulse.com/public/113810/latest) if you are interested in mirroring this project. 

### Data Acquisition  
The fresh and stale fruits / vegetables are obtained from [Kaggle](https://www.kaggle.com/datasets/raghavrpotdar/fresh-and-stale-images-of-fruits-and-vegetables) and uploaded to Edge Impulse. Be mindful on the size of the images uploaded that is able to fit to the RAM of your board. Alternatively, you may use an external SD card to sustain a more accurate dataset.   

![image](https://user-images.githubusercontent.com/64217618/178151313-aeea6674-8443-4e7a-a6f7-20cd69916569.png)

### Transfer Learning Model Configuration
1. Since we are only using minimum amount of dataset, transfer learning is highly recommended to compute a model with higher accuracy. Nonetheless, this might induce a higher FLASH/RAM memory due to larger amount of trainsets needed to achieve a certain accuracy. Alternatively, you may select *Classification* under *Learning Block*.  
![image](https://user-images.githubusercontent.com/64217618/178151565-3d905129-14ad-4284-a72b-9c85eefcd843.png)   

2. When you click on the *Generate Features* tab, if the dataset is well clustered, it will be easier for the machine learning model to train trainsets with similar features.  

![image](https://user-images.githubusercontent.com/64217618/178151691-24d8f417-9cf2-426a-be05-51d09872a440.png)    

3. For a good default value in configuring the transfer learning model, refer the diagram below. If the accuracy does not achieved as expected, increase the number of training cycles (This will not increase memory usage). Another tip to optimize the memory usage is to setup for a smaller transfer learning model. This can be done in  Neural Network Architecture --> *Choose a different model*  --> MobileNetV1 96x96 0.2 .  

![image](https://user-images.githubusercontent.com/64217618/178152155-773c1a54-3da9-410c-bc89-b28739d28221.png)  

4. Despite having an average accuracy, the training model still manage to determine whether the fruits are fresh or spoiled without classifying the type of fruit/vegetables. Hence, we can say that this model achieved the accuracy we wanted.  

![image](https://user-images.githubusercontent.com/64217618/178152307-31402dc7-88d9-4d66-97d2-c02c3ddf6cdd.png)


### Deployment Of CMSIS Pack From Edge Impulse To STM32CubeIDE
1. Before exporting the CMSIS-pack library to CubeIDE,  the FLASH and RAM usage is required to maintain within the capability of the Nucleo Board to prevent 'FLASH' overflowed issue and unable to load the code into the board.  

![image](https://user-images.githubusercontent.com/64217618/178152395-5ec39edd-4e9a-4d4a-bf62-2e7d5c3440cc.png)  

2. The deployment of Cube.MX CMSIS-PACK as library to CubeIDE is documented in https://docs.edgeimpulse.com/docs/deployment/using-cubeai   

3. After generating the C++ code, you can either copy from the [main.cpp](Edge_Impulse_Code/Core/Src/main.cpp) if you are reflecting this project from this exact [Edge Impulse project](https://studio.edgeimpulse.com/public/113810/latest) or do as follows referring the [main.cpp](Edge_Impulse_Code/Core/Src/main.cpp):  

      i.   Line 24-25: Copy to use the exact header file  
      ii.  Line 27 - 67: Replace your raw features (From Edge Impulse --> Live Classification --> Classification result --> Copy Raw feature 
![image](https://user-images.githubusercontent.com/64217618/178153237-42cccdc2-8b32-4efb-981a-45b564df44fd.png)  

      iii. Line 104 - 113: Copy to configure PuTTy  
      iv.  Line 164 - 317: Edit to display output of the image classification. Compulsory items to be included can be found in [documentation](https://docs.edgeimpulse.com/docs/deployment/using-cubeai) 

### Output From TeraTerm  

Apart from displaying the output in the external LED, the results are verified by displaying the results in an external terminal called Tera Term. The setting that was changed here was to set Speed to 115200, and the port as COM5.  

![image](https://user-images.githubusercontent.com/64217618/178303692-f23f7017-8370-40de-a87b-e822aecf3eb3.png)



![image](https://user-images.githubusercontent.com/64217618/178303570-ac806115-e515-4f6d-8964-ea43c843fc20.png)




## LED With Switch Button Pre-Work
The Morpho Headers are chosen to be the STM32 pinout selection according to [2]. 

The switches act as a temporarily replacement to react according to the given inputs, which in reality **Push Button 1=Fresh** and **Push Button2=Stale/Rotten** and the output response will be the LED, where **RED=Stale** and **GREEN=Fresh"**. In the proposed subsystem integration, the switch button is removed as the output of the image classification that is also the input of LED, shall be properly implemented. 

| Hardware      | Pinout              |  
| ------------- | -------------       |
| RED LED       | PC0 -  GPIO_OUTPUT  |
| GREEN LED     | PC1 -  GPIO_OUTPUT  |
| PUSH BUTTON 1 | PC13 - GPIO_INPUT   |
| PUSH BUTTON 2 | PC12 - GPIO_INPUT   |  


To change the pinout configurations, before allowing the IDE to generate C/C++ code, change the Pinout view as followed by right-clicking any GPIO pins and select GPIO_OUTPUT for LED and GPIO_INPUT for PUSH BUTTON and change the pull-down (resistor to GND)/pull-up (resistor to VDD) based on your hardware configuration:  

![image](https://user-images.githubusercontent.com/64217618/178117171-0041471c-6940-44c3-824f-bd0d0b0482df.png)  


After saving the Pinout View, [main.h](https://github.com/yeehongchew/MKEL1123_Group02_Milestone5/blob/main/LED/Core/Inc/main.h) where the external components are defined (Line 60 to Line 77), should be updated based on your own configuration automatically. Line 101 to Line 125 on [main.c](https://github.com/yeehongchew/MKEL1123_Group02_Milestone5/blob/main/LED/Core/Src/main.c) is hard-coded accordingly depending on your pull-up/pull-down configuration as well.  

## Camera Configuration Pre-Work  

The [camera](https://github.com/yeehongchew/MKEL1123_Group02_Milestone5/tree/main/Camera) documented in this project explains the challendges faced with configuring the OV7670 camera which was intended to be used to take live images of fresh or stale fruits and vegetables. Due to constraints of the board itself whereby it doesn't have DCMI functionality, the DMA capability of the F411 board is explored in an attempt to read the inputs from the camera.  

The DMA is supposed to work in such a way that it reads in the data and interrupts the process when the data has been completely transferred. However, due to the huge size of image files, it's possible that it takes a longer time to transfer the data, plus due to time constraints for troubleshooting the code, the camera ultimately could not be implemented as part of this project and can instead be left for future works.  

| Hardware  | Pinout    |  
| ----------| --------  |
| D0        |  PC6      |
| D1        |  PC7      |
| D2        |  PC8      |
| D3        |  PC9      |  
| D4        |  PC11     |  
| D5        |  PB6      |  
| D6        |  PB8      |  
| D7        |  PB9      |  
| SDA       |  PC12     |  
| SCL       |  PB10     |  
| VS        |  PB7      |  
| HS        |  PA4      |  
| PCLK      |  PA6      |  
| XCLK      |  PA8      |  



## Quick Links 
* [YouTube Demo Video Submitted]()


## Reference ##  
[1] [Image Classification Using Edge Impulse](https://docs.edgeimpulse.com/docs/tutorials/image-classification)  
[2] [STM32F410RB Pinout](https://os.mbed.com/platforms/ST-Nucleo-F410RB/)  
[3] [LED Configuration](https://www.youtube.com/watch?v=iMsMYHoFKBE)
 


