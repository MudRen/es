#include "mudlib.h"
inherit OBJECT;

#define NEED_MEMBERS 1

int create()
{
	seteuid(getuid());
	set_name("invis_obj", "隐形物件");
	set_short("invis_obj" ,"隐形物件");
        set_long(
                 "quest 需要的东西( 请看skeleton.c )....\n");
	
	set("unit","件");
        set( "invisible" ,1);
        set("weight",200);
	set("value",({ 0, "silver"}) );
	set("prevent_drop",1);
        set( "extra_look", "$N正和一些人，吃力的抬著一具巨大的髑髅\。\n" );
}

void init()
{
	add_action("to_quit","quit");
	add_action("to_drop","put");
	add_action("to_quit","party");
}

string query_short()
{
  return query("Title")+"[抬著一具巨大髑髅\]" ;
}
int to_quit()
{
      write("你们还在搬东西喔，先把它放下吧...\n");
      return 1;    
}
int to_drop(string arg)
{	
     int i,num;
     object *usr,me,inv,obj;
     string str;
     
     if( !arg || lower_case(arg) != "skeleton" ) return notify_fail("把什麽放下?\n");
     me=this_player();
     usr = (mixed *)me->query_temp("party_members");
     num = sizeof(usr);
    
     if ( (string)me->query_temp("leader") != (string)me->query("name") ) {
	       write("只有队伍的领导者，才能下命令喔。\n");
	       return 1;
	       }
	       for( i=0; i<sizeof(usr); i++ )
	       {       
	       str = ((usr[i]->query_temp("carry_skeleton",1))?("一，二，三....你如释重负地把这具巨大髑髅\放下...\n"):"");
	       usr[i]->delete_temp("carry_skeleton");
	       tell_object(usr[i],str );
	       }
	tell_room(environment(me),"你看到"+me->query("c_name")+"和他的队友\n"
		"将一件庞然大物丢到地上\n", usr);
        obj = new("/d/eastland/liang_shan/obj/skeleton");
        obj->move(environment(me));
	for( i=0; i<sizeof(usr); i++ )
	{
	inv = present("invis_obj",usr[i]);
	if (usr[i] != me) inv->remove();
	}
	inv = present("invis_obj",me);
	inv->remove();
	return 1;
}
