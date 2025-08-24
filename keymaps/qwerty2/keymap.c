#include QMK_KEYBOARD_H

// --- Custom Keycode Definitions ---

// Define a name for our custom keycodes to make the code more readable.
enum custom_keycodes {
  BOOT_HOLD = SAFE_RANGE // Custom keycode for entering bootloader mode on hold.
};

// Define names for our Tap Dance keys.
enum {
  TD_Q_EXCLAM,
  TD_W_AT,
  TD_E_HASH,
  TD_R_DOLLAR,
  TD_T_PERCENT,
  TD_Y_CARET,
  TD_U_AMPR,
  TD_I_ASTR,
  TD_O_LPRN,
  TD_P_RPRN,
  TD_L_QUESTION,
  TD_M_SLASH,
  TD_COMM_COLON,
  TD_DOT_QUOTE,
  TD_H_MINUS,
  TD_S_TILDE
};

// Define states for tap dance
typedef enum {
  TD_NONE,
  TD_UNKNOWN,
  TD_SINGLE_TAP,
  TD_SINGLE_HOLD,
  TD_DOUBLE_TAP,
  TD_DOUBLE_HOLD,
  TD_DOUBLE_SINGLE_TAP, // Send two single taps
  TD_TRIPLE_TAP,
  TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
  bool is_press_action;
  td_state_t state;
} td_tap_t;

// --- Tap Dance Handler Functions ---

// This function determines the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
    else return TD_SINGLE_HOLD;
  } else if (state->count == 2) {
    if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
    else if (state->pressed) return TD_DOUBLE_HOLD;
    else return TD_DOUBLE_TAP;
  }
  if (state->count == 3) {
    if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
    else return TD_TRIPLE_HOLD;
  } else return TD_UNKNOWN;
}

// Create individual instances for each key
static td_tap_t q_tap_state = { .is_press_action = true, .state = TD_NONE };
static td_tap_t w_tap_state = { .is_press_action = true, .state = TD_NONE };
static td_tap_t e_tap_state = { .is_press_action = true, .state = TD_NONE };
static td_tap_t r_tap_state = { .is_press_action = true, .state = TD_NONE };
static td_tap_t t_tap_state = { .is_press_action = true, .state = TD_NONE };
static td_tap_t y_tap_state = { .is_press_action = true, .state = TD_NONE };
static td_tap_t u_tap_state = { .is_press_action = true, .state = TD_NONE };
static td_tap_t i_tap_state = { .is_press_action = true, .state = TD_NONE };
static td_tap_t o_tap_state = { .is_press_action = true, .state = TD_NONE };
static td_tap_t p_tap_state = { .is_press_action = true, .state = TD_NONE };
static td_tap_t l_tap_state = { .is_press_action = true, .state = TD_NONE };
static td_tap_t m_tap_state = { .is_press_action = true, .state = TD_NONE };
static td_tap_t comm_tap_state = { .is_press_action = true, .state = TD_NONE };
static td_tap_t dot_tap_state = { .is_press_action = true, .state = TD_NONE };
static td_tap_t h_tap_state = { .is_press_action = true, .state = TD_NONE };
static td_tap_t s_tap_state = { .is_press_action = true, .state = TD_NONE };

// --- Tap Dance Finished Handlers (one for each key) ---

void q_exclam_finished(tap_dance_state_t *state, void *user_data) {
  q_tap_state.state = cur_dance(state);
  switch (q_tap_state.state) {
    case TD_SINGLE_TAP:
      tap_code(KC_Q);
      break;
    case TD_SINGLE_HOLD:
      tap_code16(LSFT(KC_1)); // !
      break;
    case TD_DOUBLE_TAP:
      tap_code(KC_Q);
      tap_code(KC_Q);
      break;
    case TD_DOUBLE_SINGLE_TAP:
      tap_code(KC_Q);
      register_code(KC_Q);
      break;
    default:
      break;
  }
}

void q_exclam_reset(tap_dance_state_t *state, void *user_data) {
  switch (q_tap_state.state) {
    case TD_DOUBLE_SINGLE_TAP:
      unregister_code(KC_Q);
      break;
    default:
      break;
  }
  q_tap_state.state = TD_NONE;
}

