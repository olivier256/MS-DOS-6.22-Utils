#include <stdio.h>
#include <conio.h>

struct KeyMap {
        unsigned char from;
        unsigned char to;
};

struct KeyMap map[] = {
        { '=', '-' },
        { '!', '=' },
        { '_', '!' },
        { '-', 'õ' },
        { 'õ', '+' },
        { 'œ', '*' },
        { 'æ', 'œ' },
        { '+', '_' },
        { 0, 0}
};

unsigned char translate(unsigned char c) {
        int i;

        for (i = 0 ; map[i].from != 0 ; i++) {
                if (map[i].from == c) {
                        return map[i].to;
                }
        }

        return c;
}

int pending_accent = 0;

void process_key(unsigned char c) {
        if ( c == '*') {
                pending_accent = 1;
                return;
        }

        if (pending_accent) {
                pending_accent = 0;

                switch (c) {
                        case 'a': putch('…'); return;
                        case 'e': putch('Š'); return;
                        case 'u': putch('—'); return;
                        case 'A': putch(0xB7); return;
                        case ' ': putch('`'); return;
                        default: putch('`'); break;
                }
        }

        putch(translate(c));
}

int main(void) {
        int c;
        unsigned char translated;

        printf("KEYFIX MVP - Press ESC to exit\n\n");

        while (1) {
                c = getch();

                /* Extended key prefix */
                if (c == 0) {
                        getch();
                        continue;
                }

                if (c == 27) {
                        break;
                }

                /*
                translated = translate((unsigned char) c);

                putch(translated);
                */
                process_key((unsigned char) c);
        }

        return 0;
}
