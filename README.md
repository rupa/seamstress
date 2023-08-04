# seamstress

seamstress is a Lua scripting environment for monome devices and OSC communication.

currently beta software.

## installation

seamstress requires `freetype2`, `harfbuzz` and `ncurses`. on macOS do

```bash
brew install freetype2 harfbuzz ncurses
```

on linux, additional requirements include `alsa`.
each release comes with a binary for `x86_64` linux and macOS,
as well as `aarch64` (Apple silicon) macOS.
download the appropriate file, unzip it and 
(technically optionally) add it to your PATH.

NB: `seamstress` expects the file structure found inside the zipped folder
and will not work as expected if you move only the binary to a different folder.

## building from source


building seamstress from source requires version 0.11.0 of [zig](https://github.com/ziglang/zig).
the easiest way to get zig is to download a binary from [here](https://ziglang.org/download/) and add it to your PATH.
seamstress follows releases of zig.
to build seamstress, install the dependencies listed above (as well as `pkg-config`) and invoke

```bash
git submodule update --init --recursive
zig build
```

if you get an error about `lua.h` not being found, try this
```bash
pushd lib/ziglua
zig build
popd
```
and then retry the `zig build` step above.

NB: these commands build `seamstress` in Debug mode.
you can change this 
by passing `-Doptimize=ReleaseFast` or `-Doptimize=ReleaseSafe` to the build command.

## usage

invoke `seamstress` from the terminal.
`Ctrl+C`, 'quit' or closing the OS window exits.
by default seamstress looks for and runs a file called `script.lua`
in either the current directory or in `~/seamstress/`.
this behavior can be overridden, see `seamstress -h` for details.

## docs

the lua API is documented [here](https://ryleealanza.org/assets/doc/index.html).
to regenerate docs, you'll need [LDoc](https://github.com/lunarmodules/ldoc),
which requires Penlight.
with both installed, running `ldoc .` in the base directory of seamstress will
regenerate documentation.

## acknowledgments

seamstress is inspired by [monome norns's](https://github.com/monome/norns) matron,
which was written by @catfact.
norns was initiated by @tehn.
