
#include "../echobomber.h"

inherit ROOM;

int squ;
void create()
{
	::create();
  set_short("well","���ºӵ�");
  set_long(@Long
Long
,@CLong
���ܵ���������̦��һЩ��ֵ�С��,�������������ʮ�ֳ���,�ƺ������ǵ���
�Ӵ��ĺӵ�,����Ŀǰ��ӵ��Ѿ�Ǭ��\��\.������ı�����һ���ܴ�ĵ��ºӴ�(river)
,��ˮ�����طǳ�����. ��������Ͻ��и��ƾɵĽ���,����ǽ���Ѿ�������,�ƺ��ܾ�
û���˵�������.
CLong
);

set("c_item_desc",([
    "river":"һ�����ټ���ĺӴ�.\n",
           ]) );

set("exits",([
     "east":Deathland"/dwarf/well03",
     "southwest":Deathland"/dwarf/prison",
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
      write("���ˮ������̫������,����������º�ȥ�Ļ�,����\�����ֱ����\n"
            "������������ǰ.\n");
    else {
      this_player()->move_player(Deathland"/dwarf/river01",({
      "%s�����˺��в�Ŭ�������԰���.\n",
      "%s�Ӻ������ϰ���.\n"}),"");
      write("��������ε��˶԰�.\n"); 
      }
    return 1;      
} 
