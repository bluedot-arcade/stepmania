#ifndef BLUEDOTIO_HPP
#define BLUEDOTIO_HPP

#ifdef WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include "hidapi.h"

#define BLUEDOT_VID 0x03EB
#define BLUEDOT_PID 0x204F

int bdio_send_packet(hid_device *handle, unsigned char cmd, unsigned char *data, unsigned int data_size);

int bdio_jump_to_bootloader(hid_device *handle);

int bdio_set_lights(hid_device *handle, unsigned char *mask, unsigned int size);

int bdio_turn_on_lights(hid_device *handle, unsigned char *mask, unsigned int size);

int bdio_turn_off_lights(hid_device *handle, unsigned char *mask, unsigned int size);

int bdio_init();

int bdio_exit();

hid_device *bdio_open_device();

void bdio_close_device(hid_device *handle);

/* Cabinet lights */
#define LIGHT_MARQUEE_UP_LEFT_BYTE          0
#define LIGHT_MARQUEE_UP_LEFT_MASK          0x01
#define LIGHT_MARQUEE_UP_RIGHT_BYTE         0
#define LIGHT_MARQUEE_UP_RIGHT_MASK         0x02
#define LIGHT_MARQUEE_LR_LEFT_BYTE          0
#define LIGHT_MARQUEE_LR_LEFT_MASK          0x04
#define LIGHT_MARQUEE_LR_RIGHT_BYTE         0
#define LIGHT_MARQUEE_LR_RIGHT_MASK         0x08
#define LIGHT_BASS_LEFT_BYTE                0
#define LIGHT_BASS_LEFT_MASK                0x10
#define LIGHT_BASS_RIGHT_BYTE               0
#define LIGHT_BASS_RIGHT_MASK               0x20

/* Player 1 game controller lights */
#define LIGHT_P1_BTN_MENULEFT_BYTE          1
#define LIGHT_P1_BTN_MENULEFT_MASK          0x01
#define LIGHT_P1_BTN_MENURIGHT_BYTE         1
#define LIGHT_P1_BTN_MENURIGHT_MASK         0x02
#define LIGHT_P1_BTN_MENUUP_BYTE            1
#define LIGHT_P1_BTN_MENUUP_MASK            0x04
#define LIGHT_P1_BTN_MENUDOWN_BYTE          1
#define LIGHT_P1_BTN_MENUDOWN_MASK          0x08
#define LIGHT_P1_BTN_START_BYTE             1
#define LIGHT_P1_BTN_START_MASK             0x10
#define LIGHT_P1_BTN_SELECT_BYTE            1
#define LIGHT_P1_BTN_SELECT_MASK            0x20
#define LIGHT_P1_BTN_BACK_BYTE              1
#define LIGHT_P1_BTN_BACK_MASK              0x40
#define LIGHT_P1_BTN_COIN_BYTE              1
#define LIGHT_P1_BTN_COIN_MASK              0x80
#define LIGHT_P1_BTN_OPERATOR_BYTE          2
#define LIGHT_P1_BTN_OPERATOR_MASK          0x01
#define LIGHT_P1_BTN_SCREENSHOT_BYTE        2
#define LIGHT_P1_BTN_SCREENSHOT_MASK        0x02
#define LIGHT_P1_BTN_EFFECT_UP_BYTE         2
#define LIGHT_P1_BTN_EFFECT_UP_MASK         0x04
#define LIGHT_P1_BTN_EFFECT_DOWN_BYTE       2
#define LIGHT_P1_BTN_EFFECT_DOWN_MASK       0x08
#define LIGHT_P1_BTN_CUSTOM_01_BYTE         2
#define LIGHT_P1_BTN_CUSTOM_01_MASK         0x10
#define LIGHT_P1_BTN_CUSTOM_02_BYTE         2
#define LIGHT_P1_BTN_CUSTOM_02_MASK         0x20
#define LIGHT_P1_BTN_CUSTOM_03_BYTE         2
#define LIGHT_P1_BTN_CUSTOM_03_MASK         0x40
#define LIGHT_P1_BTN_CUSTOM_04_BYTE         2
#define LIGHT_P1_BTN_CUSTOM_04_MASK         0x80
#define LIGHT_P1_BTN_CUSTOM_05_BYTE         3
#define LIGHT_P1_BTN_CUSTOM_05_MASK         0x01
#define LIGHT_P1_BTN_CUSTOM_06_BYTE         3
#define LIGHT_P1_BTN_CUSTOM_06_MASK         0x02
#define LIGHT_P1_BTN_CUSTOM_07_BYTE         3
#define LIGHT_P1_BTN_CUSTOM_07_MASK         0x04
#define LIGHT_P1_BTN_CUSTOM_08_BYTE         3
#define LIGHT_P1_BTN_CUSTOM_08_MASK         0x08
#define LIGHT_P1_BTN_CUSTOM_09_BYTE         3
#define LIGHT_P1_BTN_CUSTOM_09_MASK         0x10
#define LIGHT_P1_BTN_CUSTOM_10_BYTE         3
#define LIGHT_P1_BTN_CUSTOM_10_MASK         0x20
#define LIGHT_P1_BTN_CUSTOM_11_BYTE         3
#define LIGHT_P1_BTN_CUSTOM_11_MASK         0x40
#define LIGHT_P1_BTN_CUSTOM_12_BYTE         3
#define LIGHT_P1_BTN_CUSTOM_12_MASK         0x80
#define LIGHT_P1_BTN_CUSTOM_13_BYTE         4
#define LIGHT_P1_BTN_CUSTOM_13_MASK         0x01
#define LIGHT_P1_BTN_CUSTOM_14_BYTE         4
#define LIGHT_P1_BTN_CUSTOM_14_MASK         0x02
#define LIGHT_P1_BTN_CUSTOM_15_BYTE         4
#define LIGHT_P1_BTN_CUSTOM_15_MASK         0x04
#define LIGHT_P1_BTN_CUSTOM_16_BYTE         4
#define LIGHT_P1_BTN_CUSTOM_16_MASK         0x08
#define LIGHT_P1_BTN_CUSTOM_17_BYTE         4
#define LIGHT_P1_BTN_CUSTOM_17_MASK         0x10
#define LIGHT_P1_BTN_CUSTOM_18_BYTE         4
#define LIGHT_P1_BTN_CUSTOM_18_MASK         0x20
#define LIGHT_P1_BTN_CUSTOM_19_BYTE         4
#define LIGHT_P1_BTN_CUSTOM_19_MASK         0x40

