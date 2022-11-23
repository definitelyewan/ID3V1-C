#include "id3v1.h"


Id3v1 *Id3v1Tag(const char* filePath){

    FILE *fp = NULL;
    char id3Bytes[ID3V1_MAXBYTES];

    //make sure the file can really be read
    if((fp = fopen(filePath,"rb")) == 0){
        return NULL;
    }

    if((fseek(fp,-ID3V1_MAXBYTES,SEEK_END))){
        fclose(fp);
        return NULL;
    }

    if((fread(id3Bytes,ID3V1_MAXBYTES,1,fp)) != 1){
        fclose(fp);
        return NULL;
    }

    if(strncmp(id3Bytes,"TAG",3)){
        fclose(fp);
        return NULL;
    }

    Id3v1 *newMetadata = malloc(sizeof(Id3v1));

    unsigned char *currTag = (unsigned char *)id3Bytes + 3;
    
    //get song title and set index for next tag
    char *holdTitle = malloc(sizeof(char)*ID3V1_TAGLENGTH + 1);
    strncpy(holdTitle,(char *)currTag,ID3V1_TAGLENGTH);
    holdTitle[ID3V1_TAGLENGTH] = '\0';
    newMetadata->title = holdTitle;
    currTag = currTag + ID3V1_TAGLENGTH;

    //get artist and set index for next tag
    char *holdArtist = malloc(sizeof(char)*ID3V1_TAGLENGTH + 1);
    strncpy(holdArtist,(char *)currTag,ID3V1_TAGLENGTH);
    holdArtist[ID3V1_TAGLENGTH] = '\0';
    newMetadata->artist = holdArtist;
    currTag = currTag + ID3V1_TAGLENGTH;

    //get album title and set index for next tag
    char *holdAlbum = malloc(sizeof(char)*ID3V1_TAGLENGTH + 1);
    strncpy(holdAlbum,(char *)currTag,ID3V1_TAGLENGTH);
    holdAlbum[ID3V1_TAGLENGTH] = '\0';
    newMetadata->albumTitle = holdAlbum;
    currTag = currTag + ID3V1_TAGLENGTH;

    //get year and set index for next tag
    char four[4];
    strncpy(four,(char *)currTag,4);
    four[4] = '\0';
    if(atoi(four)){
        newMetadata->year = atoi(four);
    }else{
        newMetadata->year = 0;
    } 
    currTag = currTag + 4;

    //get comment and set index for next tag
    char *holdComment = malloc(sizeof(char)*ID3V1_TAGLENGTH + 1);
    strncpy(holdComment,(char *)currTag,ID3V1_TAGLENGTH);
    holdComment[ID3V1_TAGLENGTH] = '\0';
    newMetadata->comment = holdComment;
    currTag = currTag + ID3V1_TAGLENGTH;

    //get genre from 2nd last byte
    newMetadata->genre = (int)currTag[0];

    fclose(fp);
    return newMetadata;  
}

