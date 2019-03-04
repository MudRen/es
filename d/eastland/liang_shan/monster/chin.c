#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(19);
    set_name("Chin Ming ","����");
    add("id",({"chin","ming"}) );
    set_short("����");
	set_long(@C_LONG
��������𣬿����ˣ��Ը����Ϊ���ͣ�ʹһ������޼�Ƕ䣬����
�򲻵�֮�¡���Ϊ��ɽ������廢���е����󽫡�
C_LONG
	);
    set("alignment",500);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "��" );
    set_perm_stat( "dex",20);
    set_perm_stat( "str",33);
    set_perm_stat( "int",15);
    set_perm_stat( "karma",25);
    set_skill("blunt",100);
    set_skill("parry",100);	
    set ("max_hp",900);
    set ("max_sp",300);
    set ("hit_points",900);
    set ("spell_points",300);
    set ("wealth", ([ "gold":300]) );
    set_natural_weapon(30,18,30);
	set_natural_armor(60,32);
	set ("aim_difficulty",([ "weakest":50,"vascular":50]) );
	set("special_defense", (["magic":50,"none":20]) );
    set ("weight", 400);
    equip_armor(TARMOR"gold_helmet");
    wield_weapon(TWEAPON"ironclub");
    equip_armor(TARMOR"beastface");
    equip_armor(TARMOR"beast_cloak");
    equip_armor(TARMOR"deer_boots");
    equip_armor(TARMOR"fire_plate");
}

