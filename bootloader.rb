#!/usr/bin/env ruby

KEYBOARD_PATH = ARGV[0]

FLASHERS = {
  'lufa-dfu': 'dfu',
  'qmk-dfu': 'dfu',
  'atmel-dfu': 'dfu',
  'caterina': 'avrdude',
  'halfkay': 'teensy'
}

def bootloader
  bootloaders = FLASHERS.keys

  ['rules.mk', 'info.json'].each do |filename|
    result = bootloaders.find do |b|
      pattern = Regexp.new b.to_s
      File.foreach("#{KEYBOARD_PATH}/#{filename}").grep(pattern).any?
    end
    break result if result
  end
end

puts FLASHERS[bootloader]
