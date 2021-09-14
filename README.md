# Byte Swapper

Swaps the endianness based upon a given bit boundary (or does a 16-bit (2-byte) swap if unspecified). Tested cross-platform between at least Windows and Linux (although you'll have to find your own method of compilation for Windows).

### Usage
```
./byte_swap <input_file> <swap_num>
```

And there will be an output file `<input_file>.rev`

### Examples
#### Linux
16-bit swap (default):
```
./byte_swap example.txt
```
32-bit swap:
```
./byte_swap example.txt 32
```

#### Windows
16-bit swap (default):
```
byte_swap.exe example.txt
```
32-bit swap:
```
byte_swap.exe example.txt 32
```

On Windows, you can also drag/drop the file onto byte_swap.exe in order to run it through the byte swapper.
