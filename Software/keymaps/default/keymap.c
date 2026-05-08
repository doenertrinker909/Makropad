// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
uint16_t oled_timer = 0;
bool show_splash = false;

enum my_layers {
    _BASE,
    _LED,
    _DEBUGL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_numpad_4x4(
        KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_P4,   KC_P5,   KC_P6,   KC_PMNS,
        KC_P1,   KC_P2,   KC_P3,   KC_PAST,
        KC_P0,   KC_PDOT, KC_PSLS, KC_PENT
    ),
    [_LED] = LAYOUT_numpad_4x4(
        KC_NO,   KC_NO,   RM_HUED,   RM_HUEU,
        KC_NO,   KC_NO,   RM_SATD,   RM_SATU,
        KC_NO,   KC_NO,   RM_VALD,   RM_VALU,
        RM_PREV, RM_NEXT, RM_SPDD,   RM_SPDU
    ),
    [_DEBUGL] = LAYOUT_numpad_4x4(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   QK_RBT,   QK_BOOT
    )

};
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]   = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [_LED]    = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_DEBUGL] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif

led_config_t g_led_config = { {
  // Key Matrix to LED Index
    {   15, 14, 13, 12 },
    {    8,  9, 10, 11 },
    {    7,  6,  5,  4 },
    {    0,  1,  2,  3 }
}, {
  // LED Index to Physical Position (X, Y)
    { 0, 64 }, { 75, 64 }, { 149, 64 }, { 224, 64 }, // 0 bis 3
    { 224, 43 }, { 149, 43 }, { 75, 43 }, { 0, 43 }, // 4 bis 7
    { 0, 21 }, { 75, 21 }, { 149, 21 }, { 224, 21 }, // 8 bis 11
    { 224, 0 }, { 149, 0 }, { 75, 0 }, { 0, 0 }      // 12 bis 15
}, {
    // LED Index to Flag (1 = Underglow, 4 = Key Backlight)
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
} };

layer_state_t layer_state_set_user(layer_state_t state) {
    oled_timer = timer_read(); // Aktuelle Zeit speichern
    if (!show_splash) {
        oled_clear(); // Altes Menü sofort löschen, damit nichts überlappt
    }
    show_splash = true; 
    return state;
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    if (show_splash) {
        // Prüfen, ob schon 3000 ms (3 Sekunden) vergangen sind
        if (timer_elapsed(oled_timer) < 3000) {
            
            // Cursor für den Splash-Screen zwingend auf Start setzen
            oled_set_cursor(0, 0); 
            
            // Aktuellen Layer anzeigen (mit Leerzeichen auffüllen zum Überschreiben)
            oled_write_P(PSTR("Layer: "), false);
            switch (get_highest_layer(layer_state)) {
                case _BASE:
                    oled_write_ln_P(PSTR("Base        "), false);
                    break;
                case _LED:
                    oled_write_ln_P(PSTR("LED Config  "), false);
                    break;
                case _DEBUGL:
                    oled_write_ln_P(PSTR("Debug       "), false);
                    break;
                default:
                    oled_write_ln_P(PSTR("Unbekannt   "), false);
                    break;
            }
            
            // Wichtig: Hier abbrechen! Das normale Menü soll noch NICHT gezeichnet werden.
            return false; 
            
        } 
        else {
            // Die 3 Sekunden sind vorbei!
            show_splash = false; // Splash-Screen ausschalten
            oled_clear(); 
            return false;       // Display EINMAL leeren, um Reste des Splash-Screens zu löschen
        }
    }

    // Cursor für das Standard-Menü auf Start setzen
    oled_set_cursor(0, 0);

    // Keymap menu
    uint8_t current_layer = get_highest_layer(layer_state);
    switch (current_layer) {
        case _BASE:{
            oled_write_ln_P(PSTR("   7    8    9    +  "), false);
            oled_write_ln_P(PSTR("   4    5    6    -  "), false);
            oled_write_ln_P(PSTR("   1    2    3    *  "), false);
            oled_write_ln_P(PSTR("   0    .    /   ENT "), false);
            break;}
        case _LED:{
            uint8_t mode = rgb_matrix_get_mode();
            char buf[22];
            // Formatierung als exakt eine Zeile, um alte Zeichen zu löschen
            snprintf(buf, sizeof(buf), " Mode: %-13d", mode); 
            oled_write_ln(buf, false);

            oled_write_ln_P(PSTR("           SAT- SAT+ "), false);
            oled_write_ln_P(PSTR("           BRI- BRI+ "), false);
            oled_write_ln_P(PSTR(" MOD- MOD+ SPD- SPD+ "), false);
            break;}
        case _DEBUGL:{
            oled_write_ln_P(PSTR("                     "), false);
            oled_write_ln_P(PSTR("                     "), false);
            oled_write_ln_P(PSTR("                     "), false);
            oled_write_ln_P(PSTR("           RBT  BOOT "), false);
            break;}
        default:{
            break;}
    }
    
    return false;
}
#endif

void keyboard_post_init_user(void) {
    // Pins als Eingänge mit Pull-up-Widerstand definieren  
    setPinInputHigh(E6); // Pin für Encoder-Knopf 1
    setPinInputHigh(B4); // Pin für Encoder-Knopf 2
}

void matrix_scan_user(void) {
    // --- Encoder 1 ---
    static bool btn1_pressed = false;
    bool is_low1 = !readPin(E6); // Pin wird bei Druck gegen GND gezogen

    if (is_low1 && !btn1_pressed) {
        register_code(KC_MUTE); // Aktion beim Drücken
        btn1_pressed = true;
    } else if (!is_low1 && btn1_pressed) {
        unregister_code(KC_MUTE); // Aktion beim Loslassen
        btn1_pressed = false;
    }

    // --- Encoder 2 (Layer hochwechseln) ---
    static bool btn2_pressed = false;
    bool is_low2 = !readPin(B4); // Pin anpassen!

    if (is_low2 && !btn2_pressed) {
        // 1. Aktuellen Layer auslesen
        uint8_t current_layer = get_highest_layer(layer_state);
        
        // 2. Einen Layer addieren
        uint8_t next_layer = current_layer + 1;

        // 3. Wenn das Maximum überschritten wird, wieder auf Layer 0 (Base) springen.
        // WICHTIG: Wenn Sie z. B. 3 Layer haben (0, 1, 2), ändern Sie die 1 in eine 2!
        if (next_layer > 2) { 
            next_layer = 0;
        }

        // 4. Den neuen Layer aktivieren
        layer_move(next_layer); 

        btn2_pressed = true;
    } else if (!is_low2 && btn2_pressed) {
        // Beim Loslassen müssen wir nichts tun, da der Layer dauerhaft 
        // gewechselt bleiben soll, bis man wieder drückt.
        btn2_pressed = false;
    }
}