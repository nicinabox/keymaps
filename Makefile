QMK_ROOT = ../qmk_firmware
KEYMAP = nic
KEYMAPS = $(filter-out handwired%, $(dir $(wildcard */.)))
HANDWIRED = $(dir $(wildcard ./handwired/*/))

link-keymaps: $(foreach keymap, $(KEYMAPS:%/=%), link-keymap-$(keymap))

link-handwired: $(foreach name, $(HANDWIRED:./handwired/%/=%), link-handwired-$(name))

link: link-keymaps link-handwired

link-keymap-%:
	ln -sf $(CURDIR)/$* $(QMK_ROOT)/keyboards/$*/keymaps/$(KEYMAP)

link-handwired-%:
	ln -sf $(CURDIR)/handwired/$* $(QMK_ROOT)/keyboards/handwired/$*

include $(QMK_ROOT)/Makefile

.PHONY: link link-keymaps link-handwired link-keymaps-% link-handwired-%
