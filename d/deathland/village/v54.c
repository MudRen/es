
#include "../echobomber.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
    set_short("The road of the dwarf village","���˴����С·");
    set_long(@Long
Long
,@CLong
��Ŀǰλ춰��˵Ĵ�ׯ�Ļ�ׯ��·��,���������ǳ���ƽ���������,�з���һ����
����Դ.�����Ѿ�����û��ս����,�����ǵ�ͯ�꼸���ڴ˶ɹ�.�����и�����,ͨ��һ��
������.
CLong
    );
    set("exits",([
                "east":Deathland"/village/vr4",
                "north":Deathland"/village/v55",
                "south":Deathland"/village/v53",
             ]));
    create_door("east","west",([
               "keyword":({"archdoor","door"}),
               "status":"locked",
               "c_desc":"һ��Բ�εĹ���",
               "c_name":"����",
               "name":"archdoor",
               "desc":"a archdoor",
               "lock":"ECHO_VILLAGE_ARCHDOOR",
               ]) );
    set("objects",([
        "guard":Monster"/guard03"
        ]) );
    ::reset();
}
