#include "saulin_monk.c"

void create()
{
	::create();
	set_level(14); 
	set_name( "yeng dou", "Զ��" );
	add ("id", ({ "yeng", "dou","monk" }) );
	set_short( "Զ��" );
	set_long(@C_LONG
Զ������Լ��ʮ���꣬�����ͬ��������ʳ�����ѪΪ�������淽ʽ������ 
����ͬ������ͬ����׷ɱ��һ·�������ֶ�����������ϲ����������һ���� 
ɫ�������ķǳ������� 
C_LONG
	);
    set( "alignment",1500);
    set( "gender", "male" );
    set( "race", "vampire" );
    set( "unit", "λ" );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "str", 16 );
	set_perm_stat( "int", 12 );
	set_perm_stat( "con", 14 );
	set_perm_stat( "piety", 16);
	set_perm_stat( "karma", 14);
	set_skill("longblade",80);
        set_skill("parry",70);
	set("special_defense", ([ "all":18, "none":15 ]) );
	set("max_fp", 800);
	set("force_effect", 2);
	set("force_points", 800);
	set("attack_skill",CLASS"wu_sur");
	set("gonfus/wu-sur",100);
	set("wealth/gold", 55);
	set_natural_weapon( 0, 7, 13 );
	set_natural_armor( 36, 34 );
    wield_weapon( SAULIN_OBJ"blade4" );
    equip_armor( SAULIN_OBJ"cloth5a" );
}
