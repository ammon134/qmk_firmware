
// Fine tuning space fn tap hold timing
#define TAPPING_FORCE_HOLD
#ifdef TAPPING_TERM
    #undef TAPPING_TERM
    #define TAPPING_TERM 150
#endif
#define PERMISSIVE_HOLD
// Turn on CAPS WORD
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD