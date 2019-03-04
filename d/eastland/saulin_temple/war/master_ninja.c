#include <saulin_war.h>

inherit War;

void create()
{
        ::create();
        set_level(19);
        set_name( "Ninja master", "���С����" );
	add( "id", ({ "master","ninja", }) );
        set_short( "���С����" );
        set_long(@C_LONG
�㿴��һ��ȫ����װ������ͷĿ��������ӭ��һ���������������С����
���������̰�������������������������������书\�Ծã�һ�л������
��ɽ��ˮ���㡣
C_LONG
                );
	set( "unit", "��" );
        set( "race", "human" );
        set( "gender", "male" );
        set( "alignment", -2000 );
        set_natural_armor(50,30);
        set_natural_weapon(15,12,15);
        set( "natural_weapon_class2", 8 );
        set( "natural_min_damage2", 5 );
        set( "natural_max_damage2", 10 );
        set( "wealth/silver", 400 );
        set( "hit_points", 650 );
        set( "max_hp", 650 );
        set( "special_defense", ([ "all": 40,"none":20 ]) );
        set( "aim_difficulty",
        ([ "critical":20, "vascular":20, "weakest":30, "ganglion":15 ]));

        set( "pursuing", 1 );
        set( "killer", 1 );
        set( "monk_value", 100 );
        set_perm_stat( "str", 28 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "int", 25 );
        set_skill( "longblade", 100 );
        set_skill( "two-weapon", 100 );
        set_skill( "parry", 100 );
        set_skill( "defend", 100 );
        set( "chat_chance", 20 );
	set( "att_chat_output", ({
	"���С������Ц��: ����书\�����׳���������Ҫ��ɱ���۵�˹��\n",
	"���С���ɿ�Ц��: ��ƾ��������ͣ���С���ɻ���������ߵ��������Ǵ��ĺá�\n",
	"���С����˵��: ��ƾ����ӭ��һ�������������Ƕ�����һ������\n",
	}) );

        wield_weapon2(Obj"evil_katana");
        wield_weapon(Obj"bloody_claw" );
	equip_armor(Obj"ninja_cape");
        equip_armor("/d/noden/bluesand/item/yoroi");
        equip_armor("/d/noden/bluesand/item/kabuto");
        equip_armor(Obj"ninja_gloves");
}