void w_at_finished(tap_dance_state_t *state, void *user_data) {
  w_tap_state.state = cur_dance(state);
  switch (w_tap_state.state) {
    case TD_SINGLE_TAP:
      tap_code(KC_W);
      break;
    case TD_SINGLE_HOLD:
      tap_code16(LSFT(KC_2)); // @
      break;
    case TD_DOUBLE_TAP:
      tap_code(KC_W);
      tap_code(KC_W);
      break;
    case TD_DOUBLE_SINGLE_TAP:
      tap_code(KC_W);
      register_code(KC_W);
      break;
    default:
      break;
  }
}

void w_at_reset(tap_dance_state_t *state, void *user_data) {
  switch (w_tap_state.state) {
    case TD_DOUBLE_SINGLE_TAP:
      unregister_code(KC_W);
      break;
    default:
      break;
  }
  w_tap_state.state = TD_NONE;
}

void e_hash_finished(tap_dance_state_t *state, void *user_data) {
  e_tap_state.state = cur_dance(state);
  switch (e_tap_state.state) {
    case TD_SINGLE_TAP:
      tap_code(KC_E);
      break;
    case TD_SINGLE_HOLD:
      tap_code16(LSFT(KC_3)); // #
      break;
    case TD_DOUBLE_TAP:
      tap_code(KC_E);
      tap_code(KC_E);
      break;
    case TD_DOUBLE_SINGLE_TAP:
      tap_code(KC_E);
      register_code(KC_E);
      break;
    default:
      break;
  }
}

void e_hash_reset(tap_dance_state_t *state, void *user_data) {
  switch (e_tap_state.state) {
    case TD_DOUBLE_SINGLE_TAP:
      unregister_code(KC_E);
      break;
    default:
      break;
  }
  e_tap_state.state = TD_NONE;
}

void r_dollar_finished(tap_dance_state_t *state, void *user_data) {
  r_tap_state.state = cur_dance(state);
  switch (r_tap_state.state) {
    case TD_SINGLE_TAP:
      tap_code(KC_R);
      break;
    case TD_SINGLE_HOLD:
      tap_code16(LSFT(KC_4)); // $
      break;
    case TD_DOUBLE_TAP:
      tap_code(KC_R);
      tap_code(KC_R);
      break;
    case TD_DOUBLE_SINGLE_TAP:
      tap_code(KC_R);
      register_code(KC_R);
      break;
    default:
      break;
  }
}

void r_dollar_reset(tap_dance_state_t *state, void *user_data) {
  switch (r_tap_state.state) {
    case TD_DOUBLE_SINGLE_TAP:
      unregister_code(KC_R);
      break;
    default:
      break;
  }
  r_tap_state.state = TD_NONE;
}

void t_percent_finished(tap_dance_state_t *state, void *user_data) {
  t_tap_state.state = cur_dance(state);
  switch (t_tap_state.state) {
    case TD_SINGLE_TAP:
      tap_code(KC_T);
      break;
    case TD_SINGLE_HOLD:
      tap_code16(LSFT(KC_5)); // %
      break;
    case TD_DOUBLE_TAP:
      tap_code(KC_T);
      tap_code(KC_T);
      break;
    case TD_DOUBLE_SINGLE_TAP:
      tap_code(KC_T);
      register_code(KC_T);
      break;
    default:
      break;
  }
}

void t_percent_reset(tap_dance_state_t *state, void *user_data) {
  switch (t_tap_state.state) {
    case TD_DOUBLE_SINGLE_TAP:
      unregister_code(KC_T);
      break;
    default:
      break;
  }
  t_tap_state.state = TD_NONE;
}

void y_caret_finished(tap_dance_state_t *state, void *user_data) {
  y_tap_state.state = cur_dance(state);
  switch (y_tap_state.state) {
    case TD_SINGLE_TAP:
      tap_code(KC_Y);
      break;
    case TD_SINGLE_HOLD:
      tap_code16(LSFT(KC_6)); // ^
      break;
    case TD_DOUBLE_TAP:
      tap_code(KC_Y);
      tap_code(KC_Y);
      break;
    case TD_DOUBLE_SINGLE_TAP:
      tap_code(KC_Y);
      register_code(KC_Y);
      break;
    default:
      break;
  }
}

void y_caret_reset(tap_dance_state_t *state, void *user_data) {
  switch (y_tap_state.state) {
    case TD_DOUBLE_SINGLE_TAP:
      unregister_code(KC_Y);
      break;
    default:
      break;
  }
  y_tap_state.state = TD_NONE;
}

