/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Creality 4.2.x (STM32F103RE / STM32F103RC) board pin assignments
 */

#include "env_validate.h"

#if E_STEPPERS > 2
  #error "Creality v4 only supports 2 hotend / E stepper."
#endif

#ifndef BOARD_INFO_NAME
  #define BOARD_INFO_NAME      "Creality V4"
#endif
#ifndef DEFAULT_MACHINE_NAME
  #define DEFAULT_MACHINE_NAME "Creality V5.2.1"
#endif

#define BOARD_NO_NATIVE_USB

//
// Release PB4 (Y_ENABLE_PIN) from JTAG NRST role
//
#ifndef DISABLE_DEBUG
  #define DISABLE_DEBUG
#endif

//
// EEPROM
//
#if NO_EEPROM_SELECTED
  // I2C
  #define IIC_BL24CXX_EEPROM                      // EEPROM on I2C-0 used only for display settings
  #if ENABLED(IIC_BL24CXX_EEPROM)
    #define IIC_EEPROM_SDA       PC2
    #define IIC_EEPROM_SCL       PC3
    #define MARLIN_EEPROM_SIZE             0x800  // 2Kb (24C16)
  #else
    #define SDCARD_EEPROM_EMULATION               // SD EEPROM until all EEPROM is BL24CXX
    #define MARLIN_EEPROM_SIZE             0x800  // 2Kb
  #endif
#endif

//
// Servos
//
#ifdef BLTOUCH
  #define SERVO0_PIN       PD13  // BLTouch OUT
  #define Z_MIN_PIN        PD12
#else
  #define Z_MIN_PIN        PE1
#endif

//
// Limit Switches
//
#define X_MIN_PIN          PD10
#define X_MAX_PIN          PE15
#define Y_MIN_PIN          PE0
#define Z2_MIN_PIN         PE2

//
// Filament Runout Sensor
//
#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN                  PE5
  #define FIL_RUNOUT2_PIN                 PE6
#endif

//#define CHECKFILEMENT0_PIN                PE5
//#define CHECKFILEMENT1_PIN                PE6

//
// Steppers
//
#define X_ENABLE_PIN                        PC7
#ifndef X_STEP_PIN
  #define X_STEP_PIN                        PD15
#endif
#ifndef X_DIR_PIN
  #define X_DIR_PIN                         PD14
#endif

#define X2_ENABLE_PIN                       PE11
#ifndef X2_STEP_PIN
  #define X2_STEP_PIN                       PE9
#endif
#ifndef X2_DIR_PIN
  #define X2_DIR_PIN                        PE8
#endif

#define Y_ENABLE_PIN                        PB9
#ifndef Y_STEP_PIN
  #define Y_STEP_PIN                        PB7
#endif
#ifndef Y_DIR_PIN
  #define Y_DIR_PIN                         PB6
#endif

#define Z_ENABLE_PIN                        PB5
#ifndef Z_STEP_PIN
  #define Z_STEP_PIN                        PB3
#endif
#ifndef Z_DIR_PIN
  #define Z_DIR_PIN                         PD7
#endif

#define Z2_ENABLE_PIN                       PC5
#ifndef Z2_STEP_PIN
  #define Z2_STEP_PIN                       PA7
#endif
#ifndef Z2_DIR_PIN
  #define Z2_DIR_PIN                        PA6
#endif

#define E0_ENABLE_PIN                       PD4
#ifndef E0_STEP_PIN
  #define E0_STEP_PIN                       PD1
#endif
#ifndef E0_DIR_PIN
  #define E0_DIR_PIN                        PD0
#endif

#define E1_ENABLE_PIN                       PE7
#ifndef E1_STEP_PIN
  #define E1_STEP_PIN                       PB1
#endif
#ifndef E1_DIR_PIN
  #define E1_DIR_PIN                        PB0
#endif

