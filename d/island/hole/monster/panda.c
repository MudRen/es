#include <../hole.h>

inherit MONSTER;
void create()
{
	::create();
	set_level(18);
	set_name( "Black Panda","�����" );
	add( "id",({ "panda" }) );
	set_short( "�����" );
	set_long(@LONG
һͷ�ߴ�ǿ׳�ĺ�������Ѱ����������С�ĵ㣬ǧ
��𾪶�����������������ж�˿飬��ȥι����С����
LONG
                );
	set( "killer",1 );
	set( "alignment",-750 );
	set( "gender","female" );
	set( "unit","ͷ" );
	set_perm_stat( "dex",22 );
	set_perm_stat( "str",30 );
	set_perm_stat( "int",25 );
	set_perm_stat( "con",20 );
	set_perm_stat( "pie",10 );
	set_perm_stat( "kar",25 );
	set_skill( "unarmed",80 );
	set_skill( "dodge",80 );
	set( "special_defense",([ "sleet":50,"none":60,"fire":-20 ]) );
	set( "max_hp",800 );
	set( "hit_points",800 );
	set( "wealth",([ "gold":35 ]) );
	set_natural_weapon( 75,30,45 );
	set_natural_armor( 115,40 );
	set( "natural_weapon_class2",70 );
	set( "natural_min_damage2",20 );
	set( "natural_max_damage2",38 );
	set( "weight",800 );
	set( "unbleeding",1 );
	set_c_verbs( ({ "%s�����ʺ��������%s��ȥ","%s�ſ�����������������%sҧȥ" }) );
	set_c_limbs( ({ "��ͷ","����" }) );
}
