# Open Speed Run(OSR) Autosplitter

An autosplitter for OSR to be used in conjunction with the client in the github. 
NOTE: due to how osr works windows will not work. Mac is untested

## Installation
1. Download the latest `OSRAuto.nrm` from Releases.
2. Put the file in your DK64 Recompiled mods folder.
   - Example (Linux): `/home/<your username>/.config/DK64Recompiled/mods/`
3. Launch DK64 Recompiled and enable the mod from the mods menu.
4. Launch [OpenSpeedRun](https://srwither.github.io/OpenSpeedRun-Site/)

## Build mod Requirements
- `clang`
- `ld.lld`
- `make`
- `RecompModTool` from [N64Recomp](https://github.com/N64Recomp/N64Recomp)

Notes:
- On macOS, Apple Clang is not enough for this target. Use an LLVM toolchain that supports MIPS and point `CC`/`LD` to it if needed.
- On Linux/macOS, ensure `zip` is installed for packaging workflows. 


## Building mod from Source
From the repository root:

```bash
make
```

This builds `build/mod.elf`.

Then package the mod:

```bash
RecompModTool mod.toml C:/path/to/DK64Recompiled/mods
```

The produced mod file is named `OSRAuto.nrm`.

## Project Layout
- `src/main.c`: Main gameplay patch logic.
- `src/connector.py` Connector script, deals with connectin to unix socket
- `mod.toml`: Mod metadata, target game id, and packaging inputs.
- `dk64_decomp/`: Decompiled DK64 source and headers used by the build.
- `Dk64Syms/`: Symbol files used by RecompModTool.

## Credits
See `authors` in `mod.toml` for the full contributor list included in the mod manifest.

## AI Disclosure
**NO ai was used while creating this mod.** my mods will never use ai and ai contributions will not be allowed.
