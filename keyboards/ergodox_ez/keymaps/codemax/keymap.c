#include QMK_KEYBOARD_H
#include "version.h"
#include <stdlib.h>
#include <stdint.h>

// The layers for this keyboard.
#define BASE 0
#define NUMPAD 1
#define NAV 2
#define MOUSE 3
#define GAME 4
#define FN 5
#define SYM 6
#define SYMPLUS 7

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
  ST_MACRO_15,
  ST_MACRO_16,
  ST_MACRO_17,
  ST_MACRO_18,
  ST_MACRO_19,
  ST_MACRO_20,
  ST_MACRO_21,
  ST_MACRO_22,
  ST_MACRO_23,
  ST_MACRO_24,
  ST_MACRO_25,
};

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_4,
};

// A 'transparent' key code (that falls back to the layers below it).
#define ___ KC_TRANSPARENT

// A 'blocking' key code. Does nothing but prevent falling back to another layer.
#define XXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    KC_ESCAPE,          KC_F1,        KC_F2,           KC_F3,        KC_F4,        KC_F5,          TG(4),  
    KC_GRAVE,           KC_Q,         KC_W,            KC_F,         KC_P,         KC_G,           TG(3),  
    OSL(6),           LT(1,KC_A),  LALT_T(KC_R),   LCTL_T(KC_S),  LSFT_T(KC_T), LT(2,KC_D), 
    OSM(MOD_LSFT),      KC_Z,         KC_X,            KC_C,         KC_V,         KC_B,           KC_F15,  
    KC_DELETE,      KC_APPLICATION, KC_MS_BTN2,     KC_ESCAPE,     KC_SPACE,                      
 // left thumb --------------------------------------------------------------------------------------------------
                                                                            LCTL(KC_Z),     LALT(KC_F4),    
                                                                                              KC_TAB,        
                                                           LT(7,KC_BSPACE),LT(5,KC_ENTER), LSFT(KC_TAB),   
  // right hand --------------------------------------------------------------------------------------------------
TG(1),      KC_F6,       KC_F7,         KC_F8,         KC_F9,          KC_F10,      KC_CAPSLOCK,
TG(3),      KC_J,        KC_L,          KC_U,          KC_Y,         TD(DANCE_0),     KC_GRAVE,
            KC_H,    RSFT_T(KC_N),   LCTL_T(KC_E),  RALT_T(KC_I),   SCMD_T(KC_O),      OSL(6),
 KC_F15,    KC_K,        KC_M,        TD(DANCE_1),  TD(DANCE_2),      KC_QUES,       OSM(MOD_LSFT),
                        KC_LGUI,        KC_F11,        KC_F12,      KC_APPLICATION,     XXX,
  // right thumb -------------------------------------------------------------------------------------------------
  KC_PSCREEN,     LCTL(KC_Y),
  KC_F23,
  KC_F24,          KC_END,         LT(7,KC_SPACE)
  ),
  [NUMPAD] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    ___, ___,     ___,  ___, ___,    ___,     ___,                              
    ___, ___,     ___,  ___, ___,    ___,     XXX,                    
    ___, ___, KC_LALT,  ___, ___,   MO(2),              
    ___, ___,     ___,  ___, ___,    ___,     ___,     
    ___, ___,     XXX,  ___, ___,          
 // left thumb --------------------------------------------------------------------------------------------------
                                                           XXX,  KC_NUMLOCK,   
                                                                        ___, 
                                                           ___,  ___,   ___,
  // right hand --------------------------------------------------------------------------------------------------
                              ___,     XXX,           XXX,       XXX,        XXX,           XXX,       KC_KP_ASTERISK,
                    KC_CALCULATOR,  LCTL(KC_V),    KC_KP_7,     KC_KP_8,    KC_KP_9,       KC_COLN,     KC_KP_MINUS,
                                       XXX,         KC_KP_4,    KC_KP_5,    KC_KP_6,        KC_X,         KC_KP_PLUS,
                       ST_MACRO_0,     XXX,        KC_KP_1,     KC_KP_2,    KC_KP_3,     KC_KP_SLASH,    KC_ENTER,
                                                   KC_SPACE,  KC_KP_COMMA,  KC_KP_DOT,      ___,            TO(0),
  // right thumb -------------------------------------------------------------------------------------------------
                         ___,    XXX,
                                 ___,
                ___,   TG(2),  KC_KP_0
  ),
  [NAV] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    ___, ___,  ___,   ___, ___, ___, ___, 
    ___, ___,  ___,   ___, ___, ___, ___, 
    ___, ___,  ___,   ___, ___, ___,                  
    ___, ___,  ___,   ___, ___, ___, ___,    
    ___, ___,  XXX,   ___, ___,        
 // left thumb --------------------------------------------------------------------------------------------------
                        XXX,    KC_SCROLLLOCK, 
                                          ___,
                        ___,     ___,     ___, 
