/**
  ******************************************************************************
  * @file    Lab-Libraries/gpio.h 
  * @author  CSF Team
  * @mail    formation@csf.tn
  * @Tel     (+216)92.039.433
  * @version V1.0.0
  * @date    23-04-2024
  *****************************************************************************

/* Includes ------------------------------------------------------------------*/
/* adresse de base des GPIOx x=A..k*/
# define GPIO_A (unsigned int*)(0x40020000)
# define GPIO_B (unsigned int*)(0x40020400)
# define GPIO_C (unsigned int*)(0x40020800)
# define GPIO_D (unsigned int*)(0x40020C00)
# define GPIO_E (unsigned int*)(0x40021000)
# define GPIO_F (unsigned int*)(0x40021400)
# define GPIO_G (unsigned int*)(0x40021800)
# define GPIO_H (unsigned int*)(0x40021C00)
# define GPIO_I (unsigned int*)(0x40022000)
# define GPIO_J (unsigned int*)(0x40022400)
# define GPIO_K (unsigned int*)(0x40022800)


/* offset des registres GPIOx x=A..k */
# define    MODER    0x00
# define    OTYPER   0x04/4
# define    ODR      0x14/4
# define    IDR      0x10/4
# define    OSPEEDR  0x08/4
# define    PUPDR    0x0C/4
# define    BSRR     0x18/4
# define    LCKR     0x1C/4
# define    AFRL     0x20/4
# define    AFRH     0x24/4


/* les différents mode de fonctinement */
# define   MODE_input   0X00
# define   MODE_OUTPUT  0X01
# define   MODE_AF      0X02
# define   MODE_ANALOG  0X03

/* TYPE DE SORTIE */
# define    push_pull   0X00
# define    open_drain  0X01 

/* POSITIONS DES PIN DANS LES REGISTRE DE LECTURE ET ECRITURE */
# define    GPIO_PIN_0 ((unsigned short) 0x0001)
# define    GPIO_PIN_1 ((unsigned short) 0x0002)
# define    GPIO_PIN_2 ((unsigned short) 0x0004)
# define    GPIO_PIN_3 ((unsigned short) 0x0008)
# define    GPIO_PIN_4 ((unsigned short) 0x0010)
# define    GPIO_PIN_5 ((unsigned short) 0x0020)
# define    GPIO_PIN_6 ((unsigned short) 0x0040)
# define    GPIO_PIN_7 ((unsigned short) 0x0080)
# define    GPIO_PIN_8 ((unsigned short) 0x0100)
# define    GPIO_PIN_9 ((unsigned short) 0x0200)
# define    GPIO_PIN_10 ((unsigned short) 0x0400)
# define    GPIO_PIN_11 ((unsigned short) 0x0800)
# define    GPIO_PIN_12 ((unsigned short) 0x1000)
# define    GPIO_PIN_13 ((unsigned short) 0x2000)
# define    GPIO_PIN_14 ((unsigned short) 0x4000)
# define    GPIO_PIN_15 ((unsigned short) 0x8000)

/* NOMBRE DES PIN DANS LES REGISTRE DE LECTURE ET ECRITURE */

# define PIN_0 0
# define PIN_1 1
# define PIN_2 2
# define PIN_3 3
# define PIN_4 4
# define PIN_5 5
# define PIN_6 6
# define PIN_7 7
# define PIN_8 8
# define PIN_9 9
# define PIN_10 10
# define PIN_11 11
# define PIN_12 12
# define PIN_13 13
# define PIN_14 14
# define PIN_15 15


/* -----------------ajouter les protopyes des fonctions----------------------*/


/* GPIO enable function */
void GPIO_ClockEnable (unsigned int * gpio_x);


/* GPIO Resete function */
void GPIO_DeInit(unsigned int * gpio_x);

/* Config function */
void GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, short int pin);

/* Read functions */
unsigned char GPIO_ReadInputDataBit(unsigned int * gpio_x, unsigned short int GPIO_Pin);
unsigned short int GPIO_ReadInputData(unsigned int * gpio_x);

/* Write functions */
void GPIO_WriteBit(unsigned int * gpio_x, unsigned short int GPIO_Pin, char BitVal);
void GPIO_Write(unsigned int * gpio_x, unsigned short int PortVal);

/******************* (C) COPYRIGHT 2019 CSF *****END OF FILE*******************/