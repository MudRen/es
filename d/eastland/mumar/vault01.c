#include <mumar.h>
inherit ROOM;
inherit DOORS;
 
void create()
{
        ::create();
  set_short("�ⷿ");
  set_long( @CLong
����������ص�������ı������ģ�����ǽ�����ҵط�����\��ȴ��޸���������
����װ��������һЩ�򵥿��ѵĴ������޲����ġ�����Ҫ�޵Ķ����ж��٣�����Ĺ�
��ʦ��������������̵�ʱ������ɹ������Թ����衣���߳�ȥ�ǽ̳�����������
һ�����ҡ���
CLong
);
set("light",1);
set("exits",([
               "west":MUMAR"vault00",
               "east":MUMAR"vault02",
             ]));
 
create_door( "west","east",
           (["keyword" : ({"copper","door"}),
             "name"    : "copper door",
             "c_name"  : "ͭ��",
             "c_desc"  : "һ��ͭ�š�\n",
             "status"  : "closed"
           ]) );
reset();
}