// right hand --------------------------------------------------------------------------------------------------
                                ___,       ___,            ___,         ___,       ___,        ___,         ___,
                                ___,  LCTL(KC_HOME),  OSM(MOD_LCTL),   KC_UP,    KC_PGUP,      XXX,         XXX,
                                         KC_HOME,        KC_LEFT,     KC_DOWN,   KC_RIGHT,    KC_END,       XXX,
                                ___,       XXX,         KC_DELETE,      XXX,    KC_PGDOWN,  LCTL(KC_END),   ___,
                                                           XXX,         XXX,       XXX,        ___,        TO(0),
  // right thumb -------------------------------------------------------------------------------------------------
                        ___,   XXX,
                        ___,
                        ___,   ___,   KC_SPACE
  ),
  [MOUSE] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    ___, ___, ___, ___, ___, ___, ___,  
    ___, ___, ___, ___, ___, ___, ___,  
    ___, ___, ___, ___, ___, ___,                                              
    ___, ___, ___, ___, ___, ___, ___,                      
    ___, ___, ___, ___, ___,   
 // left thumb --------------------------------------------------------------------------------------------------
                  XXX,   ___,
                         ___, 
               ___, ___, ___, 
// right hand --------------------------------------------------------------------------------------------------
                                 ___,      ___,         ___,         ___,           ___,           ___,        ___,
                                 ___,      XXX,       KC_LCTRL,    KC_MS_UP,     KC_MS_WH_UP,      XXX,        ___,
                                           XXX,      KC_MS_LEFT,  KC_MS_DOWN,    KC_MS_RIGHT,   KC_MS_BTN3,    ___,
                                 ___,   LALT(KC_F4), ST_MACRO_1,  TD(DANCE_4),  KC_MS_WH_DOWN,     XXX,        ___,
                                                        ___,         ___,           ___,        KC_MS_BTN2,   TO(0),
  // right thumb -------------------------------------------------------------------------------------------------
                                 ___, XXX,
                                 ___,
                                 ___,  ___,    KC_MS_BTN1  
  ),
  [GAME] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    ___, ___,    ___,     ___,      ___,    ___, ___,             
    ___, ___,    ___,    KC_UP,     ___,    ___, ___,               
    ___, ___, KC_LEFT,  KC_DOWN,  KC_RIGHT, ___,             
    ___, ___,    ___,     ___,      ___,    ___, ___,                          
    ___, ___,    XXX,     ___,      ___,                                                                                        
 // left thumb --------------------------------------------------------------------------------------------------
                                  XXX,          ___, 
                                                ___, 
                               KC_SPACE,   ___, ___, 
// right hand --------------------------------------------------------------------------------------------------
                                 ___, ___, ___, ___, ___, ___,  ___,
                                 ___, ___, ___, ___, ___, ___,  ___,
                                      ___, ___, ___, ___, ___,  ___,
                                 ___, ___, ___, ___, ___, ___,  ___,
                                           ___, ___, ___, ___, TO(0),
// right thumb -------------------------------------------------------------------------------------------------
                          ___, XXX,
                          ___,
                          ___,  ___,   ___
  ),
  [FN] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    ___,   ___,   ___,            ___,            ___,     ___,    ___, 
    ___,   ___,   ___,            ___,            ___,     ___,    ___, 
    ___,  KC_1,  KC_2,           KC_3,           KC_4,    KC_5,   
    ___,  KC_6,  KC_7,           KC_8,           KC_9,    KC_0,    ___,      
    ___,   ___,   ___,   LALT(LCTL(KC_DELETE)),   ___,      
 // left thumb --------------------------------------------------------------------------------------------------
                           ___, ___,
                                ___,
                      ___, ___, ___,
// right hand --------------------------------------------------------------------------------------------------
                        ___,        ___, ___,  RESET,  ___, ___,  ___,
                        ___,        ___, ___,   ___,   ___, ___,  ___,
                                    ___, ___,   ___,   ___, ___,  ___,
                   KC_SYSTEM_SLEEP, ___, ___,   ___,   ___, ___,  ___,
                                         ___,   ___,   ___, ___, TO(0),
