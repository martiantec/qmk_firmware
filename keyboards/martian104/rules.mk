# MCU selection
MCU = at90usb1286

# Bootloader selection
BOOTLOADER = halfkay
# OPT_DEFS += -DBOOTLOADER_SIZE=4096

# Build options
BACKLIGHT_ENABLE  = yes
BLUETOOTH_ENABLE  = no
BOOTMAGIC_ENABLE  = no
COMMAND_ENABLE    = yes
CONSOLE_ENABLE    = yes
EXTRAKEY_ENABLE   = yes
LED_MATRIX_ENABLE = IS31FL3731
MOUSEKEY_ENABLE   = yes
NKRO_ENABLE       = yes
RGBLIGHT_ENABLE   = no
UNICODE_ENABLE    = no

# Optimizations
EXTRAFLAGS += -flto