char *genreFromTable(Genre val){

    //int to string
    switch (val){
    case BLUES:
        return "Blues\0";
    case CLASSIC_ROCK:
        return "Classic Rock\0";
    case COUNTRY:
        return "Country\0";
    case DANCE:
        return "Dance\0";
    case DISCO:
        return "Disco\0";
    case FUNK:
        return "Funk\0";
    case GRUNGE:
        return "Grunge\0";
    case HIP_HOP:
        return "Hip-Hop\0";
    case JAZZ:
        return "Jazz\0";
    case METAL:
        return "Metal\0";
    case NEW_AGE:
        return "New Age\0";
    case OLDIES:
        return "Oldies\0";
    case OTHER:
        return "Other\0";
    case POP:
        return "Pop\0";
    case RHYTHM_AND_BLUES:
        return "Rhythm and Blues\0";
    case RAP:
        return "Rap\0";
    case REGGAE:
        return "Reggae\0";
    case ROCK:
        return "Rock\0";
    case TECHNO:
        return "Techno\0";
    case INDUSTRIAL:
        return "Industrial\0";
    case ALTERNATIVE:
        return "Alternative\0";
    case SKA:
        return "Ska\0";
    case DEATH_METAL:
        return "Death Metal\0";
    case PRANKS:
        return "Pranks\0";
    case SOUNDTRACK:
        return "Soundtrack\0";
    case EURO_TECHNO:
        return "Euro-Techno\0";
    case AMBIENT:
        return "Ambient\0";
    case TRIP_HOP:
        return "Trip-Hop\0";
    case VOCAL:
        return "Vocal\0";
    case JAZZ_AND_FUNK:
        return "Jazz and Funk\0";
    case FUSION:
        return "Fusion\0";
    case TRANCE:
        return "Trance\0";
    case CLASSICAL:
        return "Classical\0";
    case INSTRUMENTAL:
        return "Instrumrntal\0";
    case ACID:
        return "Acid\0";
    case HOUSE:
        return "House\0";
    case GAME:
        return "Game\0";
    case SOUND_CLIP:
        return "Sound Clip\0";
    case GOSPEL:
        return "Gospel\0";
    case NOISE:
        return "Noise\0";
    case ALTERNATIVE_ROCK:
        return "Alternative Rock\0";
    case BASS:
        return "Bass\0";
    case SOUL:
        return "Soul\0";
    case PUNK:
        return "Punk\0";
    case SPACE:
        return "Space\0";
    case MEDITATIVE:
        return "Meditative\0";
    case INSTRUMENTAL_POP:
        return "Instrumental Pop\0";
    case INSTRUMENTAL_ROCK:
        return "Instrumental Rock\0";
    case ETHNIC:
        return "Ethnic\0";
    case GOTHIC:
        return "Gothic\0";
    case DARKWAVE:
        return "Darkwave\0";
    case TECHNO_INDUSTRIAL:
        return "Techno Industrial\0";
    case ELECTRONIC:
        return "Electronic\0";
    case POP_FOLK:
        return "Pop Folk\0";
    case EURODANCE:
        return "Eurodance\0";
    case DREAM:
        return "Dream\0";
    case SOUTHERN_ROCK:
        return "Southern Rock\0";
    case COMEDY:
        return "Comedy\0";
    case CULT:
        return "Cult\0";
    case GANGSTA:
        return "Gangsta\0";
    case TOP_40:
        return "Top 40\0";
    case CHRISTIAN_RAP:
        return "Christian Rap\0";
    case POP_FUNK:
        return "Pop Funk\0";
    case JUNGLE_MUSIC:
        return "Jungle Music\0";
    case NATIVE_US:
        return "Native US\0";
    case CABARET:
        return "Cabaret\0";
    case NEW_WAVE:
        return "New Wave\0";
    case PSYCHEDELIC:
        return "Psychedelic\0";
    case RAVE:
        return "Rave\0";
    case SHOWTUNES:
        return "Showtunes\0";
    case TRAILER:
        return "Trailer\0";
    case LO_FI:
        return "Lo-Fi\0";
    case TRIBAL:
        return "Tribal\0";
    case ACID_PUNK:
        return "Acid Punk\0";
    case ACID_JAZZ:
        return "Acid Jazz\0";
    case POLKA:
        return "Polka\0";
    case RETRO:
        return "Retro\0";
    case MUSICAL:
        return "Musical\0";
    case ROCKNROLL:
        return "Rock and Roll\0";
    case HARD_ROCK:
        return "Hard Rock\0";
    case FOLK:
        return "Folk\0";
    case FOLK_ROCK:
        return "Folk Rock\0";
    case NATIONAL_FOLK:
        return "National Folk\0";
    case SWING:
        return "Swing\0";
    case FAST_FUSION:
        return "Fast Fusion\0";
    case BEBOP:
        return "Bebop\0";
    case LATIN:
        return "Latin\0";
    case REVIVAL:
        return "Revival\0";
    case CELTIC:
        return "Celtic\0";
    case BLUEGRASS:
        return "Bluegrass\0";
    case AVANTGARDE:
        return "Avantgarde\0";
    case GOTHIC_ROCK:
        return "Gothic Rock\0";
    case PROGRESSIVE_ROCK:
        return "Progressive Rock\0";
    case PSYCHEDELIC_ROCK:
        return "Psychedelic Rock\0";
    case SYMPHONIC_ROCK:
        return "Symphonic Rock\0";
    case SLOW_ROCK:
        return "Slow Rock\0";
    case BIG_BAND:
        return "Big Band\0";
    case CHORUS:
        return "Chorus\0";
    case EASY_LISTENING:
        return "Easy Listening\0";
    case ACOUSTIC:
        return "Acoustic\0";
    case HUMOUR:
        return "Humour\0";
    case SPEECH:
        return "Speech\0";
    case CHANSON:
        return "Chanson\0";
    case OPERA:
        return "Opera\0";
    case CHAMBER_MUSIC:
        return "Chamber Music\0";
    case SONATA:
        return "Sonata\0";
    case SYMPHONY:
        return "Symphony\0";
    case BOOTY_BASS:
        return "Booty Bass\0";
    case PRIMUS:
        return "Primus\0";
    case PORN_GROOVE:
        return "Porn Groove\0";
    case SATIRE:
        return "Satire\0";
    case SLOW_JAM:
        return "Slow Jam\0";
    case CLUB:
        return "Club\0";
    case TANGO:
        return "Tango\0";
    case SAMBA:
        return "Samba\0";
    case FOLKLORE:
        return "Folklore\0";
    case BALLAD:
        return "Ballad\0";
    case POWER_BALLAD:
        return "Power Ballad\0";
    case RHYTHMIC_SOUL:
        return "Rhythmic Soul\0";
    case FREESTYLE:
        return "Freestyle\0";
    case DUET:
        return "Duet\0";
    case PUNK_ROCK:
        return "Punk Rock\0";
    case DRUM_SOLO:
        return "Drum Solo\0";
    case A_CAPPELLA:
        return "A Cappella\0";
    case EURO_HOUSE:
        return "Euro-House\0";
    case DANCE_HALL:
        return "Dance Hall\0";
    case GOA_MUSIC:
        return "Goa Music\0";
    case DRUM_AND_BASS:
        return "Drum and Bass\0";
    case CLUB_HOUSE:
        return "Club-House\0";
    case HARDCORE_TECHNO:
        return "Hardcore Techno\0";
    case TERROR:
        return "Terror\0";
    case INDIE:
        return "Indie\0";
    case BRITPOP:
        return "Britpop\0";
    case NEGERPUNK:
        return "Negerpunk\0";
    case POLSK_PUNK:
        return "Polsk Punk\0";
    case BEAT:
        return "Beat\0";
    case CHRISTIAN_GANGSTA_RAP:
        return "Christian Gangsta Rap\0";
    case HEAVY_METAL:
        return "Heavy Metal\0";
    case BLACK_METAL:
        return "Black Metal\0";
    case CROSSOVER:
        return "Crossover\0";
    case CONTEMPORARY_CHRISTIAN:
        return "Contemporary Christian\0";
    case CHRISTIAN_ROCK:
        return "Christian Rock\0";
    case MERENGUE:
        return "Merengue\0";
    case SALSA:
        return "Salsa\0";
    case  THRASH_METAL:
        return "Thrash Metal\0";
    case ANIME:
        return "Anime\0";
    case JPOP:
        return "Jpop\0";
    case SYNTHPOP:
        return "Synthpop\0";
    case ABSTRACT:
        return "Abstract\0";
    case ART_ROCK:
        return "Art Rock";
    case BAROQUE:
        return "Baroque\0";
    case BIG_BEAT:
        return "Big Beat\0";
    case BREAKBEAT:
        return "Breakbeat\0";
    case CHILLOUT:
        return "Chillout\0";
    case DOWNTEMPO:
        return "Downtempo\0";
    case DUB:
        return "Dub\0";
    case EBM:
        return "EBM\0";
    case ECLECTIC:
        return "Eclectic\0";
    case ELECTRO:
        return "Electro\0";
    case ELECTROCLASH:
        return "Electroclash\0";
    case EMO:
        return "Emo\0";
    case EXPERIMENTAL:
        return "Experimental\0";
    case GARAGE:
        return "Garage\0";
    case GLOBAL:
        return "Global\0";
    case IDM:
        return "IDM\0";
    case ILLBIENT:
        return "Illbient\0";
    case INDUSTRO_GOTH:
        return "Industro-Goth\0";
    case JAM_BAND:
        return "Jam Band\0";
    case KRAUTROCK:
        return "Krautrock\0";
    case LEFTFIELD:
        return "Leftfield\0";
    case LOUNGE:
        return "Lounge\0";
    case MATH_ROCK:
        return "Math Rock\0";
    case NEW_ROMANTIC:
        return "New Romantic\0";
    case NU_BREAKZ:
        return "Nu-Breakz\0";
    case POST_PUNK:
        return "Post-Punk\0";
    case POST_ROCK:
        return "Post-Rock\0";
    case PSYTRANCE:
        return "Psytrance\0";
    case SHOEGAZE:
        return "Shoegaze\0";
    case SPACE_ROCK:
        return "Space Rock\0";
    case TROP_ROCK:
        return "Trop Rock\0";
    case WORLD_MUSIC:
        return "World Music\0";
    case NEOCLASSICAL:
        return "Neoclassical\0";
    case AUDIOBOOK:
        return "Audiobook\0";
    case AUDIO_THEATRE:
        return "Audio Theatre\0";
    case NEUE_DEUTSCHE_WELLE:
        return "Neue Deutsche Welle\0";
    case PODCAST:
        return "Podcast\0";
    case INDIE_ROCK:
        return "Indie-Rock\0";
    case G_FUNK:
        return "G-Funk\0";
    case DUBSTEP:
        return "Dubstep\0";
    case GARAGE_ROCK:
        return "Garage Rock\0";
    case PSYBIENT:
        return "Psybient\0";
    default:
        return "Other\0";
    }
    //191 supported genres god this enum is huge
    return "Other\0";
}

