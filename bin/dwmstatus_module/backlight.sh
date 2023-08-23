light=$(brightnessctl -m -d amdgpu_bl1 | cut -d, -f4 | tr -d %)
echo "" $light #"%"
