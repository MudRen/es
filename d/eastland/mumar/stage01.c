//#pragma save_binary
#include <mumar.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("����¥");
  set_long( @CLong
���ߵ����������һ����¥����¥���Թ���һ�����ӣ�д��������¥��������¥
�����һ����������\��������̺����εĴ��������ܵ�ǽ������һЩ����ɽ
ˮ��������һ��С�輸�Ϸ������ײ�ߡ��������ĸо���������عٱ�����������
�������Ǿ����ң��������Իص���ǽͨ���ϡ�
CLong
);
set("light",1);
set("exits",([
               "west":MUMAR"wall03",
               "up":MUMAR"stage03"
             ]));
#include <replace_room.h>
}
