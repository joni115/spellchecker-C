#ifndef _DOCUMENT_
#define _DOCUMENT_

#include <stdio.h>
#include <stdlib.h>

typedef struct _document_ *Document;

int doc_get_word(Document doc, char *word);

void doc_put_word(Document doc, char *word);

Document doc_open(char *name_doc_in, char *name_doc_out);

void doc_close(Document doc);

#endif