void freeId3v1Tag(Id3v1 *toFree){
    
    //error checking until frees 
    if(toFree){
        if(toFree->albumTitle){
            free(toFree->albumTitle);
        }
        if(toFree->artist){
            free(toFree->artist);
        }
        if(toFree->title){
            free(toFree->title);
        }
        if(toFree->comment){
            free(toFree->comment);
        }
        
        free(toFree);
    }
}

//set family functions are pretty much all the same

void setTitleId3v1(char *title, Id3v1 *tag){
    if(!tag){
        return;
    }
    if(title == NULL || strlen(title) > ID3V1_TAGLENGTH){
        return;
    }

    free(tag->title);

    char *newTitle = calloc(ID3V1_TAGLENGTH, sizeof(char));
    strcpy(newTitle,title);
    newTitle[ID3V1_TAGLENGTH-1] = '\0';

    tag->title = newTitle;
}

void setArtistId3v1(char *artist, Id3v1 *tag){
    if(!tag){
        return;
    }
    if(artist == NULL || strlen(artist) > ID3V1_TAGLENGTH){
        return;
    }

    free(tag->artist);

    char *newArtist = calloc(ID3V1_TAGLENGTH, sizeof(char));
    strcpy(newArtist,artist);
    newArtist[ID3V1_TAGLENGTH-1] = '\0';

    tag->artist = newArtist;
}