void u_ampr_finished(tap_dance_state_t *state, void *user_data) {
  u_tap_state.state = cur_dance(state);
  switch (u_tap_state.state) {
    case TD_SINGLE_TAP:
      tap_code(KC_U);
      break;
    case TD_SINGLE_HOLD:
      tap_code16(LSFT(KC_7)); // &
      break;
    case TD_DOUBLE_TAP:
      tap_code(KC_U);
      tap_code(KC_U);
      break;
    case TD_DOUBLE_SINGLE_TAP:
      tap_code(KC_U);
      register_code(KC_U);
      break;
    default:
      break;
  }
}

void u_ampr_reset(tap_dance_state_t *state, void *user_data) {
  switch (u_tap_state.state) {
    case TD_DOUBLE_SINGLE_TAP:
      unregister_code(KC_U);
      break;
    default:
      break;
  }
  u_tap_state.state = TD_NONE;
}

void i_astr_finished(tap_dance_state_t *state, void *user_data) {
  i_tap_state.state = cur_dance(state);
  switch (i_tap_state.state) {
    case TD_SINGLE_TAP:
      tap_code(KC_I);
      break;
    case TD_SINGLE_HOLD:
      tap_code16(LSFT(KC_8)); // *
      break;
    case TD_DOUBLE_TAP:
      tap_code(KC_I);
      tap_code(KC_I);
      break;
    case TD_DOUBLE_SINGLE_TAP:
      tap_code(KC_I);
      register_code(KC_I);
      break;
    default:
      break;
  }
}

void i_astr_reset(tap_dance_state_t *state, void *user_data) {
  switch (i_tap_state.state) {
    case TD_DOUBLE_SINGLE_TAP:
      unregister_code(KC_I);
      break;
    default:
      break;
  }
  i_tap_state.state = TD_NONE;
}

void o_lprn_finished(tap_dance_state_t *state, void *user_data) {
  o_tap_state.state = cur_dance(state);
  switch (o_tap_state.state) {
    case TD_SINGLE_TAP:
      tap_code(KC_O);
      break;
    case TD_SINGLE_HOLD:
      tap_code16(LSFT(KC_9)); // (
      break;
    case TD_DOUBLE_TAP:
      tap_code(KC_O);
      tap_code(KC_O);
      break;
    case TD_DOUBLE_SINGLE_TAP:
      tap_code(KC_O);
      register_code(KC_O);
      break;
    default:
      break;
  }
}

void o_lprn_reset(tap_dance_state_t *state, void *user_data) {
  switch (o_tap_state.state) {
    case TD_DOUBLE_SINGLE_TAP:
      unregister_code(KC_O);
      break;
    default:
      break;
  }
  o_tap_state.state = TD_NONE;
}

void p_rprn_finished(tap_dance_state_t *state, void *user_data) {
  p_tap_state.state = cur_dance(state);
  switch (p_tap_state.state) {
    case TD_SINGLE_TAP:
      tap_code(KC_P);
      break;
    case TD_SINGLE_HOLD:
      tap_code16(LSFT(KC_0)); // )
      break;
    case TD_DOUBLE_TAP:
      tap_code(KC_P);
      tap_code(KC_P);
      break;
    case TD_DOUBLE_SINGLE_TAP:
      tap_code(KC_P);
      register_code(KC_P);
      break;
    default:
      break;
  }
}

void p_rprn_reset(tap_dance_state_t *state, void *user_data) {
  switch (p_tap_state.state) {
    case TD_DOUBLE_SINGLE_TAP:
      unregister_code(KC_P);
      break;
    default:
      break;
  }
  p_tap_state.state = TD_NONE;
}

void l_question_finished(tap_dance_state_t *state, void *user_data) {
  l_tap_state.state = cur_dance(state);
  switch (l_tap_state.state) {
    case TD_SINGLE_TAP:
      tap_code(KC_L);
      break;
    case TD_SINGLE_HOLD:
      tap_code16(S(KC_SLSH)); // ?
      break;
    case TD_DOUBLE_TAP:
      tap_code(KC_L);
      tap_code(KC_L);
      break;
    case TD_DOUBLE_SINGLE_TAP:
      tap_code(KC_L);
      register_code(KC_L);
      break;
    default:
      break;
  }
}

void l_question_reset(tap_dance_state_t *state, void *user_data) {
  switch (l_tap_state.state) {
    case TD_DOUBLE_SINGLE_TAP:
      unregister_code(KC_L);
      break;
    default:
      break;
  }
  l_tap_state.state = TD_NONE;
}

