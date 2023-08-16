#include QMK_KEYBOARD_H
#include "features/achordion.h"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK,
    _DWARFQ2,
    _LOWER,
    _RAISE,
    _NAV,
    _NUMPAD,
    _SYMBOL,
    _FUN,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_DWARFQ2,
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
    KC_GRV,         KC_1,               KC_2,                   KC_3,                  KC_4,            KC_5,                           KC_6,                 KC_7,                     KC_8,           KC_9,           KC_0,               KC_BSPC,
    KC_TAB,         KC_Q,               KC_W,                   KC_E,                  KC_R,            KC_T,                           KC_Y,                 KC_U,                     KC_I,           KC_O,           KC_P,               KC_DEL,
    KC_ESC,         CTL_T(KC_A),        ALT_T(KC_S),            SFT_T(KC_D),           GUI_T(KC_F),     KC_G,                           KC_H,                 RGUI_T(KC_J),             RSFT_T(KC_K),   RALT_T(KC_L),   RCTL_T(KC_SCLN),    KC_QUOT,
    KC_LSFT,        KC_Z,               KC_X,                   KC_C,                  KC_V,            KC_B,   KC_MUTE,    KC_MPLY,    KC_N,                 KC_M,                     KC_COMM,        KC_DOT,         KC_SLSH,            KC_RSFT,
    MO(_ADJUST),    LT(_FUN, KC_ESC),   LT(_NUMPAD, KC_SPC),    LT(_LOWER, KC_SPC),    LT(_NAV, KC_ENT),                                LT(_NAV, KC_ENT),     MT(MOD_RSFT, KC_BSPC),    OSL(_SYMBOL),   XXXXXXX,        XXXXXXX
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
    KC_GRV,         KC_1,               KC_2,                   KC_3,                  KC_4,            KC_5,                           KC_6,                 KC_7,                     KC_8,           KC_9,           KC_0,           KC_BSPC,
    KC_TAB,         KC_Q,               KC_W,                   KC_F,                  KC_P,            KC_B,                           KC_J,                 KC_L,                     KC_U,           KC_Y,           KC_COMM,        KC_DEL,
    KC_ESC,         CTL_T(KC_A),        ALT_T(KC_R),            SFT_T(KC_S),           GUI_T(KC_T),      KC_G,                           KC_M,                 RGUI_T(KC_N),             RSFT_T(KC_E),   RALT_T(KC_I),   RCTL_T(KC_O),   KC_SCLN,
    KC_LSFT,        KC_Z,               KC_X,                   KC_C,                  KC_D,            KC_V,   KC_MUTE,    KC_MPLY,    KC_K,                 KC_H,                     KC_QUOT,        KC_SLSH,        KC_DOT,         KC_RSFT,
    MO(_ADJUST),    LT(_FUN, KC_ESC),   LT(_NUMPAD, KC_SPC),    LT(_LOWER, KC_SPC),    LT(_NAV, KC_ENT),                                LT(_NAV, KC_ENT),     MT(MOD_RSFT, KC_BSPC),    OSL(_SYMBOL),   XXXXXXX,        XXXXXXX
),
/*
 * SEMIMAK
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

[_DWARFQ2] = LAYOUT(
    KC_GRV,         KC_1,               KC_2,                   KC_3,                  KC_4,            KC_5,                           KC_6,                 KC_7,                     KC_8,           KC_9,           KC_0,           KC_BSPC,
    KC_TAB,         KC_F,               KC_L,                   KC_H,                  KC_D,            KC_V,                           KC_Z,                 KC_Y,                     KC_O,           KC_U,           KC_COMM,        KC_DEL,
    KC_ESC,         CTL_T(KC_S),        ALT_T(KC_R),            SFT_T(KC_S),           GUI_T(KC_T),      KC_M,                           KC_G,                 RGUI_T(KC_N),             RSFT_T(KC_E),   RALT_T(KC_I),   RCTL_T(KC_A),   KC_SCLN,
    KC_LSFT,        KC_J,               KC_X,                   KC_B,                  KC_K,            KC_Q,   KC_MUTE,    KC_MPLY,    KC_P,                 KC_W,                     KC_QUOT,        KC_SLSH,        KC_DOT,         KC_RSFT,
    MO(_ADJUST),    LT(_FUN, KC_ESC),   LT(_NUMPAD, KC_SPC),    LT(_LOWER, KC_SPC),    LT(_NAV, KC_ENT),                                LT(_NAV, KC_ENT),     MT(MOD_RSFT, KC_BSPC),    OSL(_SYMBOL),   XXXXXXX,        XXXXXXX
),

/* SYMBOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   !  |   @  |   #  |   $  |   %  |                    |   +  |   7  |   8  |   9  |   *  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   &  |   :  |  (   |   {  |   [  |-------.    ,-------|   -  |   4  |   5  |   6  |   /  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|   ^  |   \  |  )   |   }  |   ]  |-------|    |-------|   0  |   1  |   2  |   3  |   \  | F12  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *           | LGUI | LAlt | LCTR |LOWER  | /SFTENT /       \BckSpc\  |RAISE  | RCTR |  .   | TO(0)|
 *           |      |      |      |(Space)|/       /         \      \ |(Enter)|      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */
