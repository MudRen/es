
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
�Ӵ��ĺӵ�,����Ŀǰ��ӵ��Ѿ�Ǭ\��\��\.�ϱߵ��ұ�������һ��ϸϸ������,��ǿ��
���Լ���ȥ.
CLong
);

set("exits",([
     "northwest":Deathland"/dwarf/well04",
     "southeast":Deathland"/dwarf/well07",
     "south":Deathland"/dwarf/pass01.c",
     ]) );
set("pre_exit_func",([
    "south":"to_south",
    ]) );     
 ::reset();
}

int to_south()
{
    write("�������ؼ���ȥ���ϸ����,������ƺ������ڿյĸо�.��һ������\n"
          "��!��ؾ�Ȼ��������.\n\n\n\n\n��...............\n���һ��,�������˵�������\n"
         );
    return 0;  
}
