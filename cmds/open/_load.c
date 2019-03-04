//#pragma save_binary
/*
// This file is part of the TMI distribution mudlib.
// Please include this header if you use this code.
// Written by Sulam(12-19-91)
// Help added by Brian (1/28/92)
*/

#include <config.h>
inherit "/std/cmd_m";

int help();

int
cmd_load(string str) {
    mixed res;

    if(!str) {
      return help();
    }
    seteuid( getuid( previous_object() ) );
    str = resolv_path((string)this_player()->query("cwd"), str);

    if (extract(str, strlen(str)-2, strlen(str)-1) != ".c")
        str += ".c";

    if (file_size(str) <= 0) {
        notify_fail("Load: " + str + " does not exist.\n");
        return 0;
    } else
        write( (res=catch(call_other(str,"???")))?str+": "+res+"\n":"Ok.\n");
    return 1;
}

int
help() {
  write("Command: load\nSyntax: load <filename>\n"+
        "This command attempts to load a file from disk.\n"+
        "Any errors in the file will prevent it from \n"+
        "loading properly.  You may also specify a path\n"+
        "along with the filename.\n");
  return 1;
}
/* EOF */
