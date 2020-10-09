enum combos
{
  AB_ESC,
  QW_TAB,
  BSPC_SPC_CAPS,
  ZX_CUT,
  XC_COPY,
  CV_PASTE,
  ZV_UNDO,
};

const uint16_t PROGMEM ab_combo[] = {KC_A, KC_B, COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_BSPC, KC_SPC, COMBO_END};
const uint16_t PROGMEM cut_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM undo_combo[] = {KC_Z, KC_V, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [AB_ESC] = COMBO(ab_combo, KC_ESC),
    [JK_TAB] = COMBO(jk_combo, KC_TAB),
    [BSPC_SPC_CAPS] = COMBO(caps_combo, KC_CAPS),
    [ZX_CUT] = COMBO(cut_combo, LGUI(KC_X)),
    [XC_COPY] = COMBO(cut_combo, LGUI(KC_C)),
    [CV_PASTE] = COMBO(cut_combo, LGUI(KC_V)),
    [ZV_UNDO] = COMBO(cut_combo, LGUI(KC_Z)),
};