void m_slash_finished(tap_dance_state_t *state, void *user_data) {
  m_tap_state.state = cur_dance(state);
  switch (m_tap_state.state) {
    case TD_SINGLE_TAP:
      tap_code(KC_M);
      break;
    case TD_SINGLE_HOLD:
      tap_code(KC_SLSH); // /
      break;
    case TD_DOUBLE_TAP:
      tap_code(KC_M);
      tap_code(KC_M);
      break;
    case TD_DOUBLE_SINGLE_TAP:
      tap_code(KC_M);
      register_code(KC_M);
      break;
    default:
      break;
  }
}

void m_slash_reset(tap_dance_state_t *state, void *user_data) {
  switch (m_tap_state.state) {
    case TD_DOUBLE_SINGLE_TAP:
      unregister_code(KC_M);
      break;
    default:
      break;
  }
  m_tap_state.state = TD_NONE;
}

void comm_colon_finished(tap_dance_state_t *state, void *user_data) {
  comm_tap_state.state = cur_dance(state);
  switch (comm_tap_state.state) {
    case TD_SINGLE_TAP:
      tap_code(KC_COMM);
      break;
    case TD_SINGLE_HOLD:
      tap_code16(LSFT(KC_SCLN)); // :
      break;
    case TD_DOUBLE_TAP:
      tap_code(KC_COMM);
      tap_code(KC_COMM);
      break;
    case TD_DOUBLE_SINGLE_TAP:
      tap_code(KC_COMM);
      register_code(KC_COMM);
      break;
    default:
      break;
  }
}

void comm_colon_reset(tap_dance_state_t *state, void *user_data) {
  switch (comm_tap_state.state) {
    case TD_DOUBLE_SINGLE_TAP:
      unregister_code(KC_COMM);
      break;
    default:
      break;
  }
  comm_tap_state.state = TD_NONE;
}

void dot_quote_finished(tap_dance_state_t *state, void *user_data) {
  dot_tap_state.state = cur_dance(state);
  switch (dot_tap_state.state) {
    case TD_SINGLE_TAP:
      tap_code(KC_DOT);
      break;
    case TD_SINGLE_HOLD:
      tap_code16(LSFT(KC_QUOT)); // "
      break;
    case TD_DOUBLE_TAP:
      tap_code(KC_DOT);
      tap_code(KC_DOT);
      break;
    case TD_DOUBLE_SINGLE_TAP:
      tap_code(KC_DOT);
      register_code(KC_DOT);
      break;
    default:
      break;
  }
}

void dot_quote_reset(tap_dance_state_t *state, void *user_data) {
  switch (dot_tap_state.state) {
    case TD_DOUBLE_SINGLE_TAP:
      unregister_code(KC_DOT);
      break;
    default:
      break;
  }
  dot_tap_state.state = TD_NONE;
}

void h_minus_finished(tap_dance_state_t *state, void *user_data) {
  h_tap_state.state = cur_dance(state);
  switch (h_tap_state.state) {
    case TD_SINGLE_TAP:
      tap_code(KC_H);
      break;
    case TD_SINGLE_HOLD:
      tap_code(KC_MINS); // -
      break;
    case TD_DOUBLE_TAP:
      tap_code(KC_H);
      tap_code(KC_H);
      break;
    case TD_DOUBLE_SINGLE_TAP:
      tap_code(KC_H);
      register_code(KC_H);
      break;
    default:
      break;
  }
}

void h_minus_reset(tap_dance_state_t *state, void *user_data) {
  switch (h_tap_state.state) {
    case TD_DOUBLE_SINGLE_TAP:
      unregister_code(KC_H);
      break;
    default:
      break;
  }
  h_tap_state.state = TD_NONE;
}

void s_tilde_finished(tap_dance_state_t *state, void *user_data) {
  s_tap_state.state = cur_dance(state);
  switch (s_tap_state.state) {
    case TD_SINGLE_TAP:
      tap_code(KC_S);
      break;
    case TD_SINGLE_HOLD:
      tap_code16(LSFT(KC_GRV)); // ~
      break;
    case TD_DOUBLE_TAP:
      tap_code(KC_S);
      tap_code(KC_S);
      break;
    case TD_DOUBLE_SINGLE_TAP:
      tap_code(KC_S);
      register_code(KC_S);
      break;
    default:
      break;
  }
}

