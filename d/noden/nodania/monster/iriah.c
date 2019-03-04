#include "../nodania.h"

inherit MONSTER;

void create()
{
	object ob1;

	::create();
	set_level(18);
	set_name("iriah", "������");
	add( "id", ({ "queen" }) );
	set_short("�����Żʺ�");
	set_long(@CLONG
�����Żʺ�͹�����Ȼֻ��ʮ�꣬������������ֻ����ʮ�겻����������
�ʺ�͹����������������ģ��������û�������˵ĵط������й�Ү��
��(yaramon)���£�Ҳ������Ը��͸©�͹�����ʶ�ľ�����
CLONG
	);
	set_perm_stat("int", 27);
	set_perm_stat("dex", 25);
	set_perm_stat("kar", 30);
	set_skill("dagger", 100);
	set_skill("dodge", 100);
	set( "alignment", 2500 );
	set( "max_hp", 600 );
	set( "hit_points", 600 );

	set( "gender", "female" );
	set( "race", "human" );
	set( "natural_defense_bonus", 80 );
	set( "natural_weapon_class1", 30 );
	set( "natural_min_damage1", 10 );
	set( "natural_max_damage1", 20 );
	set( "wealth/gold", 400 );
	set( "special_defense", ([ "all": 40 ]) );
	set( "tactic_func", "my_tactic" );

	ob1 = new( NODANIA"obj/knife" );
	ob1->move( this_object() );
	wield_weapon( ob1 );
}

int my_tactic()
{
	object *victim;
	int dam;

	if( !(victim= query_attackers()) || (random(20)>4) ) return 0;
	tell_room( environment(), 
        "\n������ʩչһ������ķ�����ʹ�����ͷʹ���ѣ�\n\n");
	dam = 60 + random(20);
	victim->receive_special_damage( "divine", dam );
	return 1;
}
