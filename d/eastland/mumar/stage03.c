//#pragma save_binary
#include <mumar.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("���ٰ칫��");
  set_long( @CLong
�����һ����ٰ칫�ҡ�һ����߼�����̴ľ���Ӿͷ��ڰ칫�ҵ����룬������
��������ط����ķ��ı���̴��¯��Ʈ������̴�㣬ʹ��о��ݷ������ɾӡ�������
��������ź�����Σ������ǽ����������һ�����֣����̡����ԱߵĶ��������ÿ�
�����飬������Ҳ��������������ϱ��������һ��������ң�¥�������������ġ�
CLong
);
set("light",1);
set("no_monster",1);
set("exits",([
               "north":MUMAR"stage04",
               "south":MUMAR"stage05",
               "down":MUMAR"stage01"
             ]));
#include <replace_room.h>
}
