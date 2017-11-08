#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Lucy Xu showed me what stpcpy does. I was experimenting with memcpy, trying to find a way to get just what I needed, when Lucy told me that stpcpy will stop when it encounters a null. //
typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2,
  YEARS_LEFT_AND_NAME = 3,
} Mode;

typedef struct {
  char *first_name;
  char *last_name;
  char *major;
  int year; 
} Student;

void print_student(Mode m, Student s) {
  switch (m) {
    case NAME_ONLY:
		printf("%s %s\n", s.first_name, s.last_name);
		break;
	case MAJOR_AND_NAME: 
		printf("%s %s %s\n", s.major, s.first_name, s.last_name);
		break;
	case YEAR_AND_NAME:
		printf("%d %s %s\n", s.year, s.first_name, s.last_name);
		break;
	case YEARS_LEFT_AND_NAME:
		printf("%d %s %s\n", (s.year - 2017), s.first_name, s.last_name);
		break;
	default:
		printf("error\n");
		break;
  }
}
// try adding years left in case

int main(int argc, char *argv[]) {

	char first_name[256];
	char last_name[256];
	char major[256];
	int year;
	int j=0;
	char *filename = argv[1];
	FILE *fp = fopen(filename,"r");// r for read, w for write
	char buffer[256];
	Student toby[256];
	
	while ((fgets(buffer, 255, fp)) != NULL) { // malloc for everything except year
		sscanf(buffer, "%s %s %s %d", first_name, last_name, major, &year);
		toby[j].first_name = ((char*)malloc(strlen(first_name)+1)); 
		toby[j].last_name = ((char*)malloc(strlen(first_name)+1));
		toby[j].major = ((char*)malloc(strlen(first_name)+1));
		toby[j].year = year; 
		
		stpcpy(toby[j].first_name,first_name);
		stpcpy(toby[j].last_name,last_name); 
		stpcpy(toby[j].major,major);
	j++;
	}
	
	int i;	// defining index and mode
	int m;
	
	if (1==1) { // must read from text file
		
		printf("index then mode\n");
		fscanf(stdin,"%d %d", &i, &m);
		print_student(m,toby[i]); //i'th toby using mode m
	}
	for (int j = 0; j < i; j++) {
	}
  return 0;
}
