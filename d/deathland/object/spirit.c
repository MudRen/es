

#include "../echobomber.h"
inherit OBJECT;

void create()
{
  seteuid(getuid());
  set_name("Ancient Evil Spirit","古代邪恶的灵魂");
  
  set_short("Ancient Evil Spirit","古代邪恶的灵魂");
  set("c_long",@ScryBall
被禁锢的古代邪恶的灵魂, 当你释放它的时候, 它将监视它被放出来
的地方, 而你将能知道那里的一举一动, 直到你把它毁掉为止.
--Use <info spirit> 获得更详细的资料.
ScryBall
);
  add("id",({"spirit",}));
  set( "unit", "个");
  set("weight", 0);
  set("c_extra_look","$N的身旁有著可怕的灵魂围绕著他.\n");
  set("prevent_drop",1);
  set("prevent_insert",1);
}

void init()
{
    add_action("to_info","info");
    add_action("to_scry","scry");
    add_action("to_toss","toss");
    add_action("to_release","release");
}

int to_release(string str)
{
    string room;
    if (!id(str)) 
      return 0;
    if (query("release")) 
      return notify_fail("这灵魂已经被释放出来了.\n");
    
    room = file_name( environment( this_player() ) );
    
    set("where",room);
    
    set("release",1);
    write("你在这里释放出古代邪恶灵魂来.\n");
    return 1;     
}

int to_scry(string str)
{
    object room,*item;
    int chinese_mode;
    string room_desc,desc;
    
    if (!id(str)) 
      return 0;
    if (!query("release")) 
      return notify_fail("这灵魂尚未被释放出来.\n");
    
    room_desc = query("where");
    chinese_mode=can_read_chinese();
    if ( !(room = find_object( room_desc )) ) room=new(room_desc);
    desc=call_other("/cmds/std/_look","remote_look_room",room,0,1,chinese_mode);
    write(desc);
    return 1;      
}

int to_toss(string str)
{
    if (!id(str)) return 0;
    write("你把古代邪恶灵魂给毁掉了.\n");
    this_object()->remove();
    return 1;
}

int to_info(string str)
{
    if (!id(str)) return 0;
    
    write(
    "------------------------\n"
    "释放灵魂: release spirit\n"
    "监视房间  scry spirit   \n"
    "毁掉灵魂  toss spirit   \n"
    );
    return 1;
}

