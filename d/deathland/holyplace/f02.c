// Deathland/holyplace/f02.c 
// Created by Echobomber @Eastern.Stories 
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    
    set_short("fire bridge","����");
    set_long(@Long
Long
,@CLong
�ص׵��ҽ���ð����������������Ϯ����,��ط��Ѿ��൱�ӽ��ص���.����Ķ���
��һ����,������������һ�ȼ�յ�����֮��,���������ҵ�����,���޷������������
�����������.������һ���ںڵĶ�Ѩ,ͨ��δ֪������.
CLong
);

set("c_item_desc",([
    "cave":"@@to_look_cave",
    "bridge":"@@to_look_bridge",
    ]) );
set("exits",([
             "west":Deathland"/holyplace/f03",
             ]));
reset();
}

void init()
{
     add_action("to_pass","pass");
}

string to_look_cave()
{
     return can_read_chinese() ?
            "һ���ڰ��Ķ�Ѩ.\n":
            "need work.\n"; 
}

string to_look_bridge()
{
    return can_read_chinese() ?
          "һ�������ι̵ĵ���,������������ظо������ϵĸ�����һ�����޷�\n"
          "���ܵ�.��Ȼ,�������������˵ĸ��µĻ�,������������ٵ�ͨ����\n"
          "������(pass bridge)����.\n":
          "need work.\n";
}

int to_pass(string str)
{
    
    int i;
    object player,*item;
    
    if (!str||str!="bridge") return 0;
    
    player=this_player();
    item=all_inventory(player);
    for(i=0;i<sizeof(item);i++) 
      if ( (string)item[i]->query("name")== "Cold oil" && item[i]->query("applied") ) {
        write("���Լ�����ٶ�ͨ���˻���\n");
        player->move_player(Deathland"/holyplace/f01",({
        "%s passes bridge very fast.\n","%s �Լ�����ٶ�ͨ������.\n",
        "%s comes here from bridge\n","%s �ӻ�������������.\n"})
        );
        return 1;
        }
    player->receive_special_damage("fire",100);
    write("������屻��������.\nͬʱ���޷������ŵĸ��¶����˻���.\n");
    return 1;
}
