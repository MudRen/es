#include "../goomay.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "Din", "�����" );
	set_short( "�����" );
	set_long(
"����ԭ���Ǹ���ʦ�������ڹ�÷��ı���������ʧ�ܣ��Ӵ��������ճ��� \n"
"춾ƹ�֮�У�����һ���ζ���������ᡣ \n"
	);
    set( "alignment",-1000);
    set( "gender", "male" );
    set( "race", "drow" );
    set( "unit", "��" );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "int", 10 );
	set_skill("unarmed",80);
	set_skill("dodge",70);
	set("special_defense", ([ "all":10, "none":10 ]) );
	set("aim_difficulty", ([ "critical":20, "vascular":12, ]) );
	set("max_hp", 350);
	set("max_fp", 800);
	set("hit_points", 350);
	set("force_effect", 2);
	set("force_points", 800);
    set("attack_skill","monk/fist/drunk_fist");
        set("gonfus/drunk-fist",100);    
	set("wealth/gold", 50);
	set_natural_weapon(31,14,30);
	set_natural_armor( 66, 19 );
        set("weight", 700);
    equip_armor( Obj"black_boots" );
    equip_armor( Obj"coat" );
}
