# ifeq ($(strip $(AUDIO_ENABLE)), yes)
#     SRC += muse.c
# endif


BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no	    # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = no		 # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
AUDIO_ENABLE = no          # Audio output
CUSTOM_MATRIX = lite
# Do not enable RGB_MATRIX_ENABLE together with RGBLIGHT_ENABLE
RGB_MATRIX_ENABLE = no
ENCODER_ENABLE = no
DIP_SWITCH_ENABLE = yes
