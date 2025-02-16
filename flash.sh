#!/bin/zsh
source ./config.sh

QMK_PATH="$HOME/src/qmk_firmware"
SOURCE_KEYBOARD=${1#keyboards/}
TARGET_KEYBOARD=${keyboards[$SOURCE_KEYBOARD]:-$SOURCE_KEYBOARD}
KEYMAP=${2:-$USER}

qmk flash -kb "$TARGET_KEYBOARD" -km "$KEYMAP"
