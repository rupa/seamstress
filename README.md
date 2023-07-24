# seamstress

seamstress is a Lua scripting environment for monome devices and OSC communication.

currently beta software.

## installation

requires `freetype2`, `harfbuzz`, `pkg-config` and `ncurses`. on macOS do

```bash
brew install freetype2 harfbuzz ncurses pkg-config
```

on linux, additional requirements include `alsa`.

building seamstress from source requires the master build of [zig](https://github.com/ziglang/zig).
the easiest way to get zig is to download a binary from [here](https://ziglang.org/download/) and add it to your PATH.
currently the earliest zig supported is `0.11.0-dev.3859`.
once zig 0.11 is released, seamstress will follow releases of zig, rather than the master.
to build seamstress, invoke

```bash
git submodule update --init --recursive
sudo zig build install -p /usr/local -Doptimize=ReleaseFast
```

if you get an error about `lua.h` not being found, try this
```bash
pushd lib/ziglua
zig build
popd
```
and then retry the `sudo zig build` step above.

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
