#include <mudlib.h>
inherit OBJECT;

void create()     
{
	set("short", "@@query_short");
	set("long", "@@query_long");
 	set_name( "wonderful-spell", "万相俱灭术" );
        add("id",({"wonderful"}));
	set( "unit", "张" );
	set("weight", 10);
	set("value", ({ 5, "silver" }));
	set("fuel", 3600); 
}


void init()
{
	add_action("cast_me", "cast-me");
	add_action("uncast_me", "uncast-me");
}

int cast_me(string arg)
{
     object player;
     player=environment();
     if ( !living(player) )
	 return notify_fail("请捡起来再施为。\n");
     if ( !arg || arg!="wonderful" ) 
	 return notify_fail("Syntax <cast-me wonderful>\n");
     if( query("wonderful_used") ) 
	 return notify_fail( "这万相俱灭术正在施展中\n");
     if( player->query_temp("wonderful_spell") )
         return notify_fail("你己经施展万相俱灭术了。\n");         
     write("你开始施展万相俱灭术试著把自己变成一颗尘埃。\n");
     set("wonderful_used", 1);
     set("prevent_get",1);
     set("prevent_drop",1);
     set("prevent_insert",1);
     player->set_temp("wonderful_spell",1);
     call_out("burn_out",query("fuel"));
     return 1;
}

int uncast_me(string arg)
{
     object player;
     player=environment();
     if ( !living(player) )
         return notify_fail("请捡起来再施为。\n");
     if ( !arg || arg!="wonderful" )
             return notify_fail("Syntax <uncast-me wonderful>\n");
     if( !query("wonderful_used") )
	 return notify_fail( "这万相俱灭术还未施展那来的终止？\n");
	                 
     write("你暂时先终止万相俱灭术的施展，变回原来的模样。\n");
     set("wonderful_used", 0);
     set("prevent_get",0);
     set("prevent_drop",0);
     set("prevent_insert",0);
     player->delete_temp("wonderful_spell");
     set("fuel", remove_call_out("burn_out"));
     return 1;
}
void burn_out()
{
     object owner;

     owner = environment(); 
     if( living(owner) )
        tell_object( owner,"万相俱灭术的能源已经耗尽了．．\n");
     owner->delete_temp("wonderful_spell");
     this_object()->remove();
}
string query_short()
{
     if(query("fuel"))
        return sprintf("万象俱灭术%s", (query("wonderful_used") ? " (使用中)" : "") );
}

string query_long()
{
     if(query("fuel"))
	return (@LONG
万相俱灭术是金石老人多年研究有形无形等物质的心得而来的。万相俱灭术在於隐
藏自已的形踪变成空气中的尘埃，并在空间放著一个自己的法相用以欺骗敌人，以
达到保护自已的功用。不过，由於研究的不完全，所以只能对某些特定的怪物而使
用。使用时，你只要　(　cast-me wonderful　)　就可以了，不过请切记，这术
有使用的时效，如果想变回只需　( uncast-me wonderful )　就可以了。据金石
老人的估计，全部有半个时辰的时效。
LONG
     );
}
