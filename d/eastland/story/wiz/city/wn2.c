#include "../../story.h"
#include "../../magic.c"
#include <conditions.h>
inherit ROOM;

void create()
{
        ::create();
	set_short("�����");
	set_long( @LONG
���������ڡ����̳ǡ��ڱ�����ϣ���������߷������죬�ϱ���������֡�
�����������һת�ѱ��Ϊ�ش�ƫƧ�ı���֣������޳�����������ľϡϡ�����
���Ӽ䣬�������£��Եĸ����������ף��ֵ����൱��������Ϊ��ס֮�ء�·����
��һ�ڿݾ���һ�ô�����Լ�ߡ��˱������֦��Ҷ��������ʮ�ĳ�ֱ����Բ��
���׽�ϲ���˳�����Ϸ��Ϊ���������һ�⡣
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "south" : SCITY"wn1",
            "east" : SCITY"nw2",
        ]) );
        set("objects", ([
            "boy#1" : SWMOB"boy2",
            "boy#2" : SWMOB"boy2",
            "girl1" : SWMOB"girl2",
            "girl2" : SWMOB"girl2",
            "older" : SWMOB"older1",
        ]) );
	reset();
}
void init()
{
   add_action("do_search","search");
   add_action("do_jump","jump");
}
int do_search(string arg)
{
    write(@LONG
�㷢����һ�ڿݾ�(well)������ף�����ò�Ҫ��������ȥ(jump)������
����Σ�ա�  
LONG
   );    
   return 1;
}
int do_jump(string arg)
{
   object player;
   if ( !arg || arg!="well" ) {
      write("Snytax:<jump well>��\n");
      return 1;
   }
   player=this_player();
   tell_object(player,"��嶯������������ȥ��\n\n\n\n\n\n\n");
   player->move_player(SCITY"well1",({
            "%s����һ�е�������һ����\n",
            "%s��������������\n"}),"");
   tell_object(player,"��ѽ���㲻С�ĵر�����ǽ��ͻ����ʯ������ˣ���Ѫ��ֹ��\n");                     
   (CONDITION_PREFIX + "bleeding")->apply_effect(player,20,2 );
   return 1;           
}