NAME = nic
QMK_DIR = ../qmk_firmware
KEYBOARDS_PATH = $(QMK_DIR)/keyboards

.PHONY: cp/handwired/%
cp/handwired/%:
	@mkdir -p $(KEYBOARDS_PATH)/handwired/$*
	@cp -r handwired/$*/* $(KEYBOARDS_PATH)/handwired/$*

.PHONY: build\:handwired/%
build\:handwired/%: cp/handwired/%
	@cd $(QMK_DIR) && make handwired/$*

.PHONY: flash\:handwired/%
flash\:handwired/%: cp/handwired/%
	@FLASHER=$(shell ruby bootloader.rb $(KEYBOARDS_PATH)/handwired/$*); \
	cd $(QMK_DIR) && make handwired/$*:$$FLASHER

.PHONY: cp/%
cp/%:
	@mkdir -p $(KEYBOARDS_PATH)/$*/keymaps/$(NAME)
	@cp -r $*/* $(KEYBOARDS_PATH)/$*/keymaps/$(NAME)

.PHONY: build\:%
build\:%: cp/%
	@cd $(QMK_DIR) && make $*:$(NAME)

.PHONY: flash\:%
flash\:%: cp/%
	@FLASHER=$(shell ruby bootloader.rb $(KEYBOARDS_PATH)/$*); \
	cd $(QMK_DIR) && make $*:$(NAME):$$FLASHER