/* Player 2 game controller lights */
#define LIGHT_P2_BTN_MENULEFT_BYTE          5
#define LIGHT_P2_BTN_MENULEFT_MASK          0x01
#define LIGHT_P2_BTN_MENURIGHT_BYTE         5
#define LIGHT_P2_BTN_MENURIGHT_MASK         0x02
#define LIGHT_P2_BTN_MENUUP_BYTE            5
#define LIGHT_P2_BTN_MENUUP_MASK            0x04
#define LIGHT_P2_BTN_MENUDOWN_BYTE          5
#define LIGHT_P2_BTN_MENUDOWN_MASK          0x08
#define LIGHT_P2_BTN_START_BYTE             5
#define LIGHT_P2_BTN_START_MASK             0x10
#define LIGHT_P2_BTN_SELECT_BYTE            5
#define LIGHT_P2_BTN_SELECT_MASK            0x20
#define LIGHT_P2_BTN_BACK_BYTE              5
#define LIGHT_P2_BTN_BACK_MASK              0x40
#define LIGHT_P2_BTN_COIN_BYTE              5
#define LIGHT_P2_BTN_COIN_MASK              0x80
#define LIGHT_P2_BTN_OPERATOR_BYTE          6
#define LIGHT_P2_BTN_OPERATOR_MASK          0x01
#define LIGHT_P2_BTN_SCREENSHOT_BYTE        6
#define LIGHT_P2_BTN_SCREENSHOT_MASK        0x02
#define LIGHT_P2_BTN_EFFECT_UP_BYTE         6
#define LIGHT_P2_BTN_EFFECT_UP_MASK         0x04
#define LIGHT_P2_BTN_EFFECT_DOWN_BYTE       6
#define LIGHT_P2_BTN_EFFECT_DOWN_MASK       0x08
#define LIGHT_P2_BTN_CUSTOM_01_BYTE         6
#define LIGHT_P2_BTN_CUSTOM_01_MASK         0x10
#define LIGHT_P2_BTN_CUSTOM_02_BYTE         6
#define LIGHT_P2_BTN_CUSTOM_02_MASK         0x20
#define LIGHT_P2_BTN_CUSTOM_03_BYTE         6
#define LIGHT_P2_BTN_CUSTOM_03_MASK         0x40
#define LIGHT_P2_BTN_CUSTOM_04_BYTE         6
#define LIGHT_P2_BTN_CUSTOM_04_MASK         0x80
#define LIGHT_P2_BTN_CUSTOM_05_BYTE         7
#define LIGHT_P2_BTN_CUSTOM_05_MASK         0x01
#define LIGHT_P2_BTN_CUSTOM_06_BYTE         7
#define LIGHT_P2_BTN_CUSTOM_06_MASK         0x02
#define LIGHT_P2_BTN_CUSTOM_07_BYTE         7
#define LIGHT_P2_BTN_CUSTOM_07_MASK         0x04
#define LIGHT_P2_BTN_CUSTOM_08_BYTE         7
#define LIGHT_P2_BTN_CUSTOM_08_MASK         0x08
#define LIGHT_P2_BTN_CUSTOM_09_BYTE         7
#define LIGHT_P2_BTN_CUSTOM_09_MASK         0x10
#define LIGHT_P2_BTN_CUSTOM_10_BYTE         7
#define LIGHT_P2_BTN_CUSTOM_10_MASK         0x20
#define LIGHT_P2_BTN_CUSTOM_11_BYTE         7
#define LIGHT_P2_BTN_CUSTOM_11_MASK         0x40
#define LIGHT_P2_BTN_CUSTOM_12_BYTE         7
#define LIGHT_P2_BTN_CUSTOM_12_MASK         0x80
#define LIGHT_P2_BTN_CUSTOM_13_BYTE         8
#define LIGHT_P2_BTN_CUSTOM_13_MASK         0x01
#define LIGHT_P2_BTN_CUSTOM_14_BYTE         8
#define LIGHT_P2_BTN_CUSTOM_14_MASK         0x02
#define LIGHT_P2_BTN_CUSTOM_15_BYTE         8
#define LIGHT_P2_BTN_CUSTOM_15_MASK         0x04
#define LIGHT_P2_BTN_CUSTOM_16_BYTE         8
#define LIGHT_P2_BTN_CUSTOM_16_MASK         0x08
#define LIGHT_P2_BTN_CUSTOM_17_BYTE         8
#define LIGHT_P2_BTN_CUSTOM_17_MASK         0x10
#define LIGHT_P2_BTN_CUSTOM_18_BYTE         8
#define LIGHT_P2_BTN_CUSTOM_18_MASK         0x20
#define LIGHT_P2_BTN_CUSTOM_19_BYTE         8
#define LIGHT_P2_BTN_CUSTOM_19_MASK         0x40

#endif