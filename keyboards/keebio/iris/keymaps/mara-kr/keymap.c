// TODO: What does tapping the encoder do while scrolling?
// TODO: Better lighting editing! Trans pride pattern moving across the board?
#include QMK_KEYBOARD_H

// Tap dance enums
enum {
	CPPS,
};


// Layer defines
#define _COLEMAK_DHM 0
#define _NUMPAD 1
#define _ARROWS 2
#define _MOUSE 3

enum custom_keycodes {
  COLEMAK_DHM = SAFE_RANGE,
  NUMPAD,
  ARROWS,
  MOUSE,
};

typedef enum {
	TD_NONE,
	TD_UNKNOWN,
	TD_SINGLE_TAP,
	TD_SINGLE_HOLD,
	TD_DOUBLE_TAP
} td_state_t;

typedef struct {
	bool is_press_action;
	td_state_t state;
} td_tap_t;

td_state_t cur_dance(qk_tap_dance_state_t *state);
void c_finished(qk_tap_dance_state_t *state, void *user_data);
void c_reset(qk_tap_dance_state_t *state, void *user_data);

// Keycode macros
#define LT_SPCE LT(_ARROWS, KC_SPC)
#define LT_ESC  LT(_MOUSE, KC_ESC)
#define MO_NUM  MO(_NUMPAD)

#define LAUNCH  LGUI(KC_SPC)
#define COPY_PW LALT(LGUI(KC_C))
#define ADD_TSK LCTL(LGUI(KC_A))
#define LOCK    LCTL(LGUI(KC_Q))
#define BREAK   LCTL(LGUI(KC_W))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK_DHM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       BREAK, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     LT_ESC,   KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                              KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,       KC_C,   KC_D,   KC_V,    KC_B,            LT_SPCE,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI,  MO_NUM,  KC_BSPC,                  LT_SPCE, KC_LCTL,  LAUNCH
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUMPAD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______,  _______,                           _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     LOCK,    _______, KC_TILD, KC_LCBR, KC_RCBR, KC_UNDS,                            KC_MINS,    KC_7,    KC_8,    KC_9, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______,  KC_GRV, KC_LPRN, KC_RPRN,  KC_EQL,                            KC_PLUS,    KC_4,    KC_5,    KC_6,    KC_0, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, ADD_TSK,   KC_F3, KC_LBRC, KC_RBRC, COPY_PW, KC_MPLY,          KC_ENT,  _______,    KC_1,    KC_2,    KC_3, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                    KC_ENT, TD(CPPS), _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ARROWS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,	                          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, KC_LCTL, KC_LSFT, _______,                            KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, G(KC_W),          _______, _______, _______,  _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______,   RESET,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, KC_MS_U, _______, _______,                            _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                            _______, KC_BTN1, KC_BTN2, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )

  /* [_MOUSE] = LAYOUT( */
  /* //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐ */
  /*    _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, */
  /* //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘ */
  /*                                   _______, _______, _______,                   _______, _______, _______ */
  /*                               // └────────┴────────┴────────┘                 └────────┴────────┴────────┘ */
  /* ) */
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK_DHM:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK_DHM);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        layer_on(_NUMPAD);
        update_tri_layer(_NUMPAD, _ARROWS, _MOUSE);
      } else {
        layer_off(_NUMPAD);
        update_tri_layer(_NUMPAD, _ARROWS, _MOUSE);
      }
      return false;
      break;
    case ARROWS:
      if (record->event.pressed) {
        layer_on(_ARROWS);
        update_tri_layer(_NUMPAD, _ARROWS, _MOUSE);
      } else {
        layer_off(_ARROWS);
        update_tri_layer(_NUMPAD, _ARROWS, _MOUSE);
      }
      return false;
      break;
    case MOUSE:
      if (record->event.pressed) {
        layer_on(_MOUSE);
      } else {
        layer_off(_MOUSE);
      }
      return false;
      break;
  }
  return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
	if (IS_LAYER_ON(_NUMPAD)) {
		if (clockwise) {
			tap_code(KC_VOLU);
		} else {
			tap_code(KC_VOLD);
		}
	} else if (IS_LAYER_ON(_ARROWS)) {
		if (clockwise) {
			tap_code16(C(KC_TAB));
		} else {
			tap_code16(C(S(KC_TAB)));
		}
	} else {
        if (clockwise) {
            tap_code(KC_WH_U);
        } else {
            tap_code(KC_WH_D);
        }
    }
    return true;
}

// Determine the current tap dance state
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }
	else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}
// Initialize tap structure associated with example tap dance key
static td_tap_t cpps_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void cpps_finished(qk_tap_dance_state_t *state, void *user_data) {
    cpps_tap_state.state = cur_dance(state);
    switch (cpps_tap_state.state) {
        case TD_SINGLE_TAP:
			tap_code16(G(KC_C));
            break;
        case TD_SINGLE_HOLD:
			tap_code16(G(KC_V));
            break;
        default:
            break;
    }
}

void cpps_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    /* if (cpps_tap_state.state == TD_SINGLE_HOLD) { */
    /*     layer_off(_MY_LAYER); */
    /* } */
    cpps_tap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
	[CPPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, cpps_finished, cpps_reset)
};

/*
Past issues:
- Tab was sending shift and escape, I think that the pins for the tab key were
  shorted, but swapping the switch fixed the issue.
*/
