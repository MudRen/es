#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("�����Ȫ");
    set_long(@LONG
�����и��ۼ��徻Ȫˮ��Сˮ�أ�Ȫˮ�Լ�ɽ��ӿ�����γ�һ��С�ٲ�
���£���ͷ�и�С���ף���ˮע��ʱ�����׾ͻ��㵹ʹˮ������У�ˮ����
һȺ�������е�������ӭ��һ�������磬����������һ����������ʯͷ��
δ������һ����Ȥ��
LONG
      );
      set("light",1);
      set("water_source",1);
      set_outside("island");
      set("exits",([
          "north":CITY"inway1"]) );
      reset();    
}

void init()
{
   add_action("do_drink","drink");
}   

int do_drink(string str)
{
   if( !str || str!="water")
      return notify_fail("�����ʲ�᣿\n");
   
   tell_object( this_player(),"����������˼���������Ȫˮ...........\n");
   tell_room(environment(this_player()),
    this_player()->query("c_name")+"�����Ķ�����������ϸ��Ʒ�������е�Ȫˮ��\n"
   ,this_player() );
   
   if( (string)this_player()->query("class") != "knight") 
       return notify_fail("�����룺������ˮ������˶����\n");
   tell_object(this_player(),"����Ȫˮ�ᣬ��ľ����ƺ��ö��ˣ�\n");
   tell_room( environment(this_player() ),
      "ͻȻ��������˫�֣����һ�����������ꡫ�������룬��Ȫˮ������Ŷ��\n"
      ,this_player() );
   this_player()->set("spell_points",(int)this_player()->query("max_sp") );
   return 1;
}  