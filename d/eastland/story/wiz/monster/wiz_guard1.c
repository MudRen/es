#include "../../story.h"

inherit SMOB"s_army";

void create()
{
	::create();
	set_level(13);
	set_name( "gate guard", "��������" );
	add( "id", ({ "guard" }) );
	set_short( "��������" );
	set_long(@C_LONG
���������Ǹ������̹����İ�ȫ��������ҪһԱ֮һ����Ȼ��һ���˵���������
�������ǣ�����ȴ����Žᣬ��������Ϯ�ĵ���һ�����ص�ʹ����
C_LONG
        );
	set( "gender", "male" );
	set( "alignment", 600 );
        set( "weight",1000);
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 17 );
        set_skill( "parry", 75 );
        set_skill( "block", 75 );
        set_skill( "polearm", 60 );
        set_natural_armor(50,11);
        set("wealth/gold",20);
        wield_weapon(SWWEA"polearm1");
        equip_armor(SWARM"wiz_shield1");
}
