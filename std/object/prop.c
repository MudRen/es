//#pragma save_binary

// This file is a part of the standard object system devised by Buddha.
// Currently under development.

// This file is part of the TMI mudlib distribution.
// Please include this header if you use this code.
// Written by Buddha@TMI, modularized and revised (92-05-01)
// Expanded to use a superior security system by Buddha (92-05-31)
// Temporary flag attribute system added by Watcher (93-02-21)
// Prop_logic written by Pallando (93-03-20)
// NB - This file does not make use of the full potential of prop_logic yet.
// Add default objects at (95-5-21) . Idea by Annihilator@Eastern.Stories.
// Add by Ruby@Eastern.Stories

mapping ob_data; // obscure name so it won't break code
nosave mapping tmp_ob_data; //	Temporary flag attrib mapping
nosave mixed default_ob;

#include <uid.h>
#include "/std/object/prop_logic.c"

// A basic init function.

void init_ob()
{
	if( !ob_data ) ob_data = ([]);
	if( !tmp_ob_data ) tmp_ob_data = ([]);
}

// set default object to original object
void set_default_ob(mixed ob)
{
	default_ob = ob;
}
mixed query_default_ob()
{
	return default_ob;
}
//  A query of the data sets ... for admins and root access only.

mapping query_ob_data()
{
	if( !member_group(geteuid(previous_object()), "admin") &&
		geteuid(previous_object()) != ROOT_UID &&
		!master()->valid_write(base_name(this_object())+".c", previous_object()) )  return 0;
	return ob_data;
}

mapping query_temp_ob_data()
{
	if(!member_group(geteuid(previous_object()), "admin") &&
		geteuid(previous_object()) != ROOT_UID &&
		!master()->valid_write(base_name(this_object())+".c", previous_object()) )  return 0;
	return tmp_ob_data;
}


// The generic set(label, value) function.
// You can specify elements deeper in the tree by passing a chain of elements
// separated by slashes...  thus, use could be:
// set("short", "a generic object");
// set("limb/left leg/hp", 63);

nomask varargs int set( string label, mixed value, int access_level )
{
/*
	string temp,temp1;
	// object in /u/ only can modify object in /u/ or wizard, Added by Yueh
	if (!wizardp(this_object()))
	{
		temp=explode(base_name(previous_object()),"/")[0];
		if ((temp== "u")||(temp=="open")){
			temp1=explode(base_name(this_object()),"/")[0];
			if ((temp1!= "u")||(temp1!="open"))
				return 0;
		}
	}
*/
	if( !ob_data ) init_ob();
	if( !label ) return 0;
	_set( ob_data, explode( label, "/" ), value );
	return 1;
}
varargs int set_temp( string label, mixed value, int access_level )
{
/*
	string temp,temp1;
	// object in /u/ only can modify object in /u/ or wizard, Added by Yueh
	if (!wizardp(this_object()))
	{
		temp=explode(base_name(previous_object()),"/")[0];
		if ((temp== "u")||(temp=="open")){
			temp1=explode(base_name(this_object()),"/")[0];
			if ((temp1!= "u")||(temp1!="open"))
				return 0;
		}
	}
*/
	if( !tmp_ob_data ) init_ob();
	if( !label ) return 0;
	_set( tmp_ob_data, explode( label, "/" ), value );
	return 1;
}

varargs void delete( string label )
{
	if( !ob_data ) init_ob();
	if( !label ) return 0;
	_delete( ob_data, explode( label, "/" ) );
}

varargs void delete_temp( string label )
{
	if( !label ) return 0;
	if( !tmp_ob_data ) init_ob();
	_delete( tmp_ob_data, explode( label, "/" ) );
}

// This is for querying data.
// If you wish to make certain parts of the structure private,
// then redefine this, and use check for the  section, before
// returning ::query().

nomask mixed query( string label )
{
	mixed value;
	string func;

	if( !ob_data ) init_ob();
	if( !label ) return base_name(this_object());
	if( strsrch(label, '/')<0 ) value = ob_data[label];
	else value = _query( ob_data, explode( label, "/" ) );
	if( stringp( value ) && sscanf( value, "@@%s", func )==1 )
		return call_other( this_object(), ({func}) );
	if (undefinedp(value) && default_ob )
		value = default_ob->query(label);
	return value;
}

nomask mixed query_temp( string label )
{
	mixed value;
	string func;

	if( !tmp_ob_data ) init_ob();
	if( !label ) return 0;
	if( strsrch(label, '/') < 0 ) value = tmp_ob_data[label];
	else value = _query( tmp_ob_data, explode( label, "/" ) );
	if( stringp( value ) && sscanf( value, "@@%s", func ) )
		return call_other( this_object(), func );
	return value;
}

// This one is just for adding to arrays and mappings..
// (though actually it will work for integers, strings, etc)
// This needs to be more thoroughly tested but it seems to work.
// to call it, use the "level1/level2/level3" format of the other functions.

void add( string label, mixed arg )
{
	mixed foo;
	foo = query( label );
	if( !foo ) set( label, arg );
	else set( label, foo + arg );
	return;
}

void add_temp( string label, mixed arg )
{
	mixed foo;
	foo = query_temp( label );
	if( !foo ) set_temp( label, arg );
	else set_temp( label, foo + arg );
	return;
}

/* EOF */
