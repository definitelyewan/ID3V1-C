# ID3V1 C
ID3V1 C is a small library written in C based on the [1996s version 1 and 1997s version 1.1](https://id3.org/ID3v1). It is focused on being dead simple to use and a list of supported functionality can be further down.

Check the provided License for use and redistribution details.

## Functionality
- supports song name, artist name, album name, year, comment, and genre
- read all supported tags
- write all suppoted tags

## Included Functions
- Id3v1 *Id3v1Tag(const char* filePath);
- char *genreFromTable(Genre val);
- void setTitleId3v1(char *title, Id3v1 *tag);
- void setArtistId3v1(char *artist, Id3v1 *tag);
- void setAlbumId3v1(char *album, Id3v1 *tag);
- void setYearId3v1(int year, Id3v1 *tag);
- void setCommentId3v1(char *comment, Id3v1 *tag);
- void setGenreId3v1(Genre genre, Id3v1 *tag);
- void setTrackId3v1(int trackNumber, Id3v1 *tag);
- void freeId3v1Tag(Id3v1 *toFree);
- void writeId3v1(char *filePath, Id3v1 *tag);

## Building 

```bash
git clone https://github.com/definitelyewan/ID3V1-C.git
cd ID3V1-C
```
**For the main example**
```bash
make main
```
**For a dynamic library**
```bash
make sharedParser
```
**For a static library**
```bash
make staticParser
```
## Example
```C
#include <stdio.h>
#include <stdlib.h>
#include "id3v1.h"

int main(int argc, char *argv[]){

    if(argc != 3){
        printf("./main file1.mp3 file2.mp3\n");
        exit(EXIT_FAILURE);
    }

    //read tags from the first file
    Id3v1 *data =  Id3v1Tag(argv[1]);
    if(data == NULL){
        printf("Error creating ID3V1 struct");
        exit(EXIT_FAILURE);
    }

    printf("Song   [%s]\n",data->title);
    printf("Artist [%s]\n",data->artist);
    printf("Album  [%s]\n",data->albumTitle);
    printf("Year   [%d]\n",data->year);
    printf("Comment[%s]\n",data->comment);
    printf("Track# [%d]\n",data->trackNumber);
    printf("Genre  [%s]\n",genreFromTable(data->genre));
    
    printf("-----------------------------------------data to write\n");
    //change tags to 
    setTitleId3v1("new title",data);
    setArtistId3v1("new artist",data);
    setAlbumId3v1("new album",data);
    setYearId3v1(2022,data);
    setCommentId3v1("new comment",data);
    setTrackId3v1(60,data);
    setGenreId3v1(DUBSTEP,data);

    printf("Song   [%s]\n",data->title);
    printf("Artist [%s]\n",data->artist);
    printf("Album  [%s]\n",data->albumTitle);
    printf("Year   [%d]\n",data->year);
    printf("Comment[%s]\n",data->comment);
    printf("Track# [%d]\n",data->trackNumber);
    printf("Genre  [%s]\n",genreFromTable(data->genre));

    //write tags to file
    writeId3v1(argv[2],data);
    freeId3v1Tag(data);

    printf("-----------------------------------------data in file\n");
    Id3v1 *data2 = Id3v1Tag(argv[2]);
    if(data2 == NULL){
        printf("Error creating ID3V1 struct");
        exit(EXIT_FAILURE);
    }

    printf("Song   [%s]\n",data2->title);
    printf("Artist [%s]\n",data2->artist);
    printf("Album  [%s]\n",data2->albumTitle);
    printf("Year   [%d]\n",data2->year);
    printf("Comment[%s]\n",data2->comment);
    printf("Track# [%d]\n",data2->trackNumber);
    printf("Genre  [%s]\n",genreFromTable(data2->genre));
    freeId3v1Tag(data2);

}
```
this example can be found in main.c