/************************************************************************
 *
 *    extrd/exist.c
 * Make output directory with the name YYDDDHHMMSS                
 * 
 ************************************************************************/
#include "extrd.h"


int mkfname( outdb, time, out_dir)
char **outdb;
double time;
char *out_dir;
{

    char tmp[256];
    struct stat buf;
    int yr,day, hour, min, sec, msec;

    if( (Data_file = (char *) malloc(512) ) == NULL )  {
          die( 1, " malloc error\n");
    }
   
/* Make directory name for new data subset from data start time   */
   
   dtsplit(time, &yr, &day, &hour, &min, &sec, &msec); yr -= 1900;
   if(out_dir != NULL)
     sprintf( *outdb,"%s/%2.2d%3.3d%2.2d%2.2d%2.2d\0", 
              out_dir, yr, day, hour, min, sec);
   else
     sprintf( *outdb,"%2.2d%3.3d%2.2d%2.2d%2.2d\0", 
              yr, day, hour, min, sec);
  
/* Make new wfdisc name from data start time  */
 
   strcpy(Data_file, *outdb);
   strcat(Data_file, ".w");

   pathfrname( Data_file, Outdir);
   if( strlen( Outdir) <= 0 ) sprintf( &Outdir[0], ".\0");
   namefrpath( Data_file, Dfile );

 
/*  Make directory for data subset from start time  */
     
   if(stat(Data_file, &buf) != 0)  {
        if (!ENOENT)  {
            complain( 1,"stat error:");
            return 0;
        }  
    } else  {
        complain( 0, "File %s already exist\n", Data_file);
        complain( 0, "Can't overwrite existing file.\n");
        return 0;
   }
   if (( Df = fopen(Data_file, "w")) == NULL )  {
         complain( 1,"Can't open file %s\n", Data_file);
         return 0;
   }

   return 1;    
}
