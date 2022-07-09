# MKEL1123_Group02_Milestone5
## Image Classification on Freshness of Fruits and Vegetables
> This README file documented the [equipment used](#hardware) and the detail procedure including [configuring Edge Impulse interface](#image-classification-using-edge-impulse), [exporting CMSIS pack to STM32CubeIDE](#deployment-of-cmsis-pack-from-edge-impulse-to-stm32cubeide) and [LED configuration](#led-and-button-pre-work) before integrating with the other subsystem. Though we could not properly implement the integration of the subsystem due to distance-learning and time-constraint, the [proposed code integration]() is still documented to be further tested. The [demo video](#quick-links) and [useful references](#reference) can also be found at the end of this page. 

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

## LED and Button Pre-Work
The Morpho Headers are chosen to be the STM32 pinout selection according to [2]. 

LED pins as output and switch pin as INPUT. The switches act as a temporarily replacement to react according to the given inputs, which in reality **Push Button 1=Fresh** and **Push Button2=Stale/Rotten**.

| Hardware      | Pinout              | 
| ------------- | -------------       |
| RED LED       | PA5 - GPIO_OUTPUT   |
| GREEN LED     | PA6 - GPIO_OUTPUT   |
| PUSH BUTTON 1 | GPIO_OUTPUT         |
| PUSH BUTTON 2 | Content Cell        |

If you wish to have a different pinout configurations, change Line to Line for [LED main.c]() 

## Quick Links 
* [YouTube Demo Video Submitted](https://youtu.be/jqhI_9lisJs)
* [YouTube Demo Video Updated]()

## Reference ##  
[1] [Image Classification Using Edge Impulse](https://docs.edgeimpulse.com/docs/tutorials/image-classification)  
[2] [STM32F410RB Pinout](https://os.mbed.com/platforms/ST-Nucleo-F410RB/)
 


