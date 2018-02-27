#!/usr/bin/env ruby

KEYBOARD_PATH = ARGV[0]

FLASHERS = {
  'lufa-dfu': 'dfu',
  'qmk-dfu': 'dfu',
  'atmel-dfu': 'dfu',
  'caterina': 'avrdude',
  'halfkay': 'teensy'
}

def find_bootloader
  bootloaders = FLASHERS.keys

  ['rules.mk', 'info.json'].map do |filename|
    result = bootloaders.find do |b|
      pattern = Regexp.new b.to_s
      File.foreach("#{KEYBOARD_PATH}/#{filename}").grep(pattern).any?
    end
    break result if result
  end
end

def flasher(bootloader)
  FLASHERS[bootloader]
end

puts flasher(find_bootloader)
