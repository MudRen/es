#include "saulin_monk.c"

void create()
{
	::create();
	set_level(8);
	set_name( "yan guan", "�Ϲ�" );
	add ("id", ({ "yan", "guan","monk" }) );
	set_short( "�Ϲ�" );
	set_long(@C_LONG
�Ϲ۴�������½�Ĵ���ʦϰ����ѧ�������������������������ѧ֮�ᣬ 
���������ר��ϰ�䣬������һ����ѧ�ɹ����
C_LONG
	);
    set( "alignment",-200);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "λ" );
	set_perm_stat( "dex", 8 );
	set_perm_stat( "str", 10 );
	set_perm_stat( "int", 8 );
	set_perm_stat( "con", 14 );
	set_perm_stat( "piety", 10);
	set_perm_stat( "karma", 10);
	set_skill("longblade",45);
	set("special_defense", ([ "all":10, "none":10 ]) );
	set("max_fp", 200);
	set("force_effect", 2);
	set("force_points", 200);
          set("attack_skill",CLASS"tai_zuo");    
          set("gonfus/tai-zuo",100);
	set("wealth/gold", 18);
	set_natural_weapon( -9, 0, 0 );
	set_natural_armor( 30, 13 );
        set("weight", 600);
    wield_weapon( SAULIN_OBJ"blade4.c" );
    equip_armor( SAULIN_OBJ"cloth7.c" );
}
