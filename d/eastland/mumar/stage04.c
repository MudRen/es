//#pragma save_binary
#include <mumar.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("��������");
  set_long( @CLong
���߽���һ��������ҡ����������һ��СС�������⣬���Ƿ����ڽ����һ��
ľ���ˡ����Ϸ���һյ�͵ƺ�һ�������飬���ϵİ�ɫ����������ط������񶹸ɰ�
�ı�������о�����������Ǹ�һ˿�������ˡ���������Ͽ��Իص����ٰ칫�ҡ�
CLong
);
set("light",1);
set("exits",([
               "south":MUMAR"stage03",
             ]));
set("objects",([
               "general":MOB"hen"]) );
reset();
#include <replace_room.h>
}
