# MCU selection
MCU = at90usb1286
# Internal oscillator is used
F_CPU = 8000000

# Bootloader selection
BOOTLOADER = qmk-dfu
# OPT_DEFS += -DBOOTLOADER_SIZE=4096

# Build options
BACKLIGHT_ENABLE  = yes
BLUETOOTH_ENABLE  = no
BOOTMAGIC_ENABLE  = no
COMMAND_ENABLE    = yes
CONSOLE_ENABLE    = yes
EXTRAKEY_ENABLE   = yes
# LED_MATRIX_ENABLE = IS31FL3737
MOUSEKEY_ENABLE   = yes
NKRO_ENABLE       = yes
RGBLIGHT_ENABLE   = no
UNICODE_ENABLE    = no

# Optimizations
EXTRAFLAGS += -flto
