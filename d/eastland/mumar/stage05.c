//#pragma save_binary
#include <mumar.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("��������");
  set_long( @CLong
���߽���һ��������ҡ����������һ��СС�������⣬���Ƿ����ڽ����һ��
ľ���ˡ����Ϸ���һյ�͵ƺ�һ˫��Ь����ɫ�����ϵı��������߰���ط�������ǽ��
������һЩ��������������о�����������Ǹ�һ̣��Ϳ���ˡ�������������Ի�
�����ٰ칫�ҡ�
CLong
);
set("light",1);
set("exits",([
               "north":MUMAR"stage03",
             ]));
set("objects",([
               "general":MOB"ha"]) );
reset();
#include <replace_room.h>
}
