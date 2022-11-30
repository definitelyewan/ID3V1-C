#ifndef ID3V1
#define ID3V1

//built according to https://id3.org/ID3v1
#ifdef __cplusplus
extern "C"{
#endif

#define ID3V1_MAXBYTES 128
#define ID3V1_TAGLENGTH 30

//table is from bellow
//https://en.wikipedia.org/wiki/List_of_ID3v1_Genres

typedef enum _genre{
    BLUES,              //00    
    CLASSIC_ROCK,       //01
    COUNTRY,            //02
    DANCE,              //03
    DISCO,              //04
    FUNK,               //05
    GRUNGE,             //06
    HIP_HOP,            //07
    JAZZ,               //08
    METAL,              //09
    NEW_AGE,            //10
    OLDIES,             //11
    OTHER,              //12
    POP,                //13
    RHYTHM_AND_BLUES,   //14
    RAP,                //15
    REGGAE,             //16
    ROCK,               //17
    TECHNO,             //18
    INDUSTRIAL,         //19
    ALTERNATIVE,        //20
    SKA,                //21
    DEATH_METAL,        //22
    PRANKS,
    SOUNDTRACK,
    EURO_TECHNO,
    AMBIENT,
    TRIP_HOP,
    VOCAL,
    JAZZ_AND_FUNK,
    FUSION,
    TRANCE,
    CLASSICAL,
    INSTRUMENTAL,
    ACID,
    HOUSE,
    GAME,
    SOUND_CLIP,
    GOSPEL,
    NOISE,
    ALTERNATIVE_ROCK,
    BASS,
    SOUL,
    PUNK,
    SPACE,
    MEDITATIVE,
    INSTRUMENTAL_POP,
    INSTRUMENTAL_ROCK,
    ETHNIC,
    GOTHIC,
    DARKWAVE,
    TECHNO_INDUSTRIAL,
    ELECTRONIC,
    POP_FOLK,
    EURODANCE,
    DREAM,
    SOUTHERN_ROCK,
    COMEDY,
    CULT,
    GANGSTA,
    TOP_40,
    CHRISTIAN_RAP,
    POP_FUNK,
    JUNGLE_MUSIC,
    NATIVE_US,
    CABARET,
    NEW_WAVE,
    PSYCHEDELIC,
    RAVE,
    SHOWTUNES,
    TRAILER,
    LO_FI,
    TRIBAL,
    ACID_PUNK,
    ACID_JAZZ,
    POLKA,
    RETRO,
    MUSICAL,
    ROCKNROLL,
    HARD_ROCK,
    FOLK,
    FOLK_ROCK,
    NATIONAL_FOLK,
    SWING,
    FAST_FUSION,
    BEBOP,
    LATIN,
    REVIVAL,
    CELTIC,
    BLUEGRASS,
    AVANTGARDE,
    GOTHIC_ROCK,
    PROGRESSIVE_ROCK,
    PSYCHEDELIC_ROCK,
    SYMPHONIC_ROCK,
    SLOW_ROCK,
    BIG_BAND,
    CHORUS,
    EASY_LISTENING,
    ACOUSTIC,
    HUMOUR,
    SPEECH,
    CHANSON,
    OPERA,
    CHAMBER_MUSIC,
    SONATA,
    SYMPHONY,
    BOOTY_BASS,
    PRIMUS,
    PORN_GROOVE,
    SATIRE,
    SLOW_JAM,
    CLUB,
    TANGO,
    SAMBA,
    FOLKLORE,
    BALLAD,
    POWER_BALLAD,
    RHYTHMIC_SOUL,
    FREESTYLE,
    DUET,
    PUNK_ROCK,
    DRUM_SOLO,
    A_CAPPELLA,
    EURO_HOUSE,
    DANCE_HALL,
    GOA_MUSIC,
    DRUM_AND_BASS,
    CLUB_HOUSE,
    HARDCORE_TECHNO,
    TERROR,
    INDIE,
    BRITPOP,
    NEGERPUNK,
    POLSK_PUNK,
    BEAT,
    CHRISTIAN_GANGSTA_RAP,
    HEAVY_METAL,
    BLACK_METAL,
    CROSSOVER,
    CONTEMPORARY_CHRISTIAN,
    CHRISTIAN_ROCK,
    MERENGUE,
    SALSA,
    THRASH_METAL,
    ANIME,
    JPOP,
    SYNTHPOP,
    ABSTRACT,
    ART_ROCK,
    BAROQUE,
    BHANGRA,
    BIG_BEAT,
    BREAKBEAT,
    CHILLOUT,
    DOWNTEMPO,
    DUB,
    EBM,
    ECLECTIC,
    ELECTRO,
    ELECTROCLASH,
    EMO,
    EXPERIMENTAL,
    GARAGE,
    GLOBAL,
    IDM,
    ILLBIENT,
    INDUSTRO_GOTH,
    JAM_BAND,
    KRAUTROCK,
    LEFTFIELD,
    LOUNGE,
    MATH_ROCK,
    NEW_ROMANTIC,
    NU_BREAKZ,
    POST_PUNK,
    POST_ROCK,
    PSYTRANCE,
    SHOEGAZE,
    SPACE_ROCK,
    TROP_ROCK,
    WORLD_MUSIC,
    NEOCLASSICAL,
    AUDIOBOOK,
    AUDIO_THEATRE,
    NEUE_DEUTSCHE_WELLE,
    PODCAST,
    INDIE_ROCK,
    G_FUNK,
    DUBSTEP,
    GARAGE_ROCK,
    PSYBIENT

}Genre;

typedef struct _Id3v1{
    char *title;
    char *artist;
    char *albumTitle;
    int year;
    int trackNumber;
    char *comment;
    Genre genre;
}Id3v1;

Id3v1 *Id3v1Tag(const char* filePath);
char *genreFromTable(Genre val);

void setTitleId3v1(char *title, Id3v1 *tag);
void setArtistId3v1(char *artist, Id3v1 *tag);
void setAlbumId3v1(char *album, Id3v1 *tag);
void setYearId3v1(int year, Id3v1 *tag);
void setCommentId3v1(char *comment, Id3v1 *tag);
void setGenreId3v1(Genre genre, Id3v1 *tag);
void setTrackId3v1(int trackNumber, Id3v1 *tag);

void freeId3v1Tag(Id3v1 *toFree);
void writeId3v1(char *filePath, Id3v1 *tag);


char *id3v1ToJSON(Id3v1 *tag);

#ifdef __cplusplus
} //extern c end
#endif

#endif