// right thumb -------------------------------------------------------------------------------------------------
               ___, ___,
               ___,
               ___, ___, ___ 
  ),
  [SYM] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
            ___,                KC_1,          KC_2,          KC_3,           KC_4,           KC_5,        ___,                                
          ST_MACRO_2,        ST_MACRO_3,      KC_AMPR,       KC_PLUS,        KC_ASTR,        KC_EQUAL,     ___,     
            ___,              KC_LCBR,       KC_LBRACKET,    KC_LPRN,        KC_EXLM,        KC_UNDS,             
            ___,              KC_BSLASH,       KC_AT,        KC_HASH,        KC_DLR,         KC_PERC,      ___,     
            ___,                 ___,           ___,           ___,           ___,                                                                                            
 // left thumb --------------------------------------------------------------------------------------------------
                                                                                                ___, ___,
                                                                                                     ___,
                                                                                           ___, ___, ___,
// right hand --------------------------------------------------------------------------------------------------
                                 ___,        KC_6,        KC_7,          KC_8,             KC_9,          KC_0,          ___,
                                 ___,      KC_TILD,      KC_SLASH,      KC_MINUS,         KC_PIPE,      ST_MACRO_4,   ST_MACRO_5,
                                          ST_MACRO_6,   ST_MACRO_7,     KC_RPRN,        KC_RBRACKET,     KC_RCBR,        ___,
                                 ___,      KC_CIRC,        ___,        ST_MACRO_8,      ST_MACRO_25,     KC_BSLASH,      ___,
                                                           ___,           ___,              ___,           ___,          TO(0),
// right thumb -------------------------------------------------------------------------------------------------
               ___, ___,
               ___,
               ___, ___, ___ 
  ),
  [SYMPLUS] = LAYOUT_ergodox(
  // left hand ---------------------------------------------------------------------------------------------------
    ___,    ___,          ___,          ___,          ___,       ___, ___, 
    ___, ST_MACRO_9,   ST_MACRO_10,  ST_MACRO_11,     ___,       ___, ___, 
    ___, ST_MACRO_12,     ___,       ST_MACRO_13,  ST_MACRO_14,  ___, 
    ___, ST_MACRO_15,     ___,          ___,          ___,       ___, ___,  
    ___,    ___,          ___,          ___,          ___,   
 // left thumb --------------------------------------------------------------------------------------------------
                                                                              ___, ___,
                                                                                   ___,
                                                                         ___, ___, ___,
// right hand --------------------------------------------------------------------------------------------------
                                 ___, ___,    ___,           ___,         ___,          ___,        ___,
                                 ___, ___,    ___,       ST_MACRO_16,  ST_MACRO_17,  ST_MACRO_18,   ___,
                                      ___, ST_MACRO_19,  ST_MACRO_20,     ___,       ST_MACRO_24,   ___,
                                 ___, ___,    ___,       ST_MACRO_21,  ST_MACRO_22,  ST_MACRO_23,   ___,
                                              ___,           ___,         ___,          ___,      TO(0),
// right thumb -------------------------------------------------------------------------------------------------
               ___, ___,
               ___,
               ___, ___, ___ 
  ),
};
uint32_t layer_state_set_user(uint32_t state);
void flash(uint16_t time, uint8_t leds);
void run(uint16_t speed);
uint8_t current_layer = 0;

// The state of the LEDs requested by the system, as a bitmask.
static uint8_t sys_led_state = 0;

// Use these masks to read the system LEDs state.
static const uint8_t sys_led_mask_num_lock = 1 << USB_LED_NUM_LOCK;
static const uint8_t sys_led_mask_caps_lock = 1 << USB_LED_CAPS_LOCK;
static const uint8_t sys_led_mask_scroll_lock = 1 << USB_LED_SCROLL_LOCK;

// Value to use to switch LEDs on. The default value of 255 is far too bright.
static const uint8_t max_led_value = 20;
#define right_led 1
#define middle_led 2

void led_1_on(void) {
  ergodox_right_led_1_on();
  ergodox_right_led_1_set(max_led_value);
}

void led_2_on(void) {
  ergodox_right_led_2_on();
  ergodox_right_led_2_set(max_led_value);
}

