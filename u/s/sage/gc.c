//�����ſڵĹ㳡
#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
      set_short( "boss���ż�" )
        set_long(
       "����ʥ�˵�˯����������ɾ����ˣ������м���ŵĲ���˵���Ǵ���û��ʲô�ر��,\n"
  "�ر���Ǵ�ͷ����һ����Ƭ��һ��������ò����Ů����Ƭ���㲻��������\n"
  "�����߹�ȥ����������������������������Ƭ�����½�д��:\n"
 "                           my wife:qwe\n"
        );
     set( "light",1 );
     set( "exits", ([
          "north" : "/u/s/sage/home/work.c",
        ]) );
