#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

/* Flag set by ‘--verbose’. */
static int verbose_flag;

int main (int argc, char **argv)
{
    int c;
    static struct option long_options[] =
    {
       /* These options don't set a flag.
          We distinguish them by their indices. */
       {"start", required_argument, 0, 's'},
       {"start-all", no_argument, 0, 'S'},
       {"stop",   required_argument, 0, 'x'},
       {"stop-all", no_argument, 0, 'X'},

       {"add",     required_argument, 0, 'a'},
       {"edit",     required_argument, 0, 'e'},
       {"delete",     required_argument, 0, 'd'},
       {"shrink",     required_argument, 0, 'S'},
       {"status",     required_argument, 0, 's'},
       {"monitor",     required_argument, 0, 'm'},

       {"list",     no_argument, 0, 'l'},
       {"help", no_argument, 0, 'h'},
       {0, 0, 0, 0}
    };

    static char* short_options = "s:S:x:X:aiu:e:d:s:S:m:l:h:";
   /* getopt_long stores the option index here. */
   int option_index = 0;

   while (1)
     {
 
       c = getopt_long (argc, argv, short_options,
                        long_options, &option_index);
 
       /* Detect the end of the options. */
       if (c == -1)
         break;
 
       switch (c)
         {
         case 0:
       printf ("ncurses starting...\n");

           /* If this option set a flag, do nothing else now. */
           if (long_options[option_index].flag != 0)
               
             break;
           printf ("option %s", long_options[option_index].name);
           if (optarg)
             printf (" with arg %s", optarg);
           printf ("\n");
           break;
 
         case 'a':
           puts ("option -a\n");
           break;
 
         case 'b':
           puts ("option -b\n");
           break;
 
         case 'c':
           printf ("option -c with value `%s'\n", optarg);
           break;
 
         case 'd':
           printf ("option -d with value `%s'\n", optarg);
           break;
 
         case 'f':
           printf ("option -f with value `%s'\n", optarg);
           break;
 
         case '?':
           /* getopt_long already printed an error message. */
           break;
 
         default:
           abort ();
         }

       if (argc <= 1) { 
       printf ("ncurses starting...\n");
       }

     }
 
   /* Instead of reporting ‘--verbose’
      and ‘--brief’ as they are encountered,
      we report the final status resulting from them. */
   if (verbose_flag)
     puts ("verbose flag is set");
 
   /* Print any remaining command line arguments (not options). */
   if (optind < argc)
     {
       printf ("non-option ARGV-elements: ");
       while (optind < argc)
         printf ("%s ", argv[optind++]);
       putchar ('\n');
     }
 
   exit (0);
 }
