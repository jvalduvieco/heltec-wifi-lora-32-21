//
// Created by jvalduvieco on 10/6/22.
//

#ifndef HELTEC_WIFI_LORA_32_21_WIFI_H
#define HELTEC_WIFI_LORA_32_21_WIFI_H

void start_wifi(void);

void start_provisioning(void);

void wifi_init(void);

esp_err_t is_provisioned(bool *provisioned);

esp_err_t get_wifi_ssid(char *ssid, int max_len);

#endif //HELTEC_WIFI_LORA_32_21_WIFI_H
