#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2s.h"
#include "esp_system.h"
#include "esp_log.h"

static const char *TAG = "AUDIO_TEST";

#define I2S_SAMPLE_RATE 44100 // standard sample rate for voice
#define I2S_SAMPLE_BIT 16    // standard sample bit for voice
#define I2S_CHANNELS 2      // Left and Right

#define I2S_BCK_IO 25
#define I2S_LRCK_IO 22
#define I2S_DATA_IO 26

#define SAMPLES 128

void i2s_init( void ){

    i2s_config_t i2s_config = {
        .mode                 = I2S_MODE_TX,
        .sample_rate          = I2S_SAMPLE_RATE,
        .bits_per_sample      = I2S_SAMPLE_BIT,
        .channel_format       = I2S_CHANNEL_FMT_RIGHT_LEFT,
        .communication_format = I2S_COMM_FORMAT_STAND_I2S,
        .intr_alloc_flags      = 0,
        .dma_buf_count        = 8,
        .dma_buf_len          = 64,
        .use_apll             = false,
        .tx_desc_auto_clear   = true,
        .fixed_mclk           = 0

    };

    i2s_pin_config_t pin_config = {
        .bck_io_num   = I2S_BCK_IO,
        .ws_io_num    = I2S_LRCK_IO,
        .data_out_num = I2S_DATA_IO,
        .data_in_num  = I2S_PIN_NO_CHANGE // any input data
    };


    i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
    i2s_set_pin(I2S_NUM_0, &pin_config);
    i2s_set_clk(I2S_NUM_0, I2S_SAMPLE_RATE, I2S_SAMPLE_BIT, I2S_CHANNELS);
}

void app_main( void ){
    
    i2s_init( );

    int16_t sample_data[SAMPLES * 2];

    for (int i = 0; i < SAMPLES; i++){
        sample_data[i*2] = (int16_t)(i * 100); // left channel
        sample_data[i*2 + 1] = (int16_t)(-i * 100); // right channel
    }

    size_t bytes_written;


    // void loop function
    while (1)
    {
        for (int i = 0; i < SAMPLES; i++){
        ESP_LOGI(TAG, "Sample[%d]: L=%d, R=%d",
                    i, sample_data[i*2], sample_data[i*2 + 1]);
        }
        
        i2s_write(I2S_NUM_0, (const char*)sample_data, sizeof(sample_data), &bytes_written, portMAX_DELAY);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
