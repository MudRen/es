//#pragma save_binary

#include "../mage.h"
// Let players can use flare [2] , original limit is flare [1], modified in 1995/2/29

inherit "/d/mage/study1";
inherit ROOM;

void create()
{
	::create();
	set_short("A empty room", "��ħ��ͼ����");
	set_long( @LONG_DESCRIPTION
NEED TRANSLATE HERE.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
������ר���ղغ�ħ��������ղ��ң����ƹ�����ղ��ҵ��˹��ƣ���Լ��
�ٷ�֮��ʮ����Ŀǰ��֪�ĺ�ħ�����ﶼ���������ҵ����������ǰ��һ������
��Ŀ¼(catalog)������԰������������ж�(study)ħ���飬���о�����(raise
)ħ���ȼ���֪ʶ���������Իص�ħ��ͼ��ݵĴ�����
C_LONG_DESCRIPTION
	);
    set( "no_monster", 1);
	set( "light", 1 );
	set( "exits", ([ 
		"east" : MAGE"library" ]) );
	set( "item_func", ([
		"catalog": "view_catalog" ]) );
	set_spells( ([
		"ether-bolt"  : ({ "black-magic", 20, 7, 10, 130 }),
		"lightning"   : ({ "black-magic", 50, 3, 10, 200 }),
		"flare"       : ({ "black-magic", 80, 2, 10, 500 }),
     "mirror-shield"  : ({ "black-magic", 40, 3, 15, 160 }),
     "energy-shield"  : ({ "black-magic", 40, 3, 15, 110 }),
	]) );
	reset();
}
