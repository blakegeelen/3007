
#include "curdle.h"

/** \file adjust_score.c
 * \brief Functions for safely amending a player's score in the
 * `/var/lib/curdle/scores` file.
 *
 * Contains the \ref adjust_score_file function, plus supporting data
 * structures and functions used by that function.
 *
 * ### Known bugs
 *
 * \bug The \ref adjust_score_file function does not yet work.
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

// for off_t
#include <sys/types.h>

/** Size of a field (name or score) in a line of the `scores`
  * file.
  */
const size_t FIELD_SIZE = FIELD_SIZE_;

/** Size of a line in the `scores` file.
  */
const size_t REC_SIZE   = REC_SIZE_;

/** Initialize a \ref score_record struct.
  *
  * \param rec pointer to a \ref score_record struct to initialize.
  * \param name player name to be inserted into `rec`.
  * \param score player score to be inserted into `rec`.
  */
void score_record_init(struct score_record *rec, const char *name, int score) {
  // this function is needed to initialize a score_record,
  // because you can't *assign* to the name member -- it's an array.
  // so we must copy the name in.
  memset(rec->name, 0, FIELD_SIZE);
  strncpy(rec->name, name, FIELD_SIZE);
  rec->name[FIELD_SIZE-1] = '\0';
  rec->score = score;
}


/** Adjust the score for player `player_name`, incrementing it by
  * `score_to_add`. The player's current score (if any) and new score
  * are stored in the scores file at `/var/lib/curdle/scores`.
  * The scores file is owned by user ID `uid`, and the process should
  * use that effective user ID when reading and writing the file.
  * If the score was changed successfully, the function returns 1; if
  * not, it returns 0, and sets `*message` to the address of
  * a string containing an error message. It is the caller's responsibility
  * to free `*message` after use.
  *
  * \todo implement the function.
  *
  * \param uid user ID of the owner of the scores file.
  * \param player_name name of the player whose score should be incremented.
  * \param score_to_add amount by which to increment the score.
  * \param message address of a pointer in which an error message can be stored.
  * \return 1 if the score was successfully changed, 0 if not.
  */
int adjust_score(uid_t uid, const char * player_name, int score_to_add, char **message) {
	while player_name.length < 10 {
		player_name = player_name + "\0"
	}
	if find_record() = -1 {
		adjust_score_file(scores, player_name, score_to_add)
			//append line found with = player_name, new_score
		}
		else {
			old_score = line_number_found, string[10,19]; //will need to make work
			temp_score = old_score + score_to_add;
			int i = 10 - temp_score.length;
			fprintf(out, "0000000000");
			fseek(out, i, SEEK_SET);
			fprintf(temp_score) //new_score
			//append scores line with player_name, new_score
		}
	}
  return 0;
}

/** Return the size of the open file with file descriptor `fd`.
  * If the size cannot be determined, the function may abort program
  * execution (optionally after printing an error message).
  *
  * `filename` is used for diagnostic purposes only, and may be `NULL`.
  * If non-NULL, it represent the name of the file path from which
  * `fd` was obtained.
  *
  * \param filename name of the file path from which `fd` was obtained.
  * \param fd file descriptor for an open file.
  * \return the size of the file described by `fd`.
  */
size_t file_size(const char * filename, int fd) {
	FILE* fp = fopen(filename, "r");
	fseek(fp, 0L, SEEK_END;
	long int res = ftell(fp);
	fclose(fp);
	return res;
}


/** Parse a \ref score_record struct from an
  * array of size \ref REC_SIZE.
  *
  * If a name and score cannot be found in `rec_buf`,
  * the function may abort program
  * execution (optionally after printing an error message).
  *
  * \param rec_buf an array of size \ref REC_SIZE.
  * \return a parsed \ref score_record.
  */
struct score_record parse_record(char rec_buf[REC_SIZE]) {
  struct score_record rec;
  // Note that writing the `rec_buf` parameter as `rec_buf[REC_SIZE]`
  // serves only as documentation of the intended use of the
  // function - C doesn't prevent arrays of other sizes being passed.
  //
  // In fact, nearly any time you use an array type in C,
  // it "decays" into a pointer -
  // the C11 standard, sec 6.3.2.1 ("Lvalues, arrays, and
  // function designators").
  //
  // (One significant exception is when you use sizeof() on an
  // array - in that case, the proper size of the array is
  // returned.)
  return rec;
}

/** Stores the player name and score in `rec` into a buffer of size
  * \ref REC_SIZE, representing a line from the scores file.
  *
  * The fields of rec should contain values that are valid for the
  * scores file; if not, the behaviour of the function is undefined.
  *
  * If the caller passes a buffer of size less than \ref REC_SIZE,
  * the behaviour of function is undefined.
  *
  * \param buf a `char` array of size \ref REC_SIZE.
  * \param rec pointer to a player's score record.
  */
void store_record(char buf[REC_SIZE], const struct score_record *rec) {
}

/** search within the open scores file with file descriptor
  * `fd` for a line containing the score for `player_name`.
  * If no such line exists, -1 is returned; otherwise, the
  * offset within the file is returned.
  *
  * `filename` is used only for diagnostic purposes.
  *
  * \param filename name of the file described by `fd`.
  * \param fd file descriptor for an open scores file.
  * \param player_name player name to seek for.
  * \return position in the file where a record can be found,
  *   or -1 if no no such record exists.
  */
off_t find_record(const char * filename, int fd, const char * player_name) {
	int line_number = 1;
	FILE *in_file = fopen("filename", "r");
	if (in_file == NULL) {
		printf("file not found");
		exit(1);
	}
	while (fgets(player_name, 10, in_file)) {
		if (strstr(player_name, filename)){
			int line_number_found = line_number;
		}
		if (strchr(player_name, '\n')) {
			line_number += 1;
		}
		fclose(in_file);
  if line_number_found == 1 {
    return -1;
  }
  else {
    return line_number_found;
  }
}

/** Adjust the score for player `player_name` in the open file
  * with file descriptor `fd`, incrementing it by
  * `score_to_add`. If no record for a player with that name
  * is found in the file, then one is created and appended to
  * the file.
  *
  * The `filename` parameter is purely for diagnostic purposes.
  *
  * If the file is not a valid "scores" file, or player name is
  * longer than the allowable length for a score record,
  * the function may abort program execution.
  *
  * \param filename name of the file from which `fd` was obtained.
  * \param fd file descriptor for an open scores file.
  * \param player_name name of the player whose score should be incremented.
  * \param score_to_add amount by which to increment the score.
  */
void adjust_score_file(const char * filename, int fd, const char * player_name, int score_to_add) {
	strcpy(tempScores, "temp____");
	strcat(tempScores, filename);
	int replace_line = find_record()
	newInput = player_name, new_score
	fgets(replace, MAX_LINE, newInput);
	
	file = fopen(filename, "r");
	temp = fopen(temp_filename, "w");
	
	bool keep_reading = true;
	int current_line = 1;
	
	do {
	fgets(buffer, MAX_LINE, file);
	if (feof(file)) keep_reading = false;
	else if (current_line == replace_line)
		fputs(replace, temp);
	else fputs(buffer, temp);
	
	curent_line++;
	} while (keep_reading);
	
	fclose(file);
	fclose(temp);
	
	remove(filename);
	rename(temp_filename, filename);
}
