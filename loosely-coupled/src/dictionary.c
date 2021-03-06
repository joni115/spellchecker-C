#include "dictionary.h"

struct _dictionary_{
    char word[MAX_WORD_SIZE1];
    Dictionary next;
};


Dictionary dict_load(char *filename){
    char word[MAX_WORD_SIZE1];
    int size = 0;
    FILE *fd = NULL;

    Dictionary dict = NULL;
    Dictionary tmp = NULL;

    if(!(fd = fopen(filename, "r")))
      printf("ERROR AL ABRIR ARCHIVO\n");

    while(fscanf(fd, "%s", word) > 0){
        if(dict == NULL){
            dict = calloc(1, sizeof(struct _dictionary_));
            strcpy(dict->word, word);
            tmp = dict;
        } else {
            tmp->next = calloc(1, sizeof(struct _dictionary_));
            tmp = tmp->next;
            strcpy(tmp->word, word);
        }
    }

  fclose(fd);

  return dict;
}


void dict_save(Dictionary dict, char *filename){
    Dictionary tmp = dict;
    FILE *fd = NULL;

    fd = fopen(filename, "w");

    while(tmp != NULL){
        fprintf(fd, "%s\n", tmp->word);
        tmp = tmp->next;
    }

    fclose(fd);
}


Dictionary dict_add(Dictionary dict, char *word){
    Dictionary tmp = dict;

    // Condicion si el diccionario esta vacío
    if(tmp != NULL){
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = calloc(1, sizeof(struct _dictionary_));
        strcpy(tmp->word, word);
    } else {
        dict = calloc(1, sizeof(struct _dictionary_));
        strcpy(dict->word, word);
    }

    return dict;
}


int dict_contains(Dictionary dict, char *word){
    Dictionary tmp = NULL;
    int known = 0;

    tmp = dict;

    while(tmp != NULL && !known){
        if(strcmp(tmp->word, word) == 0){
            known = 1;
        }
        tmp = tmp->next;
    }
    return known;
}


Dictionary dict_new(void){
    return NULL;
}


void dict_destroy(Dictionary dict){
    Dictionary tmp = dict;

    while(dict != NULL){
        dict = dict->next;
        free(tmp);
        tmp = dict;
    }
}
