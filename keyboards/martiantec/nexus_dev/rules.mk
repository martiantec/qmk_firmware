# MCU selection
MCU = atmega32u4
# F_CPU = 8000000

# Bootloader selection
BOOTLOADER = atmel-dfu
# OPT_DEFS += -DBOOTLOADER_SIZE=4096

# Build options
BACKLIGHT_ENABLE   = no
BLUETOOTH          = no
BOOTMAGIC_ENABLE   = lite
COMMAND_ENABLE     = yes
CONSOLE_ENABLE     = yes
EXTRAKEY_ENABLE    = yes
KEYBOARD_SHARED_EP = no
# LED_MATRIX_ENABLE  = IS31FL3737
# RGB_MATRIX_ENABLE  = IS31FL3737
MOUSEKEY_ENABLE    = yes
NKRO_ENABLE        = yes
RGBLIGHT_ENABLE    = no

# Optimizations
EXTRAFLAGS += -flto
