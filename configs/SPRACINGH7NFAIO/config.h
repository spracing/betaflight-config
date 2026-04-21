/*
 * This file is part of Betaflight.
 *
 * Betaflight is free software. You can redistribute this software
 * and/or modify this software under the terms of the GNU General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later
 * version.
 *
 * Betaflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define FC_TARGET_MCU                 STM32H743

#define BOARD_NAME                    SPRACINGH7NFAIO
#define MANUFACTURER_ID               SPRO

#define TARGET_BOARD_IDENTIFIER       "SPNF"
#define USBD_PRODUCT_STRING           "SPRacingH7NFAIO"

// Target supports 2 flash chips, one on SPI6 (1 bit), one on QuadSPI1 Bank 2 (4-bit)

#define USE_QUADSPI
#define USE_QUADSPI_DEVICE_1
#define QUADSPI1_SCK_PIN PB2
#define QUADSPI1_BK1_IO0_PIN          NONE
#define QUADSPI1_BK1_IO1_PIN          NONE
#define QUADSPI1_BK1_IO2_PIN          NONE
#define QUADSPI1_BK1_IO3_PIN          NONE
#define QUADSPI1_BK1_CS_PIN           NONE
#define QUADSPI1_BK2_IO0_PIN          PE7
#define QUADSPI1_BK2_IO1_PIN          PE8
#define QUADSPI1_BK2_IO2_PIN          PE9
#define QUADSPI1_BK2_IO3_PIN          PE10
#define QUADSPI1_BK2_CS_PIN           PC11
#define QUADSPI1_MODE                 QUADSPI_MODE_BK2_ONLY
#define QUADSPI1_CS_FLAGS             (QUADSPI_BK1_CS_NONE | QUADSPI_BK2_CS_HARDWARE | QUADSPI_CS_MODE_LINKED)

#define FLASH_QUADSPI_INSTANCE        QUADSPI

#define FDCAN1_RX_PIN                 PB8
#define FDCAN2_TX_PIN                 PB9

#define USE_SPI
// SDI = MISO, SDO = MOSI, SCK = SCK, NSS = CS

// SPI1/SPI2 share the same clock MUX and same DMA instance, best for dual gyro to
// have nothing else sharing the same SPI clock so it can be set EXACTLY for lowest transmission latency

// GYRO 1 (hardware NSS)
#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN                  PB13
#define SPI2_SDI_PIN                  PB14
#define SPI2_SDO_PIN                  PB15
#define SPI2_NSS_PIN                  PB12

// GYRO 2 (hardware NSS)
#define USE_SPI_DEVICE_3
#define SPI3_SCK_PIN                  PB3
#define SPI3_SDI_PIN                  PB4
#define SPI3_SDO_PIN                  PB5
#define SPI3_NSS_PIN                  PA15

// SPI based OSD (hardware NSS), eg. MAX7456 or compatible
#define USE_SPI_DEVICE_4
#define SPI4_SCK_PIN                  PE12
#define SPI4_SDI_PIN                  PE13
#define SPI4_SDO_PIN                  PE14
#define SPI4_NSS_PIN                  PE11
#define MAX7456_SPI_CS_PIN            SPI4_NSS_PIN
#define MAX7456_SPI_INSTANCE          SPI4

// SPI based FLASH (hardware NSS), using pins that could also be used for SPI1 (via AF mappings) has it's own clock MUX, uses DMA2
// allows the SPI clock speed to set to match the maximum clock signal of the connected flash chip
#define USE_SPI_DEVICE_6
#define SPI6_SCK_PIN                  PA5
#define SPI6_SDI_PIN                  PA6
#define SPI6_SDO_PIN                  PA7
#define SPI6_NSS_PIN                  PA4
#define FLASH_CS_PIN                  SPI6_NSS_PIN
#define FLASH_SPI_INSTANCE            SPI6

#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_FLASH_W25Q128FV
#define USE_FLASH_W25N01G
#define USE_FLASH_MT29F

#define USE_FLASH_TOOLS

#define DEFAULT_BLACKBOX_DEVICE       BLACKBOX_DEVICE_FLASH

#define USE_I2C
#define USE_I2C_DEVICE_1
#define I2C1_SCL_PIN                  PB6
#define I2C1_SDA_PIN                  PB7

#define USE_I2C_DEVICE_2
#define I2C2_SCL_PIN                  PB10
#define I2C2_SDA_PIN                  PB11

#define MAG_I2C_INSTANCE              I2CDEV_1
#define BARO_I2C_INSTANCE             I2CDEV_1

#define ENSURE_MPU_DATA_READY_IS_LOW

#define DEFAULT_RX_FEATURE            FEATURE_RX_SERIAL
#define DEFAULT_FEATURES              (FEATURE_TELEMETRY | FEATURE_OSD | FEATURE_LED_STRIP)

// ADC pins on PC0-3
#define ADC_INSTANCE                  ADC3
#define ADC3_INSTANCE                 ADC3

#define ADC_VBAT_INSTANCE             ADC3

// ADC3 INP10
#define ADC_VBAT_PIN                  PC0
#define ADC_VBAT_INSTANCE             ADC3
// ADC3 INP11
#define ADC_CURR_PIN                  PC1
#define ADC_CURR_INSTANCE             ADC3
// ADC3 INP0
#define ADC_EXTERNAL1_PIN             PC2
#define ADC_EXTERNAL1_INSTANCE        ADC3
// ADC3 INP1
#define ADC_EXTERNAL2_PIN             PC3
#define ADC_EXTERNAL1_INSTANCE        ADC3

#define DEFAULT_CURRENT_METER_SOURCE  CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE  VOLTAGE_METER_ADC
// TODO - confirm these
#define DEFAULT_VOLTAGE_METER_SCALE   110
#define DEFAULT_CURRENT_METER_SCALE   400

#define VTX_ENABLE_PIN                PE15
#define PINIO1_PIN                    VTX_ENABLE_PIN
#define PINIO1_CONFIG                 129
#define PINIO1_BOX                    0

#define USE_ACC
#define USE_ACC_SPI_ICM42605
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42605
#define USE_GYRO_SPI_ICM42688P
// TIM8 CH1/2 for GYRO1 INT/CLK  EXTI6 = GYRO1 INT (EXTI9_5)
// TIM8 CH3/4 for GYRO2 INT/CLK  EXTI8 = GYRO2 INT (EXTI9_5)
#define USE_GYRO_CLKIN
#define GYRO_1_EXTI_PIN               PC6
#define GYRO_1_CLKIN_PIN              PC7
#define GYRO_2_EXTI_PIN               PC8
#define GYRO_2_CLKIN_PIN              PC9
#define GYRO_1_SPI_INSTANCE           SPI2
#define GYRO_1_CS_PIN                 SPI2_NSS_PIN
#define GYRO_1_ALIGN                  CW180_DEG
#define GYRO_2_SPI_INSTANCE           SPI3
#define GYRO_2_CS_PIN                 SPI3_NSS_PIN
#define GYRO_2_ALIGN                  CW270_DEG

#define DEFAULT_GYRO_TO_USE           GYRO_CONFIG_USE_GYRO_BOTH

#define USE_BARO
#define USE_BARO_BMP388
#define USE_BARO_DPS310  //DPS368

#define USE_MAG
#define USE_MAG_LIS2MDL
#define USE_MAG_HMC5883
#define USE_MAG_QMC5883

#ifndef USE_LED_STRIP
#define USE_LED_STRIP
#endif

#define USE_MAX7456

#ifndef USE_OSD
#define USE_OSD
#endif

// EXTI10 (EXTI15_10)
#define USB_DETECT_PIN                PC10
// EXTI13 (EXTI15_10)
#define MAG_INT_PIN                   PC13
// EXTI14 (EXTI15_10)
#define BARO_INT_PIN                  PC14
// EXTI15 (EXTI15_10)
#define EXTERNAL_INT_PIN              PC15
//
// The functionality of PE5/PE6/PA8 can be balanced between user requirements
// There are IO connections for all of them, some PCBs using this target may have built-in LEDs pn PE5 however.

// TIM15_CH1 (with DMA)
#define LED_STRIP_PIN                 PE5
// TIM15_CH2 (for PWM in)
#define RX_PPM_PIN                    PE6
// TIM1 is unused for PWM/motor signals, keeps TIM1 free for other purposes (DSHOT)
#define MCO_PIN                       PA8


#define BEEPER_INVERTED
#define BEEPER_PIN                    PD7

// TIM5 CH1-4, Single GPIO port, Single timer instance.
#define MOTOR1_PIN                    PA0
#define MOTOR2_PIN                    PA1
#define MOTOR3_PIN                    PA2
#define MOTOR4_PIN                    PA3

// TIM4 CH1-4, Single GPIO port, Single timer instance.
#define MOTOR5_PIN                    PD12
#define MOTOR6_PIN                    PD13
#define MOTOR7_PIN                    PD14
#define MOTOR8_PIN                    PD15

// TIM3 CH3/4
#define MOTOR9_PIN                    PB0
#define MOTOR10_PIN                   PB1

// SERIAL RX
#define UART1_TX_PIN                  PA9
#define UART1_RX_PIN                  PA10

// MAVLINK (with hardware flow control as required, FC is DTE, Radio is DCE, wire FC RX-> Radio TX and FC RTS-> Radio CTS and vice versa
//#define UART2_CTS_PIN               PD3
//#define UART2_RTS_PIN               PD4
#define UART2_TX_PIN                  PD5
#define UART2_RX_PIN                  PD6

// GPS
#define UART3_TX_PIN                  PD8
#define UART3_RX_PIN                  PD9

// MSP_DISPLAYPORT + VTX
#define UART4_TX_PIN                  PD1
#define UART4_RX_PIN                  PD0

// FRSKYPIXELOSD
#define UART5_TX_PIN                  PC12
#define UART5_RX_PIN                  PD2

#define UART6_TX_PIN                  NONE
#define UART6_RX_PIN                  NONE

#define UART7_TX_PIN                  NONE
#define UART7_RX_PIN                  NONE

// SPARE
#define UART8_TX_PIN                  PE1
#define UART8_RX_PIN                  PE0

#define LED0_PIN                      PD10
#define LED1_PIN                      PD11

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PA0 , 2,  0) \
    TIMER_PIN_MAP( 1, PA1 , 2,  1) \
    TIMER_PIN_MAP( 2, PA2 , 2,  2) \
    TIMER_PIN_MAP( 3, PA3 , 2,  3) \
    TIMER_PIN_MAP( 4, PD12, 1,  4) \
    TIMER_PIN_MAP( 5, PD13, 1,  5) \
    TIMER_PIN_MAP( 6, PD14, 1,  6) \
    TIMER_PIN_MAP( 7, PD15, 1,  7) \
    TIMER_PIN_MAP( 8, PB0 , 2,  -1) \
    TIMER_PIN_MAP( 9, PB1 , 2,  -1) \
    TIMER_PIN_MAP(10, PE5 , 1,  -1) \
    TIMER_PIN_MAP(11, PE6 , 1,  -1) \
    TIMER_PIN_MAP(12, PC7 , 2,  -1) \
    TIMER_PIN_MAP(13, PC9 , 2,  -1) \
    TIMER_PIN_MAP(14, PA8 , 1,  8)

// Defines not used by BF
#define SWDIO_PIN                     PA13
#define SWCLK_PIN                     PA14

// TODO - confirm these
#define ADC3_DMA_OPT                  10
#define TIMUP1_DMA_OPT                0
#define TIMUP3_DMA_OPT                2
#define TIMUP5_DMA_OPT                0
#define TIMUP8_DMA_OPT                4
