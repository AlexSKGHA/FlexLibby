#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* generatePassword(char **charSets, size_t setNum, char *conditions, size_t passLength) {
	char *password = calloc(passLength + 1, 1);

	//Creating remapped sets according to conditions/
  char **remappedSets = calloc(setNum, sizeof (char*));
	int index = 0;
	for (int i = setNum; i > 0; i--) {
		if (conditions[i - 1] != 0) {
			remappedSets[index++] = charSets[i - 1];
		} else {
			setNum--;
		}
	}

  //Creating password with characters from remapped sets
	if (setNum > 0) {
		for (int i = 0; i < passLength; i++) {
			int pickSet = rand() % setNum;
			int setSize = strlen(remappedSets[pickSet]);
			password[i] = remappedSets[pickSet][rand() % setSize];
		}
	}

	free(remappedSets);
	return password;
}

char* generateDefaultSetPassword(size_t length, char* conditions) {
	char *abc[] = {"abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "0123456789", "!@#$%^&*()"};
	return generatePassword(abc, 4, conditions, length);
}
