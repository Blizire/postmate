#include "postmate.h"

int main(int arg, char **argv)
{
	CURL *curl;
	CURLcode res;
	struct curl_slist *list = NULL;
	char *url = NULL;

	config_setup();
	url = config_get_hook();


	printf("posting too : %s", url);

	curl = curl_easy_init();
	if(curl) 
	{
		/* set target */
		curl_easy_setopt(curl, CURLOPT_URL, url);

		/* tell libcurl not to verify peer */
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, FALSE);

		/* adjusting headers */
		list = curl_slist_append(list, "Content-Type: application/json");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);

		/* set the data to be posting */
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{\"content\": \"hello\"}");

		/* Perform the request, res will get the return code */ 
		res = curl_easy_perform(curl);

		/* Check for errors */ 
		if(res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));

		/* free curl list */
		curl_slist_free_all(list);

		/* always cleanup */ 
		curl_easy_cleanup(curl);

		free(url);
	}

	return 0;
}