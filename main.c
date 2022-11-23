#include <stdio.h>
#include "id3v1.h"

int main(int argc, char *argv[]){
    

    if(argc != 3){
        printf("./main file1.mp3 file2.mp3\n");
        exit(EXIT_FAILURE);
    }

    //read tags from the first file
    Id3v1 *data =  Id3v1Tag(argv[1]);
    printf("Song   [%s]\n",data->title);
    printf("Artist [%s]\n",data->artist);
    printf("Album  [%s]\n",data->albumTitle);
    printf("Year   [%d]\n",data->year);
    printf("Comment[%s]\n",data->comment);
    printf("Genre  [%s]\n",genreFromTable(data->genre));

    printf("-----------------------------------------data to write\n");
    //change tags to 
    setTitleId3v1("new title",data);
    setArtistId3v1("new artist",data);
    setAlbumId3v1("new album",data);
    setYearId3v1(2022,data);
    setCommentId3v1("new comment",data);
    setGenreId3v1(DUBSTEP,data);

    printf("Song   [%s]\n",data->title);
    printf("Artist [%s]\n",data->artist);
    printf("Album  [%s]\n",data->albumTitle);
    printf("Year   [%d]\n",data->year);
    printf("Comment[%s]\n",data->comment);
    printf("Genre  [%s]\n",genreFromTable(data->genre));

    //write tags to file
    writeId3v1("Beetlebumcopy.mp3",data);
    freeId3v1Tag(data);

    printf("-----------------------------------------data in file\n");
    Id3v1 *data2 = Id3v1Tag(argv[2]);
    printf("Song   [%s]\n",data2->title);
    printf("Artist [%s]\n",data2->artist);
    printf("Album  [%s]\n",data2->albumTitle);
    printf("Year   [%d]\n",data2->year);
    printf("Comment[%s]\n",data2->comment);
    printf("Genre  [%s]\n",genreFromTable(data2->genre));
    freeId3v1Tag(data2);
}
