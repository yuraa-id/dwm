# Screenshoot
<img src="https://github.com/yuraa-id/dwm/blob/main/screenshot/Screenshot_2023-08-22_14-33-17.png">
<img src="https://github.com/yuraa-id/dwm/blob/main/screenshot/Screenshot_2023-08-22_14-16-53.png">

# Requirements
- imlib2 
- xsetroot package (status2d uses this to add colors on dwmbar)
- picom
- dunst
- nitrogen
- oh-my-zsh
- zsh
- xterm (this terminal used in the default config in dwm)

# icon & theme
- cursor = ComixCursor
- icon = TokyoNight-SE
- theme = Monochrome-GTK , Tokyonight-Dark-B

# Font
- JetbrainsMono Nerd Font
- include in font folder

# Install 
  edit .zshrc
```
export PATH=$HOME/.local/bin/scripts:$PATH
export PATH=$HOME/.local/bin:$PATH
```
 edit config.def.h to change keybindings and menu launcher (default is dmenu)
 
```
cd dwm
sudo make install
```
  launch statusbar
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
- for Color theme [chadwm](https://github.com/siduck/chadwm)
- for script statusbar [bandithijo](https://bandithijo.dev/)
