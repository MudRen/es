#include "saulin_monk.c"

void create()
{
	::create();
	set_level(7);
	set_name( "hwei ti", "�޵�" );
	add ("id", ({ "hwei", "ti","monk" }) );
	set_short( "�޵�" );
	set_long(@C_LONG
�޵̴�С����ĸ�������������ԵĲݴ��У���������������Ͳ���... 
����һ���ڰ����飬���Գ��ĺں����ݵģ�����ר������\֮�⣬û���� 
֪�����ĵ�����Щʲ��... 
C_LONG
	);
	set( "alignment",0);
	set( "gender", "male" );
	set( "race", "drow" );
	set( "unit", "λ" );
	set_perm_stat( "dex", 10 );
	set_perm_stat( "str", 8);
	set_perm_stat( "int", 12 );
	set_perm_stat( "con", 10 );
	set_perm_stat( "piety", 10);
	set_perm_stat( "karma", 7);
	set_skill("unarmed",100);
	set_skill("dodge",40);
	set("aim_difficulty", ([ "critical":5, "vascular":4, ]) );
	set("max_fp", 45);
	set("force_effect", 2);
	set("force_points", 45);
	set("attack_skill",FIST"ro_han");
	set("gonfus/ro_han",1);
	set("defense_type","dodge");    
	set("wealth/gold", 11);
	set_natural_weapon( 10, 8, 12 );
	set_natural_armor( 27, 10);
        set("weight", 340);
	equip_armor( SAULIN_OBJ"cloth7" ); 
} 