//
// Temperature Sensors
//
#define TEMP_0_PIN                          PA4   // TH0
#define TEMP_1_PIN                          PA5   // TH1
#define TEMP_BED_PIN                        PA3   // TB1

//
// Heaters / Fans
//
#define HEATER_0_PIN                        PA1   // HEATER0
#define HEATER_1_PIN                        PA0   // HEATER1
#define HEATER_BED_PIN                      PA2   // HOT BED

#define FAN_PIN                             PB14   // FAN
#define FAN1_PIN                            PB12   // FAN
#define FAN_SOFT_PWM

//
// SD Card
//
#define SD_DETECT_PIN                       PA8
#define SDCARD_CONNECTION                ONBOARD
#define ONBOARD_SPI_DEVICE                     1
#define ONBOARD_SD_CS_PIN                   PC11   // SDSS
#define SDIO_SUPPORT
#define NO_SD_HOST_DRIVE                           // This board's SD is only seen by the printer

#if ENABLED(CR10_STOCKDISPLAY) && NONE(RET6_12864_LCD, VET6_12864_LCD)
  #error "Define RET6_12864_LCD or VET6_12864_LCD to select pins for CR10_STOCKDISPLAY with the Creality V4 controller."
#endif

#if ANY(RET6_12864_LCD, HAS_DWIN_E3V2, IS_DWIN_MARLINUI)

  /**
   *    RET6 12864 LCD
   *        ------
   *  PC6  | 1  2 | PB2
   *  PB10 | 3  4 | PB11
   *  PB14   5  6 | PB13
   *  PB12 | 7  8 | PB15
   *   GND | 9 10 | 5V
   *        ------
   */
  #define EXP3_01_PIN                       PC6
  #define EXP3_02_PIN                       PB2
  #define EXP3_03_PIN                       PB10
  #define EXP3_04_PIN                       PB11
  #define EXP3_05_PIN                       PB14
  #define EXP3_06_PIN                       PB13
  #define EXP3_07_PIN                       PB12
  #define EXP3_08_PIN                       PB15

#elif EITHER(VET6_12864_LCD, DWIN_VET6_CREALITY_LCD)

  /**
   *    VET6 12864 LCD
   *        ------
   *  ?    | 1  2 | PC5
   *  PB10 | 3  4 | ?
   *  PA6    5  6 | PA5
   *  PA4  | 7  8 | PA7
   *   GND | 9 10 | 5V
   *        ------
   */
  #define EXP3_01_PIN                       -1
  #define EXP3_02_PIN                       PC5
  #define EXP3_03_PIN                       PB10
  #define EXP3_04_PIN                       -1
  #define EXP3_05_PIN                       PA6
  #define EXP3_06_PIN                       PA5
  #define EXP3_07_PIN                       PA4
  #define EXP3_08_PIN                       PA7

#elif EITHER(CR10_STOCKDISPLAY, FYSETC_MINI_12864_2_1)
  #error "Define RET6_12864_LCD or VET6_12864_LCD to select pins for the LCD with the Creality V4 controller."
#endif

#if ENABLED(CR10_STOCKDISPLAY)

  #define LCD_PINS_RS                EXP3_07_PIN
  #define LCD_PINS_ENABLE            EXP3_08_PIN
  #define LCD_PINS_D4                EXP3_06_PIN

  #define BTN_ENC                    EXP3_02_PIN
  #define BTN_EN1                    EXP3_03_PIN
  #define BTN_EN2                    EXP3_05_PIN

  #ifndef HAS_PIN_27_BOARD
    #define BEEPER_PIN               EXP3_01_PIN
  #endif

#elif ANY(HAS_DWIN_E3V2, IS_DWIN_MARLINUI, DWIN_VET6_CREALITY_LCD)

  #define BTN_ENC                    EXP3_05_PIN
  #define BTN_EN1                    EXP3_08_PIN
  #define BTN_EN2                    EXP3_07_PIN

  #ifndef BEEPER_PIN
    #define BEEPER_PIN               EXP3_06_PIN
  #endif

