

/*
 * Fareed Read
 * http://www.facebook.com/fareed.reads
 *
 * SegoePrint10
 *
 * created with FontCreator
 * written by F. Maximilian Thiele
 *
 * http://www.apetech.de/fontCreator
 * me@apetech.de
 *
 * File Name           : SegoePrint10.h
 * Date                : 26.06.2018
 * Font size in bytes  : 7512
 * Font width          : 10
 * Font height         : 15
 * Font first char     : 32
 * Font last char      : 128
 * Font used chars     : 96
 *
 * The font data are defined as
 *
 * struct _FONT_ {
 *     uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
 *     uint8_t    font_Width_in_Pixel_for_fixed_drawing;
 *     uint8_t    font_Height_in_Pixel_for_all_characters;
 *     unit8_t    font_First_Char;
 *     uint8_t    font_Char_Count;
 *
 *     uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
 *                  // for each character the separate width in pixels,
 *                  // characters < 128 have an implicit virtual right empty row
 *
 *     uint8_t    font_data[];
 *                  // bit field of all characters
 */

#include <inttypes.h>
#include <avr/pgmspace.h>

#ifndef SEGOEPRINT10_H
#define SEGOEPRINT10_H

#define SEGOEPRINT10_WIDTH 10
#define SEGOEPRINT10_HEIGHT 15