[_SYMBOL] = LAYOUT(
    KC_TILD,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,    KC_F7,          KC_F8,          KC_F9,          KC_F10,           XXXXXXX,
    _______,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         XXXXXXX,  XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,
    TO(0)  ,   KC_AMPR, KC_COLN, KC_LPRN, KC_LCBR, KC_LBRC,                         XXXXXXX,  OSM(MOD_RGUI),  OSM(MOD_RSFT),  OSM(MOD_RALT),  OSM(MOD_RCTL),    XXXXXXX,
    _______,   KC_CIRC, KC_BSLS, KC_RPRN, KC_RCBR, KC_RBRC,   KC_MPLY,     _______, XXXXXXX,  XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,
                        _______, _______, _______, KC_MINUS,  KC_EQUAL,    _______, XXXXXXX,  XXXXXXX,        XXXXXXX,        XXXXXXX
),

/* NUMPAD
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
[_NUMPAD] = LAYOUT(
    _______,   KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                               KC_F6,    KC_F7,  KC_F8,   KC_F9,  KC_F10,   XXXXXXX,
    _______,   XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                             KC_SLSH,  KC_7,   KC_8,    KC_9,   KC_MINS,  KC_F11,
    TO(0)  ,   OSM(MOD_LCTL),  OSM(MOD_LALT),  OSM(MOD_LSFT),  OSM(MOD_LGUI),  XXXXXXX,                             KC_SLSH,  KC_4,   KC_5,    KC_6,   KC_PLUS,  XXXXXXX,
    _______,   XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,     KC_MPLY,    _______,    KC_0,     KC_1,   KC_2,    KC_3,   KC_EQUAL, KC_F12,
               _______,        _______,        _______,        _______,        _______,                             KC_COMM,  KC_BSPC, KC_PDOT, XXXXXXX, XXXXXXX
),

/* NAV
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
[_NAV] = LAYOUT(
    XXXXXXX, XXXXXXX,       XXXXXXX,         XXXXXXX,        XXXXXXX,        XXXXXXX,                          _______,     _______,    _______, _______,  _______ ,    XXXXXXX,
    XXXXXXX, XXXXXXX,        C(KC_W),        XXXXXXX,        XXXXXXX,        XXXXXXX,                          A(KC_UP),    KC_PRVWD,   KC_UP,   KC_NXTWD, A(KC_BSPC),  XXXXXXX,
    TO(0)  , OSM(MOD_LCTL),  OSM(MOD_LALT),  OSM(MOD_LSFT),  OSM(MOD_LGUI),  KC_CAPS,                          A(KC_DOWN),  KC_LEFT,    KC_DOWN, KC_RGHT,  KC_BSPC,     XXXXXXX,
    XXXXXXX, KC_UNDO,        KC_CUT,         KC_COPY,        KC_PASTE,       KC_REDO,   KC_MPLY,      _______, KC_DEL,      KC_LSTRT,   C(KC_A), KC_LEND,  KC_DLINE,    _______,
                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       _______,     KC_BSPC,    _______, _______,  XXXXXXX
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
[_FUN] = LAYOUT(
    _______, _______ ,       _______,        _______,        _______,        _______,                            _______,    _______,    _______,   _______,   _______,  XXXXXXX,
    _______, XXXXXXX,        XXXXXXX,        XXXXXXX,        LSG(KC_4),      LSG(KC_5),                          KC_F12,     KC_F7,      KC_F8,     KC_F9,     XXXXXXX,  XXXXXXX,
    TO(0)  , OSM(MOD_LCTL),  OSM(MOD_LALT),  OSM(MOD_LSFT),  OSM(MOD_LGUI),  XXXXXXX,                            KC_F11,     KC_F4,      KC_F5,     KC_F6,     XXXXXXX,  XXXXXXX,
    _______, KC_UNDO,        KC_CUT,         KC_COPY,        KC_PASTE,       KC_REDO,   KC_MPLY,       _______,  KC_F10,     KC_F1,      KC_F2,     KC_F3,     XXXXXXX,  XXXXXXX,
                            _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, XXXXXXX
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
    XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,                     QK_BOOT, DB_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    TO(0)  ,  KC_COLEMAK, KC_DWARFQ2, KC_QWERTY,  XXXXXXX,     XXXXXXX,                     CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                           _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______
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
        case _DWARFQ2:
            oled_write_ln_P(PSTR("Dwq2"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _DWARFQ2:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav"), false);
            break;
        case _SYMBOL:
            oled_write_P(PSTR("Sym"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Num"), false);
            break;
        case _FUN:
            oled_write_P(PSTR("Fun"), false);
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
        case KC_DWARFQ2:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DWARFQ2);
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
    };
    if (!process_achordion(keycode, record)) { 
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
  if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4) { return true; }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

void matrix_scan_user(void) {
    achordion_task();
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
