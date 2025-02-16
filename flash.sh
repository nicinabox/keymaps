#!/bin/zsh
source ./config.sh

QMK_PATH="$HOME/src/qmk_firmware"
SOURCE_KEYBOARD=${1}
TARGET_KEYBOARD=${keyboards[$1]:-$1}
KEYMAP=${2:-$USER}

qmk flash -kb "$TARGET_KEYBOARD" -km "$KEYMAP"
