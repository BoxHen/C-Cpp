/*The  block of code in this comment is in setpath_defs.h
#ifndef _WIN32
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#endif

void setpath();

// These 2 lines belong BEFORE �main�, so the names are global
       FILE* infile;
       FILE* outfile;
*/ 

void setpath()
{
#ifdef _WIN32  //Windows
       char in_path[]="C:\\temp\\coursein\\p3-in.txt";
       char out_path[]="C:\\temp\\courseout\\p3-out.txt";
#else //Linux
       // For Linux, the "home" directory actually contains the current userid
       // so we have to get that name from the system and put it in front of the path.
       // Many Linux shells will only expand the "~" if it is used from the command line
       in_path[200];
       out_path[200];
       //char out_path[]="/fileio/courseout/p2-out.txt";
       //strcpy(out_path,"/fileio/courseout/p2-out.txt");
       // outpath is NOT in your home directory!!!
             const char *homedir;
             homedir = getenv("HOME");
             if (homedir!= NULL)
                    homedir = getpwuid(getuid())->pw_dir;
             // get the actual home directory for the current user
             strcpy(in_path,homedir);
             //strcpy(out_path,homedir);
             // the outfile goes to a separate drive, NOT in your home directory
             // now add on the common part of the path
             strcat(in_path,"/temp/coursein/p3-in.txt");
             strcat(out_path,"fileio/courseout/p3-out.txt");
#endif
}

// Now you can use the names, infile and outfile in your fopen, input and output statements.
