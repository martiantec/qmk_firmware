# MCU selection
MCU = at90usb1286
# F_CPU = 8000000

# Bootloader selection
BOOTLOADER = atmel-dfu
# OPT_DEFS += -DBOOTLOADER_SIZE=4096

# Build options
BACKLIGHT_ENABLE   = yes
BLUETOOTH          = BT121
BOOTMAGIC_ENABLE   = no
COMMAND_ENABLE     = yes
CONSOLE_ENABLE     = yes
EXTRAKEY_ENABLE    = yes
KEYBOARD_SHARED_EP = yes
# LED_MATRIX_ENABLE  = IS31FL3737
MOUSEKEY_ENABLE    = yes
NKRO_ENABLE        = no
RGBLIGHT_ENABLE    = no
UNICODE_ENABLE     = no

# Optimizations
EXTRAFLAGS += -flto
