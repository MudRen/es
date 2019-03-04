//  File : /adm/daemons/language.c
//  Creator : Megadeath@TMI-2
//  Version : 1.7
//
//  language daemon, handles the languages and translation.
//  Written by Megadeath@TMI-2

#include <language.h>

string *l_list;
mapping l_mapp;

void set_lists();

mapping get_mapping();

string transform_string (string str, string language) ;

string garble_string (string str, string language) ;

string *transform_array (string *chunks) ;

//  This function will shake out some nice signs in the text such as
// , . ! ? etc..

string get_signs (string str);

//  This nifty little function is used if ya wanna check the capitalizing
//  of a word.

int check_capitalizing (string str);

 string get_string ( string what, object who, string language, int success, string garbled_string, string garbled_lang )
{
   int t ;
   mapping lang_mapp;

  lang_mapp=who->query("languages");

   if (!lang_mapp)
      lang_mapp = get_mapping();

       if (lang_mapp[language] > 0) {
           if (success) {

// Let's check and see if the listener understood the speech.

      if (random(100) < lang_mapp[language])

	if (language!="common")
         return " in " + capitalize(language) + ": " + what ;
	return ": "+what ;

// Oops, I guess he didn't...

        return " in " + capitalize(language) + ": " + garbled_string ;

	  }

// In this case the speaker failed, so we send out the tripe.

           return " in " + capitalize(language) + ": " + garbled_string ;
       }
   
   // OOps.. seems that this bloke don't know the language. Well.. lets
   // transform the string into a serie of strange sounds. ;)

   return " in some strange tongue: " + garbled_lang ;
}

string transform_string (string str, string language)
{
   string *chunks, lfile;
   int loop, i;

   chunks=explode(str, " ");

   chunks=transform_array(chunks);

   lfile = "/adm/daemons/languages/" + language + ".c";

  return (string)lfile->garble(chunks) ;
}

//  This is called when we didn't succeeded to speak well. ;)
//  Remember, this can be done nicer. Like transforming the words or
//  shifting the order and such.

string garble_string (string str, string language)
{
   int t, left, rest ;
   string *chunks, actual_string;

   chunks=explode(str, " ");

   chunks=transform_array(chunks) ;

   left=sizeof(chunks)  ;

   rest = random(sizeof(chunks)) ;


   if ( ! left )
      left = 1;

   actual_string="";

   while (left -- )
   {
       int a;
       string chunk;

       if (! rest || (rest && random(101)<50 ))
       {
         a=random(sizeof(chunks));
         actual_string+=" " + chunks[a];
         chunk = chunks[a] ;
         chunks -= ({ chunk }) ;
         if (! sizeof(chunks))
           break;
       }
        else
        {
           string dstring, lfile;
           lfile = "adm/daemons/languages/" + language  + ".c";
           dstring = (string)lfile->garble( ({ "dummy" }) );

           actual_string += " " + dstring;
           rest -- ;
        }

   }

   return actual_string;
}

//  Now we wanna check if there are any nice non-alphabetical characters
//  in the string


string get_signs ( string str )
{
   string junk;

   if ( ! str )
      return "" ;

   if (sscanf(str,"%s.",junk ) || str == "." )
      return ".";

   if (sscanf(str,"%s,",junk ) || str == ","  )
      return ",";

   if (sscanf(str,"%s!",junk ) || str == "!"  )
      return "!";

   if (sscanf(str,"%s:",junk ) || str == ":"  )
      return ":";

   if (sscanf(str,"%s;",junk ) || str == ";"  )
      return ";";

   if (sscanf(str,"%s?",junk ) || str == "?"  )
      return "?";

   if (sscanf(str,"%s'",junk ) || str == "'"  )
      return "'";

   return "";
}

int check_capitalizing ( string str )
{
   string capstr;

   if (! str )
      return 0;

   capstr=capitalize(str);

   if ( str[0] > capstr[0] )
      return 0;

   return 1;
}

string *transform_array (string *chunks)
{
   string  *chunk2;
   int loop, i;

   chunk2=allocate(sizeof(chunks)) ;

   loop = sizeof(chunks);

//  this may be a bit cludgy but without it, the daemon crashes
//  due to the strange behaviour from explode when you deal with
//  stuff like "    ".

   while ( loop-- )
   {

      if ( chunks[loop] )
      {
         chunk2[i]=chunks[loop];
         i++;
      }
      else
         break;
   }

   return chunk2 ;
}

void set_lists()
{
 int t;
 string *chunks;

   chunks = get_dir("/adm/daemons/language/");

   l_mapp = ([]);
   l_list = allocate(sizeof(chunks));

   for (t=0;t<sizeof(chunks);t++)
   {
       sscanf(chunks[t], "%s.c", l_list[t]);
       l_mapp += ([ l_list[t] : LANGUAGE_DEFAULT_SCORE ]);
   }
}

string *get_list()
{
   if (!l_list)
      set_lists();

   return l_list;
}

mapping get_mapping()
{
   if (!l_mapp)
      set_lists();

   return l_mapp;
}
