#include QMK_KEYBOARD_H

// #include "doge_dance.c"

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  CMD_H = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,    CMD_H,            RGB_TOG, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                          KC_BSPC,  KC_LGUI, MO(_LOWER), KC_SPC,                  KC_ENT, MO(_RAISE), KC_RALT, KC_DEL
                       // └────────┴────────┴────────┴────────┘                 └────────┴────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PGUP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RESET,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PGDN,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  _______, KC_LEFT, KC_RGHT, KC_UP,   KC_LBRC,                            KC_RBRC, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_HOME,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     BL_STEP, _______, _______, _______, KC_DOWN, KC_LCBR, _______,          _______, KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_MINS, KC_END,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                           _______,  _______, _______, KC_DEL,                    KC_DEL, _______, KC_P0,   _______
                       // └────────┴────────┴────────┴────────┘                 └────────┴────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, _______,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                           _______, _______, _______, _______,                   _______, _______, _______, _______
                       // └────────┴────────┴────────┴────────┘                 └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                           _______, _______, _______, _______,                   _______, _______, _______, _______
                       // └────────┴────────┴────────┴────────┘                 └────────┴────────┴────────┴────────┘
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  // no rotation on slave, 270 degrees on master
  if (!is_keyboard_master())
    return OLED_ROTATION_0;
  return OLED_ROTATION_270;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *nw_test(void);
// const char *read_logo(void);
// void set_keylog(uint16_t keycode, keyrecord_t *record);
// const char *read_keylog(void);
// const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

// static uint16_t oled_timer = 0;

// void render_animation(uint8_t frame) {
//     oled_write_raw_P(animation[frame], sizeof(animation[frame]));
// }

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(nw_test(), false);

    // oled_write_ln(read_layer_state(), false);
    // oled_write_ln(read_keylog(), false);
    // oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
    // oled_write(read_logo(), false);
  } else {
    // if (is_oled_on()) {
    //   render_animation((timer_read() / 200) % 6);
    // }

    oled_write_ln(nw_test(), false);

    // oled_write(read_logo(), false);
  }
}

void suspend_power_down_user(void) {
  oled_off();
}

void suspend_wakeup_init_user(void) {
  oled_on();
}

#endif // OLED_ENABLE

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
// #ifdef OLED_ENABLE
//     set_keylog(keycode, record);
// #endif
//     // set_timelog();
//   }
//   return true;
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CMD_H:
    if (record->event.pressed) {
      // when keycode CMD_H is pressed
      tap_code16(LGUI(KC_H));
    } else {
      // when keycode CMD_H is released
    }
    break;
  }
  return true;
}

bool tab_timer = false;
unsigned long tab_start = 0;
uint8_t mod_state;
bool encoder_update_user(uint8_t index, bool clockwise) {
  mod_state = get_mods();

  #ifdef ENCODER_ENABLE
    // left rotary / slave
    if (index == 0) {
      // if on upper layer
      if (layer_state_is(_RAISE)) {
        // set start time to know when to release
        // reset start time to current time with every encoder click
        tab_start = timer_read();

        // let global code know to start tab timer
        tab_timer = true;

        // hold GUI
        add_mods(MOD_MASK_GUI);

        if (clockwise) {
          // shift + tab
          tap_code16(LSFT(KC_TAB));
        } else {
          // tab
          tap_code(KC_TAB);
        }

        // GUI release will be handled by matrix_scan_user()
      } else {
        if (clockwise) {
          // undo
          tap_code16(LGUI(KC_Z));
        } else {
          // redo
          tap_code16(LSFT(LGUI(KC_Z)));
        }
      }
    }

    // right rotary / master
    if (index == 1) {
      // note:
      // on right side, clockwise is actually counterclockwise

      // if shift is pressed
      if (mod_state & MOD_MASK_SHIFT) {
        // First temporarily canceling both shifts so that
        // shift isn't applied to the arrow keycode
        del_mods(MOD_MASK_SHIFT);

        // up / down
        if (clockwise) {
          tap_code(KC_UP);
        } else {
          tap_code(KC_DOWN);
        }

        // Reapplying modifier state so that the held shift key(s)
        set_mods(mod_state);
      } else {
        // left / right
        if (clockwise) {
          tap_code(KC_LEFT);
        } else {
          tap_code(KC_RIGHT);
        }
      }

    }
  #endif // ENCODER_ENABLE

  return clockwise;
}

void matrix_scan_user() {
  // if timer is active
  if (tab_timer) {
    // if last encoder click was more than 500ms ago
    if (timer_read() - tab_timer > 500) {
      // release GUI
      del_mods(MOD_MASK_GUI);

      // prevent code from checking at every iteration
      tab_timer = false;
    }
  }
}
