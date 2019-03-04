
#include "../echobomber.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
    set_short("The protect room","���˴���ı�����");
    set_long(@Long
Long
,@CLong
һ��Ϊ�˱������˵İ�ȫ�����ı�����.�����ƺ���û��ʹ�ù�,��������ط����ɱ�
����һ����Ⱦ.
CLong
    );
    set("exits",([
                "west":Deathland"/village/v54",
             ]));
    create_door("west","east",([
               "keyword":({"archdoor","door"}),
               "status":"locked",
               "c_desc":"һ��Բ�εĹ���",
               "c_name":"����",
               "name":"archdoor",
               "desc":"a archdoor",
               "lock":"ECHO_VILLAGE_ARCHDOOR",
               ]) );
    ::reset();
}

void init()
{
  this_player()->set_explore( "deathland#11" );
}
