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

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

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

#define COPY_PW LALT(LGUI(KC_C))
#define ADD_TSK LCTL(LGUI(KC_A))
#define LOCK    LCTL(LGUI(KC_Q))
#define BREAK   LCTL(LGUI(KC_W))

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
 * |      |      | Alt  | Cmd  |  BS  |    space    | Ctrl | F6   |   -  |   +  |      |
 * `-----------------------------------------------------------------------------------'
 */
    // F6 used for spotlight
    // TODO: Try for a bit, maybe a rotary encoder in one of the bottom spots
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    _______, _______, KC_LALT, KC_LGUI, BS_LOWR, SP_RAIS, SP_RAIS, KC_LCTL, KC_F6, _______,  _______, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | LOCK |  F4  |   ~  |   [  |   ]  |   _  |   -  |   7  |   8  |   9  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F3  |   `  |   (  |   )  |   =  |   +  |   4  |   5  |   6  |   0  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  F5  |   {  |   }  |  PW  |      |   1  |   2  |   3  |      |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |  Enter      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
// F3/F4 used for otter speed/slow, F5 used for Misson Control
[_LOWER] = LAYOUT_planck_grid(
    LOCK,    KC_F4,   KC_TILD, KC_LCBR, KC_RCBR, KC_UNDS, KC_MINS,    KC_7,      KC_8,     KC_9, _______, _______,
    _______, KC_F3,    KC_GRV, KC_LPRN, KC_RPRN,  KC_EQL, KC_PLUS,    KC_4,      KC_5,     KC_6,    KC_0, KC_PIPE,
    _______, ADD_TSK,   KC_F5, KC_LBRC, KC_RBRC, COPY_PW,  KC_F12,    KC_1,      KC_2,     KC_3, _______, KC_BSLS,
    _______, _______, _______, _______, _______, _______,  KC_ENT,  KC_ENT,   _______,  _______, _______, _______
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
    _______,  _______,   WIN_L,   WIN_U,   WIN_R, _______, _______, _______, _______, _______, _______,  _______,
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

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

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

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
