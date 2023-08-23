# Screenshoot
<img src="https://github.com/yuraa-id/dwm/blob/main/screenshot/Screenshot_2023-08-22_14-33-17.png">
<img src="https://github.com/yuraa-id/dwm/blob/main/screenshot/Screenshot_2023-08-22_14-16-53.png">

# Requirements
- ifstat
- imlib2 
- picom
- dunst
- zsh (oh-my-zsh)
- xsetroot package (status2d uses this to add colors on dwmbar)

# Apps used
- scrot / flameshot : take screenshots
- firefox           : web browser
- thunar            : file manager
- xterm / st        : terminal
- rofi / dmenu      : launcher apps menu
- nvchad            : text editor

(see config.def.h to conform keybindings of the apps)

# icon & theme
- cursor = ComixCursor
- icon   = TokyoNight-SE
- themes = Monochrome-GTK , Tokyonight-Dark-B

# Font
- JetbrainsMono Nerd Font
- included in font folder

# Install 
- In zsh (oh-my-zsh)
```
# edit .zshrc and add this line
export PATH=$HOME/.local/bin/scripts:$PATH
export PATH=$HOME/.local/bin:$PATH
```
- make install
```
cd dwm
sudo make install
```
- launch statusbar
```
bar.sh
```

# Patch
- alt tag decoration
- attach top
- bar padding
- center
- cfact vanitygaps
- colorful tag by [chadwm](https://github.com/siduck/chadwm)
- cycle layouts
- movestack
- pertag
- restartsig
- restore after restart
- stairs fullgaps
- status2d
- statuscmd-status2d
- status padding
- tag preview
- tatami
- underlinetag

# Credit
- inspired by [chadwm](https://github.com/siduck/chadwm) for Color themes
- for script statusbar [bandithijo](https://bandithijo.dev/)
- for rofi themes [adi1090x](https://github.com/adi1090x/rofi/tree/master)
