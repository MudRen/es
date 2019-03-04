#include "../echobomber.h"

inherit MONSTER;

void create ()
{
	::create();
    set_level(15);
    set_name("drawf royal guard","���˻�������");
    add ("id", ({ "guard","dwarf"}) );
    set_short( "a drawf royal guard",
           "���˻�������");
	set_long(@LONG
A drawf guard protects the dwarven palace.
LONG
    ,@C_LONG
һ�����˻������������������˻ʹ�.
C_LONG
	);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "��" );
    set_perm_stat( "dex",  18);
    set_perm_stat( "str",  25);
    set_perm_stat( "int",   8);
    set_perm_stat( "piety", 8);
    set_perm_stat( "karma",19);
	set_skill("longblade",87);
	set_skill("parry",86);
	set_skill("dodge",70);
	set("special_defense",(["all":15,"none":10]) );
	set("aim_difficulty",([ "vascular":20]) );
    set ("max_hp",450);
    set ("max_sp",0);
    set ("hit_points",450);
    set ("spell_points",0);
    set ("wealth", ([ "gold":13]) );
    set_natural_weapon(13,12,18);
	set_natural_armor(49,19);
    set ("weight", 350);
    set("chat_chance",15);
    set("chat_output",({
//        "guard says:Be quiet,this is a peace place.\n",
        "����˵:����.��ʹ���һ����ƽ�ĵط�.\n"
       }) );
    equip_armor(Armour"/chainmail01");
    wield_weapon(Weapon"/sword01");
}


