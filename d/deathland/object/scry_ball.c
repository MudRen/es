#include "../echobomber.h"
  inherit OBJECT;
void create()
{
  set_name("Scry ball","Scry ball");
  set("c_short","ˮ����");
  set("c_long",@ScryBall
һ��ħ��ˮ����,����׷����ĵ���,��PK������
use <scry someone>.
------------creator Echobomber--------
ScryBall
);
  set("id",({"ball","scryball"}));
  set( "unit", "��");
  set("weight", 0);
  set("invisible",1);
  set("c_extra_look","$N��ħ��������������ת.\n");
  set("prevent_drop",1);
}

int query_auto_load() { return 1;}

void init()
{
    add_action("scry_someone","scry");
}

int scry_someone(string who)
{
    object ob,room;
    
    if (!who) return notify_fail("Scry Who\n");
    else {
      ob=find_player(lower_case(who));
      if (!ob)
        return notify_fail("No such player\n");
      room=environment(ob);
      write(can_read_chinese() ? 
        room->query("c_long") : room->query("long") );
    }
    return 1;
}