void s_tilde_reset(tap_dance_state_t *state, void *user_data) {
  switch (s_tap_state.state) {
    case TD_DOUBLE_SINGLE_TAP:
      unregister_code(KC_S);
      break;
    default:
      break;
  }
  s_tap_state.state = TD_NONE;
}

// --- Tap Dance Definition ---

// This array registers our tap dance actions with QMK.
tap_dance_action_t tap_dance_actions[] = {
  [TD_Q_EXCLAM]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, q_exclam_finished, q_exclam_reset),
  [TD_W_AT]       = ACTION_TAP_DANCE_FN_ADVANCED(NULL, w_at_finished, w_at_reset),
  [TD_E_HASH]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, e_hash_finished, e_hash_reset),
  [TD_R_DOLLAR]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, r_dollar_finished, r_dollar_reset),
  [TD_T_PERCENT]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, t_percent_finished, t_percent_reset),
  [TD_Y_CARET]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, y_caret_finished, y_caret_reset),
  [TD_U_AMPR]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, u_ampr_finished, u_ampr_reset),
  [TD_I_ASTR]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, i_astr_finished, i_astr_reset),
  [TD_O_LPRN]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, o_lprn_finished, o_lprn_reset),
  [TD_P_RPRN]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, p_rprn_finished, p_rprn_reset),
  [TD_L_QUESTION] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, l_question_finished, l_question_reset),
  [TD_M_SLASH]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, m_slash_finished, m_slash_reset),
  [TD_COMM_COLON] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, comm_colon_finished, comm_colon_reset),
  [TD_DOT_QUOTE]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dot_quote_finished, dot_quote_reset),
  [TD_H_MINUS]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, h_minus_finished, h_minus_reset),
  [TD_S_TILDE]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, s_tilde_finished, s_tilde_reset)
};


// --- Bootloader on Hold Feature ---

// Variable to track when the bootloader key was pressed.
static uint16_t boot_hold_timer;

// This function runs for every key press and release.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BOOT_HOLD:
      if (record->event.pressed) {
        // When BOOT_HOLD is pressed, start the timer.
        boot_hold_timer = timer_read();
      } else { // On key release
        // Check if the key was held for at least 5 seconds (5000ms).
        if (timer_elapsed(boot_hold_timer) >= 5000) {
          bootloader_jump(); // Jump to the bootloader.
        }
      }
      return false; // We've handled this keycode, so don't process it further.
  }
  return true; // Process all other keycodes normally.
}


// --- Your Keymap Layout ---

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2(
        TD(TD_Q_EXCLAM), TD(TD_W_AT), TD(TD_E_HASH), TD(TD_R_DOLLAR), TD(TD_T_PERCENT),
        TD(TD_Y_CARET), TD(TD_U_AMPR), TD(TD_I_ASTR), TD(TD_O_LPRN), TD(TD_P_RPRN),

        KC_A,        TD(TD_S_TILDE), LALT_T(KC_D), LGUI_T(KC_F), KC_G,
        TD(TD_H_MINUS), RGUI_T(KC_J), RALT_T(KC_K), TD(TD_L_QUESTION), KC_BSPC,

        KC_Z,        KC_X, KC_C, KC_V, KC_B,
        KC_N, TD(TD_M_SLASH), TD(TD_COMM_COLON), TD(TD_DOT_QUOTE), KC_ENT,

                                          KC_SPC, KC_LSFT, KC_LCTL, TO(1)
    ),

    [1] = LAYOUT_split_3x5_2(
        KC_1, KC_2, KC_3, KC_4, KC_5,                                    KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_ESC, KC_GRV, KC_UP, KC_VOLD, KC_VOLU,                         KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_TAB, KC_LEFT, KC_DOWN, KC_RGHT, KC_MSTP,                      KC_BSLS, KC_SLSH, KC_SCLN, KC_QUOT, KC_ENT,
                                          TO(0), KC_LSFT, KC_RALT, TO(2)
    ),

    [2] = LAYOUT_split_3x5_2(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                               KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
        BOOT_HOLD, KC_WH_U, KC_MS_U, KC_WH_D, KC_BTN2,                   KC_BRIU, KC_BTN1, KC_MS_U, BOOT_HOLD, KC_F11,
        KC_BTN1,   KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,                     KC_BRID, KC_MS_L, KC_MS_D, KC_MS_R, KC_F12,
                                          TO(0), KC_NO, KC_NO, KC_NO
    )
};