void led_3_on(void) {
  ergodox_right_led_3_on();
  ergodox_right_led_3_set(max_led_value);
}

void led_1_off(void) {
  ergodox_right_led_1_off();
}

void led_2_off(void) {
  ergodox_right_led_2_off();
}

void led_3_off(void) {
  ergodox_right_led_3_off();
}

void set_indicator(void) {
	if (current_layer > NAV) {
		return;
	}
	 led_1_off();
	  if (current_layer == BASE) {
		if (sys_led_state & sys_led_mask_caps_lock) {
		  led_1_on();
		}
		return;
  }
  if (current_layer == NUMPAD) {
    if (!(sys_led_state & sys_led_mask_num_lock)) {
      led_1_on();
    } 
	return;
  }
  if (current_layer == NAV) {
    if (sys_led_state & sys_led_mask_scroll_lock) {
      led_1_on();
    }
	return;
  }
}

void led_set_user(uint8_t usb_led) {
  sys_led_state = usb_led;
	set_indicator();
 }
 
 void breathe(void) {
	 	uint8_t level = abs((timer_read() % 4000)/100 - 20);
		ergodox_led_all_set(level);
 }
 
 void run(uint16_t speed)  {
	uint8_t level = (timer_read() % (4 * speed))/speed ;
	switch (level) {
		case 0:
			led_1_off();
			led_2_off();
			led_3_off();
			break;
		case 1:
			led_1_on();
			led_2_off();
			led_3_off();
			break;
		case 2:
			led_1_off();
			led_2_on();
			led_3_off();
			break;
		case 3:
			led_1_off();
			led_2_off();
			led_3_on();
			break;
		default:
		  break;
	 }
 }
 
 void flash(uint16_t time, uint8_t leds) {
	 uint8_t state = (timer_read() % time) / (time / 2);
	 led_1_off();
	 if (state ==  0) {
		 led_2_off();
		 led_3_off();
		 return;
	 }
	 if (leds & middle_led) {
		 led_2_on();
	 }
	 if (leds & right_led) {
		 led_3_on();
	 }
 }

uint16_t change_time = 0;

void matrix_scan_user(void) {
	if (current_layer == GAME) {
		run(512);
		return;
	}
	if ((current_layer == SYM) && (timer_read()>change_time + 500)) {
		flash(512, right_led);
		return;
	}
	if ((current_layer == SYMPLUS) && (timer_read()>change_time + 500)) {
		flash(512, right_led | middle_led);
		return;
	}
};

