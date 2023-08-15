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
#include "muse.h"
#include "features/achordion.h"

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _DWARFQ2,
  _SYMBOL,
  _NUMPAD,
  _NAV,
  _FUN,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DWARFQ2,
  LOWER,
  RAISE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
    KC_GRV,           KC_1,            KC_2,              KC_3,               KC_4,                 KC_5,               KC_6,                 KC_7,                 KC_8,                   KC_9,                 KC_0,             KC_BSPC,
    KC_Q,             KC_W,            KC_E,              KC_R,               KC_T,                 KC_DOWN,            KC_UP,                KC_Y,                 KC_U,                   KC_I,                 KC_O,             KC_P   , 
    CTL_T(KC_A),      ALT_T(KC_S),     SFT_T(KC_D),       GUI_T(KC_F),        KC_G,                 KC_LEFT,            KC_RGHT,              KC_H,                 RGUI_T(KC_J),           RSFT_T(KC_K),         RALT_T(KC_L),     RCTL_T(KC_SCLN),    
    KC_Z,             KC_X,            KC_C,              KC_V,               KC_B,                 KC_MINUS,           KC_EQUAL,             KC_K,                 KC_H,                   KC_COMM,              KC_DOT ,          KC_SLSH, 
    BACKLIT,          MO(_ADJUST),     LT(_FUN, KC_ESC),  LT(_NUMPAD, KC_SPC),LT(_NAV, KC_TAB),     LT(_NAV, KC_ENT),   LT(_NAV, KC_ENT),     LT(_NAV, KC_ENT),     MT(MOD_RSFT, KC_BSPC),  OSL(_SYMBOL),         XXXXXXX,          XXXXXXX
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid(
    KC_GRV,           KC_1,            KC_2,              KC_3,               KC_4,                 KC_5,               KC_6,                 KC_7,                 KC_8,                   KC_9,                 KC_0,             KC_BSPC,
    KC_Q,             KC_W,            KC_F,              KC_P,               KC_B,                 KC_DOWN,            KC_UP,                KC_J,                 KC_L,                   KC_U,                 KC_Y,             KC_COMM, 
    CTL_T(KC_A),      ALT_T(KC_R),     SFT_T(KC_S),       GUI_T(KC_T),        KC_G,                 KC_LEFT,            KC_RGHT,              KC_M,                 RGUI_T(KC_N),           RSFT_T(KC_E),         RALT_T(KC_I),     RCTL_T(KC_O),    
    KC_Z,             KC_X,            KC_C,              KC_D,               KC_V,                 KC_MINUS,           KC_EQUAL,             KC_K,                 KC_H,                   KC_QUOT,              KC_SLSH,          KC_DOT, 
    BACKLIT,          MO(_ADJUST),     LT(_FUN, KC_ESC),  LT(_NUMPAD, KC_SPC),LT(_NAV, KC_TAB),     LT(_NAV, KC_ENT),   LT(_NAV, KC_ENT),     LT(_NAV, KC_ENT),     MT(MOD_RSFT, KC_BSPC),  OSL(_SYMBOL),         XXXXXXX,          XXXXXXX
),

