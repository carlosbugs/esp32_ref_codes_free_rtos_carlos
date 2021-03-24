//7.	We are ready to test if the spiffs partition will be created by running a simple application as follows.


#include <stdio.h>
#include <sys/stat.h>
#include "esp_spiffs.h"
#include "esp_err.h"

void app_main(void)
{
    printf("Initializing SPIFFS\n");

esp_vfs_spiffs_conf_t conf = {
        .base_path = "/spiffs",
        .partition_label = NULL,
        .max_files = 5,
        .format_if_mount_failed = true};
//In app_main, we first create a configuration variable to register the spiffs partition. 
    esp_err_t ret = esp_vfs_spiffs_register(&conf);
    if (ret != ESP_OK)
    {
        printf("Failed to initialize SPIFFS (%s)\n", esp_err_to_name(ret));
        return;
    }
//Then we call esp_vfs_spiffs_register with that variable. When the code first runs, the register function will format the spiffs partition.
    size_t total = 0, used = 0;
    ret = esp_spiffs_info(conf.partition_label, &total, &used);
    if (ret == ESP_OK)
    {
        printf("Partition size: total: %d, used: %d\n", total, used);
    }
    else
    {
        printf("Failed to get SPIFFS partition information (%s)\n", esp_err_to_name(ret));
    }
}
//esp_spiffs_info will read the partition information and if everything goes well, we see the partition size printed on the serial monitor.