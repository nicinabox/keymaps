QMK_ROOT = ../qmk_firmware
DEFAULT_KEYMAP = nic
KEYMAPS = $(filter-out handwired%, $(dir $(wildcard */.)))
HANDWIRED = $(dir $(wildcard ./handwired/*/))

include $(QMK_ROOT)/Makefile

.PHONY: link-keymaps
link-keymaps: $(foreach keymap, $(KEYMAPS:%/=%), link-keymap-$(keymap))

.PHONY: link-handwired
link-handwired: $(foreach name, $(HANDWIRED:./handwired/%/=%), link-handwired-$(name))

.PHONY: link
link: link-keymaps link-handwired

.PHONY: link-keymap-%
link-keymap-%:
	rm -rf $(QMK_ROOT)/keyboards/$*/keymaps/$(DEFAULT_KEYMAP); \
	ln -s $(CURDIR)/$* $(QMK_ROOT)/keyboards/$*/keymaps/$(DEFAULT_KEYMAP)

.PHONY: link-handwired-%
link-handwired-%:
	rm -rf $(QMK_ROOT)/keyboards/handwired/$*; \
	ln -s $(CURDIR)/handwired/$* $(QMK_ROOT)/keyboards/handwired/$*
