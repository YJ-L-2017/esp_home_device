/*
 * @Author: yj.liu yj.liu@szryty.cn
 * @Date: 2023-07-16 13:01:58
 * @LastEditors: yj.liu yj.liu@szryty.cn
 * @LastEditTime: 2023-07-16 15:11:28
 * @FilePath: \esp_home_device\main\main.c
 * @Description: 
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

#include "wifi_util.h"
#include "led.h"

void app_main()
{
    printf("Hello world!\n");
    hello();
    /* Print chip information */
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    printf("This is ESP8266 chip with %d CPU cores, WiFi, ",
           chip_info.cores);

    printf("silicon revision %d, ", chip_info.revision);

    printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
           (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    led_init();
    while (1)
    {
        /* code */
    }
    
}
