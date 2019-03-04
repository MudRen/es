
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("forest house","ɭ��С��");
  set_long(@Long
Long
,@CLong
һ����ǿֻ����ס�����Сľ��, ����Ŀǰ�����ǻҳ���֩����, ���ƺ�����
���ﱻһ�ֹ����������ռ����, ��һ��������õ�����.
    ���������������Ĵ���, �����ǻ����������������?
CLong
);
set("echo_special_place",1);
set("exits",([
     "west" :Deathland"/island/forest12",
     ]) );
set("objects",([
    "wight":Monster"/wight03",
    ]) );     
 ::reset();
}

void release(object player,object box)
{
     int i;
     object *monster,leit;
     
     if ( (string)box->query("quest_action/bottle_lock")=="falady" ) {
       tell_object(player,
      "�����ڵ���걻�ͷ���, һ���Ӿ���ʧ����Ӱ������.\n");    
       box->delete("quest_action/bottle_lock");
       return; 
       }
     monster=all_inventory(this_object());
     for(i=0;i<sizeof(monster);i++) 
        if ( monster[i]->id("wight") && monster[i]->query("npc") ) {
          tell_object(player,
          "���ͷų����ص����.\n"
          "���������س����������ǰ.\n"
          );
          leit=new(Monster"/wight02");
          leit->move(this_object());
          box->delete("quest_action/bottle_lock");
          call_out("quest_info",2,player,monster[i],leit,0);
          return;
          } 
     box->delete("quest_action/bottle_lock");
     tell_object(player,
      "���ص���걻�ͷ���, һ���Ӿ���ʧ����Ӱ������.\n");
     return; 
}

void quest_info(object player,object kanni,object leit,int depth)
{
     switch(depth) {
     case 0:
            tell_room(this_object(),
            
            "����������������ƺ����ڽ�̸Щ����...\n\n\n\n"
            );
            call_out("quest_info",5,player,kanni,leit,1);
            break;
     case 1:
            tell_room(this_object(),
            "һ�����,���������������,������Ҳ�����ص���ͷ.\n\n\n\n"
            );
            call_out("quest_info",2,player,kanni,leit,2);
            break;
     case 2:
            tell_room(this_object(),
            "һ���׻��ӿ�����������,�����ص������ݻ���.\n"
            );
            leit->remove();
            tell_object(player,
            "����˵��:\n"
            "�����ֵ����˵���Ը�Ѿ������, ���԰��ĵ��뿪���������.\n"
            "�ǳ�лл��İ�æ, �������ٸ�����һ������, ��˼Ȫˮ�Ķ���\n"
            "����������Ļ�ɫĢ��������, ���㳢��Ҫȥ����Ȫˮ��ʱ��, \n"
            "�ǵ�Ҫ�ȷŵ�Ģ����( mix )��Ȫˮ֮��.ǧ��Ҫ�ǵ�, ��������\n"
            "�ֵܵ��Ҹ�.\n"
            "����һ����,�����ˮ����Ƭ����. �ҽ����������������������.\n"
            "���������ط�����˫��춿�Ƭ��.\n"
            );            
            call_out("quest_info_2",5,player,kanni);               
            break; 
     }
     return;
}

void quest_info_2(object player,object kanni)
{
     object *items;
     int i;
     tell_object(player,
     "����ʩչ���ķ�����,˵:\n"
     "�����ǳ���ͼ�����, ��Ѱ�ذ�(floor),�㽫����һƿ������, ���ǲ���.\n"
     "��ͨ�ĺ�����, �����л��, ��������ð������һ����Σ����������. ϣ��\n"
     "�������������.\n"
     "�Ծ�춴�, �ҵ��ֵ�����������...\n"
     "��ʱ, ���������׻����Լ�, ��ʧ�������.\n"
     );
     kanni->remove();
     items=all_inventory(player);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           items[i]->set("quest_action/pepper_find",1);
     if ( (int)player->query_quest_level("queen_smile") < 4 )
       player->finish_quest("queen_smile",4);
     return;
}
