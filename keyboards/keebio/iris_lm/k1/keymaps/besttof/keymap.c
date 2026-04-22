// This is my layout, there are many like it but this one is mine

#include "keycodes.h"
#include "keymap_us.h"
#include "rgb_matrix.h"
#include QMK_KEYBOARD_H

enum custom_layers {
     _BASE,
     _SYM,
     _NAV,
     _SYS,
};

enum custom_keycodes {
    ARWLMDA = SAFE_RANGE,
    ARWPTR,

    // Parenthesis, Bracket, Curly Bracket, Angle Bracket macros
    IN_PRN,
    IN_BRC,
    IN_CBR,
    IN_ABK,

    MD_CODE,

    // Color settings
    COL_1,
    COL_2,
    COL_3,
};

#define TO_SYM LT(1, KC_SPC)
#define TO_NAV LT(2, KC_SPC)
#define TO_SYS LT(3, KC_EQL)

#define HM_S   LALT_T(KC_S)
#define HM_D   LSFT_T(KC_D)
#define HM_F   LGUI_T(KC_F)
#define HM_TAB LCTL_T(KC_TAB)
#define HM_G   MEH_T(KC_G)

#define HM_L    RALT_T(KC_L)
#define HM_K    RSFT_T(KC_K)
#define HM_J    RGUI_T(KC_J)
#define HM_QUOT RCTL_T(KC_QUOT)
#define HM_H    MEH_T(KC_H)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     HM_TAB,  KC_A,    HM_S,    HM_D,    HM_F,    HM_G,                               HM_H,    HM_J,    HM_K,    HM_L,    KC_SCLN, HM_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MINS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,          KC_RBRC,  KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, TO_SYS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LSFT, TO_SYM,  KC_ENT,                    KC_BSPC, TO_NAV,  KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F11,  KC_F12,  _______, _______, _______,                            IN_BRC,  IN_PRN,  IN_CBR,  IN_ABK,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_LALT, KC_LSFT, KC_LGUI, KC_MEH,                             KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     ARWPTR,  _______, _______, _______, KC_LCTL, _______, _______,          _______, KC_LPRN, KC_RPRN, KC_LT,   KC_GT,   _______, ARWLMDA,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, KC_INS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, KC_WBAK,          KC_WFWD, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     EE_CLR,  _______, _______, RM_TOGG, _______, _______,                            _______, _______, KC_MUTE, _______, _______, KC_SLEP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     COL_1,   _______, _______, RM_VALU, _______, DT_UP,                              _______, KC_MSTP, KC_VOLU, KC_MPLY, _______, KC_BRMU,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     COL_2,   _______, RM_PREV, RM_VALD, RM_NEXT, DT_DOWN,                            _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, KC_BRMD,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     COL_3,   _______, _______, _______, _______, DT_PRNT, CG_TOGG,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};


const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =

    LAYOUT(
        // ┌────┬────┬────┬────┬────┬────┐                  ┌────┬────┬────┬────┬────┬────┐
            '*', 'L', 'L', 'L', 'L', 'L',                    'R', 'R', 'R', 'R', 'R', '*',
        // ├────┼────┼────┼────┼────┼────┤                  ├────┼────┼────┼────┼────┼────┤
            '*', 'L', 'L', 'L', 'L', 'L',                    'R', 'R', 'R', 'R', 'R', '*',
        // ├────┼────┼────┼────┼────┼────┤                  ├────┼────┼────┼────┼────┼────┤
            '*', 'L', 'L', 'L', 'L', 'L',                    'R', 'R', 'R', 'R', 'R', '*',
        // ├────┼────┼────┼────┼────┼────┼────┐        ┌────┼────┼────┼────┼────┼────┼────┤
            '*', 'L', 'L', 'L', 'L', 'L', '*',          '*', 'R', 'R', 'R', 'R', 'R', '*',
        // └────┴────┴────┴─┬──┴─┬──┴─┬──┴─┬──┘        └─┬──┴─┬──┴─┬──┴─┬──┴────┴────┴────┘
                             '*', '*', '*',               '*', '*', '*'
        //                  └────┴────┴────┘             └────┴────┴────┘
    );

// MACROS
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ARWLMDA:
            if (record->event.pressed) SEND_STRING("=>");
            break;

        case ARWPTR:
            if (record->event.pressed) SEND_STRING("->");
            break;

        case MD_CODE:
            if (record->event.pressed) SEND_STRING("```");
            break;

        case IN_PRN:
           if (record->event.pressed) SEND_STRING("()"SS_TAP(X_LEFT));
           break;

        case IN_BRC:
           if (record->event.pressed) SEND_STRING("[]"SS_TAP(X_LEFT));
           break;

        case IN_CBR:
           if (record->event.pressed) SEND_STRING("{}"SS_TAP(X_LEFT));
           break;

        case IN_ABK:
           if (record->event.pressed) SEND_STRING("<>"SS_TAP(X_LEFT));
           break;

        case COL_1:
            if (record->event.pressed) {
                rgblight_mode(RGB_MATRIX_SOLID_COLOR);
                rgblight_sethsv(0, 255, 88);
            }
            break;

        case COL_2:
            if (record->event.pressed) {
                rgblight_mode(RGB_MATRIX_SOLID_COLOR);
                rgblight_sethsv(128, 255, 88);
            }
            break;

        case COL_3:
            if (record->event.pressed) {
                rgblight_mode(RGB_MATRIX_SOLID_COLOR);
                rgblight_sethsv(32, 255, 88);
            }
            break;
    }
    return true;
};

// COMBOS
const uint16_t PROGMEM CB_MDCODE[] = {KC_GRV, KC_Q, COMBO_END};

const uint16_t PROGMEM CB_LPRN[] = {KC_6    , KC_7    , COMBO_END};
const uint16_t PROGMEM CB_LBRC[] = {KC_Y    , KC_U    , COMBO_END};
const uint16_t PROGMEM CB_LCBR[] = {HM_H    , HM_J    , COMBO_END};
const uint16_t PROGMEM CB_LT[]   = {KC_N    , KC_M    , COMBO_END};

const uint16_t PROGMEM CB_RPRN[] = {KC_9    , KC_0    , COMBO_END};
const uint16_t PROGMEM CB_RBRC[] = {KC_O    , KC_P    , COMBO_END};
const uint16_t PROGMEM CB_RCBR[] = {HM_L    , KC_SCLN , COMBO_END};
const uint16_t PROGMEM CB_GT[]   = {KC_DOT  , KC_SLSH , COMBO_END};

combo_t key_combos[] = {
    COMBO(CB_MDCODE, MD_CODE),

    COMBO(CB_LPRN, KC_LPRN),
    COMBO(CB_LBRC, KC_LBRC),
    COMBO(CB_LCBR, KC_LCBR),
    COMBO(CB_LT,   KC_LT),

    COMBO(CB_RPRN, KC_RPRN),
    COMBO(CB_RBRC, KC_RBRC),
    COMBO(CB_RCBR, KC_RCBR),
    COMBO(CB_GT,   KC_GT),
};
