/*
 * ebd: Eight Bit Dump - A hexdump utility for 8 bit software development
 *
 * http://github.com/simonboak/ebd
 *
 * Copyright (c) 2020 Simon Boak
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_PER_ROW 8

static void usage(const char *prog) {
    fprintf(stderr,
        "ebd: Eight Bit Dump - A hexdump utility for 8 bit software development\n"
        "http://github.com/simonboak/ebd - Version 2.0.0\n\n"
        "Usage: %s -f <file> [-a <address>] [-d]\n\n"
        "  -f <file>      Input file to dump\n"
        "  -a <address>   Decimal starting address of output (default: 0)\n"
        "  -d             Display ASCII characters to the right of output\n",
        prog);
}

int main(int argc, char *argv[]) {
    const char *filename = NULL;
    unsigned int byte_count = 0;
    int display_ascii = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--file") == 0) {
            if (++i >= argc) { fprintf(stderr, "Missing argument for -f\n"); return 1; }
            filename = argv[i];
        } else if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--address") == 0) {
            if (++i >= argc) { fprintf(stderr, "Missing argument for -a\n"); return 1; }
            byte_count = (unsigned int)atoi(argv[i]);
        } else if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--displayascii") == 0) {
            display_ascii = 1;
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            usage(argv[0]);
            return 0;
        } else {
            fprintf(stderr, "Unknown argument: %s\n", argv[i]);
            usage(argv[0]);
            return 1;
        }
    }

    if (!filename) {
        fprintf(stderr, "Error: -f <file> is required\n");
        usage(argv[0]);
        return 1;
    }

    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror(filename);
        return 1;
    }

    unsigned char row[BYTES_PER_ROW];
    int row_len;

    for (;;) {
        row_len = 0;
        while (row_len < BYTES_PER_ROW) {
            int c = fgetc(fp);
            if (c == EOF) break;
            row[row_len++] = (unsigned char)c;
        }

        if (row_len == 0) break;

        printf("%04X: ", byte_count & 0xFFFF);

        for (int i = 0; i < row_len; i++) {
            printf("%02X ", row[i]);
            byte_count++;
        }

        if (display_ascii) {
            for (int i = row_len; i < BYTES_PER_ROW; i++)
                printf("   ");
            for (int i = 0; i < row_len; i++) {
                if (row[i] > 31 && row[i] < 127)
                    putchar(row[i]);
                else
                    putchar('.');
            }
        }

        putchar('\n');

        if (row_len < BYTES_PER_ROW) break;
    }

    fclose(fp);
    return 0;
}
