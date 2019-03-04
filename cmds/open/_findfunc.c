//#pragma save_binary
// File:       _findfunc.c
// Purpose:    A command line interface to function_exists for wizards
// Credits:
// 92-12-11    Mobydick wrote the original version.
// 93-02-13    Pallando added shadow stuff and get_object()
// 93-07-07    Grendel rewrote to give more informative result.
// 93-07-13    Grendel added references

#include <mudlib.h>
#include <daemons.h>

inherit DAEMON ;
inherit REF_D ;

#define SYNTAX "Usage: findfunc <function> <target object>\n"

int cmd_findfunc(string arg)
{
    string func, target, str;
    mixed tmp;
    object ob,shad;

    notify_fail( SYNTAX );

    if(!arg || sscanf(arg,"%s %s",func, target) != 2)
	return 0;
    
    // find the function we are after
    tmp=resolv_ref(func);
    if(!stringp(tmp)) {
	notify_fail(sprintf("findfunc: %s is not a string\n",identify(tmp)));
	return 0;
    }
    func=tmp;

    // find the object refered to on the command line
    tmp=resolv_ref(target);
    if(stringp(tmp)) {
	ob=get_objects(tmp,0,1);
	if(!ob) {
	    notify_fail(sprintf("findfunc: could not locate \"%s\"\n",tmp));
	    return 0;
	}
    }
    else if(objectp(tmp))
	ob=tmp;
    else {
	notify_fail(sprintf("findfunc: %s is not an object\n",identify(tmp)));
	return 0;
    }

    // test if the function exists
    str=function_exists(func,ob);

    if(str)
	// it exists
	printf("%s() in %s is defined in %s\n",func,file_name(ob),str);
    else
    {
	// test shadows
	for(shad=shadow(ob,0);shad;shad=shadow(shad,0))
	    if(str=function_exists(func,shad))
	    {
		printf("%s() is defined in the shadow %s of %s\n",
		    func,file_name(shad),file_name(ob));
		return 1;
	    }
	// failed to find in the object or its shadows
	printf("%s() is not defined in %s\n",func,file_name(ob));
    }
    
    return 1;
}

int help()
{
    write(SYNTAX + "\n" + @EOH
This command is used to find out where a function within an object is
defined.  If the function is not defined the command will inform the
user, otherwise it will give the name of the file where the function is
defined.  get_objects() is used to locate the object, and shadows are
also tested for.
  Note that findfunc will not find efuns or simul_efuns.  Neither will
it detect static or  functions, as these cannot be detected by
function_exists() from the outside.
  findfunc is one of the reference set of commands, and will accept
references for either argument. (see "help refs")
EOH
	);
    return 1;
}
