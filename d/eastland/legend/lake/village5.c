#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("������");
        set_long( 
@LONG
������ľС��Ѱ��Ȫˮ�����ߵ������̧ͷһ���������ϱ������ɽ����һ��
������ն���������һ���������ƥ�����������������ֱк��ע����ɽ��֮�У�
�ٲ���Ȫ����ͣ��̻ص��䣬���๬�̣�����춶�������ˮ���丣�����������˿
���ᵯ������ˮ���ƺ���ͬ��ʯ������ÿ������֮�գ���������������Ʈ�գ�����
���䣬������£����������������˱��ڣ��˵�����������֮���棬������̾��
LONG);
    set( "light",1);
    set( "exit_suppress", ({
          "west" }) );
    set("exits",([
          "west":LAKE"village4",
    ]) );
    set("objects",([
       "hermit":LMONSTER"hermit"
    ]) );
    ::reset();
}

void init()
{
   add_action("do_dive_down","dive");
   add_action("do_search","search");
}
int do_search()
{
   tell_object(this_player(),
        "����û��ʲ�ᶫ�����������������������(pool)ǱǱ(dive)����\n");
   return 1;
}
int do_dive_down(string arg)
{
  int probability;
  object player,env;
  string name;
  
  player=this_player();
  if (!arg||arg!="pool") {
    tell_object(player,"����Ǳ������ȥ��\n");
    return 1;
  }
  env=environment(player);
  name=player->query("c_name");
  tell_object(player,"������һ�������Թ���ʽǱ�°����������µ�ˮ̶.......\n");
  tell_room(env,sprintf(
    "%s����һ�������Թ���ʽǱ�°����������µ�ˮ̶.......\n",name),player);
  probability=(int)player->query_skill("swimming")/(int)player->query_level();
  if ( probability+random(5) >7 ) {
     player->set_temp("block_command",1);
     call_out("recover1",7,player);
     return 1;
  }
  tell_object(player,"�㲻��ˮ�ԣ��Ǳ������������ܵ����µ�����ͤ��С��\n\n");
  tell_room(env,sprintf(
    "%s�Ǳ�������������ʲ���ջ�Ҳû���ܵ����µ�����ͤ��С��\n\n",name),player); 
  player->move_player(LAKE"village6","SNEAK");
  return 1;
}
void recover1(object player)
{
   player->delete_temp("block_command"); 
   tell_object(player,"\n�͵أ�ˮ̶��һ�������������һ���ط�....\n\n\n\n");
   player->move(LAKE"village7","SNEAK");
}  



