#include "../../story.h"
inherit MONSTER ;
void create ()
{
	::create();
	set_level(13);
	set_name( "The palace's lady", "�춼��Ů" );
	add ("id", ({"lady"}) );
	set_short( "�춼��Ů");
	set_long(@CLONG
�춼��Ů����ѩ����ò��������ǣ�һɫǳ��ɫ��װ�����޷��ߣ����˴�Լ��ͤͤ
��������ִ���ȣ�����һ�ԡ�
CLONG
	);
	set("race","god");
	set("gender","female");
	set_natural_armor( 70, 0 );
        set_natural_weapon(6,0,5);
        set("wealth/silver",100);
        set_skill("blunt",40);
        set("queen_f",1);
        wield_weapon(SPWEA"fan1");
        equip_armor(SPARM"f_cloth1");
}

