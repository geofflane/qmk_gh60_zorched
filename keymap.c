#include "gh60.h"
#include "action_layer.h"

#define _BL 0
#define _AL 1
#define _FL 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /*
   *  Base layer, pretty standard ANSI layout.
   * ,-----------------------------------------------------------.
   * |F(12)| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
   * |-----------------------------------------------------------|
   * |Caps/Fn|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Alt |Gui |      Space             |Alt |Fn  |Menu|Ctrl|
   * `-----------------------------------------------------------'
   */
  [_BL] = LAYOUT(
        F(3),KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINS,KC_EQL,KC_BSPC, \
        KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_LBRC,KC_RBRC,KC_BSLS, \
        F(2),KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,KC_NO,KC_ENT,  \
        KC_LSFT,KC_NO,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_NO,KC_RSFT, \
        KC_LCTL,KC_LGUI,KC_LALT,        KC_SPC,      KC_NO,KC_RALT,F(0),KC_APP,KC_RCTL),

   /*
   * Locking arrow keys to WASD for when you need dedicated arrow keys
   * ,-----------------------------------------------------------.
   * |    |  |   |   |   |   |   |   |   |   |   |   |   |       |
   * |-----------------------------------------------------------|
   * |     |   |Up |   |   |   |   |   |   |   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |       |Left|Down|Rght|   |   |   |   |   |   |   |   |    |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
  [_AL] = LAYOUT(
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, \
        KC_TRNS,KC_TRNS,KC_UP,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, \
        KC_TRNS,KC_LEFT,KC_DOWN,KC_RGHT,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, \
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,   \
        KC_TRNS,KC_TRNS,KC_TRNS,          KC_TRNS,               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS),


   /*
   * Primary function layer, mostly the same as the traditional Pok3r layout.
   * ,-------------------------------------------------------------.
   * |`~ | F1| F2| F3| F4| F5| F6| F7| F8| F9| F10| F11| F12|DEL   |
   * |-------------------------------------------------------------|
   * |    |_AL|Up |Mu |Vup|Vdn|Pl|  |PgUp|PgDn|Ptscn|Srlck|Pause|  |
   * |-------------------------------------------------------------|
   * |      |Left|Down|Right|  |  |Left|Down| Up |Rght|Ins|  |     |
   * |-------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |Home| End |   |         |
   * |-------------------------------------------------------------|
   * |    |    |    |                          |    |    |    |    |
   * `-------------------------------------------------------------'
   */
  [_FL] = LAYOUT(
        KC_GRAVE,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12,KC_DELETE, \
        KC_TRNS,F(1),KC_UP,KC_MUTE,KC__VOLDOWN,KC__VOLUP,KC_MPLY,KC_TRNS,KC_PGUP,KC_PGDN,KC_PSCR,KC_SLCK,KC_PAUS,KC_TRNS, \
        KC_TRNS,KC_LEFT,KC_DOWN,KC_RIGHT,KC_TRNS,KC_TRNS,KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,KC_INS,KC_TRNS,KC_TRNS,KC_TRNS, \
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_HOME,KC_END,KC_TRNS,KC_TRNS,KC_TRNS, \
        KC_TRNS,KC_TRNS,KC_TRNS,          KC_TRNS,               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS),
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(2),  // Momentary Fn overlay
    [1] = ACTION_LAYER_TOGGLE(1),     // Toggle Arrow Layer overlay
    [2] = ACTION_LAYER_TAP_KEY(2, KC_CAPS), // Tap to toggle caps lock and hold to activate function layer
    [3] = ACTION_FUNCTION(SHIFT_ESC),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};

void matrix_scan_user(void) {

// Layer LED indicators
// ESC led on when in function layer, WASD cluster leds enabled when on arrow cluster
    uint32_t layer = layer_state;
    if (layer & (1<<1)) {
        gh60_wasd_leds_on();
    } else {
        gh60_wasd_leds_off();
    }

    if (layer & (1<<2)) {
        gh60_esc_led_on();
    } else {
        gh60_esc_led_off();
    }
};

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    static uint8_t shift_esc_shift_mask;
    // Shift + ESC = ~
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
    }
};