/* Dvorak -> Dwarfq2
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DWARFQ2] = LAYOUT_preonic_grid(
    KC_GRV,           KC_1,            KC_2,              KC_3,               KC_4,                 KC_5,               KC_6,                 KC_7,                 KC_8,                   KC_9,                 KC_0,             KC_BSPC,
    KC_F,             KC_L,            KC_H,              KC_D,               KC_V,                 KC_DOWN,            KC_UP,                KC_Z,                 KC_Y,                   KC_O,                 KC_U,             KC_COMM, 
    CTL_T(KC_S),      ALT_T(KC_R),     SFT_T(KC_N),       GUI_T(KC_T),        KC_M,                 KC_LEFT,            KC_RGHT,              KC_G,                 RGUI_T(KC_C),           RSFT_T(KC_E),         RALT_T(KC_I),     RCTL_T(KC_A),    
    KC_J,             KC_X,            KC_B,              KC_K,               KC_Q,                 KC_MINUS,           KC_EQUAL,             KC_P,                 KC_W,                   KC_QUOT,              KC_SLSH,          KC_DOT, 
    BACKLIT,          MO(_ADJUST),     LT(_FUN, KC_ESC),  LT(_NUMPAD, KC_SPC),LT(_NAV, KC_TAB),     LT(_NAV, KC_ENT),   LT(_NAV, KC_ENT),     LT(_NAV, KC_ENT),     MT(MOD_RSFT, KC_BSPC),  OSL(_SYMBOL),         XXXXXXX,          XXXXXXX
),

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = LAYOUT_preonic_grid(
  KC_TILD, KC_F1,   KC_F2,   KC_F3,     KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8,          KC_F9,          KC_F10,         KC_F11,
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,    KC_PERC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
  KC_AMPR, KC_COLN, KC_LPRN, KC_LCBR,   KC_LBRC,  XXXXXXX, XXXXXXX, XXXXXXX, OSM(MOD_RGUI),  OSM(MOD_RSFT),  OSM(MOD_RALT),  OSM(MOD_RCTL),
  KC_CIRC, KC_BSLS, KC_RPRN, KC_RCBR,   KC_RBRC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
  XXXXXXX, XXXXXXX, TO(0)  , KC_MINUS,  KC_EQUAL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_preonic_grid(
  KC_TILD,        KC_F1,          KC_F2,          KC_F3,          KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX, XXXXXXX, KC_F12,  KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS,
  OSM(MOD_LCTL),  OSM(MOD_LALT),  OSM(MOD_LSFT),  OSM(MOD_LGUI),  XXXXXXX, XXXXXXX, XXXXXXX, KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS,
  XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, KC_0,    KC_1,    KC_2,    KC_3,    KC_EQUAL,
  XXXXXXX,        XXXXXXX,        TO(0)  ,        XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, KC_COMM, KC_BSPC, KC_PDOT, XXXXXXX, XXXXXXX
),

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_preonic_grid(
  _______,        _______,        _______,        _______,        _______,    _______,    _______,    _______,     _______,     _______,     _______,    _______,
  XXXXXXX,        G(KC_W),        XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    A(KC_UP),    A(KC_LEFT),  KC_UP,       A(KC_RGHT), A(KC_BSPC),
  OSM(MOD_LCTL),  OSM(MOD_LALT),  OSM(MOD_LSFT),  OSM(MOD_LGUI),  KC_CAPS,    XXXXXXX,    XXXXXXX,    A(KC_DOWN),  KC_LEFT,     KC_DOWN,     KC_RGHT,    XXXXXXX,
  G(KC_Z),        G(KC_X),        G(KC_C),        G(KC_V),        LSG(KC_Z),  XXXXXXX,    XXXXXXX,    KC_DEL,      G(KC_LEFT),  G(KC_A),     G(KC_RGHT), G(KC_BSPC),
  XXXXXXX,        XXXXXXX,        TO(0)  ,        XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,     KC_BSPC,     XXXXXXX,     XXXXXXX,    XXXXXXX
),

/* Functions
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_FUN] = LAYOUT_preonic_grid(
  _______,        _______,        _______,        _______,        _______,    _______,    _______,    _______,    _______,    _______,   _______,   _______,
  XXXXXXX,        XXXXXXX,        XXXXXXX,        LSG(KC_4),      LSG(KC_5),  KC_VOLD,    KC_VOLU,    KC_F12,     KC_F7,      KC_F8,     KC_F9,     A(KC_BSPC),
  OSM(MOD_LCTL),  OSM(MOD_LALT),  OSM(MOD_LSFT),  OSM(MOD_LGUI),  KC_CAPS,    KC_MUTE,    KC_MPLY,    KC_F11,     KC_F4,      KC_F5,     KC_F6,     XXXXXXX,
  G(KC_Z),        G(KC_X),        G(KC_C),        G(KC_V),        LSG(KC_Z),  KC_BRMD,    KC_BRMU,    KC_F10,     KC_F1,      KC_F2,     KC_F3,     G(KC_BSPC),
  XXXXXXX,        XXXXXXX,        TO(0)  ,        XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_BSPC,    XXXXXXX,   XXXXXXX,   XXXXXXX
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  AU_ON,   AU_NEXT, MU_ON  , MU_NEXT, MI_ON,   _______, _______, QK_BOOT, DB_TOGG, _______, _______, _______,
  AU_OFF , AU_PREV, MU_OFF , _______, MI_OFF,  _______, _______, CG_NORM, CG_SWAP, _______, _______, _______,
  COLEMAK, DWARFQ2, QWERTY , _______, _______, _______, _______, _______, _______, _______, _______, _______, 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case DWARFQ2:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DWARFQ2);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_NUMPAD);
            update_tri_layer(_NUMPAD, _NAV, _ADJUST);
          } else {
            layer_off(_NUMPAD);
            update_tri_layer(_NUMPAD, _NAV, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_NAV);
            update_tri_layer(_NUMPAD, _NAV, _ADJUST);
          } else {
            layer_off(_NAV);
            update_tri_layer(_NUMPAD, _NAV, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      };
  if (!process_achordion(keycode, record)) { 
    return false; 
  }
  return true;
};

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NUMPAD, KC_SPC):
            return 0;
        default:
            return 125;
    }
}

bool achordion_eager_mod(uint8_t mod) {
  switch (mod) {
    case MOD_LSFT:
    case MOD_RSFT:
    case MOD_LCTL:
    case MOD_RCTL:
      return true;  // Eagerly apply Shift and Ctrl mods.

    default:
      return false;
  }
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // Also allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
  if (other_record->event.key.row >= 4) { return true; }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_NAV)) {
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
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
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
  achordion_task();
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
