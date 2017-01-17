#include <stdio.h>
#include <stdlib.h>

/** Generates a password length characters long. Returns a pointer
 * to the generated password. This pointer must be free()'d by the
 * caller. */
char* generate_password(int length);

int main(int argc, char** argv) {
	int length;
	char* password;

	if (argc < 2) {
		printf("Enter a length for the password: ");
		scanf("%d", &length);
	}
	else {
		length = atoi(argv[1]);
	}

	fprintf(stderr, "If you do not get a password right away, it will be necessary to provide more random data. More your mouse, type on the keyboard or open some files to do this.\n");

	password = generate_password(length);
	if (password == NULL) {
		fprintf(stderr, "Error: cannot open /dev/random.");
		return 1;
	}
	printf("\n%s\n", password);
	free(password);

	return 0;
}

/** Generates a password length characters long. Returns a pointer
 * to the generated password. This pointer must be free()'d by the
 * caller. */
char* generate_password(int length) {
	char* buffer = malloc(length + 1);
	int i = 0;
	unsigned char c;

	while (1) {
		FILE* random = fopen("/dev/random", "r");
		if (random == NULL) {
			free(buffer);
			return NULL;
		}

		for (; i < length && fscanf(random, "%c", &c) != EOF; i++) {
			if (c > 95) {
				i--;
				continue;
			}
			buffer[i] = c + 32;
		}
		
		fclose(random);

		if (i == length) {
			buffer[length] = 0;
			break;
		}

	}

	return buffer;
}
