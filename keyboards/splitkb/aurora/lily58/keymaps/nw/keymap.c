/* Copyright 2025 Norman Wink <mail@normanwink.com>
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

enum layers {
    _DEF = 0,
    _LOWER,
    _RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Default
 * | ESC | 1 | 2 | 3 | 4 | 5 |                 | 6 | 7 | 8 | 9 | 0 | ` |
 * | TAB | Q | W | E | R | T |                 | Z | U | I | O | P | \ |
 * |CTRL | A | S | D | F | G |                 | H | J | K | L | ; | ' |
 * |SHFT | Y | X | C | V | B |  [  |  ]        | N | M | , | . | / |SHF|
 *                  | BSPC | GUI |LOWER| SPC | ENTER |RAISE| RALT| DEL |
 */
[_DEF] = LAYOUT(
    KC_ESC,  KC_1,   KC_2,   KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_TAB,  KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                      KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_LCTL, KC_A,   KC_S,   KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Y,   KC_X,   KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMMA,KC_DOT,  KC_SLSH, KC_RSFT,
                         KC_BSPC, KC_LGUI, MO(_LOWER), KC_SPC,  KC_ENT,   MO(_RAISE), KC_RALT, KC_DEL
),

/* Lower
 * | ~ | ! | @ | # | $ | % |                      | ^ | & | * | ( | ) | PgUp |
 * |   | 1 | 2 | 3 | 4 | 5 |                      | 6 | 7 | 8 | 9 | 0 | PgDn |
 * |Del|   | <-| ->| Up| [ |                      | ] |   |   |   | + | Home |
 * |   |   |   |   | Dn| { |   |                  | } |   |   |   | - | End  |
 *                   |    | ALT |     | Del | Del |     |     |     |
 */
[_LOWER] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PGUP,
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PGDN,
    KC_DEL,  KC_TRNS, KC_LEFT, KC_RGHT, KC_UP,   KC_LBRC,                   KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_PLUS, KC_HOME,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DOWN, KC_LCBR, KC_TRNS, KC_TRNS, KC_RCBR, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_END,
                          KC_TRNS, KC_LALT, KC_TRNS, KC_DEL, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS
),

/* Raise
 * | F12| F1| F2| F3| F4| F5|                     | F6| F7| F8| F9| F10| F11 |
 * |    | ! | @ | # | $ | % |                     | ^ | & | * | ( | ) | `   |
 * |    |Prev|Next|Vol+|PgUp| _ |                  | = |Home|   |   |   |    |
 * |Mute|Stop|Play|Vol-|PgDn| KP-|  |              | KP+| End|  |   |   |    |
 *                    |     |     |     |     |    |     |     |     |
 */
[_RAISE] = LAYOUT(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_F5,                    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,    KC_PERC,                  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV,
    KC_TRNS, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP,   KC_UNDS,                  KC_EQL,  KC_HOME, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN,   KC_KP_MINUS, KC_TRNS, KC_TRNS, KC_KP_PLUS, KC_END,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS
),
};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(HSV_RED);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    const uint8_t layer = get_highest_layer(layer_state);
    if (index == 0) {
        // Undo / Redo (Cmd+Z, Cmd+Shift+Z)
        if (clockwise) {
            tap_code16(LGUI(LSFT(KC_Z))); // Redo
        } else {
            tap_code16(LGUI(KC_Z));       // Undo
        }
        return false;
    }
    // Right encoder: arrows (Left/Right on Default; Up/Down on Lower/Raise)
    if (layer == _LOWER || layer == _RAISE) {
        tap_code(clockwise ? KC_UP : KC_DOWN);
    } else {
        tap_code(clockwise ? KC_RGHT : KC_LEFT);
    }
    return false;
}
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    static const char PROGMEM text[] =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789!@#$%^&*()[]{}-=_+?";
    oled_write_P(text, false);
    return false;
}
#endif

