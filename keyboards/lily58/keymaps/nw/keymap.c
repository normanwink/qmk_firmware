#include <stdio.h>
#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  TMR = SAFE_RANGE
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
     KC_LSFT, KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,    TMR,              RGB_TOG, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
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

#ifdef OLED_ENABLE

// setup oled
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_270;
  return OLED_ROTATION_0;
}

uint16_t start_time = 0;
uint16_t elapsed_time = 0;
bool timer_running = false;

uint16_t seconds = 0;
uint16_t minutes = 0;
uint16_t hours = 0;

uint8_t mSeconds = 0;
uint8_t mMinutes = 0;
uint8_t mHours = 0;

char sSeconds[24];
char sMinutes[24];
char sHours[24];

void start_timelog(void) {
  seconds = 0;
  minutes = 0;
  hours = 0;

  start_time = timer_read();
}

// loop on oled refresh
void oled_task_user(void) {
  if (is_oled_on()) {
    if (is_keyboard_master()) {
      // master
      oled_write_ln("TIME", false);
      oled_write_ln(" ", false);

      if (timer_running) {
        elapsed_time = timer_elapsed(start_time);
      }

      // weird way of storing seconds to prevent overflow
      // resetting the timer regularily seems more reliable
      if (elapsed_time / 1000 >= 1) {
        start_time = timer_read();
        elapsed_time = elapsed_time % 1000;
        seconds++;
      }

      minutes = seconds / 60;
      hours = minutes / 60;

      mSeconds = seconds % 60;
      mMinutes = minutes % 60;
      mHours = hours % 99;

      sprintf(sSeconds, "%u", mSeconds);
      sprintf(sMinutes, "%u", mMinutes);
      sprintf(sHours, "%u", mHours);

      if (mHours < 10) oled_write(" ", false);
      oled_write(sHours, false);
      oled_write_ln(" h", false);

      if (mMinutes < 10) oled_write(" ", false);
      oled_write(sMinutes, false);
      oled_write_ln(" m", false);

      if (mSeconds < 10) oled_write(" ", false);
      oled_write(sSeconds, false);
      oled_write_ln(" s", false);

      // add space
      oled_write_ln(" ", false);

      if (timer_running) {
        oled_write_ln("STOP ", false);
      } else {
        if (elapsed_time > 1) {
          oled_write_ln("RESET", false);
        } else {
          oled_write_ln("START", false);
        }
      }
    } else {
      // slave
    }
  }
}

void suspend_power_down_user(void) {
  // turn off oled
  oled_off();

  // turn off rgb led
  // and do not save turning off
  // (don't remember state when unplugging)
  rgblight_disable_noeeprom();
}

void suspend_wakeup_init_user(void) {
  // turn on oled
  oled_on();

  // turn on rgb led
  // and do not save turning on
  // (don't remember state when unplugging)
  rgblight_enable_noeeprom();
}

#endif // OLED_ENABLE

#define BACKLIGHT_TIMEOUT 5 // in minutes
static uint16_t idle_timer = 0;
static uint8_t halfmin_counter = 0;
static bool lights_on = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TMR:
      if (record->event.pressed) {
        // when keycode TIMER is pressed
        if (timer_running) {
          timer_running = false;
        } else {
          if (elapsed_time > 1) {
            elapsed_time = 0;
          } else {
            timer_running = true;
            start_timelog();
          }
        }
      } else {
        // when keycode TIMER is released
      }
      break;
  }

  if (record->event.pressed) {
    if (lights_on == false) {
      rgblight_enable_noeeprom();

      #ifdef OLED_ENABLE
        oled_on();
      #endif

      lights_on = true;
    }

    idle_timer = timer_read();
    halfmin_counter = 0;
  }

  return true;
}


#ifdef ENCODER_ENABLE
unsigned long tab_start = 0;
uint8_t mod_state;
bool encoder_update_user(uint8_t index, bool clockwise) {
  mod_state = get_mods();

  // left rotary / slave
  if (index == 0) {
    if (clockwise) {
      // undo
      tap_code16(LGUI(KC_Z));
    } else {
      // redo
      tap_code16(LSFT(LGUI(KC_Z)));
    }
  }

  // right rotary / master
  if (index == 1) {
    // note:
    // on right side, 'clockwise' is actually counterclockwise

    if (layer_state_is(_LOWER)) {
      // up / down
      if (clockwise) {
        tap_code(KC_UP);
      } else {
        tap_code(KC_DOWN);
      }
    } else {
      // left / right
      if (clockwise) {
        tap_code(KC_LEFT);
      } else {
        tap_code(KC_RIGHT);
      }
    }
  }

  return clockwise;
}
#endif // ENCODER_ENABLE

void matrix_scan_user() {
  // if timer is active
  // if (tab_timer) {
  //   // if last encoder click was more than 500ms ago
  //   if (timer_elapsed(tab_start) > 500) {
  //     // release GUI
  //     del_mods(MOD_MASK_GUI);
  //
  //     // prevent code from checking at every iteration
  //     tab_timer = false;
  //   }
  // }

  // idle_timer needs to be set one time
  if (idle_timer == 0) idle_timer = timer_read();

  // count half minutes
  if (lights_on && timer_elapsed(idle_timer) > 30000) {
    halfmin_counter++;
    idle_timer = timer_read();
  }

  if (lights_on && halfmin_counter >= BACKLIGHT_TIMEOUT * 2) {
    rgblight_disable_noeeprom();

    #ifdef OLED_ENABLE
      oled_off();
    #endif

    lights_on = false;
    halfmin_counter = 0;
  }
}
