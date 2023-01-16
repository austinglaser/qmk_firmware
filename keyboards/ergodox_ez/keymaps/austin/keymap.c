#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN,
};

enum layers {
  BASE = 0,
  BASE_FUNCTION,
  GAMING,
  GAMING_FUNCTION,
  LAYER_COUNT
};

#define LAYOUT_FUNCTION LAYOUT_ergodox(                                \
      _______, KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,    _______, \
      _______, _______, _______,  _______, _______, _______,  _______, \
      _______, _______, _______,  _______, _______, _______,           \
      _______, _______, _______,  _______, _______, _______,  _______, \
      _______, _______, _______,  _______, _______,                    \
                                                                       \
                                                    _______,  _______, \
                                                              _______, \
                                            _______, _______, _______, \
                                                                       \
      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,   \
      _______, _______, _______, _______, _______,  _______, _______,  \
               KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,  \
      _______, _______, _______, _______, _______,  _______, _______,  \
                        _______, _______, _______,  _______, _______,  \
                                                                       \
      _______, _______,                                                \
      _______,                                                         \
      _______, _______, _______                                        \
  )

const uint16_t PROGMEM keymaps[LAYER_COUNT][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ergodox(
      KC_GRAVE,         KC_1,    KC_2,     KC_3,    KC_4,       KC_5,  TO(GAMING),
      KC_TAB,           KC_Q,    KC_W,     KC_E,    KC_R,       KC_T,  _______,
      CTL_T(KC_ESCAPE), KC_A,    KC_S,     KC_D,    KC_F,       KC_G,
      KC_LEFT_SHIFT,    KC_Z,    KC_X,     KC_C,    KC_V,       KC_B,  _______,
      _______,          _______, _______,  KC_MEH,  MO(BASE_FUNCTION),

                                                              _______, _______,
                                                                       _______,
                                           GUI_T(KC_NO), KC_BACKSPACE, _______,

      KC_6,             KC_7, KC_8,    KC_9,     KC_0,    KC_MINUS,     KC_EQUAL,
      KC_LEFT_BRACKET,  KC_Y, KC_U,    KC_I,     KC_O,    KC_P,         KC_BACKSLASH,
                        KC_H, KC_J,    KC_K,     KC_L,    KC_SEMICOLON, KC_QUOTE,
      KC_RIGHT_BRACKET, KC_N, KC_M,    KC_COMMA, KC_DOT,  KC_SLASH,     KC_RIGHT_SHIFT,
                         _______, _______,  _______, _______,   KC_RCTL,

      _______, _______,
      _______,
      _______, KC_ENTER, KC_SPACE
  ),

  [BASE_FUNCTION] = LAYOUT_FUNCTION,

  [GAMING] = LAYOUT_ergodox(
      KC_GRAVE,         KC_1,    KC_2,     KC_3,    KC_4,       KC_5,  TO(BASE),
      KC_TAB,           KC_Q,    KC_W,     KC_E,    KC_R,       KC_T,  _______,
      CTL_T(KC_ESCAPE), KC_A,    KC_S,     KC_D,    KC_F,       KC_G,
      KC_LEFT_SHIFT,    KC_Z,    KC_X,     KC_C,    KC_V,       KC_B,  _______,
      _______,          _______, _______,  KC_MEH,  MO(GAMING_FUNCTION),

                                                              _______, _______,
                                                                       _______,
                                               KC_SPACE, KC_BACKSPACE, _______,

      KC_6,             KC_7, KC_8,    KC_9,     KC_0,    KC_MINUS,     KC_EQUAL,
      KC_LEFT_BRACKET,  KC_Y, KC_U,    KC_I,     KC_O,    KC_P,         KC_BACKSLASH,
                        KC_H, KC_J,    KC_K,     KC_L,    KC_SEMICOLON, KC_QUOTE,
      KC_RIGHT_BRACKET, KC_N, KC_M,    KC_COMMA, KC_DOT,  KC_SLASH,     KC_RIGHT_SHIFT,
                         _______, _______,  _______, _______,   KC_RCTL,

      _______, _______,
      _______,
      _______, KC_ENTER, KC_SPACE
  ),

  [GAMING_FUNCTION] = LAYOUT_FUNCTION,
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }
    return state;

};
