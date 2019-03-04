//#pragma save_binary

#include "/d/mage/mage.h"

inherit "/d/mage/study1";
inherit ROOM;

void create()
{
	::create();
	set_short("A empty room", "����ħ��ͼ����");
	set_long( @LONG_DESCRIPTION
This is a simple room created by roommaker.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
�������ղص�ħ����������������ɫ֮���ż�ʱ����һЩ�ƾɵ�ʯ�׻�����
�з��ֵģ���Ȼ���Ƕ���ȱ��ȫ�����Ǿ�����λ����ħ��ʦ������֮�ᣬҲ�Ѿ�
���߹�ģ������ƽ��������ħ��ʦ���������Ե��������ҳ�������Բ���ǰ�����
�ϵ��嵥(list)��������������Щ���������ϡ�����ͨ��һ���������ߵ����Իص�
ͼ��ݴ�����
C_LONG_DESCRIPTION
	);
    set( "no_monster", 1);
	set( "light", 1 );
	set( "exits", ([ 
		"south" : MAGE"library" ]) );
	set( "item_func", ([
		"list" : "view_catalog" ]) );
	set_spells( ([
	   "wizard-eye"     : ({ "misc", 10, 3, 15, 150 }),
	   "magical-shield" : ({ "misc", 40, 2, 15, 200 }),
	   "detect-invis" : ({ "misc", 10, 6, 10, 250 }),
	   "detect-hide" : ({ "misc", 10, 6, 10, 250 }),
	   "magic-cube"     : ({ "misc", 20, 2, 20, 200 }),
	]) );
	reset();
}
