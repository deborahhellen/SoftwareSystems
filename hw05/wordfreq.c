/*
Deborah Hellen. 
Homework 5 - Software Systems Spring 2014

Uses Glib to read a text file, split lines into words,
and count the frequency of each word. Most punctuation is
stripped. Each word is printed with its corresponding
frequency.

*/
 
#include <stdlib.h>
#include <stdio.h>
#include <glib.h>


/*Evan helped me with this function!
This function creates a hashtable of all of the words in the given array*/
GHashTable *make_word_table (char** words) {
	int j;
	GHashTable *word_table = g_hash_table_new(g_str_hash, g_str_equal);

	for (j = 0; words[j] != 0; j++) {
		gpointer word_freq = g_hash_table_lookup(word_table, words[j]);
		if (word_freq != NULL) {
			g_hash_table_insert(word_table, words[j], word_freq + 1);}
		else {
			g_hash_table_insert(word_table, words[j], 1);}
		}
	return word_table;

}

/*Prints out each word in the document and its frequency given the word, freq*/
void print_table_entry(gpointer key, gpointer val, gpointer user_data) {
	g_printf("%s: %d \n", key, val);
}


int main () {
	gchar *data = (gchar *) "Hello"; //initialized to "Hello" for testing

	//open file for reading and read it
	GIOChannel *test = g_io_channel_new_file("leaves_of_grass.txt", "r", NULL);
	g_io_channel_read_to_end(test, &data, &len, NULL);

	//split the file into words at white spaces and common punctuation
	gchar **split_words = g_strsplit_set(data, ":;/!.,- ", -1);

	//create hashtable of each word and its frequency
	GHashTable *words_hash_table = make_word_table(split_words);

	//print out the words
	g_printf("Frequency of words in Leaves of Grass:");
	g_hash_table_foreach(words_hash_table, print_table_entry, NULL);

	return 0;
}