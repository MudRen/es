// Deathland/holyplace/f03.c 
// Created by Echobomber @Eastern.Stories 
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    
    set_short("dark cave","�ڰ��Ķ�Ѩ");
    set_long(@Long
Long
,@CLong
һƬ��ڵĵط�, ���˺ڰ����Ǻڰ�, һ������ĺ��Ǻ���춶�Ѩ�Ľ���, ���
���и������ƺ����Ƶĵط�. 
CLong
);
set("search_desc",([
    "skeleton":"@@to_search_skeleton",
    ]) );
set("item_func",([
    "skeleton":"to_look_skeleton",
    "paper": "to_look_paper",
    ]) );
set("exits",([
             "leave":Deathland"/holyplace/f03",
             ]));
reset();
}

int to_look_skeleton()
{
     write( 
           "�ƺ���������Ѿ���������ط��ܾ���. ����������һ��\n"           
           "����(incantation paper)��������.\n"
           );
     return 1;        
}

int to_look_paper()
{

    write(
          "һ�Ÿ�춺������ϵĹ������.\n"
          );
    return 1;      
}

string to_search_skeleton()
{
     object paper,*item,player;
     int i;
     
     player=this_player();
     item=all_inventory(player);
     write( 
            "���Ѳ麧��, û��ʲ�����, ����������ֵķ�����, û����\n"
            "���ر������. �����Ͱ����ŷ����˺����\n"
          );
     write(
           "Ȼ�������õ��˷���֮��, �㷢�ֺ������ֶ���һ����ͬ�ķ���.\n"
           "���˾���������ƺ����ֺ�ǿ��ħ��."
           );
     for(i=0;i<sizeof(item);i++) 
       if ( (string)item[i]->query("name")=="Incantation paper of Lock") 
         return "\n";
     paper=new(Object"/letter03");
     paper->move(this_player());
     return "\n";            
}

