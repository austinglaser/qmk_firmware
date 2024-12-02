// --- Dual-function key configuration
//
// Reference docs/tap_hold.md

// Without this, dual function keys (tapped/held) like Esc/Ctrl don't act as
// modifiers when tapped very quickly. This is good for use-cases like
// "Z"/Ctrl, where you might get tripped up by quick rolling combos -- but for
// Esc/Ctrl, it means that sometimes rapid keypresses don't register as
// shortcuts, just as literal letters.
#undef IGNORE_MOD_TAP_INTERRUPT

// Makes quick rolling combos even better (for cases when a dual-function
// modifier key is held down for a very short period of time).
#define HOLD_ON_OTHER_KEY_PRESS

#undef TAPPING_TERM
#define TAPPING_TERM 200
