#include <mudlib.h>

inherit ROOM;

void create()
{

	::create();
	set_short("С����");
	set_long( @C_LONG_DESCRIPTION
��������ð�չ���ר�����Ե�һ��С���䣬���������Ǳ����й���ëƤ��Ƭ��
������м����һ�Ź���̨�����Ϸ���һЩδ��ɵķ��߻��·���һ��Ů�÷�
ʦ�������ߣ�����Ŭ���Ĺ�����
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "objects", ([
	             "woman" : "/d/adventurer/hall/monsters/woman"
	                                         ]) );
	set( "exits", ([
	             "east" : "/d/adventurer/hall/adv_shop",
	                                         ]) );
        reset();       
}