void setAlbumId3v1(char *album, Id3v1 *tag){
    if(!tag){
        return;
    }
    if(album == NULL || strlen(album) > ID3V1_TAGLENGTH){
        return;
    }

    free(tag->albumTitle);

    char *newAlbum = calloc(ID3V1_TAGLENGTH, sizeof(char));
    strcpy(newAlbum,album);
    newAlbum[ID3V1_TAGLENGTH-1] = '\0';

    tag->albumTitle = newAlbum;    
}

void setYearId3v1(int year, Id3v1 *tag){
    if(!tag){
        return;
    }
    //restriction for 4 bytes when char* array happens
    if(year > 9999 || year < 0){
        return;
    }

    tag->year = year;
}

void setCommentId3v1(char *comment, Id3v1 *tag){
    if(!tag){
        return;
    }
    if(comment == NULL || strlen(comment) > ID3V1_TAGLENGTH){
        return;
    }

    free(tag->comment);

    char *newComment = calloc(ID3V1_TAGLENGTH,sizeof(char));
    strcpy(newComment,comment);
    newComment[ID3V1_TAGLENGTH-1] = '\0';

    tag->comment = newComment;  
}

void setGenreId3v1(Genre genre, Id3v1 *tag){
    if(!tag){
        return;
    }

    tag->genre = genre;
}

void writeId3v1(char *filePath, Id3v1 *tag){
    if(!tag){
        return;
    }
    if(filePath == NULL){
        return;
    }
    
    FILE *fp = NULL;

    if((fp = fopen(filePath,"r+b")) == NULL){
        return;
    }

    fseek(fp,0L,SEEK_END);
    int index = ftell(fp);
    rewind(fp);

    if((fseek(fp,index - ID3V1_MAXBYTES,SEEK_SET)) != 0){
        fclose(fp);
        return;
    }

    //write TAG onto new file so its marked as ID3
    fwrite("TAG",sizeof(char),sizeof(char) * 3,fp);
    index = index + 3;
    
    fwrite(tag->title,1,sizeof(char) * ID3V1_TAGLENGTH, fp);
    index = index + ID3V1_TAGLENGTH;
    
    fwrite(tag->artist,1,sizeof(char) * ID3V1_TAGLENGTH, fp);
    index = index + ID3V1_TAGLENGTH;
    
    fwrite(tag->albumTitle,1,sizeof(char) * ID3V1_TAGLENGTH, fp);
    index = index + ID3V1_TAGLENGTH;

    //year conversion
    int n = log10(tag->year) + 1;
    int i;
    char *numberArray = calloc(n, sizeof(char));
    for (i = n-1; i >= 0; --i, tag->year /= 10)
    {
        numberArray[i] = (tag->year % 10) + '0';
    }

    fwrite(numberArray,1,sizeof(char) * 4, fp);
    free(numberArray);
    index = index + 4;

    fwrite(tag->comment,1,sizeof(char) * ID3V1_TAGLENGTH, fp);
    index = index + ID3V1_TAGLENGTH;

    fwrite(&tag->genre,1,sizeof(char), fp);
    fclose(fp);
}





