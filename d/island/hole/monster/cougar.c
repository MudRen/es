#include <../hole.h>

inherit MONSTER;
void create()
{
	::create();
	set_level(16);
	set_name( "Black Cougar","�ڱ�" );
	add( "id",({ "cougar" }) );
	set_short( "�ڱ�" );
	set_long(@LONG
һͷ���͵ĺڱ�����ݺݵĶ����㣬С�ĳ�Ϊ����ʳ��ม�
LONG
                );
	set( "killer",1 );
	set( "pursuing",1 );
	set( "alignment",-1000 );
	set( "gender","male" );
	set( "unit","ͷ" );
	set_perm_stat( "dex",25 );
	set_perm_stat( "str",25 );
	set_perm_stat( "int",25 );
	set_perm_stat( "con",10 );
	set_perm_stat( "piety",10 );
	set_perm_stat( "karma",25 );
	set_skill( "unarmed",80 );
	set_skill( "dodge",100 );
	set( "special_defense",([ "sleet":50,"none":60,"fire":-20 ]) );
	set( "max_hp",600 );
	set( "hit_points",600 );
	set( "wealth",([ "gold":35 ]) );
	set_natural_weapon( 75,20,40 );
	set_natural_armor( 100,35 );
	set( "natural_weapon_class2",70 );
	set( "natural_min_damage2",15 );
	set( "natural_max_damage2",35 );
	set( "weight",400 );
	set( "unbleeding",1 );
	set_c_verbs( ({ "%s������ǰצ��%s��ץ","%s�����������%sһ��","%s������β����%sһ��" }) );
	set_c_limbs( ({ "ͷ��","����","β��" }) );
}
