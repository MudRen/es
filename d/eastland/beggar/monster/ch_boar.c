#include "../dony.h"

inherit MONSTER;

void create()
{
        ::create();
	set_level(14);
	set_name( "fat boar", "Ұ��" );
        add ("id", ({ "boar","fat" }) );
        set_short( "Ұ��" );
	set_long(@C_LONG
����һͷ���͵�Ұ��
C_LONG
	);
        set_perm_stat( "str", 22 );
        set_perm_stat( "dex", 16 );
        set_perm_stat( "kar", 20 );
        set("weight",650);
        set_skill( "dodge", 80 );
        set( "special_defense", ([ "all": 20 ]) );
        set( "alignment", -200 );
        set_natural_armor(25,10);
        set_natural_weapon( 40, 18, 20 );
        set( "natural_weapon_class2", 40 );
        set( "natural_min_damage2", 15 );
        set( "natural_max_damage2", 25 );
        set( "race", "beast" );
	set( "unit", "ͷ" );
	set_c_verbs( ({ "%s��ͷ�ͳ壬ײ��%s", "%s�ڵ���һ������������%s��ȥ" }) );
	set_c_limbs( ({ "ͷ��", "����", "�Ȳ�", "ƨ��" }) );
}
void die()
{
    set("alt_corpse",DITEM"bone");
    set( "c_death_msg","%s��������,����һ����ͷ....\n\n");
    ::die();
}