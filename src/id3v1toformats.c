#include <id3v1.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *id3v1ToJSON(Id3v1 *tag){

    char *jsonStr = NULL;
    int memCount = 0;
    if(tag == NULL){
        jsonStr = malloc(sizeof(char)*3);
        strncpy(jsonStr,"{}",3);
        return jsonStr;
    }
    memCount = 2/*{}*/ + 1/*\0*/ + 28/*""*8 - the ints*/ + 8/*:*8*/ + 1/*,*7*/;
    memCount = memCount + strlen("title");
    memCount = memCount + strlen("artist");
    memCount = memCount + strlen("album");
    memCount = memCount + strlen("year");
    memCount = memCount + strlen("track");
    memCount = memCount + strlen("comment");
    memCount = memCount + strlen("genreNumber");
    memCount = memCount + strlen("genre");
    memCount = memCount + strlen(tag->title);
    memCount = memCount + strlen(tag->artist);
    memCount = memCount + strlen(tag->albumTitle);
    memCount = memCount + strlen(tag->comment);
    memCount = memCount + strlen(genreFromTable(tag->genre));
    memCount = memCount + (sizeof(int) * 3); /*year, track & genre*/
    
    jsonStr = malloc(sizeof(char)*memCount);

    sprintf(jsonStr,"{\"title\":\"%s\",\"artist\":\"%s\",\"album\":%s,\"year\":%d,\"track\":%d,\"comment\":%s,\"genreNumber\":%d,\"genre\":%s}",tag->title, tag->artist,
                                                                                                                                                tag->albumTitle, tag->year,
                                                                                                                                                tag->trackNumber, tag->comment,
                                                                                                                                                tag->genre, genreFromTable(tag->genre));
    return jsonStr;

}



