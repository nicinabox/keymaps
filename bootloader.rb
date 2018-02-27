#!/usr/bin/env ruby

KEYBOARD_PATH = ARGV[0]

def parse_rules(line)
  line and line.match(/=\s?(.*)/)[1]
end

def parse_info_json(line)
  line and line.match(/:\s?"(.*)"/)[1]
end

def read_rules
  File.open "#{KEYBOARD_PATH}/rules.mk" do |f|
    f.find { |line| line =~ /BOOTLOADER\s?=/ }
  end
end

def read_info_json
  File.open "#{KEYBOARD_PATH}/info.json" do |f|
    f.find { |line| line =~ /"bootloader"/ }
  end
end

def bootloader
  parse_rules(read_rules) or parse_info_json(read_info_json)
end

case bootloader
when 'lufa-dfu'
when 'qmk-dfu'
when 'atmel-dfu'
  puts 'dfu'

when 'caterina'
  puts 'avrdude'

when 'halfkay'
  puts 'teensy'
end
