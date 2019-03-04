#include <../goomay.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(13);
        set_name( "fire monster", "������" );
        add( "id", ({ "monster" }) );
        set_short( "������" );
        set_long( @C_LONG
�㿴��һֻ��������ɫ��������֣�����˫��ɢ����һ������Ĺ�â
����ʹ������ս���㣬���������һֻ���������ܴ�������ϵ�����
��Ҳ�̲�ס����ֱð���⡣
C_LONG
);
	set("killer",1);
	set_perm_stat( "str", 20 );
	set_perm_stat( "int", 18 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "kar", 18 );
	set_skill( "dodge", 100 );
	set("defense_type","dodge");
	set( "alignment", -1500 );
	set( "natural_armor_class", 70 );
	set( "natural_defense_bonus", 30 );
	set( "natural_weapon_class1", 30 );
	set( "natural_min_damage1", 12 );
	set( "natural_max_damage1", 23 );
	set( "tactic_func", "my_tactic" );
}

void report( object attacker, object victim )
{
   seteuid(getuid());
   tell_object( victim,
     sprintf("( ��%s )\n","/adm/daemons/statsd"->status_string(victim)));
   return;
}

int my_tactic()
{
	object *victim,ob;
	int i,spec;

	spec=random(100);
	if (spec <20 && (victim = query_attackers()))
	{
	tell_room( environment(this_object()), 
		"\n���������һ����棬����������� !!\n\n" ,
		this_object() );
	for( i=0; i<sizeof(victim); i++ )
	    {
		victim[i]->receive_special_damage( "fire", 20+random(10) );
		report(this_object(),victim[i]);
	    }
		return 1;
	}
	else if ( spec>20 && spec<50 && (victim = query_attackers()) ) 
	{
        tell_room( environment(this_object()), 
		"\n������ɢ����ǿ�ҵĹ�â������۾�һ���ʹ !!\n\n" ,
                this_object() );
        for( i=0; i<sizeof(victim); i++ )
	{
        ob = present("glasses", victim[i]);
        if(ob && ob->query("equipped"))
			tell_object( victim[i], "���ī����ס�˴��۵�ǿ�⡣\n\n");
		else
		{
	        if( victim[i]->query("stop_attack") ) continue;
	        victim[i]->block_attack(8);
	        victim[i]->set_temp("msg_stop_attack", 
	          "( ������ʲ��Ҳ������ ! )\n" );
		}
	}
	return 1;
	}
	return 0;
}

void die()
{
		tell_room( environment(this_object()), 
			"�����޴�У����ڰ�֮ĸ !! ���� !!�� ....\n\n"
			"һ����ɫ������ͻȻ����ס�����ޣ�Ȼ����ʧ����Ӱ����\n"
			"������һ����������ı����з���: ������Ϊ��������ܵĻ����ޣ�����ͻ������ͽ����𣿹����� !!��\n\n"
			"���ͷһ����һ��Ů����վ����ı��ᡣ����������һ��Ů����\n"
			"�������� !!�������һ���������Ϊһֻ��ͷ���������\n\n" ,
			this_object() );
		set( "alt_corpse", Mob"snake" );
		::die(1);
}
