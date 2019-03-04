#include <mudlib.h>

inherit MONSTER;
int wait_state;

void create()
{
	object ob1, ob2, ob3;

	::create();
	set_level(17);
	set_name( "Musashi", "���" );
	add( "id", ({ "travelling samurai", "samurai" }) );
   set_short( "������ʿ���" );
	set_long(
		"����Ǵ�һ��ңԶ�Ķ������ң������ձ�������������ʿ������\n"
		"��Ѱ����Ϊ��ʿ����ѭ��������\n"
	);
	set( "gender", "human" );
	set( "gender", "male" );
	set( "alignment", 600 );
    set_natural_armor( 20, 30 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage", 5 );
	set( "natural_max_damage", 5 );
	set( "wealth/gold", 30 );
	set( "tactic", "melee" );
	set( "tactic_func", "my_tactic" );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "pie", 20 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 60 );
	set_skill( "dodge", 60 );
	set_skill( "tactic", 80 );

	ob1 = new( "/d/noden/bluesand/item/katana" );
	ob1->move( this_object() );
	wield_weapon( ob1 );

	ob2 = new( "/d/noden/bluesand/item/yoroi" );
	ob2->move( this_object() );
	equip_armor( ob2 );

	ob3 = new( "/d/noden/bluesand/item/kabuto" );
	ob3->move( this_object() );
	equip_armor( ob3 );
}

int my_tactic()
{
	object *victim;

	if( !(victim = query_attackers()) ) return 0;
	if( wait_state ) {
		if( --wait_state ) {
                    tell_room( environment(),
                           "����������񣬲�֪�����ʲ�� ....\n",
				this_object() );
			return 1;
		} else {
                    tell_object( victim[0],
				"��ش��: �û��ᣡ\n�����������������ٶȳ�������޷����ĵط���һ����֮�����ľ�ʹ\n"
                            "ʹ�㼸���޷��о����Լ������еĲ�λ��\n" );
                    tell_room( environment(this_object()),
				"��ش��: �û��ᣡ\n"
"ֻ�������ĵ���������ǰһ����"+victim[0]->query("c_name")+"�������Ѿ�����һ�������ֳ����˿ڣ�\n" ,
				({ this_object(), victim[0] }) );
			victim[0]->receive_damage( (int)query("max_damage1") * 3 );
			return 1;
		}
	}
	if( random(20)<5 ) {
		wait_state = 2 + random(3);
		return 0;
	}
}
