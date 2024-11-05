/**
  ******************************************************************************
  * @file    Lab-Libraries/gpio.c
  * @author  CSF Team
  * @mail    formation@csf.tn
  * @Tel     (+216)92.039.433
  * @version V1.0.0
  * @date    28-04-2024
  *****************************************************************************
/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

// Ajouter define pour RCC clock 
volatile unsigned short int *RCC_AHB1ENR =(unsigned short int *) (0x40023800+0x30);
// Ajouter define pour RCC  reste 
volatile unsigned short int *RCC_AHB1RSTR =(unsigned short int *) (0x40023800+0x10);

/**
  * @brief  Enable the gpio_x peripheral clock.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @retval None
  */
void GPIO_ClockEnable (unsigned int * gpio_x)
{

  if (gpio_x == GPIO_A)
  {
   *RCC_AHB1ENR |=(1<<0);
  }
  
  // ajouter les autres gpio
  else if (gpio_x == GPIO_B)
  {
  *RCC_AHB1ENR |=(1<<1);
  } 
  else if (gpio_x == GPIO_C)
  {
  *RCC_AHB1ENR |=(1<<2);
  } 
  else if (gpio_x == GPIO_D)
  {
  *RCC_AHB1ENR |=(1<<3);
  } 
  else if (gpio_x == GPIO_E )
  {
  *RCC_AHB1ENR |=(1<<4);
  } 
  else if (gpio_x == GPIO_F )
  {
  *RCC_AHB1ENR |=(1<<5);
  } 
  else if (gpio_x == GPIO_G )
  {
  *RCC_AHB1ENR |=(1<<6);
  } 
  else if (gpio_x == GPIO_H )
  {
  *RCC_AHB1ENR |=(1<<7);
  } 
  else if (gpio_x == GPIO_I )
  {
  *RCC_AHB1ENR |=(1<<8);
  } 
  
}
/**
* @brief Deinitializes the gpio_x peripheral registers to their default reset values.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @retval None
*/
void GPIO_DeInit(unsigned int * gpio_x)
{
  
  if (gpio_x == GPIO_A)
  {
   *RCC_AHB1RSTR |=(1<<0);
   *RCC_AHB1RSTR &=~(1<<0);
  }
  
  else if (gpio_x == GPIO_B)
  {
  *RCC_AHB1RSTR |=(1<<1);
  *RCC_AHB1RSTR &=~(1<<1);
  } 
  else if (gpio_x == GPIO_C)
  {
  *RCC_AHB1RSTR |=(1<<2);
  *RCC_AHB1RSTR &= ~(1<<2);
  } 
  else if (gpio_x == GPIO_D)
  {
  *RCC_AHB1RSTR |= (1<<3);
  *RCC_AHB1RSTR &= ~(1<<3);
  } 

  else if (gpio_x == GPIO_E )
  {
  *RCC_AHB1RSTR |=(1<<4);
  *RCC_AHB1RSTR &=~(1<<4);
  } 
  else if (gpio_x == GPIO_F )
  {
  *RCC_AHB1RSTR |=(1<<5);
  *RCC_AHB1RSTR &=~(1<<5);
  } 
  else if (gpio_x == GPIO_G )
  {
  *RCC_AHB1RSTR |=(1<<6);
  *RCC_AHB1RSTR &=~(1<<6);
  } 
  else if (gpio_x == GPIO_H )
  {
  *RCC_AHB1RSTR |=(1<<7);
  *RCC_AHB1RSTR &=~(1<<7);
  } 
  else if (gpio_x == GPIO_I )
  {
  *RCC_AHB1RSTR |=(1<<8);
  *RCC_AHB1RSTR &=~(1<<8);
  }
 
}
/**
* @brief Configure the gpio_x
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.

* @param Mode: can be INPUT, OUTPUT, AF or AN
* @param typeOutput: can be PP or OD
* @param pin: can be 0...15
* @retval None
*/
void GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, short int pin)
{
  unsigned int mask = (0x3<<(pin*2)); 
  
  /* forcer les 2 bits d configuration du mode à 0*/
  (*(gpio_x + MODER)) &= ~mask ;
  
  /* Appliquer les "1" du mode dans les bits de configuration du pin choisi */
  (*(gpio_x + MODER)) |= Mode<<(pin*2) ;
  
  mask = (0x01<<pin);
  
  if (typeOutput == push_pull)
  {
    (*(gpio_x + OTYPER)) &= ~mask;
  }
  else
  {
    (*(gpio_x + OTYPER)) |= mask;
  }
    
 }
  
  
  
  
/**
* @brief Reads the specified input port pin.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @param GPIO_Pin: specifies the port bit to read.
* This parameter can be GPIO_Pin_x where x can be (0..15).
* @retval The input port pin value.
*/
unsigned char GPIO_ReadInputDataBit(unsigned int * gpio_x, unsigned short int GPIO_Pin)
{
  unsigned char bit_state = 0x00 ;
  
  if((*(gpio_x + IDR) & GPIO_Pin)!= 0x00 ) 
 {
   bit_state = 0x01 ;
   }
 else
 {
  bit_state = 0x00 ;
 }
 return bit_state ;
}






/**
* @brief Reads the specified GPIO input data port.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @retval GPIO input data port value.
*/
unsigned short int GPIO_ReadInputData(unsigned int * gpio_x)
{
 return (*(gpio_x + IDR));
  
}







/**
* @brief Sets or clears the selected data port bit.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @param GPIO_Pin: specifies the port bit to be written.
* This parameter can be one of GPIO_Pin_x where x can be (0..15).
* @param BitVal: specifies the value to be written to the selected bit.
* This parameter can be one of the BitAction enum values:
* @arg Bit_RESET: to clear the port pin
* @arg Bit_SET: to set the port pin
* @retval None
*/
void GPIO_WriteBit(unsigned int * gpio_x, unsigned short int GPIO_Pin, char BitVal)
{
  if (BitVal != 0x00)
  {
    (*(gpio_x + ODR)) |= (GPIO_Pin)  ;
  }
  else
  {
    (*(gpio_x + ODR)) &= ~(GPIO_Pin)  ;
  }
}





/**
* @brief Writes data to the specified GPIO data port.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @param PortVal: specifies the value to be written to the port output data register.
* @retval None
*/
void GPIO_Write(unsigned int * gpio_x, unsigned short int PortVal)
{
  *(gpio_x + ODR) = PortVal ;
  

}










/******************* (C) COPYRIGHT 2024 CSF *****END OF FILE*******************/

