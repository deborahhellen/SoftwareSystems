#include <stdlib.h>
#include <stdio.h>
#include <glib.h>



int main () {
	//char line[80];
	gchar *data = (gchar *) "Hello";
	gsize len = 0;
	int i=0;


	GIOChannel *test = g_io_channel_new_file("sample.txt", "r", NULL);
	g_io_channel_read_to_end(test, &data, &len, NULL);
	gchar **split_words = g_strsplit_set(data, ":;/!. ", -1);
	

	while(split_words[i]) {
		g_printf("%s\n", split_words[i]);

		i++;
	}
	return 0;
}