# MCU name
MCU = at90usb1286

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   atmega32a    bootloadHID
BOOTLOADER = halfkay

# If you don't know the bootloader type, then you can specify the
# Boot Section Size in *bytes* by uncommenting out the OPT_DEFS line
#   Teensy halfKay      512
#   Teensy++ halfKay    1024
#   Atmel DFU loader    4096
#   LUFA bootloader     4096
#   USBaspLoader        2048
# OPT_DEFS += -DBOOTLOADER_SIZE=4096

# Build Options
#   change yes to no to disable
BACKLIGHT_ENABLE   = no
BLUETOOTH_ENABLE   = no
BOOTMAGIC_ENABLE   = no
COMMAND_ENABLE     = yes
CONSOLE_ENABLE     = yes
EXTRAKEY_ENABLE    = yes
# LED_MATRIX_ENABLE  = yes
MOUSEKEY_ENABLE    = yes
NKRO_ENABLE        = yes
RGBLIGHT_ENABLE    = no
SPACE_CADET_ENABLE = yes
UNICODE_ENABLE     = no
