#ifndef __DSP_ERR_H__
#define __DSP_ERR_H__

#include <stdint.h>
#include <stdlib.h>

typedef int esp_err_t;

#define ESP_OK 0

#define DSP_OK                        0 // For internal use only. Please use ESP_OK instead
#define ESP_ERR_DSP_BASE              0x70000
#define ESP_ERR_DSP_INVALID_LENGTH    (ESP_ERR_DSP_BASE + 1)
#define ESP_ERR_DSP_INVALID_PARAM     (ESP_ERR_DSP_BASE + 2)
#define ESP_ERR_DSP_PARAM_OUTOFRANGE  (ESP_ERR_DSP_BASE + 3)
#define ESP_ERR_DSP_UNINITIALIZED     (ESP_ERR_DSP_BASE + 4)
#define ESP_ERR_DSP_REINITIALIZED     (ESP_ERR_DSP_BASE + 5)
#define ESP_ERR_DSP_ARRAY_NOT_ALIGNED (ESP_ERR_DSP_BASE + 6)

#endif