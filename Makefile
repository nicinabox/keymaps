QMK_ROOT = ../qmk_firmware
DEFAULT_KEYMAP = nic
KEYMAPS = $(filter-out handwired%, $(dir $(wildcard */.)))
HANDWIRED = $(dir $(wildcard ./handwired/*/))

link-keymaps: $(foreach keymap, $(KEYMAPS:%/=%), link-keymap-$(keymap))

link-handwired: $(foreach name, $(HANDWIRED:./handwired/%/=%), link-handwired-$(name))

link: link-keymaps link-handwired

link-keymap-%:
	rm -rf $(QMK_ROOT)/keyboards/$*/keymaps/$(DEFAULT_KEYMAP); \
	ln -s $(CURDIR)/$* $(QMK_ROOT)/keyboards/$*/keymaps/$(DEFAULT_KEYMAP)

link-handwired-%:
	rm -rf $(QMK_ROOT)/keyboards/handwired/$*; \
	ln -s $(CURDIR)/handwired/$* $(QMK_ROOT)/keyboards/handwired/$*

.PHONY: %

include $(QMK_ROOT)/Makefile