const static uint8_t SegoePrint10[] PROGMEM = {
    0x1D, 0x58, // size
    0x0A, // width
    0x0F, // height
    0x20, // first char
    0x60, // char count
    
    // char widths
    0x00, 0x02, 0x03, 0x08, 0x05, 0x06, 0x08, 0x01, 0x04, 0x03, 
    0x04, 0x05, 0x02, 0x04, 0x01, 0x06, 0x07, 0x06, 0x07, 0x05, 
    0x06, 0x06, 0x06, 0x06, 0x05, 0x05, 0x01, 0x01, 0x04, 0x04, 
    0x04, 0x04, 0x08, 0x08, 0x06, 0x06, 0x07, 0x06, 0x05, 0x07, 
    0x07, 0x02, 0x06, 0x06, 0x05, 0x09, 0x07, 0x07, 0x06, 0x07, 
    0x07, 0x05, 0x07, 0x06, 0x07, 0x09, 0x07, 0x08, 0x08, 0x03, 
    0x05, 0x04, 0x05, 0x04, 0x03, 0x06, 0x05, 0x04, 0x06, 0x05, 
    0x03, 0x06, 0x06, 0x02, 0x02, 0x05, 0x02, 0x09, 0x07, 0x05, 
    0x06, 0x05, 0x04, 0x04, 0x05, 0x06, 0x05, 0x08, 0x05, 0x05, 
    0x05, 0x04, 0x01, 0x04, 0x07, 0x05, 
    
    // font data
    0xC0, 0xF8, 0x04, 0x00, // 33
    0x38, 0x00, 0x38, 0x00, 0x00, 0x00, // 34
    0x40, 0x40, 0xC0, 0x40, 0x30, 0xE0, 0xB8, 0xA0, 0x00, 0x02, 0x06, 0x02, 0x06, 0x00, 0x00, 0x00, // 35
    0x00, 0x60, 0xF0, 0x9C, 0x90, 0x02, 0x02, 0x0E, 0x00, 0x00, // 36
    0x70, 0x48, 0xF8, 0x28, 0x98, 0x80, 0x00, 0x06, 0x00, 0x06, 0x04, 0x02, // 37
    0x00, 0x80, 0xF8, 0x38, 0x80, 0x80, 0x80, 0x80, 0x06, 0x08, 0x0A, 0x0C, 0x04, 0x0A, 0x08, 0x08, // 38
    0x30, 0x00, // 39
    0xC0, 0x20, 0x10, 0x08, 0x0E, 0x10, 0x20, 0x00, // 40
    0x04, 0x18, 0xE0, 0x00, 0x10, 0x0E, // 41
    0xE0, 0x30, 0xE8, 0x20, 0x00, 0x00, 0x00, 0x00, // 42
    0x80, 0x80, 0xE0, 0x80, 0x80, 0x00, 0x00, 0x06, 0x00, 0x00, // 43
    0x00, 0x00, 0x08, 0x06, // 44
    0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, // 45
    0x00, 0x04, // 46
    0x00, 0x80, 0x60, 0x10, 0x08, 0x04, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, // 47
    0xC0, 0x20, 0x10, 0x08, 0x08, 0x98, 0x70, 0x06, 0x04, 0x04, 0x04, 0x02, 0x00, 0x00, // 48
    0x20, 0x10, 0xF8, 0x00, 0x00, 0x00, 0x04, 0x0C, 0x0E, 0x04, 0x04, 0x04, // 49
    0x00, 0x10, 0x08, 0x88, 0x48, 0x30, 0x00, 0x08, 0x04, 0x06, 0x04, 0x04, 0x04, 0x04, // 50
    0x10, 0x50, 0x70, 0x50, 0xC0, 0x04, 0x04, 0x04, 0x02, 0x02, // 51
    0xC0, 0xA0, 0x90, 0xF0, 0x98, 0x80, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, // 52
    0x00, 0x30, 0x48, 0x48, 0xC8, 0x08, 0x02, 0x04, 0x04, 0x06, 0x02, 0x00, // 53
    0xC0, 0xA0, 0xD0, 0x48, 0x40, 0xC0, 0x02, 0x06, 0x04, 0x04, 0x02, 0x02, // 54
    0x10, 0x10, 0x10, 0xD0, 0x30, 0x10, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, // 55
    0x60, 0x50, 0x90, 0xD0, 0x20, 0x06, 0x06, 0x04, 0x04, 0x06, // 56
    0xC0, 0xA0, 0x90, 0xD0, 0x70, 0x00, 0x00, 0x00, 0x06, 0x00, // 57
    0x40, 0x04, // 58
    0x20, 0x0E, // 59
    0xC0, 0xA0, 0x10, 0x00, 0x00, 0x00, 0x02, 0x02, // 60
    0xA0, 0xA0, 0xA0, 0xA0, 0x00, 0x00, 0x00, 0x00, // 61
    0x10, 0x20, 0xA0, 0x40, 0x00, 0x06, 0x00, 0x00, // 62
    0x90, 0x48, 0x48, 0x38, 0x04, 0x00, 0x00, 0x00, // 63
    0xC0, 0x20, 0xD0, 0xB8, 0xA8, 0x68, 0x98, 0x70, 0x02, 0x06, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, // 64
    0x00, 0x80, 0xE0, 0x90, 0x98, 0x60, 0x80, 0x00, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04, // 65
    0xD0, 0x38, 0x48, 0x48, 0x68, 0x98, 0x0E, 0x08, 0x08, 0x08, 0x04, 0x02, // 66
    0xC0, 0x30, 0x08, 0x04, 0x04, 0x1C, 0x02, 0x04, 0x04, 0x04, 0x02, 0x00, // 67
    0xE8, 0x18, 0x08, 0x08, 0x08, 0x98, 0x70, 0x06, 0x04, 0x04, 0x02, 0x02, 0x00, 0x00, // 68
    0x80, 0x78, 0x48, 0x48, 0x48, 0x08, 0x06, 0x04, 0x04, 0x04, 0x04, 0x00, // 69
    0xC0, 0x78, 0x48, 0x48, 0x08, 0x06, 0x00, 0x00, 0x00, 0x00, // 70
    0xC0, 0x30, 0x18, 0x08, 0x04, 0x84, 0x4C, 0x02, 0x04, 0x04, 0x04, 0x02, 0x0E, 0x00, // 71
    0xA0, 0x58, 0x40, 0x40, 0x40, 0xC0, 0x38, 0x06, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, // 72
    0xF0, 0x18, 0x06, 0x00, // 73
    0x00, 0x00, 0x00, 0x00, 0x80, 0x78, 0x02, 0x04, 0x04, 0x04, 0x02, 0x00, // 74
    0xE0, 0x58, 0xA0, 0x10, 0x08, 0x00, 0x06, 0x00, 0x00, 0x02, 0x06, 0x04, // 75
    0xE0, 0x38, 0x00, 0x00, 0x00, 0x06, 0x04, 0x04, 0x04, 0x04, // 76
    0x80, 0xF8, 0x30, 0xC0, 0x80, 0xC0, 0x20, 0xF0, 0x18, 0x0E, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x06, 0x00, // 77
    0xC0, 0x38, 0x20, 0xC0, 0x00, 0xC0, 0x38, 0x06, 0x00, 0x00, 0x00, 0x02, 0x06, 0x00, // 78
    0xC0, 0x20, 0x10, 0x08, 0x08, 0x08, 0xF0, 0x06, 0x08, 0x08, 0x08, 0x04, 0x02, 0x00, // 79
    0xF0, 0x88, 0x88, 0x48, 0x48, 0x30, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, // 80
    0xC0, 0x20, 0x10, 0x08, 0x08, 0x10, 0xE0, 0x02, 0x04, 0x04, 0x06, 0x0C, 0x1A, 0x00, // 81
    0xE0, 0x18, 0x48, 0xC8, 0xA8, 0x30, 0x00, 0x06, 0x00, 0x00, 0x00, 0x02, 0x02, 0x04, // 82
    0x70, 0x58, 0x88, 0x88, 0x18, 0x08, 0x08, 0x04, 0x06, 0x00, // 83
    0x08, 0x08, 0x08, 0xF8, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, // 84
    0xF8, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x06, 0x0C, 0x08, 0x08, 0x04, 0x02, // 85
    0x18, 0xE0, 0x00, 0x80, 0x40, 0x30, 0x08, 0x00, 0x00, 0x06, 0x02, 0x00, 0x00, 0x00, // 86
    0x78, 0x80, 0x00, 0xC0, 0x60, 0x80, 0x00, 0xC0, 0x38, 0x00, 0x06, 0x02, 0x00, 0x00, 0x02, 0x06, 0x00, 0x00, // 87
    0x00, 0x18, 0xA0, 0x40, 0xA0, 0x10, 0x08, 0x08, 0x06, 0x00, 0x00, 0x00, 0x02, 0x04, // 88
    0x08, 0x10, 0x20, 0xC0, 0x40, 0x20, 0x10, 0x08, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, // 89
    0x00, 0x08, 0x88, 0xC8, 0x48, 0x28, 0x18, 0x08, 0x04, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04, 0x04, // 90
    0xFC, 0x04, 0x04, 0x1E, 0x10, 0x00, // 91
    0x04, 0x18, 0x60, 0x80, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0C, // 92
    0x00, 0x08, 0xE8, 0x1C, 0x20, 0x20, 0x3E, 0x00, // 93
    0x40, 0x30, 0x18, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, // 94
    0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 0x08, // 95
    0x08, 0x10, 0x20, 0x00, 0x00, 0x00, // 96
    0x00, 0xC0, 0x60, 0x20, 0xC0, 0x00, 0x0E, 0x08, 0x04, 0x06, 0x0E, 0x08, // 97
    0xE0, 0x9C, 0x40, 0x20, 0xE0, 0x0E, 0x08, 0x08, 0x06, 0x00, // 98
    0x80, 0xC0, 0x20, 0x60, 0x0E, 0x08, 0x08, 0x04, // 99
    0x80, 0x40, 0x20, 0x20, 0xE0, 0x1C, 0x06, 0x04, 0x04, 0x02, 0x06, 0x04, // 100
    0x80, 0x40, 0xA0, 0x60, 0x00, 0x0E, 0x0A, 0x08, 0x08, 0x04, // 101
    0xF8, 0x24, 0x22, 0x0E, 0x00, 0x00, // 102
    0x00, 0x80, 0x40, 0x20, 0xA0, 0x60, 0x4E, 0x48, 0x48, 0x24, 0x1E, 0x00, // 103
    0xE0, 0x9C, 0x40, 0x20, 0xE0, 0x00, 0x06, 0x02, 0x00, 0x00, 0x06, 0x04, // 104
    0x80, 0x64, 0x06, 0x00, // 105
    0x00, 0xF4, 0x20, 0x1E, // 106
    0xE0, 0x9C, 0x40, 0x40, 0x20, 0x06, 0x00, 0x02, 0x04, 0x04, // 107
    0xE0, 0x1C, 0x0E, 0x00, // 108
    0x80, 0xE0, 0x40, 0x20, 0xE0, 0x80, 0x40, 0xE0, 0x00, 0x06, 0x02, 0x00, 0x00, 0x02, 0x00, 0x00, 0x02, 0x04, // 109
    0xE0, 0x80, 0x40, 0x20, 0xE0, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x06, 0x04, // 110
    0x80, 0x40, 0x20, 0x20, 0xC0, 0x06, 0x08, 0x08, 0x04, 0x02, // 111
    0x00, 0xE0, 0x80, 0x40, 0x20, 0xE0, 0x3C, 0x02, 0x04, 0x04, 0x02, 0x00, // 112
    0x80, 0x60, 0x30, 0x90, 0xE0, 0x06, 0x04, 0x02, 0x3E, 0x00, // 113
    0xE0, 0xC0, 0x20, 0x20, 0x06, 0x00, 0x00, 0x00, // 114
    0x00, 0x60, 0x90, 0x90, 0x04, 0x04, 0x04, 0x02, // 115
    0x20, 0xF0, 0x28, 0x20, 0x20, 0x00, 0x06, 0x04, 0x02, 0x00, // 116
    0x80, 0x60, 0x00, 0x80, 0xE0, 0x00, 0x06, 0x04, 0x06, 0x02, 0x06, 0x04, // 117
    0xE0, 0x00, 0x00, 0x80, 0x60, 0x00, 0x06, 0x06, 0x00, 0x00, // 118
    0xF0, 0x00, 0x80, 0xF0, 0x90, 0x00, 0xC0, 0x30, 0x02, 0x04, 0x02, 0x00, 0x02, 0x04, 0x02, 0x00, // 119
    0x00, 0x60, 0x80, 0x40, 0x20, 0x0C, 0x06, 0x02, 0x04, 0x08, // 120
    0x00, 0xE0, 0x00, 0x00, 0xE0, 0x10, 0x26, 0x24, 0x32, 0x0E, // 121
    0x00, 0x20, 0xA0, 0x60, 0x20, 0x04, 0x06, 0x04, 0x04, 0x04, // 122
    0x80, 0x90, 0x68, 0x08, 0x00, 0x1E, 0x10, 0x10, // 123
    0xFF, 0xFE, // 124
    0x04, 0x04, 0x64, 0x9C, 0x00, 0x10, 0x12, 0x1C, // 125
    0xC0, 0x20, 0x20, 0x40, 0x80, 0x80, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 126
    0xF8, 0x08, 0x08, 0x08, 0xF8, 0x06, 0x04, 0x04, 0x04, 0x06 // 127
    
};

#endif