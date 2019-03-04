#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(18);
    set_name("Wu Song ","����");
    add("id",({"wu","song","monk"}) );
    set_short("����");
	set_long(@C_LONG
����������ɣ����������������ɣ�ɽ��������ˡ����øߴ����ͣ�����
һ������գ����ھ����Ժ����ʧ�ִ������پ��ֵ��ϻ�����ͨ����ĿǰΪ��ɽ
������ͳ��֮һ��
C_LONG
	);
    set("alignment",-400);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "��" );
    set_perm_stat( "dex",25);
    set_perm_stat( "str",25);
    set_perm_stat( "int",15);
    set_perm_stat( "karma",25);
    set_skill("longblade",90);	
    set_skill("parry",90);
    set ("max_hp",700);
    set ("hit_points",700);
    set ("time_to_heal",2);
    set ("wealth", ([ "gold":300]) );
    set_natural_weapon(30,18,30);
	set_natural_armor(50,26);
	set ("aim_difficulty",([ "weakest":40,"vascular":50]) );
	set("special_defense", (["magic":40,"none":20]) );
    set ("weight", 400);
    wield_weapon(TWEAPON"snowblade");
    equip_armor(TARMOR"skeleton_bead");
    equip_armor(TARMOR"iron_headband");
    equip_armor(TARMOR"cowskin_boots");
    equip_armor(TARMOR"vest");
}