#elif ENABLED(FYSETC_MINI_12864_2_1)

  #ifndef NO_CONTROLLER_CUSTOM_WIRING_WARNING
    #error "CAUTION! FYSETC_MINI_12864_2_1 and clones require wiring modifications. See 'pins_CREALITY_V4.h' for details. Define NO_CONTROLLER_CUSTOM_WIRING_WARNING to suppress this warning."
  #endif

  #if SD_CONNECTION_IS(LCD)
    #error "The LCD SD Card is not connected with this configuration."
  #endif

  /**
   *
   *                 Board (RET6 12864 LCD)              Display
   *                 ------                               ------
   *  (EN1)    PC6  | 1  2 | PB2  (BTN_ENC)           5V |10  9 | GND
   *  (LCD_CS) PB10 | 3  4 | PB11 (LCD RESET)         -- | 8  7 | --
   *  (LCD_A0) PB14   5  6 | PB13 (EN2)           (DIN)  | 6  5   (LCD RESET)
   *  (LCD_SCK)PB12 | 7  8 | PB15 (MOSI)        (LCD_A0) | 4  3 | (LCD_CS)
   *            GND | 9 10 | 5V                (BTN_ENC) | 2  1 | --
   *                 ------                               ------
   *                  EXP1                                 EXP1
   *
   *                                                      ------
   *                -----                             -- |10  9 | --
   *                | 1 | VCC                    (RESET) | 8  7 | --
   *                | 2 | PA13 (DIN)             (MOSI)  | 6  5   (EN2)
   *                | 3 | PA14                        -- | 4  3 | (EN1)
   *                | 4 | GND                   (LCD_SCK)| 2  1 | --
   *                -----                                 ------
   *              Debug port                               EXP2
   *
   * Needs custom cable. Connect EN2-EN2, LCD_CS-LCD_CS and so on.
   * Debug port is just above EXP1. You need to add pins.
   *
   */

  #define BTN_ENC                    EXP3_02_PIN
  #define BTN_EN1                    EXP3_01_PIN
  #define BTN_EN2                    EXP3_06_PIN
  #define BEEPER_PIN                        -1

  #define DOGLCD_CS                  EXP3_03_PIN
  #define DOGLCD_A0                  EXP3_05_PIN
  #define DOGLCD_SCK                 EXP3_07_PIN
  #define DOGLCD_MOSI                EXP3_08_PIN
  #define LCD_RESET_PIN              EXP3_04_PIN

  #define FORCE_SOFT_SPI
  #define LCD_BACKLIGHT_PIN                 -1
  #define NEOPIXEL_PIN                      PA13

#endif

// Pins for documentation and sanity checks only.
// Changing these will not change the pin they are on.

// Hardware UART pins
#define UART1_TX_PIN                        PA9   // default uses CH340 RX
#define UART1_RX_PIN                        PA10  // default uses CH340 TX
#define UART2_TX_PIN                        PA2   // default uses HEATER_BED_PIN
#define UART2_RX_PIN                        PA3   // not connected
#define UART3_TX_PIN                        PB10  // default uses LCD connector
#define UART3_RX_PIN                        PB11  // default uses LCD connector
#define UART4_TX_PIN                        PC10  // default uses sdcard SDIO_D2
#define UART4_RX_PIN                        PC11  // default uses sdcard SDIO_D3
#define UART5_TX_PIN                        PC12  // default uses sdcard SDIO_CK
#define UART5_RX_PIN                        PD2   // default uses sdcard SDIO_CMD

// SDIO pins
#define SDIO_D0_PIN                         PC8
#define SDIO_D1_PIN                         PC9
#define SDIO_D2_PIN                         PC10
#define SDIO_D3_PIN                         PC11
#define SDIO_CK_PIN                         PC12
#define SDIO_CMD_PIN                        PD2
