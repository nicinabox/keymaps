.PHONY: all
all:
	ruby link.rb

.PHONY: link-%
link-%:
	ruby link.rb $*
