#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("ɳ̲");
	set_long( @LONG
������������һ��ƽ̹�İ�ɳ̲��������һ���޼ʵĴ󺣣��д����м���ͺ
������Ľ�ʯ��ͷ�������ȵġ�����һĨ�������ա���������˹����Ĵ���ɳ��
������Щ��ˮ�����������������������գ���ɢ���������ϵ���������֫�ٺ���
����ܵ����Ķ��ݣ�ɨ���˿�������գ�ɳ̲�ϸ�ʽ���������岼��������С�з
������ͷ��������ʰ�쵵��������������һƬ��ɳ̲���ʱ�е����վ�ʧ��ʹ
�㲻���뵽�κ�ɱ����ִ��
LONG
	);
        set("light",1);
	set("exits", ([ 
       	    "east" : SAREA"coast3", 
           "north" : SAREA"coast1",
           "south" : SAREA"coast1",
        ]) );
	set("objects", ([
	  "crab#1" : SMOB"crab1",
          "crab#2" : SMOB"crab2",
          "crab#3" : SMOB"crab3",
          "crab#4" : SMOB"crab4",
	]) );
        set( "c_item_desc" ,([
          "��ʯ" : "����ͺ����ƽ�����ʯ��������غ����� ( swim ) ��ȥ��\n"        
        ]) );
	reset();
}
void init()
{
   add_action("do_search","search");
   add_action("do_swim","swim");
}
int do_search( string arg )
{
   write("�㷢�ֺ������м���ͺ���Ľ�ʯ��������μ��ÿ����ι�ȥ( swim )��\n");
   return 1;   
}
int do_swim( string arg )
{
   object player;
   string c_name;
   player=this_player();  
   c_name=player -> query("c_name");
   tell_object(player,
      "��������������Զ���Ľ�ʯ�ι�ȥ����\n");
   tell_room(this_object(),sprintf(
      "%s������������Զ���Ľ�ʯ�ι�ȥ����\n",c_name),player);
   player->move_player(SAREA"stone1","SNEAK");
   return 1;
}