#include "../tsunami.h"

inherit ROOM;
inherit DOORS;

void create()
{
    ::create();
    set_short("�о���");
    set_long(@LONG
һ������䷿�ӣ�ֻ����������ʵ���õ���������Ȼ�࣬��ȴ�������
�����ɣ�ʵ�������᷽�����������ֵĴ���ӣ�������һЩû����������
�����������ħ���о���������ĳ��������������⣬�����ƺ�������һЩ
�������˵������������е���ˮ������;����������ѰζŶ��
LONG
             );
    set("light",1);
    set("item_desc",([
        "canteen" : @LONG
��Щˮ�������������һ����ʵ��������һ�ξ���ĵط����ƺ�����
�ر���;�ģ���֪���ɲ����Ը�����Ҫ����һ����
LONG
             ]) );
    set("exits",([
        "west":AREA"house1"]) );
    set("objects",([
        "flamen":TMOB"flamen"]) );
    create_door("west","east",([
         "keyword" :({"Oak door","door"}),
         "status"  :"closed",
         "name"    :"oak door",
         "c_name"  :"��ľ��",
         "c_desc"  :"һ���������µ�̵���ľ��"
               ]) );   
          reset();
}

