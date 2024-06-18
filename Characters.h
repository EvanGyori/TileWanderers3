/*
 This file contains the constants for which characters to draw.
 
 The characters may vary between platforms or for different styles.
 To change which unicode characters are used or to add new styles, 
 use the preprocessor and CMake cache variables.
 
 The list of unicode characters can be found at:
 https://en.wikipedia.org/wiki/List_of_Unicode_characters#Box_Drawing
*/

#pragma once

namespace CHARS
{

using CharType = const char* const;

// Map Characters
CharType BORDER_HORIZONTAL = "\u2550";
CharType BORDER_VERTICAL = "\u2551";
CharType BORDER_TOP_LEFT = "\u2554";
CharType BORDER_TOP_RIGHT = "\u2557";
CharType BORDER_BOTTOM_LEFT = "\u255A";
CharType BORDER_BOTTOM_RIGHT = "\u255D";

CharType PLAYER = "\u2573";

// Tile Characters
CharType HIDDEN_TILE = "\u2591";
CharType EMPTY_TILE = "\u2592";
}
