#include "saulin_monk.c"

void create()
{
	::create();
	set_level(6);
	set_name( "gin hwa", "����" );
	add ("id", ({ "gin", "hwa","monk" }) );
	set_short( "����" );
	set_long(@C_LONG
���ֱ���������͵�һ������������ʮ���꣬��������Ҳ����ʮ�꣬��һ�� 
���ֳ�ȭ�ɴ�Ĳ���Ŷ��
C_LONG
	);
    set( "alignment",50);
    set( "gender", "male" );
    set( "race", "elf" );
    set( "unit", "λ" );
	set_perm_stat( "dex", 10 );
	set_perm_stat( "str", 8);
	set_perm_stat( "int", 7 );
	set_perm_stat( "con", 10 );
	set_perm_stat( "piety", 10);
	set_perm_stat( "karma", 8);
	set_skill("unarmed",100);
	set_skill("dodge",35);
	set("aim_difficulty", ([ "critical":5, "vascular":4, ]) );
	set("max_fp", 35);
	set("force_effect", 2);
	set("force_points", 35);
	set("attack_skill",FIST"long_fist");    
	set("defense_type","berserk");    
	set("wealth/gold", 6);
	set_natural_weapon( 12, 7, 12 );
	set_natural_armor( 25, 9 );
        set("weight", 350);
    equip_armor( SAULIN_OBJ"cloth8.c" ); 
} 
