/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H


enum planck_layers {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  COLEMAK = SAFE_RANGE,
  BACKLIT,
  EXT_PLV
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define SP_RAIS LT(_RAISE, KC_SPC)
#define BS_LOWR LT(_LOWER, KC_BSPC)
#define ESC_CMD MT(MOD_LGUI, KC_ESC)
#define QUO_CTL MT(MOD_LCTL, KC_QUOT)

#define COPY_PW LALT(LGUI(KC_C))
#define ADD_TSK LCTL(LGUI(KC_A))
#define LOCK    LCTL(LGUI(KC_Q))
#define BREAK   LCTL(LGUI(KC_W))
#define VOL_DN KC_KB_VOLUME_DOWN
#define VOL_UP KC_KB_VOLUME_UP

#define WIN_R   LCTL(LGUI(KC_RGHT))
#define WIN_L   LCTL(LGUI(KC_LEFT))
#define WIN_U   LCTL(LGUI(KC_UP))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Alt  | Cmd  | LOWER|    space    |  BS  | Ctrl | F6   |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    // F6 used for spotlight, tap-hold on bs works as continuously sending BS
    // NOTE: Maybe a rotary encoder in top right spot (bottom's covered by hands when typing)
    //       Encoder for volume up/down/mute, tab switching; or just add controls for tab switching
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
    ESC_CMD, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    QUO_CTL,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    _______, _______, KC_LALT, KC_LGUI, LOWER,SP_RAIS, SP_RAIS, KC_BSPC,    KC_LCTL,  KC_F6, _______,  _______
),
#define ESC_CMD MT(MOD_LGUI, KC_ESC)
#define QUO_CTL MT(MOD_LCTL, KC_QUOT)

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | LOCK |  F4  |   ~  |   [  |   ]  |   _  |   -  |   7  |   8  |   9  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F3  |   `  |   (  |   )  |   =  |   +  |   4  |   5  |   6  |   0  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  F5  |   {  |   }  |  PW  |      |   1  |   2  |   3  |      |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Enter    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
// F3/F4 used for otter speed/slow, F5 used for Misson Control
[_LOWER] = LAYOUT_planck_grid(
    LOCK,    KC_F4,   KC_TILD, KC_LCBR, KC_RCBR, KC_UNDS, KC_MINS,    KC_7,      KC_8,     KC_9, _______, _______,
    _______, KC_F3,    KC_GRV, KC_LPRN, KC_RPRN,  KC_EQL, KC_PLUS,    KC_4,      KC_5,     KC_6,    KC_0, KC_PIPE,
    _______, ADD_TSK,   KC_F5, KC_LBRC, KC_RBRC, COPY_PW, _______,    KC_1,      KC_2,     KC_3, _______, KC_BSLS,
    _______, _______, _______, _______, _______, _______,  KC_ENT,  KC_ENT,   KC_BRMD,  KC_BRMU,  VOL_DN,  VOL_UP
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Ctrl | shift|      |      | Left |  Up  | Right| Down |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |Gui+L |Gui+U |Gui+R |      |      |      |      | PgUp | PgDn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Vol- | Vol+ |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______,  KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_BSPC,
    _______,  _______, _______, KC_LCTL, KC_LSFT, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,  _______,
    _______,  _______,   WIN_L,   WIN_U,   WIN_R, _______, _______, KC_PGDN, KC_PGUP, _______, _______,  _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______
),


/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    // NOTE: Used to be able to swap to QWERTY here
    // NOTE: Currently speaker is unattached, so most of these won't apply
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______,
    _______, _______, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, COLEMAK, _______, _______,  _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

