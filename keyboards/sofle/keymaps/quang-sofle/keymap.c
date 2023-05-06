#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    KC_REDO
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *           | LGUI | LAlt | LCTR |LOWER | / SFTENT /       \RAISE \  | LShift| RCTR | RAlt | RGUI |
 *           |      |      |      |(Space)|/       /         \      \ | (Bspc)|      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  MT(MOD_LCTL | MOD_LSFT, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G,         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
KC_LGUI,KC_LALT,CTL_T(KC_MINUS), LT(_LOWER, KC_SPC), LT(_RAISE, KC_ENT),     MO(_RAISE), MT(MOD_LSFT, KC_BSPC), RCTL_T(KC_EQUAL), TO(_LOWER), TO(_RAISE)
),
/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *           | LGUI | LAlt | LCTR |LOWER  | /SFTENT /       \RAISE \  |LShift | RCTR | RAlt | RGUI |
 *           |      |      |      |(Space)|/       /         \      \ |(Bspc) |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_COLEMAK] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_DEL,
    KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_BSPC,
    MT(MOD_LCTL | MOD_LSFT, KC_ESC), KC_A, KC_R, KC_S, KC_T, KC_G,          KC_M,    KC_N,    KC_E,    KC_I,    KC_O,     KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V, KC_MUTE,     XXXXXXX,KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
KC_LGUI,KC_LALT,CTL_T(KC_MINUS), LT(_LOWER, KC_SPC), LT(_RAISE, KC_ENT),     MO(_RAISE), MT(MOD_RSFT, KC_BSPC), RCTL_T(KC_EQUAL), TO(_LOWER), TO(_RAISE)),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   !  |   @  |   #  |   $  |   %  |                    |   +  |   7  |   8  |   9  |   *  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   &  |   :  |  (   |   {  |   [  |-------.    ,-------|   -  |   4  |   5  |   6  |   /  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|   ^  |   _  |  )   |   }  |   ]  |-------|    |-------|   0  |   1  |   2  |   3  |   \  | F12  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *           | LGUI | LAlt | LCTR |LOWER  | /SFTENT /       \BckSpc\  |RAISE  | RCTR |  .   | TO(0)|
 *           |      |      |      |(Space)|/       /         \      \ |(Enter)|      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,    KC_F7,  KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______,   KC_EXLM, KC_AT,   KC_UNDS, KC_DLR,  KC_PERC,                         KC_PLUS,  KC_7,   KC_8,    KC_9,   KC_ASTR, KC_DEL,
  _______,   KC_AMPR, KC_COLN, KC_LPRN, KC_LCBR, KC_LBRC,                         KC_MINS,  KC_4,   KC_5,    KC_6,   KC_SLSH, KC_PIPE,
  _______,   KC_CIRC, KC_UNDS, KC_RPRN, KC_RCBR, KC_RBRC, _______,       _______, KC_0,     KC_1,   KC_2,    KC_3,   KC_BSLS, KC_F12,
                       _______, _______, _______, _______, _______,       _______, _______, _______, KC_PDOT, TO(0)
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      |En/Vi |Raycast|     |      |                    | PgUp | PWrd |  Up  | NWrd | DWrd | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |      | LCtl |LShift| LAlt | Caps |-------.    ,-------| PgDwn| Left | Down | Rigth|      | Bspc |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste| Redo |-------|    |-------|      | LStr |      | LEnd | DLine| Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *           | LGUI | LAlt | LCTR |LOWER  | /SFTENT /       \BckSpc\  |RAISE  | RCTR | TO(0)|      |
 *           |      |      |      |(Space)|/       /         \      \ |(Enter)|      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, _______ , _______ , _______ ,   _______ , _______,                          _______,     _______,    _______, _______,  _______ ,    _______,
  _______, XXXXXXX, A(KC_SPC), C(KC_SPC),  XXXXXXX,  XXXXXXX,                          A(KC_UP),    KC_PRVWD,   KC_UP,   KC_NXTWD, A(KC_BSPC),  KC_DEL,
  _______, C(KC_A), KC_LCTL,   KC_LSFT,    KC_LALT,  KC_CAPS,                          A(KC_DOWN),  KC_LEFT,    KC_DOWN, KC_RGHT,  XXXXXXX,     KC_BSPC,
  _______, KC_UNDO, KC_CUT,    KC_COPY,    KC_PASTE, KC_REDO,  _______,       _______, KC_DEL,      KC_LSTRT,   XXXXXXX, KC_LEND,  KC_DLINE,    _______,
                           _______, _______, _______, _______, _______,       _______, _______, _______, TO(0), XXXXXXX
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |QK_BOOT|     |QWERTY|COLEMAK|      |      |                   |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *           | LGUI | LAlt | LCTR |LOWER  | /SFTENT /       \BckSpc\  |RAISE  | RCTR | RAlt | RGUI |
 *           |      |      |      |(Space)|/       /         \      \ |(Enter)|      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT  , XXXXXXX,KC_QWERTY,KC_COLEMAK,CG_TOGG,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )
};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
        case KC_REDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL | MOD_LSFT));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL | MOD_LSFT));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_LOWER, KC_SPC):
            return 0;
        default:
            return 125;
    }
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) { 
            tap_code(KC_BRIU);
        } else {
            tap_code(KC_BRID);
        }
    }
    return true;
}

#endif
