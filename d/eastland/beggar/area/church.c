#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "church", "����" );
	set_long(@C_LONG
����һ���Ͼɵ�����,��Ϊ����δ�޼�, ���Կ���������Ҫ���������ӡ�һ��
����ȥ�����кܶ����,���Ϲ���Ķ�������������һЩ���ұ���֮ʿ�������� ��
̴������,�о�֮������,��ʱ������ղ�����˵ķ緶, �����������������,����
��������������֮ʹ���������д��ɡ�
C_LONG
	);
	set("light",1);
	set( "exits", ([
                      "out":DBEGGAR"east7.c"
	]) );
        set( "objects", ([
                      "old":DMONSTER"old_garden.c",
                "enforcer1":DMONSTER"enforcer.c",
        ]) );
     reset();
}
