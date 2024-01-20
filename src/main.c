#include "stdio.h"
#include "nvs_flash.h"
#include "network.h"
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_netif.h>
#include <esp_event.h>

void app_main()
{
    printf("I've got the power!\n");
    esp_err_t err = nvs_flash_init();
    if (err != ESP_OK)
    {
        printf("Error (%s) initializing nvs system!\n", esp_err_to_name(err));
    }
    ESP_ERROR_CHECK(esp_netif_init());

    ESP_ERROR_CHECK(esp_event_loop_create_default());
    start_network();
}