uint32_t layer_state_set_user(uint32_t state) {
  current_layer = biton32(state);
  change_time = timer_read();
  	set_indicator();
	led_2_off();
	led_3_off();
  switch (current_layer) {
    case NUMPAD:
      led_3_on();
      break;
    case NAV:
      led_2_on();
	  break;
    case MOUSE:
      led_2_on();
      led_3_on();
      break;
    case FN:
      led_1_on();
	 led_2_on();
      led_3_on();
      break;
    default:
      break;
  }
  return state;
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    if ((keycode == LT(1,KC_A)) || (keycode == LCTL_T(KC_E))) {
      return 190;
    }
    if ((keycode == TD(DANCE_0)) || (keycode == TD(DANCE_1)) || (keycode == TD(DANCE_2))) {
      return 220;
    }
    return TAPPING_TERM;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_C)) SS_DELAY(50) SS_LALT(SS_TAP(X_F4)));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_SPACE)) SS_DELAY(50) SS_TAP(X_N));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_6) ));

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_5) ));

    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_6) ));

    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_7) ));

    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_END) SS_DELAY(50) SS_TAP(X_SCOLON) SS_DELAY(50) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_EQUAL) SS_DELAY(50) SS_TAP(X_EQUAL));

    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_COMMA)) SS_DELAY(50) SS_TAP(X_SLASH));

    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_7) ));

    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_7)) SS_DELAY(50) SS_LSFT(SS_TAP(X_7)));

    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_EQUAL)) SS_DELAY(50) SS_LSFT(SS_TAP(X_EQUAL)) SS_DELAY(50) SS_TAP(X_SCOLON) SS_DELAY(50) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_END) SS_DELAY(50) SS_TAP(X_SPACE) SS_DELAY(50) SS_LSFT(SS_TAP(X_LBRACKET)) SS_DELAY(50) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_9)) SS_DELAY(50) SS_LSFT(SS_TAP(X_0)));

    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_1)) SS_DELAY(50) SS_TAP(X_EQUAL));

    }
    break;
    case ST_MACRO_15:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ENTER) SS_DELAY(50) SS_LSFT(SS_TAP(X_RBRACKET)) SS_DELAY(50) SS_TAP(X_UP));

    }
    break;
    case ST_MACRO_16:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_1) ));

    }
    break;
    case ST_MACRO_17:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_BSLASH)) SS_DELAY(50) SS_LSFT(SS_TAP(X_BSLASH)));

    }
    break;
    case ST_MACRO_18:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_8) ));

    }
    break;
    case ST_MACRO_19:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_EQUAL) SS_DELAY(50) SS_TAP(X_EQUAL) SS_DELAY(50) SS_TAP(X_EQUAL));

    }
    break;
    case ST_MACRO_20:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_9)) SS_DELAY(50) SS_LSFT(SS_TAP(X_0)) SS_DELAY(50) SS_TAP(X_SCOLON) SS_DELAY(50) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_21:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_COMMA)) SS_DELAY(50) SS_TAP(X_EQUAL));

    }
    break;
    case ST_MACRO_22:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(50) SS_TAP(X_EQUAL));

    }
    break;
    case ST_MACRO_23:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_END) SS_DELAY(50) SS_LSFT(SS_TAP(X_HOME)) SS_DELAY(50) SS_TAP(X_DELETE) SS_DELAY(50) SS_TAP(X_DELETE));

    }
    break;
    case ST_MACRO_24:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_DELAY(50) SS_LSFT(SS_TAP(X_LBRACKET)) SS_DELAY(50) SS_LSFT(SS_TAP(X_RBRACKET)) SS_DELAY(50) SS_TAP(X_LEFT) SS_DELAY(50) SS_TAP(X_ENTER) SS_DELAY(50) SS_LCTL(SS_TAP(X_V)) SS_DELAY(50) SS_TAP(X_ENTER) SS_DELAY(50) SS_TAP(X_UP));

    }
    break;
    case ST_MACRO_25:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_DOT) SS_DELAY(50) SS_TAP(X_DOT));
    }
    break;
  }
  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state = {
    .is_press_action = true,
    .step = 0
};

void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_0_dance_step(qk_tap_dance_state_t *state);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
    }
    if(state->count > 3) {
        tap_code16(KC_QUOTE);
    }
}

uint8_t dance_0_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_0_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_QUOTE); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_QUOTE)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_QUOTE)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_QUOTE); register_code16(KC_QUOTE);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_QUOTE); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_QUOTE)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_QUOTE)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_QUOTE); break;
    }
    dance_state.step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_1_dance_step(qk_tap_dance_state_t *state);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
    }
    if(state->count > 3) {
        tap_code16(KC_COMMA);
    }
}

uint8_t dance_1_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_1_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_COMMA); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_COMMA)); break;
        case DOUBLE_TAP: register_code16(KC_SCOLON); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COMMA); register_code16(KC_COMMA);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_COMMA); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_COMMA)); break;
        case DOUBLE_TAP: unregister_code16(KC_SCOLON); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMMA); break;
    }
    dance_state.step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_2_dance_step(qk_tap_dance_state_t *state);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

uint8_t dance_2_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_2_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_DOT)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_SCOLON)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_DOT)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_SCOLON)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state.step = 0;
}
void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_4_dance_step(qk_tap_dance_state_t *state);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(LCTL(LGUI(LSFT(KC_C)))));
        tap_code16(LALT(LCTL(LGUI(LSFT(KC_C)))));
        tap_code16(LALT(LCTL(LGUI(LSFT(KC_C)))));
    }
    if(state->count > 3) {
        tap_code16(LALT(LCTL(LGUI(LSFT(KC_C)))));
    }
}

uint8_t dance_4_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_4_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(LALT(LCTL(LGUI(LSFT(KC_C))))); break;
        case DOUBLE_TAP: register_code16(LALT(LCTL(LGUI(LSFT(KC_A))))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(LCTL(LGUI(LSFT(KC_C))))); register_code16(LALT(LCTL(LGUI(LSFT(KC_C)))));
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(LALT(LCTL(LGUI(LSFT(KC_C))))); break;
        case DOUBLE_TAP: unregister_code16(LALT(LCTL(LGUI(LSFT(KC_A))))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(LCTL(LGUI(LSFT(KC_C))))); break;
    }
    dance_state.step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
};
