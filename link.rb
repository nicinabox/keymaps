#!/usr/bin/env ruby

QMK_ROOT = "../qmk_firmware"
DEFAULT_KEYMAP = "nic"
CURDIR = Dir.pwd()

def symlink(dir)
  if dir.include? "handwired"
    `rm -rf #{QMK_ROOT}/keyboards/#{dir}`
    `ln -s #{CURDIR}/#{dir} #{QMK_ROOT}/keyboards/#{dir}`
  else
    `rm -rf #{QMK_ROOT}/keyboards/#{dir}/keymaps/#{DEFAULT_KEYMAP}`
    `ln -s #{CURDIR}/#{dir} #{QMK_ROOT}/keyboards/#{dir}/keymaps/#{DEFAULT_KEYMAP}`
  end
end

def link_keymap(name)
  files = Dir.glob("#{name}/**/keymap.c")
  dir = File.dirname(files.first)

  symlink dir
  puts "Linked #{dir}"
end

def link_handwired(dir)
  if dir === "handwired"
    Dir.glob("#{dir}/*").each { |name| link_handwired(name) }
  else
    symlink dir
    puts "Linked #{dir}"
  end
end

def link_all
  dirs = Dir.glob("*").select {|f| File.directory? f}
  dirs.each do |dir|
    run dir
  end
end

def run(target)
  if target
    if target.include? "handwired"
      link_handwired target
    else
      link_keymap target
    end
  else
    link_all
  end
end

run ARGV[0]
