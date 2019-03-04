
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("???","�ӱ�");
  set_long(@Long
Long
,@CLong
һ������ĵط�, ��������δ��������ֲ��, ��ʪ�ĵر��Լ������ڱǵ���ζ�����
�ط�����ĸо�. ������һ�����ټ���ĺӴ�, ��������Ӧ��һ������, ����֮����Ҳ
����������������.
CLong
);

set("c_item_desc",([
    "river":"һ�����ټ���ĺӴ�.\n",
           ]) );

set("exits",([
     "north":Deathland"/dwarf/batcave01",
     "east":Deathland"/dwarf/river02",
     ]) );
 ::reset();
}

void init()
{
   add_action("to_swim","swim");
}

int to_swim()
{
    int swim;
    swim=this_player()->query_skill("swimming");
    if ( swim<50 )
      write("���ˮ������̫������,����������º�ȥ�Ļ�,\��\��\�����ֱ����\n"
            "������������ǰ.\n");
    else {
      this_player()->move_player(Deathland"/dwarf/well05",({
      "%s swims river.\n","%s�����˺��в�Ŭ�������԰���.\n",
      "%s appears from river.\n","%s�Ӻ������ϰ���.\n"}),"");
      write("��������ε��˶԰�.\n"); 
      }
    return 1;      
} 
