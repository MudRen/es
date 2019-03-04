
#include "../echobomber.h"
#include <move.h>
inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("mystic fire","����");
  set_long(@Long
Long
,@CLong
���Ѿ�����ؿ�������������, ֻ��һ��а��������ɻ�����ɢ��, ���˲���
����. 
CLong
);
set("item_func",([
    "fire":"to_look_fire",
    ]) );
set("search_desc",([
    "fire":"һ�ſ��µĻ�, ����ñ�̫������.\n",
    ]) );    
set("exits",([
             "east":Deathland"/holyplace/h23",
             ]));
reset();
}

int to_look_fire()
{
    object player;
    player=this_player();
    write("���㿴�����Ż��ʱ��, ����˾��û�������, ֻ�����и�ģģ"
          "��������Ӱ�����س������������.\n");
    player->set_temp("block_command",1);          
    say("��"+player->query("c_short")+"ע�������ŵ�ʱ��, �����������ʧ�˻��Ƶ�.\n");
    call_out("quest",3,player);
    return 1;
}

void quest(object player)
{
     tell_object(player,
     "һ��������������������Ժ�.\n"
     "��, �������� , а��֮�� YANG �ĵ��� , ��˼(ICE) , �����ٻ���.\n"
     "������ҵؿ���Ϊ��Ч��. ����Ҫһ���˰��ҽ������������ϵ�����\n"
     ", ��ֻ��Ҫ�ҵ��ҵĺ���, ˺�����������ϵ��ǵ�����, Ȼ��ص�����\n"
     "�㽫�õ���ı���.\n"
     );  
     if ( present("paper",player) ) { 
       tell_object(player,
       "�벻�����������������ķ���, �����ҽ����Իָ��ҵ�ħ����.\n"
       "������.....\n\n\n\n"
       "��ʱ�㿴�����������������䰵........\n"
       );
       call_out("quest_2",4,player);
       }
     else
       player->set_temp("block_command",0);
     return;
}


void quest_2(object player)
{
     object item;
     int moveflg;
     
     tell_object(player,
     "\n\n\n\n\n\n���ٶȵ���������.\n\n"
     "����˵��: �Ƿ����Ѿ������˼����µ�����, ���˽��޷������.\n"
     "�벻��������������ħ��������ǿ��. ����ɶ�ļһ�, ��\n"
     "�뵽������ķ���ҲӦ�ú��ҵ���һ���˰�! \n"
     "���ܼ�������Ϊ�Ҵ������? ������Ҳû��ѡ����. ����һ����\n"
     "֮��. ����Ψһ���ܹ�����������Ʒ, ���Ǿ������⼸������,\n"
     "��֪����û��Ч. \n"
     );
     item=new(Object"/diamond01");
     moveflg=item->move(player);
     if ( moveflg !=MOVE_OK ) { 
       tell_object(player,
       "**���޷��õĶ�����֮��**.\n"
       );
       item->remove();
       }
     player->set_temp("block_command",0);
     return ;  
}
