/* Includes ------------------------------------------------------------------*/
#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include <stdlib.h>

#include "wifi.h"
#include "screen.h"

/* Entry point ----------------------------------------------------------------*/
void setup()
{
  wifiStartUp();

  screenStartUp();
}

/* The main loop -------------------------------------------------------------*/
void loop()
{
  //  struct tm timeinfo;
  //  getCurrentTimeInfo(&timeinfo);

  //  Serial.println(now);

  // 2.Drawing on the image
  printf("Drawing:BlackImage\r\n");
//  Paint_DrawString_CN(0, 0, "微雪电子", &Font24CN, BLACK, WHITE);

  time_t now;
  struct tm timeinfo;

  time(&now);
  // 将时区设置为中国标准时间
  setenv("TZ", "CST-8", 1);
  tzset();

  localtime_r(&now, &timeinfo);

//  Paint_DrawNum(0, 50, timeinfo.tm_year + 1900, &Font16, BLACK, WHITE);
//  Paint_DrawNum(50, 50, timeinfo.tm_mon + 1, &Font16, BLACK, WHITE);
//  Paint_DrawNum(70, 50, timeinfo.tm_mday , &Font16, BLACK, WHITE);
  Paint_DrawNum(100, 50, timeinfo.tm_hour, &Font240, BLACK, WHITE);
//  Paint_DrawNum(150, 50, timeinfo.tm_min, &Font16, BLACK, WHITE);

  printf("EPD_Display\r\n");
  EPD_7IN5_V2_Display(BlackImage);
  DEV_Delay_ms(2000);

  delay(10000);
}
