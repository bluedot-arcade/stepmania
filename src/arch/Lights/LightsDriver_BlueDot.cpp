#include "global.h"
#include "LightsDriver_BlueDot.h"

REGISTER_LIGHTS_DRIVER_CLASS( BlueDot );

LightsDriver_BlueDot::LightsDriver_BlueDot()
{
	device = NULL;

	//Initialize the bluedot library
	if (bdio_init() < 0) {
		MessageBox(NULL, "Could not initialize the BlueDot library.", "ERROR", MB_OK);
	}

	//Open the device
	device = bdio_open_device();
	if (device == NULL) {
		MessageBox(NULL, "Could not connect to the BlueDot device.", "ERROR", MB_OK);
	}
}

LightsDriver_BlueDot::~LightsDriver_BlueDot()
{
	//Close active device
	if (device != NULL) {
		bdio_close_device(device);
	}

	//Exit the bluedot library
	bdio_exit();
}

void LightsDriver_BlueDot::Set(const LightsState *ls)
{
	if (device == NULL) {
		return;
	}

	//Each bit addresses a light.
	//Set a light ON by setting its bit to 1, or OFF by setting it to 0
	unsigned char buf[8];
	for(int i = 0; i < 8; i++) {
		buf[i] = 0x00;
	}

	//Update cabinet lights
	if (ls->m_bCabinetLights[LIGHT_MARQUEE_UP_LEFT])
		buf[LIGHT_MARQUEE_UP_LEFT_BYTE] |= LIGHT_MARQUEE_UP_LEFT_MASK;
	if (ls->m_bCabinetLights[LIGHT_MARQUEE_UP_RIGHT])
		buf[LIGHT_MARQUEE_UP_RIGHT_BYTE] |= LIGHT_MARQUEE_UP_RIGHT_MASK;
	if (ls->m_bCabinetLights[LIGHT_MARQUEE_LR_LEFT])
		buf[LIGHT_MARQUEE_LR_LEFT_BYTE] |= LIGHT_MARQUEE_LR_LEFT_MASK;
	if (ls->m_bCabinetLights[LIGHT_MARQUEE_LR_RIGHT])
		buf[LIGHT_MARQUEE_LR_RIGHT_BYTE] |= LIGHT_MARQUEE_LR_RIGHT_MASK;
	if (ls->m_bCabinetLights[LIGHT_BASS_LEFT])
		buf[LIGHT_BASS_LEFT_BYTE] |= LIGHT_BASS_LEFT_MASK;
	if (ls->m_bCabinetLights[LIGHT_BASS_RIGHT])
		buf[LIGHT_BASS_RIGHT_BYTE] |= LIGHT_BASS_RIGHT_MASK;

	//Update pad lights Player 1
	if (ls->m_bGameButtonLights[GameController_1][GAME_BUTTON_CUSTOM_01])
		buf[LIGHT_P1_BTN_CUSTOM_01_BYTE] |= LIGHT_P1_BTN_CUSTOM_01_MASK;
	if (ls->m_bGameButtonLights[GameController_1][GAME_BUTTON_CUSTOM_02])
		buf[LIGHT_P1_BTN_CUSTOM_02_BYTE] |= LIGHT_P1_BTN_CUSTOM_02_MASK;
	if (ls->m_bGameButtonLights[GameController_1][GAME_BUTTON_CUSTOM_03])
		buf[LIGHT_P1_BTN_CUSTOM_03_BYTE] |= LIGHT_P1_BTN_CUSTOM_03_MASK;
	if (ls->m_bGameButtonLights[GameController_1][GAME_BUTTON_CUSTOM_04])
		buf[LIGHT_P1_BTN_CUSTOM_04_BYTE] |= LIGHT_P1_BTN_CUSTOM_04_MASK;
	if (ls->m_bGameButtonLights[GameController_1][GAME_BUTTON_CUSTOM_05])
		buf[LIGHT_P1_BTN_CUSTOM_05_BYTE] |= LIGHT_P1_BTN_CUSTOM_05_MASK;

	//Update pad lights Player 2
	if (ls->m_bGameButtonLights[GameController_2][GAME_BUTTON_CUSTOM_01])
		buf[LIGHT_P2_BTN_CUSTOM_01_BYTE] |= LIGHT_P2_BTN_CUSTOM_01_MASK;
	if (ls->m_bGameButtonLights[GameController_2][GAME_BUTTON_CUSTOM_02])
		buf[LIGHT_P2_BTN_CUSTOM_02_BYTE] |= LIGHT_P2_BTN_CUSTOM_02_MASK;
	if (ls->m_bGameButtonLights[GameController_2][GAME_BUTTON_CUSTOM_03])
		buf[LIGHT_P2_BTN_CUSTOM_03_BYTE] |= LIGHT_P2_BTN_CUSTOM_03_MASK;
	if (ls->m_bGameButtonLights[GameController_2][GAME_BUTTON_CUSTOM_04])
		buf[LIGHT_P2_BTN_CUSTOM_04_BYTE] |= LIGHT_P2_BTN_CUSTOM_04_MASK;
	if (ls->m_bGameButtonLights[GameController_2][GAME_BUTTON_CUSTOM_05])
		buf[LIGHT_P2_BTN_CUSTOM_05_BYTE] |= LIGHT_P2_BTN_CUSTOM_05_MASK;

	bdio_set_lights(device, buf, 8);
}
