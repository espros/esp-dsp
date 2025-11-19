# Copyright (c) 2025 espros photonics co.
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_ESP_DSP)

  set(ESP_DSP_DIR ${ZEPHYR_CURRENT_MODULE_DIR})
  set(esp_glue_path ${ZEPHYR_ESP_DSP_MODULE_DIR})

  zephyr_library()
  zephyr_library_compile_options(-Ofast)

  zephyr_include_directories(
    ${ESP_DSP_DIR}/modules/math/include
    ${ESP_DSP_DIR}/modules/math/add/include
    ${ESP_DSP_DIR}/modules/math/addc/include
    ${ESP_DSP_DIR}/modules/math/sub/include
    ${ESP_DSP_DIR}/modules/math/mul/include
    ${ESP_DSP_DIR}/modules/math/mulc/include
    ${ESP_DSP_DIR}/modules/math/sqrt/include
    ./include
  )

    if(CONFIG_ESP_DSP_BASICMATH)
      if(CONFIG_DSP_OPTIMIZED)
        set(SRC_S3_BASICMATH 
          # add
          ${ESP_DSP_DIR}/modules/math/add/fixed/dsps_add_s8_aes3.S
          ${ESP_DSP_DIR}/modules/math/add/fixed/dsps_add_s16_aes3.S
          ${ESP_DSP_DIR}/modules/math/add/float/dsps_add_f32_ae32.S
          # addc
          ${ESP_DSP_DIR}/modules/math/addc/float/dsps_addc_f32_ae32.S
          # sub
          ${ESP_DSP_DIR}/modules/math/sub/fixed/dsps_sub_s8_aes3.S
          ${ESP_DSP_DIR}/modules/math/sub/fixed/dsps_sub_s16_aes3.S
          ${ESP_DSP_DIR}/modules/math/sub/float/dsps_sub_f32_ae32.S
          # mul
          ${ESP_DSP_DIR}/modules/math/mul/fixed/dsps_mul_s8_aes3.S
          ${ESP_DSP_DIR}/modules/math/mul/fixed/dsps_mul_s16_aes3.S
          ${ESP_DSP_DIR}/modules/math/mul/float/dsps_mul_f32_ae32.S
          # mulc
          ${ESP_DSP_DIR}/modules/math/mulc/fixed/dsps_mulc_s16_ae32.S
          ${ESP_DSP_DIR}/modules/math/mulc/float/dsps_mulc_f32_ae32.S
          # sqrt
          ${ESP_DSP_DIR}/modules/math/sqrt/float/dsps_sqrt_f32_ansi.c
          )
          else()
          set(SRC_S3_BASICMATH 
          # add
          ${ESP_DSP_DIR}/modules/math/add/fixed/dsps_add_s8_ansi.c
          ${ESP_DSP_DIR}/modules/math/add/fixed/dsps_add_s16_ansi.c
          ${ESP_DSP_DIR}/modules/math/add/float/dsps_add_f32_ansi.c
          # addc
          ${ESP_DSP_DIR}/modules/math/addc/float/dsps_addc_f32_ansi.c
          # sub
          ${ESP_DSP_DIR}/modules/math/sub/fixed/dsps_sub_s8_ansi.c
          ${ESP_DSP_DIR}/modules/math/sub/fixed/dsps_sub_s16_ansi.c
          ${ESP_DSP_DIR}/modules/math/sub/float/dsps_sub_f32_ansi.c
          # mul
          ${ESP_DSP_DIR}/modules/math/mul/fixed/dsps_mul_s8_ansi.c
          ${ESP_DSP_DIR}/modules/math/mul/fixed/dsps_mul_s16_ansi.c
          ${ESP_DSP_DIR}/modules/math/mul/float/dsps_mul_f32_ansi.c
          # mulc
          ${ESP_DSP_DIR}/modules/math/mulc/fixed/dsps_mulc_s16_ae32.S
          ${ESP_DSP_DIR}/modules/math/mulc/float/dsps_mulc_f32_ansi.c
          # sqrt
          ${ESP_DSP_DIR}/modules/math/sqrt/float/dsps_sqrt_f32_ansi.c
        )
      endif()

    endif()
  zephyr_library_sources(${SRC_S3_BASICMATH})

endif()