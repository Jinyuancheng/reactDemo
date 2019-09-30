/**********************************************************************
* Copyright (C) 2017-2018 天津蔚蓝玄通科技有限公司
* 文件名: gpio.h
* 描述: GPIO模块 关于读取状态时从配置文件读取
**********************************************************************/
#ifndef GPIO_H
#define GPIO_H

/*POE1~6 Ctrl 
MX6UL_PAD_LCD_DATA17__GPIO3_IO22  64+22
MX6UL_PAD_LCD_DATA18__GPIO3_IO23  64+23
MX6UL_PAD_LCD_DATA19__GPIO3_IO24  64+24
MX6UL_PAD_LCD_DATA20__GPIO3_IO25  64+25
MX6UL_PAD_LCD_DATA21__GPIO3_IO26  64+26
MX6UL_PAD_LCD_DATA22__GPIO3_IO27  64+27

MX6UL_PAD_CSI_DATA03__GPIO4_IO24  96+24  //ALARM OUT
MX6UL_PAD_CSI_DATA02__GPIO4_IO23  96+23  //LED lamp
MX6UL_PAD_LCD_DATA08__GPIO3_IO13  64+13  //AC220V
MX6UL_PAD_CSI_DATA04__GPIO4_IO25  96+25  //FAN
MX6UL_PAD_CSI_MCLK__GPIO4_IO17    96+17  //SWITCH
MX6UL_PAD_CSI_VSYNC__GPIO4_IO19   96+19  //SWITCH RESET
MX6UL_PAD_LCD_DATA09__GPIO3_IO14  64+14  //AC24V_3
MX6UL_PAD_LCD_DATA10__GPIO3_IO15  64+15  //AC24V_2
MX6UL_PAD_LCD_DATA12__GPIO3_IO17  64+17  //AC24V_1
MX6UL_PAD_LCD_DATA23__GPIO3_IO28  64+28  //DC12V_1
MX6UL_PAD_LCD_DATA14__GPIO3_IO19  64+19  //DC12V_2
MX6UL_PAD_LCD_DATA15__GPIO3_IO20  64+20  //DC12V_3
MX6UL_PAD_LCD_DATA16__GPIO3_IO21  64+21  //DC48V

MX6UL_PAD_CSI_DATA07__GPIO4_IO28  96+28  //REINIT
MX6UL_PAD_CSI_DATA06__GPIO4_IO27  96+27  //DOOR
MX6UL_PAD_CSI_DATA05__GPIO4_IO26  96+26  //TALKIN

MX6UL_PAD_CSI_DATA00__GPIO4_IO21  96+21  //GSM MOD
MX6UL_PAD_CSI_DATA00__GPIO4_IO22  96+22  //GSM MOD RESET

MX6UL_PAD_SNVS_TAMPER0__GPIO5_IO00 128  //PLAYTYPE 

MX6UL_PAD_CSI_HSYNC__GPIO4_IO20  96+20   //RS4852
MX6UL_PAD_CSI_PIXCLK__GPIO4_IO18 96+18   //RS485 

MX6UL_PAD_GPIO1_IO09__GPIO1_IO09 9 //Reset ADC */


#define GPIO_POE_1     "86"
#define GPIO_POE_2     "87"
#define GPIO_POE_3     "88"
#define GPIO_POE_4     "89"
#define GPIO_POE_5     "90"
#define GPIO_POE_6     "91"
#define GPIO_DC12V_1   "92"
#define GPIO_DC12V_2   "83"
#define GPIO_DC12V_3   "84"
#define GPIO_DC48V     "85"
#define GPIO_AC12V_1   "81"
#define GPIO_AC12V_2   "79"
#define GPIO_AC12V_3   "78"
#define GPIO_AC220V    "77"
#define GPIO_DOOR      "123"
#define GPIO_TALKIN    "122"
#define GPIO_REINIT    "124"
#define GPIO_SWITCH    "113"
#define GPIO_SWITCHRESET "115"
#define GPIO_FAN       "121"
#define GPIO_ALARM_OUT "120"
#define GPIO_LED_LAMP  "119"
#define GPIO_GSM_MOD   "117"
#define GPIO_GSM_MODRESET   "118"
#define GPIO_PLAY_TYPE   "128"
#define GPIO_RS485_1  "116"
#define GPIO_RS485_2  "114"
#define GPIO_RESET_ADC "9"
/************************************************************************/
/*导出GPIO模块 比如"64"   GPIO3_IO00     (3-1)*32+0=64                  */
/************************************************************************/
int exportGPIO(char* pchPin);
/************************************************************************/
/*取消导出GPIO模块 比如"64"   GPIO3_IO00     (3-1)*32+0=64              */
/************************************************************************/
int unexportGPIO(char* pchPin);
/************************************************************************/
/*设置GPIO输出的方向                                                    */
/************************************************************************/
int setGPIODirection(char* pchPin,char* value);
/************************************************************************/
/*设置GPIO输出                                                         */
/************************************************************************/
int setGPIO(char* pchPin,char* value,int record);
/************************************************************************/
/*设置GPIO输出(为报警器、风扇、LED专用)                                  */
/************************************************************************/
int setGPIOEx(char* pchPin,char* value,int record);
/************************************************************************/
/*获得GPIO输出                                                         */
/************************************************************************/
int getGPIO(char* pchPin);
/************************************************************************/
/*获得输入端口GPIO输出                                                         */
/************************************************************************/
int getGPIOIn(char* pchPin);


#endif
