//#pragma save_binary

// The standard guild token
// Due to variant of all the guilds, this file supplys only default functions
// Created by Annihilator Oct 6, 1993
// Updated by Kyoko 4/12/1994

#include <daemons.h>

object owner;
string class_name;
mapping levels = ([]);

void create()
{
	this_object()->set( "prevent_drop", 1 );
	this_object()->set( "prevent_get", 1 );
	this_object()->set( "prevent_insert", 1 );
}

init()
{
	object obj;
    string old_class;
    
    // Update the old owner
	if( owner && living(owner) ) {
	    old_class = (string)owner->query("class");
		owner->delete( "guild" );
		owner->delete( "class" );
		PATH_D->delete_path(owner, "/cmds/std/"+old_class);
		PATH_D->delete_path(owner, "/d/"+old_class+"/cmds");
		this_object()->unapply_stat();
	}
	owner = environment( this_object() );
	if( living(owner) ) {
        // Destruct old guild token if exists.
		if( obj = (object)owner->query("guild") ) {
		    old_class = (string)owner->query("class");
		    PATH_D->delete_path(owner, "/cmds/std/"+old_class);
		    PATH_D->delete_path(owner, "/d/"+old_class+"/cmds");
		    obj->unapply_stat();
			obj->remove();
	    }
		owner->set("guild", this_object() );
		owner->set("class", class_name );
		// just add for a while.
		PATH_D->delete_path(owner, "/cmds/std/"+class_name);
		PATH_D->add_path(owner, "/d/"+class_name+"/cmds");
		this_object()->apply_stat();
	}
	else this_object()->remove();
}

// Define this function to enable this object be auto-loaded
// when a player login. 
int query_auto_load()
{
	return 1;
}

void set_class_name(string arg)
{
	class_name = arg;
}

object get_owner()
{
	return owner;
}

int filter_members(object plr)
{
	if( (string)plr->query("class")==class_name && visible(plr,owner) ) {
		levels[plr] = (int)plr->query_level();
		if( !levels[plr] || levels[plr] == 0 ) return 0;
		return 1;
	}
	return 0;
}

int sort_members( object u1, object u2 )
{
	return (int)levels[u2] - (int)levels[u1];
}

int filter_member(object plr)
{
	if( (string)plr->query("class") == class_name ) return 1;
	if( member_group(plr->query("name"), "admin") &&
		plr->query("listening/"+class_name) ) return 1;
	return 0;
}

// default function to list all guild members.
int list_guild_members()
{
	object *usr;
	int i;

	usr = filter_array( users(), "filter_members", this_object() );
	usr = sort_array( usr, "sort_members", this_object() );
	if( sizeof(usr) ) {
		owner->quick_message(
             "Ŀǰ���� " + sizeof(usr) + " λ"+to_chinese(class_name)+"������:\n"
			 "==================================\n");
		for( i=0; i<sizeof(usr); i++ )
			owner->quick_message(
				sprintf( "[ %2d ] %s (%s)\n", usr[i]->query_level(),
					usr[i]->query("short"), capitalize(usr[i]->query("name")) ) );
	} else 
		owner->quick_message(
			"�ƺ�û���κ�"+to_chinese(class_name)+"����ĳ�Ա������....��\n");
	return 1;
}

// default guild channel, added by Kyoko.
// if a admin set listening then he will heaar, too.
int guild_line(string msg)
{
	object *usr;
	int i;
	string color;

	if( !msg ) return notify_fail(
		"��Ҫ�Ա������ͬ��˵ʲ�᣿\n");
	usr = filter_array( users(), "filter_member", this_object() );
	if( sizeof(usr) )
		for( i=0; i<sizeof(usr); i++ )
			usr[i]->quick_message( 
				sprintf(set_color("[%s] %s(%s):", "CYN", usr[i])+" %s\n",
					to_chinese(class_name), owner->query("c_name"),
					capitalize(owner->query("name")), msg) );
	return 1;
}
