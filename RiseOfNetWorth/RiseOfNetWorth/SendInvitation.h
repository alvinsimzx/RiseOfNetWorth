#pragma once
#include "curl/curl.h"
#include <iostream>
using namespace std;


static const char* payload_text[] = {
  "Date: Mon, 29 Nov 2010 21:54:29 +1100\r\n",
  "To: " "\r\n",
  "From: " "< lunchinatorassignment@gmail.com>" " (Rise Of Net Worth)\r\n",
  "Subject: You have been invited to play Rise Of Net Worth!\r\n",
  "\r\n", /* empty line to divide headers from body, see RFC5322 */
  "Download Rise of Net Worth at https://github.com/alvinsimzx. \r\n",
  "\r\n",
  NULL
};


class SendInvitation
{
private:
    struct upload_status {
        int lines_read;
    };

    static size_t payload_source(void* ptr, size_t size, size_t nmemb, void* userp)
    {
        struct upload_status* upload_ctx = (struct upload_status*)userp;
        const char* data;

        if ((size == 0) || (nmemb == 0) || ((size * nmemb) < 1)) {
            return 0;
        }

        data = payload_text[upload_ctx->lines_read];

        if (data) {
            size_t len = strlen(data);
            memcpy(ptr, data, len);
            upload_ctx->lines_read++;

            return len;
        }

        return 0;
    };
public:
    SendInvitation(string aReceipientEmail)
    {
        CURL* curl;
        CURLcode res = CURLE_OK;
        struct curl_slist* recipients = NULL;
        struct upload_status upload_ctx;
        string FromEmail = "lunchinatorassignment@gmail.com";

        upload_ctx.lines_read = 0;

        curl = curl_easy_init();
        
        if (curl) {
            /* Set username and password */
            curl_easy_setopt(curl, CURLOPT_USERNAME, "lunchinatorassignment@gmail.com");
            curl_easy_setopt(curl, CURLOPT_PASSWORD, "lunchinator2019");

            /* Set Mail Server to Gmail SMTP Server. */
            curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.gmail.com:587");

            /* Start with a plain text connection, and upgrade
             * to Transport Layer Security (TLS) using the STARTTLS command.  */
            curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);

            /* Disable part of the Transport Layer Security protection */

            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
            //curl_easy_setopt(curl, CURLOPT_CAINFO, "/path/to/certificate.pem");

            /* Setting the Sender Email Address*/
            curl_easy_setopt(curl, CURLOPT_MAIL_FROM,  FromEmail.c_str());

            /* Setting the email address of the recipient */
            recipients = curl_slist_append(recipients, aReceipientEmail.c_str());
            curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

            /* We're using a callback function to specify the payload (the headers and
             * body of the message). You could just use the CURLOPT_READDATA option to
             * specify a FILE pointer to read from. */
            curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
            curl_easy_setopt(curl, CURLOPT_READDATA, upload_ctx);
            curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

            /* Used to show debug information*/
            //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

            /* Send the message */
            res = curl_easy_perform(curl);

            /* Check for errors */
            if (res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
            else
                system("cls");
            cout << "Invitation Sent Successfully!" << endl;
            system("pause");
            system("cls");

            /* Free the list of recipients */
            curl_slist_free_all(recipients);

            /* Always cleanup */
            curl_easy_cleanup(curl);
        }
    };
};

