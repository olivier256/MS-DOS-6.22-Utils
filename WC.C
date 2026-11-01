#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	FILE *f;
	int c, inword=0;
	long lines = 0, words = 0, bytes = 0;

	if (argc != 2) {
		printf("Usage: wc fichier\n");
		return 1;
	}

	f = fopen(argv[1], "rb");
	if (!f) {
		printf("Erreur ouverture fichier %s\n", argv[1]);
		return 1;
	}

	while ((c = fgetc(f)) != EOF) {
		bytes++;

		if (c == '\n') {
			lines++;
		}

		if (isspace((unsigned char) c)) {
			inword = 0;
		} else if (!inword) {
			inword = 1;
			words++;
		}
	}

	fclose(f);

	printf("%ld lignes, %ld mots, %ld octets\n", lines, words, bytes);

	return 0;
}
