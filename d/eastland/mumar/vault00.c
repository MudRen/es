#include <mumar.h>
inherit ROOM;
inherit DOORS;
 
void create()
{
        ::create();
  set_short("�ⷿ");
  set_long( @CLong
����������ص������ֿ⣬ǽ���������������ʽ����������װ�����ӵ�����ì
��������ڣ�������ȫ����������ۻ����ҡ���˵������ղ���һЩ���͵��������
���������������׵����汦�
CLong
);
set("light",1);
set("exits",([
               "east":MUMAR"vault01",
             ]));
set("objects",([
               "advisor":MOB"advisor",
               ]) );
 
create_door( "east","west",
           (["keyword" : ({"copper","door"}),
             "name"    : "copper door",
             "c_name"  : "ͭ��",
             "c_desc"  : "һ��ͭ�š�\n",
             "status"  : "closed"
           ]) );
reset();
}
