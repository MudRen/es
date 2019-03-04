
#include "../echobomber.h"
#define QUEEN_SMILE Deathland+"/adm/queen_smile"

inherit ROOM;
inherit DOORS;
void create()
{
	::create();
set("light",1);
set_short("�ʺ�����˿�������");
  set_long(@Long
Long
,@CLong
�����ǻʺ�����˿���޹�.��һ�Ŵ�,һ����ױ̨�������ڽ�����.��������,
��û���κζ��ŵ���Ʒ.
CLong
);
set("echo_special_place",1);
set("exits",([
             "west":Deathland"/palace/pa_05",
             ]));
create_door("west","east",([
             "name":"gold door",
             "c_name":"��ɫ����",
             "keyword":({"gold door","door",}),
             "c_desc":"��ɫ����",
             "status":"locked",
             "desc":"a gold door",
             "lock":"ECHO_DWARF_CITY_1",
                     ]) );

set("objects",([
    "queen":Monster"/queen",
     ]) );
reset();
}

void init()
{
	this_player()->set_explore( "deathland#12" );
}

void release(object player,object box)
{
     int i;
     object *monster,falady;
     
     if ( (string)box->query("bottle_lock")=="leit" ) {
       tell_object(player,
      "���ص���걻�ͷ���, һ���Ӿ���ʧ����Ӱ������.\n");    
       box->delete("quest_action/bottle_lock");
       return; 
       }
     monster=all_inventory(this_object());
     for(i=0;i<sizeof(monster);i++) 
        if ( monster[i]->id("queen") && monster[i]->query("npc") ) {
          tell_object(player,
          "���ͷų������ڵ����.\n"
          "�����������س����������ǰ.\n"
          );
          box->delete("quest_action/bottle_lock");
          falady=new(Monster"/falady");
          falady->move(this_object());
          tell_room(this_object(),
          "���ʺ���������ӵ�ʱ��, ���˵�����������.\n"
          "������Ҳ�Ǻܸ���,����������˺ܾ�.\n",
          ({falady,monster[i],}) ); 
          call_out("quest_info",10,player,falady,box);
          return;
          } 
     box->delete("quest_action/bottle_lock");
     tell_object(player,
      "�����ڵ���걻�ͷ���, һ���Ӿ���ʧ����Ӱ������.\n");
     return; 
}

void quest_info(object player,object falady,object box)
{
     tell_room(this_object(),
     "���˺ܾ�, ����������ĸ�׻ӻ���, Ȼ�����ʧ��.\n"
     );
     falady->remove();
     tell_object(player,
     "�ʺ���ʱ����˵: лл��, ���Ѿ�֪���Ҷ�������һ���������ĺܺ�.\n"
     "��ҲӦ����������, ��Ҫ��������Ϊ�ҵ�����.\n"
     "�ʺ�����΢Ц��.\n" 
     "**********************************\n"
     "�������������ѵ�����.\n"
     "**********************************\n"
     );
     tell_room(this_object(),"�ʺ�����΢Ц��.\n",player);
     if ( (int)player->query_quest_level("queen_smile")< 5 )
       player->finish_quest("queen_smile",5);
     return;
}
