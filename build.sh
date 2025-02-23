#!/bin/zsh
source ./config.sh

QMK_PATH="$HOME/src/qmk_firmware"
SOURCE_KEYBOARD=${1#keyboards/}
TARGET_KEYBOARD=${keyboards[$SOURCE_KEYBOARD]:-$SOURCE_KEYBOARD}
KEYMAP=${2:-$USER}

echo "Syncing userspace files $SOURCE_KEYBOARD -> $TARGET_KEYBOARD.."

mkdir -p "$QMK_PATH/users/$KEYMAP"
mkdir -p "$QMK_PATH/keyboards/$TARGET_KEYBOARD/keymaps/$KEYMAP"

rsync -av --delete users/$KEYMAP/ "$QMK_PATH/users/$KEYMAP"

ROOT_KEYBOARD=$(echo $TARGET_KEYBOARD | sed 's|/rev[0-9]*$||')
rsync -av --delete keyboards/$SOURCE_KEYBOARD/ "$QMK_PATH/keyboards/$ROOT_KEYBOARD/keymaps/$KEYMAP"

echo "Building firmware for $TARGET_KEYBOARD:$KEYMAP..."
cd "$QMK_PATH"
qmk compile -kb "$TARGET_KEYBOARD" -km "$KEYMAP"

if [ $? -eq 0 ]; then
    echo "Build successful!"
    echo "To flash, run: ./flash.sh keyboards/$SOURCE_KEYBOARD"
else
    echo "Build failed!"
    exit 1
fi
