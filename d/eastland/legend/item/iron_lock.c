#include <mudlib.h>

inherit OBJECT;

void create()
{
     set_name("iron lock", "大铁索");
     add("id", ({ "lock"}) );
     set_short("大铁索");
     set_long(@C_LONG
一件沈重的铁锁。
C_LONG
     );                             
     set( "unit", "件" );
     set( "no_sale",1);
}
void init()
{
   add_action("do_lock","iron_lock");
}
int do_lock(string arg)
{
    object holder,env,victim;
   
    holder=environment(this_object());
    if ( !living(holder) ) 
       return 0;    
    env=environment(holder);
    if ( !victim=present("beast",env) ) {
       tell_object(holder,"对不起,请不要乱来。\n");
       return 1;
    }
    if ( !victim->query("npc") ) {
       tell_object(holder,"咩,他跟你有仇吗?\n");
       return 1;
    }
    if ( !victim->query("faint") ) {
       tell_object(holder,"呜,它清醒著～～\n");
       return 1;
    }
    if ( victim->query("locked") ) {
       tell_object(holder,"可怜的它已经被锁上了!\n");
    }
    tell_object(holder, sprintf("你用大铁索锁在%s的颈脖上,鼻孔里又给穿上了金铃!\n",
       victim->query("c_name")) );
    tell_room(env,sprintf(
       "%s用大铁索锁在%s的颈脖上,鼻孔里又给穿上了金铃!\n",holder->query("c_name"),victim->query("c_name")),holder);
    victim->set("locked",1);
    this_object()->remove();               
    return 1;
}