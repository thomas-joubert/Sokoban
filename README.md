# Sokoban

This game is basic Sokoban game. The goal is to put every box in their
respective spot.

# Build

The game relies on the SFML library for graphics.

To build the project, run:

`meson build builddir && cd builddir && meson compile`

This will produce the `sokoban` binary.

# Tests

To run tests, run:

`meson build builddir && cd builddir && meson test`
