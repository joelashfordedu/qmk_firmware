/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 240

#define ONESHOT_TAP_TOGGLE 3

#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 2000

#define USB_SUSPEND_WAKEUP_DELAY 0
