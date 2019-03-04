#include "../legend.h"
#include <conditions.h>

inherit ROOM;

void create()
{
        ::create();
    set_short("����ˮ��̶��");
        set_long( 
@LONG
쬣�����롸��ˮ��̶����������̶ˮ���ϵ�ӿ����ȫ���ëϸ�ף�һ��
�������������ͷ������ֱ��ŵף����ݷ������������������һ��������̶
��㲻ס�ض������壬��ʱ����ˮ�棬ȴ����Խ��Խ���ܣ�������Ļ��ܾ�����
����뿪���뿪��Ȼ���������ˡ�
LONG);
    set( "light",1);
    set("underwater",1);
    set( "exit_suppress", ({
         "up"}) );
    set("exits",([
            "up":LAKE"village5"
    ]) );
    ::reset();
}

void init()
{
   UNDERWATER->apply_effect(this_player(),4,2);
   add_action("do_dive_down","dive");
   add_action("do_search","search");
}
int do_search()
{
   tell_object(this_player(),
     "����û��ʲ�ᶫ���������������������(down)ǱǱ(dive)�����������Ӿ�ļ��ܲ������ǻ�������(up)�뿪���ˡ�\n");
   return 1;
}
int do_dive_down(string arg)
{
    
  int probability;
  object player,env;
  string name;
  
  player=this_player();
  if (!arg||arg!="down") {
     tell_object(player,"����Ǳ������ȥ��\n");
     return 1;
  }
  if ( player->query_temp("have_dive") ) return 1;
  player->set_temp("have_dive",1);
  env=environment(player);
  name=player->query("c_name");
  tell_object(player,"������һ������Ǳ�¡���ˮ��̶��.......\n");
  tell_room(env,sprintf("%s����һ������Ǳ�¡�ˮ̶��̶��.......\n",name),player);
  probability=(int)player->query_skill("swimming")/(int)player->query_level();
  if ( probability+random(5) >7 ) {
     player->set_temp("block_command",1);  
     call_out("recover1",7,player);
     return 1;
  }
  tell_object(player,"��Ȼһ�ɼ����ѹ��ӭ��������㼸�����˹�ȥ..\n\n");
  player->delete_temp("have_dive");
  player->receive_damage(10);
  return 1;
}
void recover1(object player)
{
   player->delete_temp("block_command"); 
   player->delete_temp("have_dive");
   tell_object(player,"\n�͵أ�ˮ̶��һ�������������....\n\n\n\n");
   player->move(LAKE"village8","SNEAK");
}  



