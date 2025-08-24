# QMK Ferris Sweep Keymap Development Workflow

This document outlines the complete workflow for updating and deploying QMK keymaps for the Ferris Sweep keyboard.

## Required Steps for Keymap Updates

When updating the keymap, **ALL** of the following steps must be performed in order:

### 1. Edit the Keymap
- Modify `keymaps/qwerty2/keymap.c` with the required changes
- Follow existing patterns for tap dance, custom keycodes, etc.
- Ensure proper syntax and QMK conventions

### 2. Compile the Firmware
```bash
qmk compile -kb ferris/sweep -km qwerty2
```
- Verify compilation succeeds without errors
- Check firmware size is within limits (should be < 28,672 bytes)
- Note any warnings or issues

### 3. Flash the Firmware
```bash
qmk flash -kb ferris/sweep -km qwerty2
```
- Put keyboard in bootloader mode when prompted
- Verify successful flash and validation
- Test basic functionality

### 4. Generate JSON Keymap
```bash
qmk c2json -kb ferris/sweep -km qwerty2 keymaps/qwerty2/keymap.c > keymaps/qwerty2/keymap.json
```
- This creates/overwrites the JSON representation
- Required for QMK Configurator compatibility
- Ensures C and JSON keymaps stay synchronized

### 5. Commit Changes
```bash
# Stage all modified files
git add keymaps/qwerty2/keymap.c keymaps/qwerty2/keymap.json

# Commit with descriptive message
git commit -m "$(cat <<'EOF'
[Brief description of changes]

[Detailed explanation of what was modified]

🤖 Generated with [Claude Code](https://claude.ai/code)

Co-Authored-By: Claude <noreply@anthropic.com>
EOF
)"
```

## Current Keymap Features

### Tap Dance Keys (Layer 0)
- **Q** → hold: ! (exclamation)
- **W** → hold: @ (at)
- **E** → hold: # (hash)
- **R** → hold: $ (dollar)
- **T** → hold: % (percent)
- **Y** → hold: ^ (caret)
- **U** → hold: & (ampersand)
- **I** → hold: * (asterisk)
- **O** → hold: ( (left parenthesis)
- **P** → hold: ) (right parenthesis)
- **S** → hold: ~ (tilde)
- **H** → hold: - (minus)
- **L** → hold: ? (question mark)
- **M** → hold: / (slash)
- **,** → hold: : (colon)
- **.** → hold: " (double quote)

### Special Keys
- **BOOT_HOLD**: Hold for 5 seconds to enter bootloader mode

### Layer Structure
- **Layer 0**: Main QWERTY with tap dance
- **Layer 1**: Numbers, navigation, symbols
- **Layer 2**: Function keys, mouse controls

## Important Notes

- **Never skip any step** - all steps are required for proper deployment
- **Always test** the keyboard after flashing before committing
- **Maintain JSON sync** - the JSON file must be regenerated after any C changes
- **Use descriptive commit messages** that explain what functionality was added/changed
- **Follow QMK best practices** for code style and conventions

## Troubleshooting

### Compilation Errors
- Check syntax in keymap.c
- Verify all custom keycodes are properly defined
- Ensure tap dance arrays match enum definitions

### Flash Issues
- Ensure keyboard is in bootloader mode
- Check USB connection
- Try different USB port or cable

### Functionality Issues
- Verify tap dance timing settings
- Check layer definitions
- Test with QMK's built-in debugging tools

## File Structure
```
keymaps/qwerty2/
├── keymap.c     # Main C implementation
├── keymap.json  # JSON representation (auto-generated)
└── rules.mk     # Build configuration
```