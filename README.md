# Screenshoot
<img src="https://github.com/yuraa-id/dwm/blob/main/screenshot/2023-08-29-145512_1366x768_scrot.png">
<img src="https://github.com/yuraa-id/dwm/blob/main/screenshot/2023-08-29-145953_1366x768_scrot.png">

# Requirements
- ifstat
- imlib2 
- picom
- dunst
- zsh (oh-my-zsh)
- xsetroot package (status2d uses this to add colors on dwmbar)

# Apps used
- scrot / flameshot : take screenshots
- chromium          : web browser
- thunar            : file manager
- xterm / st        : terminal
- rofi / dmenu      : launcher apps menu
- nvchad / sublime  : text editor
- xsecurelock       : lockscreen

(see config.def.h to conform keybindings of the apps)

# icon & theme
- cursor = ComixCursor
- icon   = TokyoNight-SE
- themes = Monochrome-GTK , Tokyonight-Dark-B

# Font
- JetbrainsMono Nerd Font
- included in font folder (DWM logo)

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
# add to .xinitrc / .profile (if use display manager)
bar.sh &
```

# Patch
- actualfullscreen
- alt tag decoration
- attach top
- bar padding
- center
- cfact vanitygaps combo
- [colorful tag](https://github.com/fitrh/dwm/issues/1)
- cycle layouts
- launchers
- movecenter
- movestack
- movethrow
- noborder
- notitle
- pertag
- resizecorner
- restartsig
- restore after restart
- scratchpad
- stairs fullgaps
- status2d
- statusbutton
- statuscmd-status2d
- status padding
- tatami
- underlinetag

# Credit
- inspired by [chadwm](https://github.com/siduck/chadwm) for themes
- for script statusbar [bandithijo](https://bandithijo.dev/)
- for rofi themes [adi1090x](https://github.com/adi1090x/rofi/tree/master)
